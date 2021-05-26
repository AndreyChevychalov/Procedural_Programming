#define USE_MATH_DEFINES // for c++

#include <iostream>
#include <cmath>

using namespace std;

/**
 * \brief Функция нахождения параметра a.
 * \param x параметр x.
 * \param y параметр y.
 * \param y параметр z.
 * \return параметр a.
 */
double geta(const double x, const double y, const double z);

/**
 * \brief Функция нахождения параметра a.
 * \param x параметр x.
 * \param y параметр y.
 * \param y параметр z.
 * \return параметр a.
 */
double getb(const double x, const double y, const double z);

/**
 * \brief Точка входа в программу
 * \return Возвращает нуль, в случае успеха
 */
int main()
{
	const double x = 0.5;
	const double y = 0.05;
	const double z = 0.7;
	const double a = geta(x, y, z);
	const double b = getb(x, y, z);

	cout << "x = " << x << ", y =  " << y << ", z = " << z << "\n";
	cout << "a = " << a << ", b = " << b << endl;

	return 0;
}

double geta(const double x, const double y, const double z)
{
	return (pow(x, 2) * (x + 1.0)) / (y - pow(sin(x + z), 2));
}

double getb(const double x, const double y, const double z)
{
	return sqrt(x * y / z) + pow(cos(pow(x + y, 2)), 2);
}