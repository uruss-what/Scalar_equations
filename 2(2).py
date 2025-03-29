import math

def equation(x):
 return math.cos(x) + (0.25*x) - 0.5

def localizeRoot(a, b, epsilon):
 iterations=0 
 if equation(a) * equation(b) >= 0:
        return None
        
 while (b-a) >= epsilon:  
        c = (a + b) / 2
        if equation(c) == 0.0:
            return round(c,4)
        elif equation(c) * equation(a) < 0:
            b = c
        else:
            a = c
        print("iteration ", iterations, ": ", c)
        iterations += 1
 return round(((a + b) / 2),4)

def d_equation(x):
 return (1/4) - math.sin(x)

def iteration(x):
 return math.cos(0.25*x - 0.5)

def iterationMethod(a,b, epsilon, maxIterations):
 newX = 0.0
 iterations = 0
 x = a
 while (iterations <= maxIterations):
  if equation(a) * equation(b) >= 0:
        return None
  newX = iteration(x)
  print("iteration ", iterations, ": ", newX)
  if abs(newX - x) <= epsilon:
   return round(newX,4)
  x = newX
  iterations += 1
  
 return round(newX,4)


def newtonMethod(a,b, epsilon, maxIterations):
 x = a
 iterations = 0
 while iterations < maxIterations:
    if equation(a) * equation(b) >= 0:
        return None
    fx = equation(x)
    dfx = d_equation(x)

    if abs(fx) < epsilon:
        break
    x = x - (fx / dfx)

    print("iteration", iterations, ":", x)
    iterations += 1

 return round(x,4)

a = -1
b = 1
epsilon = 0.0001
maxIterations = 100
x0 = -10

root = localizeRoot(a, b, epsilon)
print("Root of an equation using the dichotomy method:", root)

newton = newtonMethod(a,b, epsilon, maxIterations)
print("Root of an equation using the tangent method (Newton's method):", newton)

itt = iterationMethod(a,b, epsilon,maxIterations)
print("The root of the equation using the simple iteration method:", itt)