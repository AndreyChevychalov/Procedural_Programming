//Определить сопротивление провода.

#include <iostream>

using namespace std;

/**
 * \brief Расчет сопротивления в проводе.
 * \param resestivity Удельное сопротивление.
 * \param length Длинна провода.
 * \param area Площадь поперечного сечения.
 * \return Сопротивление провода.
 */
double FindResistance(const double resestivity, const double length, const double area);

/**
 * \brief Точка входа в программу
 * \return Возвращает нуль, в случае успеха
 */
int main()
{
	const auto RO = 0.028;

	cout << "Input length of the wire = ";
	double l;
	cin >> l;

	cout << "Input Cross-sectional area = ";
	double S;
	cin >> S;

	const auto R = FindResistance(RO, l, S);
	cout << "Resistance is = " << R;

	return 0;
}

double FindResistance(const double resestivity, const double length, const double area)
{
	return resestivity * length / area;
}