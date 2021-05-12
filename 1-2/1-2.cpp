#define _USE_MATH_DEFINES // for C++
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

/**
 * \brief Функция нахождения третьей стороны треугольника.
 * \param firstSide Первая сторона.
 * \param secondSide Вторая сторона.
 * \param angle Угол в радианах между сторонами.
 * \return Возвращает длинну третьей стороны.
 */
double FindThirdSide(const double firstSide, const double secondSide, const double angle);

/**
 * \brief Функция нахождения площади треугольника.
 * \param firstSide Первая сторона.
 * \param secondSide Вторая сторона.
 * \param angle Угол в радианах между сторонами.
 * \return Возвращает площадь треугольника.
 */
double FindArea(const double firstSide, const double secondSide, const double angle);

/**
 * \brief Функция нахождения радиуса описанной вокруг треугольника окружности.
 * \param firstSide Первая сторона.
 * \param secondSide Вторая сторона.
 * \param angle Угол в радианах между сторонами.
 * \return Возвращает радиус описанной вокруг треугольника окружности.
 */
double FindRadiusOfCircumscribedCircle(const double firstSide, const double secondSide, const double angle);

/**
 * \brief Точка входа в программу
 * \return Возвращает нуль, в случае успеха
 */
int main()
{
    cout << "Input a first side of the triangle = ";
    double firstSide;
    cin >> firstSide;

    cout << "Input a second side of the triangle = ";
    double secondSide;
    cin >> secondSide;

    cout << "Input an angle in radian between the sides of the triangle = ";
    double angle;
    cin >> angle;

    const auto thirdSide = FindThirdSide(firstSide, secondSide, angle);
    const auto area = FindArea(firstSide, secondSide, angle);
    const auto radius = FindRadiusOfCircumscribedCircle(firstSide, secondSide, angle);

    cout << setprecision(10)
        << "\nThe Third side is " << thirdSide
        << "\nThe Area is " << area
        << "\nThe Radius Of Circumscribed Circle is " << radius;

    return 0;
}

double FindThirdSide(const double firstSide, const double secondSide, const double angle)
{
    return pow(firstSide, 2.0) + pow(secondSide, 2.0) - 2.0 * firstSide * secondSide * cos(angle);
}

double FindArea(const double firstSide, const double secondSide, const double angle)
{
    return 0.5 * firstSide * secondSide * sin(angle);
}

double FindRadiusOfCircumscribedCircle(const double firstSide, const double secondSide, const double angle)
{
    return pow(firstSide, 2.0) + pow(secondSide, 2.0) - 2.0 * firstSide * secondSide * cos(angle) / 2.0 * sin(angle);
}