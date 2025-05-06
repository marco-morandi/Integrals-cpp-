// test file

#include <iostream>

#include "Polynomial.h"

using namespace std;

int main() {

	// instantiation of the objects
	cout << "*** Instantiation of polynomial p1 ***\n\n";
	Polynomial p1;

	double coeff2[4] = { 0., 1.2, -3.6, 4. };

	int size2 = sizeof(coeff2) / sizeof(coeff2[0]);

	Polynomial p2(coeff2, size2);

	// doing dumps of the objects
	cout << "*** Polynomial 1 ***\n\n";
	p1.Dump();

	cout << "*** Polynomial 2 ***\n\n";
	p2.Dump();

	// changing parameters of p1
	double new_coeff1[3] = { -3, 1, 2 };

	int new_size1 = sizeof(new_coeff1) / sizeof(new_coeff1[0]);

	p1.SetNewParam(new_coeff1, new_size1);

	cout << "*** Polynomial 1 ***\n\n";
	p1.Dump();

	/// doing the sum of the two polynomials
	Polynomial p_sum = p1 + p2;

	// p_sum = p1 + p2;

	cout << "*** Polynomial Sum ***\n\n";
	p_sum.Dump();
	
	// getting degree of p1
	cout << "The degree of p1 is: " << p1.GetDegree() << "\n\n";

	// getting the value of p2 for x = 5
	cout << "If x = 5, the value of p2 is: " << p2.GetValue(5) << "\n\n";

	// checking if p1 and p2 are the same, assigning p2 to p1 and checking again
	if (p1 == p2)
		cout << "The two polynomials are the same\n\n";
	else
		cout << "The two polynomials are not the same\n\n";

	p1 = p2;

	if (p1 == p2)
		cout << "The two polynomials are the same\n\n";
	else
		cout << "The two polynomials are not the same\n\n";


	return 0;
}