#define _USE_MATH_DEFINES // for C++
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double function(double x);

int main()
{
	double x;
	for (x = 0; x <= 1; x = x + 0.1)
	{
		 double у = function(x);
		 cout << "\nx= " << x << " y= " << y;
	}
	return 0;
}

double function(double x)
{
	return sqrt(1 - x) - cos(sqrt(1 - x));
}
