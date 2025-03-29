#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
double newtonMethod(double x0, double epsilon, int maxIterations);
double equation(double x);
double localizeRoot(double a, double b, double epsilon);
double iterationMethod(double x, double epsilon);
double iteration(double x);

double equation(double x)
{
    return pow(2, x) - pow(x, 2) - 0.5;
}



double localizeRoot(double a, double b, double epsilon) //метод дихотомии
{
    double c = (a + b) / 2;
    int n = 0;
    while (abs(equation(c)) > epsilon)
    {

        if (equation(c) * equation(a) < 0)
            b = c;
        else
            a = c;

        c = (a + b) / 2;
        n++;
        cout << "Итерация " << n << " : " << c << endl;
    }

    return c;
}

double d_equation(double x) {
    return pow(2, x) * log(2) - 2 * x; // производная уравнения
}
double iteration(double x) { // иттерационная функция
    return log2(pow(x, 2) + 0.5);
}

double iterationMethod(double x,double epsilon) {  //метод простой итерации
    double newX;
    int iterations = 0;
    do {
        newX = iteration(x);
        cout << "Итерация " << iterations << " : " << newX << endl;

        if (fabs(newX - x) <= epsilon) {
            break;
        }

        x = newX;
        iterations++;
    } while (true);

    return newX;
}

double newtonMethod(double x0, double epsilon, int maxIterations) {//метод ньютона
    double x = x0;
    int iterations = 0;

    while (iterations < maxIterations) {
        double fx = equation(x);
        double dfx = d_equation(x);

        if (abs(fx) < epsilon) {
            break;
        }
        x = x - (fx / dfx);

        cout << "Итерация " << iterations << " : " << x << endl;
        iterations++;
    }

    return x;
}




int main()
{
    setlocale(LC_ALL, "Russian");
    double a = -10.0; // начальная точка интервала
    double b = 10.0; // конечная точка интервала
    double epsilon = 0.0001; // точность
    int maxIterations = 100;
    double x0 = -10;

    double root = localizeRoot(a, b, epsilon);
    cout << "Корень уравнения методом дихотомии : " << root << endl;

    double newton = newtonMethod(a, epsilon, maxIterations);

    cout << "Корень уравнения методом касательных(метод Ньютона): " << newton << endl;

    double itt= iterationMethod(a, epsilon);
    cout << "Корень уравнения методом простой итерации: " << itt << endl;

    return 0;
}