#include <iostream>
#include <cmath>

const double epsilon = 1e-10; // Точность вычислений

// Функция для решения уравнения Кеплера методом итераций
double solveKeplerIteration(double M, double e) {
    double E = M; // Начальное приближение
    double diff = 2 * epsilon;

    while (diff > epsilon) {
        double sinE = sin(E);
        double f = E - e * sinE - M;
        double df = 1 - e * cos(E);
        double dE = -f / df;
        E += dE;

        diff = std::fabs(dE);
    }

    return E;
}

// Функция для решения уравнения Кеплера методом половинного деления
double solveKeplerBisection(double M, double e) {
    double a = M - 2 * M_PI; // Любое число меньше M
    double b = M + 2 * M_PI; // Любое число больше M

    while (b - a > 2 * epsilon) {
        double c = (a + b) / 2;
        double fc = c - e * sin(c) - M;

        if (fc * (a - c) < 0) {
            b = c;
        } else {
            a = c;
        }
    }

    return (a + b) / 2;
}

// Функция для решения уравнения Кеплера методом золотого сечения
double solveKeplerGoldenSection(double M, double e) {
    double a = M - 2 * M_PI; // Любое число меньше M
    double b = M + 2 * M_PI; // Любое число больше M
    double phi = (1 + sqrt(5)) / 2; // Золотое сечение

    while (b - a > 2 * epsilon) {
        double c = b - (b - a) / phi;
        double d = a + (b - a) / phi;

        double fc = c - e * sin(c) - M;
        double fd = d - e * sin(d) - M;

        if (fc * fd < 0) {
            b = d;
        } else {
            a = c;
        }
    }

    return (a + b) / 2;
}

// Функция для решения уравнения Кеплера методом Ньютона
double solveKeplerNewton(double M, double e) {
    double E = M; // Начальное приближение
    double diff = 2 * epsilon;

    while (diff > epsilon) {
        double sinE = sin(E);
        double cosE = cos(E);
        double f = E - e * sinE - M;
        double df = 1 - e * cosE;
        double dE = -f / df;
        E += dE;

        diff = std::fabs(dE);
    }

    return E;
}

int main() {
    double M, e;

    // Ввод значений угла и эксцентриситета
    std::cout << "Enter angle M(Radian): ";
    std::cin >> M;

    std::cout << "Enter eccentricity e: ";
    std::cin >> e;

    // Решение уравнения Кеплера для каждого метода
    double E_iteration = solveKeplerIteration(M, e);
    double E_bisection = solveKeplerBisection(M, e);
    double E_goldenSection = solveKeplerGoldenSection(M, e);
    double E_newton = solveKeplerNewton(M, e);

    // Вывод результатов
    std::cout << "Method of iterations: " << E_iteration << std::endl;
    std::cout << "Half division method: " << E_bisection << std::endl;
    std::cout << "Golden Ratio Method: " << E_goldenSection << std::endl;
    std::cout << "Newton's method: " << E_newton << std::endl;

    return 0;
}