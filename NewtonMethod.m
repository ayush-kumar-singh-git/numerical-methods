% runs bisection method for atmost 5 iterations / 0.001 tolerance
% Gets the initial guess in the range [a,b] and performs NM till tol
% f is the function and fp is its derivative
function [p] = NewtonMethod(a, b, f, fp, tol)
 curr = BisectionMethod(a,b,f,0.001,10);
 prev = a;
 while abs(curr - prev) > tol
   prev = curr;
   curr = prev - (f(prev)/fp(prev));
 endwhile
p = curr;
