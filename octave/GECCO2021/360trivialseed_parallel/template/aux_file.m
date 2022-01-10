
noise = randn(1,1000)/100;

fs = 500; %500Hz sampling frequency
f = 5;
t = (0:1000-1)/fs;
x = sin(2*pi*f*t);
%plot(t,x)

%FIR filter
expression = "0.8*x(k -11)+0.1771*x(k -3)+0.12*x(k -9)";


for k=1:length(x) 
 	 try 
 		 y(k)=eval(expression) + noise(k); 
 	 catch 
 	 	 y(k)=0; 
     end    
end

plot(t,y,t,x)


file_id = fopen('x.txt','w')
fdisp(file_id, x')
fclose(file_id)

file_id = fopen('y.txt','w')
fdisp(file_id, y')
fclose(file_id)


%Evaluating resulting individual

%Loads X
x = load('-ascii','x.txt');
%Loads Y
y = load('-ascii','y.txt');
%Create random noise for Monte Carlo Simulation
%noise = randn(1,length(y))/100;
noise = load('-ascii','noise.txt');

%Individual
individual = '  - 2.4004 *y(k- 13 ) ^2 + 0.8716 *x(k- 2 )   ';

t=1:1:length(y);

for k=1:length(x) 
 	 try 
 		 y_hat(k)=eval(individual); 
 	 catch 
 	 	 y_hat(k)=0; 
   end
   
   error(k) = (y(k) - y_hat(k));
   
end

squared_error = error.^2;

plot(squared_error)

RMSE = sqrt(mean(squared_error));


plot(t,y,t,y_hat)
legend('Original','Modelled')