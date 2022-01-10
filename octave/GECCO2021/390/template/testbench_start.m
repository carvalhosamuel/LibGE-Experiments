%Includes fitness function for 4 Step Ahead
function [RMSE_4SA]= eval_fitness4SA(expression, inputs, outputs)

unstable_flag = 0;

str = expression;
x = inputs;
y = outputs;

%Avoiding dynamic allocation
Yhat = zeros(1,length(y));

Yhat_1 = 0;
Yhat_2 = 0;
Yhat_3 = 0;
Yhat_4 = 0;

error_4sa= zeros(1,length(y));

for k=1:(length(y)-3) 
 	 
     %1 step
     try 
 		 Yhat_1=eval(expression); 
 	 catch 
 	 	 Yhat_1=y(k); %Catching out of bounds exception 
     end
     
     %2 step
     expression2 = strrep(str,"y(k-1)","Yhat_1");
    
     try 
 		 Yhat_2=eval(expression2); 
 	 catch 
 	 	 Yhat_2=y(k+1); %Catching out of bounds exception 
     end
     
     %3 step
     expression3 = strrep(expression2,"y(k-2)","Yhat_2");
    
     try 
 		 Yhat_3=eval(expression3); 
 	 catch 
 	 	 Yhat_3=y(k+2); %Catching out of bounds exception 
     end
     
     %4 step
     expression4 = strrep(expression3,"y(k-3)","Yhat_3");
    
     try 
 		 Yhat_4=eval(expression4); 
 	 catch 
 	 	 Yhat_4=y(k+3); %Catching out of bounds exception 
     end
     
     Yhat(k+3) = Yhat_4;
     
     if (abs(Yhat_4) > 50) %Catching unstable outputs
        unstable_flag = 1;
        break
     end
    
      error_4sa(k) = (y(k+3) - Yhat_4)^2;
     
end

%Root Mean Squared Error 
if(unstable_flag == 0)
  RMSE_4SA = sqrt(mean(error_4sa(101:end))); %%IMPORTANT: THE INDEX HERE MUST MATCH THE LAGS IN THE GRAMMAR
else
  RMSE_4SA = 9999;
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
  train_4SA = eval_fitness4SA(expression,train_x,train_y);
  
  %Evaluates individual on test set  
  test_4SA = eval_fitness4SA(expression,test_x,test_y);
   
  %Saves free simulation error in results array
  results(j+1) = 1/train_4SA;
  
  test_results(j+1) = 1/test_4SA;
  %sprintf("Fitness individual %d: %f \n",j,results(j+1))
end


  


sprintf("Saving test results")
% Saving the mean of the test results for this population in txt file
  
file_test = fopen('test_results_mean','a');
fdisp(file_test, mean(test_results));
fclose(file_test);

% Saving the test results for the best individual from population in txt file
  
file_best = fopen('test_results_max','a');
fdisp(file_best, max(test_results));
fclose(file_best);

% Saving the min test results from population in txt file
  
file_min = fopen('test_results_min','a');
fdisp(file_min, min(test_results));
fclose(file_min);
  
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
