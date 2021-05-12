#define USE_MATH_DEFINES // for c++

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	const auto x = 0.5;
	const auto y = 0.05;
	const auto z = 0.7;
	const auto a = (pow(x , 2) * (x + 1.0)) / (y - pow(sin(x + y) , 2));
	const auto b = sqrt(x * y / z) + pow(cos(pow(x + y, 2)), 2);

	cout << "x = " << x << ", y =  " << y << ", z = " << z << "\n";
	cout << "a = " << a << ", b = " << b << endl;

	return 0;
}