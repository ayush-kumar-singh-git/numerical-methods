% Bisection Method
% Returns the root after at most itr iterations or tolerence tol (whichever happens first)
% Input is [a, b] interval, f - the function, tol and itr
function [p] = BisectionMethod(a, b, f, tol, itr)
if f(a) * f(b) > 0
  p = NaN;
  disp('Invalid Search Interval')
  return;
endif

i = 0;
while i<itr && b-a > 2*tol
  i++;
  p = a + (b-a)/2;
  y = f(p);
  if y==0
    return
   elseif y>0
    b = p;
   else
    a = p;
  endif
endwhile
end
