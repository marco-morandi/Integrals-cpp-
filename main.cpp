// test file

#include <iostream>

#include "Polynomial.h"
#include "CIntegral.h"
#include "Trapezoidal.h"

using namespace std;

int main() {

	// instantiation of the polynomial
	cout << "*** Instantiation of polynomial p ***\n\n";

	double coeff[4] = { 0., 1.2, -3.6, 4. };

	int size = sizeof(coeff) / sizeof(coeff[0]);

	Polynomial p(coeff, size);

	Polynomial* pPtr = &p;

	Trapezoidal t1(pPtr);
	Trapezoidal t2 = t1;

	cout << "*** Trapezoidal integral 1 ***\n\n";
	t1.Dump();

	cout << "*** Trapezoidal integral 2 ***\n\n";
	t2.Dump();

	cout << "The value of the integral between 1 and 3 is: " << t1.GetIntegral(1, 3) << "\n\n";

	return 0;
}