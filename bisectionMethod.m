clc;
clearvars;

f = @(x) (x^6-x-1);
l = 1;
r = 2;
itr = 0;
maxItr = 100;
e = 1e-10;

E = [];
I = [];
while(itr<maxItr && (r-l)/2 > e)
    itr++;
    m = l + (r-l)/2;
    if f(m)>0
        r = m;
    else
        l = m;
    endif
    E(end+1)=(r-l)/2;
    I(end+1)=itr;
endwhile


plot(I, E, 'r*-');
xlabel('Iteration');
ylabel('Error');
title('Bisection Method Error Convergence');
grid on;
datacursormode on;

disp("Number of Iterations: ")
itr
disp("Final Approximation: ")
(l+r)/2
