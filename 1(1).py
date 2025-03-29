import math

def equation(x):
 return math.pow(2, x) - math.pow(x, 2) - 0.5

def localizeRoot(a, b, epsilon):
 c = (a + b) / 2
 n = 0
 while abs(equation(c)) > epsilon:
  if equation(c) * equation(a) < 0:
   b = c
  else:
   a = c
  c = (a + b) / 2
  n += 1
  print("iteration", n, ":", c)
 return c

def d_equation(x):
 return math.pow(2, x) * math.log(2) - 2 * x

def iteration(x):
 return math.log2(math.pow(x, 2) + 0.5)

def iterationMethod(x, epsilon):
 newX = 0.0
 iterations = 0
 
 while True:
  newX = iteration(x)
  print("iteration ", iterations, ": ", newX)
  if abs(newX - x) <= epsilon:
   break
  x = newX
  iterations += 1
  
 return newX


def newtonMethod(x0, epsilon, maxIterations):
 x = x0
 iterations = 0
 while iterations < maxIterations:
    fx = equation(x)
    dfx = d_equation(x)

    if abs(fx) < epsilon:
        break
    x = x - (fx / dfx)

    print("iteration", iterations, ":", x)
    iterations += 1

 return x

a = -10
b = 10
epsilon = 0.0001
maxIterations = 100
x0 = -10

root = localizeRoot(a, b, epsilon)
print("Root of an equation using the dichotomy method:", root)

newton = newtonMethod(a, epsilon, maxIterations)
print("Root of an equation using the tangent method (Newton's method):", newton)

itt = iterationMethod(a, epsilon)
print("The root of the equation using the simple iteration method:", itt)