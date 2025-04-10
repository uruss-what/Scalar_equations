﻿#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
double newtonMethod(double a,double b, double epsilon, int maxIterations);
double equation(double x);
double localizeRoot(double a, double b, double epsilon);
double iterationMethod(double a, double b, double epsilon);
double iteration(double x);

double equation(double x)
{
    return pow(x, 3) + pow(x, 2) - x - 0.5;
}



double localizeRoot(double a, double b, double epsilon) //метод дихотомии
{
    if (equation(a) * equation(b) >= 0) {
        cout << "Нет корней в интервале" << endl;
        return 0.0;
    }
    double c = (a+b)/2;
    int n = 0;
    while ((b-a) >= epsilon)
    {

        if (equation(c) == 0.0)
            break;
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
    return 3 * pow(x, 2) + 2 * x - 1;  // производная уравнения
}
double iteration(double x) { // иттерационная функция
    return pow(x + 0.5, 1.0 / 3.0);
}

double iterationMethod(double a,double b, double epsilon) {  //метод простой итерации
    double newX;
    int iterations = 0;

    double x0 = (a + b) / 2;

    do {
        newX = iteration(x0);
        x0 = newX;
        cout << "Итерация " << iterations << " : " << iterations << endl;
        iterations++;

    } while (abs(newX - x0) > epsilon);

    return newX;
}


double newtonMethod(double a,double b, double epsilon, int maxIterations) {//метод ньютона
    double x = (a+b)/2;
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
    double a = -10; // Начальная точка интервала
    double b = 10; // Конечная точка интервала
    double epsilon = 0.0001; // Точность
    int maxIterations = 1000;

    double root = localizeRoot(a, b, epsilon);
    cout << "Корень уравнения методом дихотомии : " << root << endl;

    double newton = newtonMethod(a,b, epsilon, maxIterations);

    cout << "Корень уравнения методом касательных(метод Ньютона): " << newton << endl;

    double itt= iterationMethod(a,b, epsilon);
    cout << "Корень уравнения методом простой итерации: " << itt << endl;

    return 0;
}