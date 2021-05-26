#define _USE_MATH_DEFINES // for C++
#include <iostream>
#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

/**
 * \brief Функция нахождения значения y при a * x < 1.
 * \param x Значение x.
 * \param z Значение z.
 * \return Возвращает Значение y.
 */
double firstVariant(const double x, const double a);

/**
 * \brief Функция нахождения значения y при a * x > 1.
 * \param x Значение x.
 * \param z Значение z.
 * \return Возвращает Значение y.
 */
double secondVariant(const double x, const double a);

/**
 * \brief Точка входа в программу
 * \return Возвращает нуль, в случае успеха
 */
int main()
{
    cout << "Input x = ";
    double x;
    cin >> x;
    const double a = 1.5;
    double y = 1.0;
    if (a * x < 1)
    {
      y = firstVariant(x, a);
    }
    else
    {
      y = secondVariant(x, a);
    }

    cout << setprecision(10)
        << "\n x = " << x
        << "\n a = " << a
        << "\n y = " << y;
}

double firstVariant(const double x, const double a)
{
    return pow(a, x) - log(a * x);
}

double secondVariant(const double x, const double a)
{
    return pow(a, x) + log(a * x);
}
