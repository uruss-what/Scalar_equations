#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
double newtonMethod(double x0, double epsilon, int maxIterations);
double equation(double x);
double localizeRoot(double a, double b, double epsilon);
double iterationMethod(double a, double b, double epsilon);
double iteration(double x);

double equation(double x)
{
    return log(x + 2) - pow(x, 2);
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
        std::cout << "Итерация " << n << " : " << c << endl;
    }

    return c;
}

double d_equation(double x) {
    return (1 / (x + 2)) - (2 * x);  // производная уравнения
}
double iteration(double x) { // иттерационная функция
    return pow((pow(2,x)-0.5),(1/2));
}

double iterationMethod(double a,double b, double epsilon) {  //метод простой итерации
    double newX;
    int iterations = 0;

    double x0 = (a + b) / 2;
    double x = x0;
    double xn;

    do {
        xn = x0;
        x0 = x;
        x = x0 - equation(x0);
        std::cout << "Итерация " << iterations << " : " << x << endl;
        iterations++;

    } while (std::abs(x - xn) > epsilon);

    return x;
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

        std::cout << "Итерация " << iterations << " : " << x << endl;
        iterations++;
    }

    return x;
}




int main()
{
    setlocale(LC_ALL, "Russian");
    double a = -1; // Начальная точка интервала
    double b = 2; // Конечная точка интервала
    double epsilon = 0.0001; // Точность
    int maxIterations = 100;
    double x0 = -10;

    double root = localizeRoot(a, b, epsilon);
    cout << "Корень уравнения методом дихотомии : " << root << endl;

    double newton = newtonMethod(a, epsilon, maxIterations);

    cout << "Корень уравнения методом касательных(метод Ньютона): " << newton << endl;

    double itt= iterationMethod(a,b, epsilon);
    cout << "Корень уравнения методом простой итерации: " << itt << endl;

    return 0;
}