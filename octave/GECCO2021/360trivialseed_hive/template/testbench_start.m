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
sloth = 0; 

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
