function [RMSE_OSA, RMSE_FS, TERMS]= eval_fitness2(expression, inputs, outputs, noise)

str = expression;
%OSA_expression = strrep(str,"y="," ");
x = inputs;
y = outputs;
w = noise;
%TERMS= count(str,'(');
TERMS = length(strfind(str, "("));

FS_expression = strrep(str,"y","Yhat_fs")

%One Step Ahead Simulation

for k=1:length(y) 
 	 try 
 		 Yhat(k)=eval(str); 
 	 catch 
 	 	 Yhat(k)=0; %Catching "index out of bounds" exception for initial conditions
     end
     
     error_OSA(k) = abs(y(k) - Yhat(k));
     
end

%Root Mean Square Error: ONE STEP AHEAD
RMSE_OSA = sum(error_OSA)/length(y);

%Free Simulation

for k=1:length(y) 
 	 try 
 		 Yhat_fs(k)=eval(FS_expression); 
 	 catch 
 	 	 Yhat_fs(k)=0; 
     end
     
     if isinf(Yhat_fs(k)) %Catching unstable outputs
        sprintf("Infinity reached at k= %d", k)
        RMSE_FS = 9999;
        break
     end
    
     error_FS(k) = abs(y(k) - Yhat_fs(k));
end

%Root Mean Squared Error
RMSE_FS = sum(error_FS)/length(y);

endfunction
    

