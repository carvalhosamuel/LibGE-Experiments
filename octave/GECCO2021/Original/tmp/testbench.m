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
