clear all
% Include all individivuals
#<include>individual_0.m</include>
#<include>individual_1.m</include>
#<include>individual_2.m</include>
#<include>individual_3.m</include>
#<include>individual_4.m</include>
#<include>individual_5.m</include>
#<include>individual_6.m</include>
#<include>individual_7.m</include>
#<include>individual_8.m</include>
#<include>individual_9.m</include>
#<include>individual_10.m</include>
#<include>individual_11.m</include>
#<include>individual_12.m</include>
#<include>individual_13.m</include>
#<include>individual_14.m</include>
#<include>individual_15.m</include>
#<include>individual_16.m</include>
#<include>individual_17.m</include>
#<include>individual_18.m</include>
#<include>individual_19.m</include>
#<include>individual_20.m</include>
#<include>individual_21.m</include>
#<include>individual_22.m</include>
#<include>individual_23.m</include>
#<include>individual_24.m</include>
#<include>individual_25.m</include>
#<include>individual_26.m</include>
#<include>individual_27.m</include>
#<include>individual_28.m</include>
#<include>individual_29.m</include>
#<include>individual_30.m</include>
#<include>individual_31.m</include>
#<include>individual_32.m</include>
#<include>individual_33.m</include>
#<include>individual_34.m</include>
#<include>individual_35.m</include>
#<include>individual_36.m</include>
#<include>individual_37.m</include>
#<include>individual_38.m</include>
#<include>individual_39.m</include>
#<include>individual_40.m</include>
#<include>individual_41.m</include>
#<include>individual_42.m</include>
#<include>individual_43.m</include>
#<include>individual_44.m</include>
#<include>individual_45.m</include>
#<include>individual_46.m</include>
#<include>individual_47.m</include>
#<include>individual_48.m</include>
#<include>individual_49.m</include>
#<include>individual_50.m</include>
#<include>individual_51.m</include>
#<include>individual_52.m</include>
#<include>individual_53.m</include>
#<include>individual_54.m</include>
#<include>individual_55.m</include>
#<include>individual_56.m</include>
#<include>individual_57.m</include>
#<include>individual_58.m</include>
#<include>individual_59.m</include>
#<include>individual_60.m</include>
#<include>individual_61.m</include>
#<include>individual_62.m</include>
#<include>individual_63.m</include>
#<include>individual_64.m</include>
#<include>individual_65.m</include>
#<include>individual_66.m</include>
#<include>individual_67.m</include>
#<include>individual_68.m</include>
#<include>individual_69.m</include>
#<include>individual_70.m</include>
#<include>individual_71.m</include>
#<include>individual_72.m</include>
#<include>individual_73.m</include>
#<include>individual_74.m</include>
#<include>individual_75.m</include>
#<include>individual_76.m</include>
#<include>individual_77.m</include>
#<include>individual_78.m</include>
#<include>individual_79.m</include>
#<include>individual_80.m</include>
#<include>individual_81.m</include>
#<include>individual_82.m</include>
#<include>individual_83.m</include>
#<include>individual_84.m</include>
#<include>individual_85.m</include>
#<include>individual_86.m</include>
#<include>individual_87.m</include>
#<include>individual_88.m</include>
#<include>individual_89.m</include>
#<include>individual_90.m</include>
#<include>individual_91.m</include>
#<include>individual_92.m</include>
#<include>individual_93.m</include>
#<include>individual_94.m</include>
#<include>individual_95.m</include>
#<include>individual_96.m</include>
#<include>individual_97.m</include>
#<include>individual_98.m</include>
#<include>individual_99.m</include>

%Definitions
POPULATION_SIZE=100;
%Includes fitness function for One Step Ahead
function [RMSE_OSA]= eval_fitnessOSA(expression, inputs, outputs)

unstable_flag = 0;

str = expression;
%OSA_expression = strrep(str,"y="," ");
x = inputs;
y = outputs;


%FS_expression = strrep(str,"y","Yhat_fs");

%Free Simulation
%Avoiding dynamic allocation
Yhat_osa = zeros(1,length(y));
error_osa= zeros(1,length(y));

for k=1:length(y) 
 	 try 
 		 Yhat_osa(k)=eval(expression); 
 	 catch 
 	 	 Yhat_osa(k)=y(k); %Catching out of bounds exception
     %sprintf("Out of bounds exception k= %d \n",k) 
   end
     
     if (abs(Yhat_osa(k)) > 50) %Catching unstable outputs
     %if isinf(Yhat_fs(k)) %Catching unstable outputs
        %sprintf("Individual unstable at k= %d \n", k)
        %sprintf("Expression: %s \n", str)
        unstable_flag = 1;
        %return 9999;
        break
     end
    
      error_osa(k) = (y(k) - Yhat_osa(k))^2;
     
end

%Root Mean Squared Error 
if(unstable_flag == 0)
  RMSE_OSA = sqrt(mean(error_osa(48:end))); %%IMPORTANT: THE INDEX HERE MUST MATCH THE LAGS IN THE GRAMMAR
else
  RMSE_OSA = 9999;
end


endfunction
    

%Loads X
x = load('-ascii','x.txt');
%Loads Y
y = load('-ascii','y.txt');

%Training set
s75 = floor(length(x)*0.75);
train_x = x(1:s75);
train_y = y(1:s75);

%Test set
test_x = x((s75+1):end);
test_y = y((s75+1):end);

%Create random noise for Monte Carlo Simulation
%noise = randn(1,length(y))/100;
%noise = load('-ascii','noise.txt');


%Create array of results
results = zeros(POPULATION_SIZE,1);
test_results = zeros(POPULATION_SIZE,1);

for j=0:(POPULATION_SIZE-1)

  %Obtains expression from individual_
  str = strcat("individual_", num2str(j));
  expression = eval(str);
  
  %Calls fitness evaluation function
  %[OSA, FS, TERMS] = eval_fitness2(expression,x,y,noise);
  train_OSA = eval_fitnessOSA(expression,train_x,train_y);
  
  %Evaluates individual on test set  
  test_OSA = eval_fitnessOSA(expression,test_x,test_y);
   
  %Saves free simulation error in results array
  results(j+1) = 1/train_OSA;
  
  test_results(j+1) = 1/test_OSA;
  %sprintf("Fitness individual %d: %f \n",j,results(j+1))
end


  
##  %%% Calculating test error with best individual of the population
##  [W, IW] = max(results);
##
##  best = IW-1;
##
##  %Obtains expression from individual_
##  best_individual = strcat("individual_", num2str(best));
##  expression = eval(best_individual);
##
##  %Evaluates best individual on test set  
##  test_OSA = eval_fitnessOSA(expression,test_x,test_y);

% Saving the mean of the test results for this population in txt file
  
file_test = fopen('test_results','a');
fdisp(file_test, mean(test_results));
fclose(file_test);
  
%%% Q-SLOTH
sloth = 1; 

if(sloth == 1)

 quantiles = quantile(results);                 # Gets the quantiles of the fitness scores

 swapped_index = find(results >= quantiles(4)); # Getting the index of all results >= the 75th quantile
 swapped_index = swapped_index(end);            # Choosing just one of the above, closest to the 75th
 
 results(swapped_index) = max(results);         # Replacing the score of the "sloth" with the max score of the population
 
end 
  
% Saving training results to txt file, so GA can run evolution loop  
file_id = fopen('results','w');
fdisp(file_id, results);
fclose(file_id);