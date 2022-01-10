

%Includes fitness function
function [RMSE_OSA, RMSE_FS, TERMS]= eval_fitness2(expression, inputs, outputs, noise)

str = expression;
%OSA_expression = strrep(str,"y="," ");
x = inputs;
y = outputs;
w = noise;
%TERMS= count(str,'(');
TERMS = length(strfind(str, "("));

FS_expression = strrep(str,"y","Yhat_fs");

%One Step Ahead Simulation

for k=1:length(y) 
 	 try 
 		 Yhat(k)=eval(str); 
 	 catch 
 	 	 Yhat(k)=0; %Catching "index out of bounds" exception for initial conditions
     end
     
     error_OSA(k) = (y(k) - Yhat(k))^2;
     
end

%Root Mean Square Error: ONE STEP AHEAD
RMSE_OSA = sqrt(mean(error_OSA));

%Free Simulation
unstable_flag = 0;

for k=1:length(y) 
 	 try 
 		 Yhat_fs(k)=eval(FS_expression); 
 	 catch 
 	 	 Yhat_fs(k)=0; 
     end
     
     if isinf(Yhat_fs(k)) %Catching unstable outputs
        sprintf("Infinity reached at k= %d", k)
        unstable_flag = 1;
        break
     end
    
     error_FS(k) = (y(k) - Yhat_fs(k))^2;
     
end

%Root Mean Squared Error
if(unstable_flag == 0)
  RMSE_FS = sqrt(mean(error_FS));
else
  RMSE_FS = 9999;
end

endfunction

%Includes fitness function for free simulation
function [RMSE_FS]= eval_fitnessFS(expression, inputs, outputs, noise)

unstable_flag = 0;

str = expression;
%OSA_expression = strrep(str,"y="," ");
x = inputs;
y = outputs;
w = noise;

FS_expression = strrep(str,"y","Yhat_fs");

%Free Simulation
%Avoiding dynamic allocation
Yhat_fs = ones(1,length(y));
error_FS= zeros(1,length(y));

for k=1:length(y) 
 	 try 
 		 Yhat_fs(k)=eval(FS_expression); 
 	 catch 
 	 	 Yhat_fs(k)=0.1; 
   end
     
     if (abs(Yhat_fs(k)) > 50) %Catching unstable outputs
     %if isinf(Yhat_fs(k)) %Catching unstable outputs
        %sprintf("Individual unstable at k= %d \n", k)
        %sprintf("Expression: %s \n", str)
        unstable_flag = 1;
        %return 9999;
        break
     end
    
      error_FS(k) = (y(k) - Yhat_fs(k))^2;
     
end

%Root Mean Squared Error
if(unstable_flag == 0)
  RMSE_FS = sqrt(mean(error_FS));
else
  RMSE_FS = 9999;
end

%Correlation
##if(unstable_flag == 0)
##  RMSE_FS = corr(y, Yhat_fs);
##else
##  RMSE_FS = 0;
##end

%Total Squared Error
##if(unstable_flag == 0)
##  RMSE_FS = sum(error_FS);
##else
##  RMSE_FS = 9999;
##end

endfunction


%Includes fitness function for One Step Ahead
function [RMSE_OSA]= eval_fitnessOSA(expression, inputs, outputs, noise)

unstable_flag = 0;

str = expression;
%OSA_expression = strrep(str,"y="," ");
x = inputs;
y = outputs;
w = noise;

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
  RMSE_OSA = sqrt(mean(error_osa(25:end)));
else
  RMSE_OSA = 9999;
end


endfunction
    

%Loads X
x = load('-ascii','x.txt');
%Loads Y
y = load('-ascii','y.txt');


%Create random noise for Monte Carlo Simulation
noise = randn(1,length(y))/100;
%noise = load('-ascii','noise.txt');


%Create array of results
results = zeros(POPULATION_SIZE,1);

for j=0:(POPULATION_SIZE-1)

  %Obtain expression from individual_
  str = strcat("individual_", num2str(j));
  expression = eval(str);
  
  %Calls fitness evaluation function
  %[OSA, FS, TERMS] = eval_fitness2(expression,x,y,noise);
  OSA = eval_fitnessOSA(expression,x,y,noise);

  %Saves free simulation error in results array
  
  results(j+1) = 1/OSA;
  %sprintf("Fitness individual %d: %f \n",j,results(j+1))
end
  
file_id = fopen('results','w');
fdisp(file_id, results);
fclose(file_id);