import math

def equation(x):
 return math.log(x + 2) - math.pow(x, 2)

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
 return (1 / (x + 2)) - (2 * x)

def iteration(x):
 return math.pow((math.pow(2, x) - 0.5), (1 / 2))

def iterationMethod(a, b, epsilon):
 newX = 0
 iterations = 0
 x0 = (a + b) / 2
 x = x0
 xn = 0
 while abs(x - xn) > epsilon:
    xn = x0
    x0 = x
    x = x0 - equation(x0)
    print("iteration", iterations, ":", x)
    iterations += 1

 return x

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

a = -1
b = 2
epsilon = 0.0001
maxIterations = 100
x0 = -10

root = localizeRoot(a, b, epsilon)
print("Root of an equation using the dichotomy method:", root)

newton = newtonMethod(a, epsilon, maxIterations)
print("Root of an equation using the tangent method (Newton's method):", newton)

itt = iterationMethod(a, b, epsilon)
print("The root of the equation using the simple iteration method:", itt)