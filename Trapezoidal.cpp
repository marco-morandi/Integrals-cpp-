/// @file Trapezoidal.cpp
/// @file Implementation of the class Trapezoidal

#include "Trapezoidal.h"


/// @brief default constructor
Trapezoidal::Trapezoidal() {
    
}

/// @brief constructor 
/// @param p pointer to the polynomial of the integral
Trapezoidal::Trapezoidal(Polynomial* p) : Integral(p) {

}

/// @brief copy constructor 
/// @param t reference to the trapezoidal integral to copy
Trapezoidal::Trapezoidal(const Trapezoidal& t) {

    cout << "Trapezoidal - copy constructor\n\n";

    if (t.poly != 0) {
        poly = new Polynomial;
        if (poly == 0) {
            ErrorMessage("Copy constructor - Allocation didn't go as expected");
        }
        
        *poly = *(t.poly);
    } 
    else {
        poly = 0;
    }

}

/// @brief destructor
Trapezoidal::~Trapezoidal() {

}

/// @brief overload of operator =
/// @param t reference to the trapezoidal to assign
Trapezoidal& Trapezoidal::operator=(const Trapezoidal& t) {

    if(poly != 0) {
        delete(poly);
        poly = 0;
    }

    poly = new Polynomial;
    if (poly == 0) 
        ErrorMessage("Operator= - Allocation didn't go as expected");

    if (t.poly != 0) {
        poly = t.poly;
    }
    else {
        poly = 0;
    }

    return *this;
}

/// @brief Compute the value of the integral using trapezoidal method
/// @param inf lower end of the integral
/// @param sup upper end of the integral
/// @param intervals number of intervals in which we divide the integration interval
double Trapezoidal::GetIntegral(double inf, double sup, int intervals) {

    int i;

    double integ = 0;
    double stepsize = (sup - inf) / (double)intervals;
    double h = stepsize / 2.;
    double in1, in2;

    in1 = inf;
    for(i = 0; i < intervals; i++) {
        in2 = in1 + stepsize;
        integ += h*(poly->GetValue(in1) + poly->GetValue(in2));
        in1 = in2;
    }

    return integ;

}

/// @brief write an error message 
/// @param string message to be printed
void Trapezoidal::ErrorMessage(const char *string) {
	
	cout << endl << "ERROR -- Trapezoidal --";
	cout << string << endl;

}

/// @brief write a warning message 
/// @param string message to be printed
void Trapezoidal::WarningMessage(const char *string) {
	
	cout << endl << "WARNING -- Trapezoidal --";
	cout << string << endl;

}

void Trapezoidal::Dump() {
	
	cout << "*** Trapezoidal Integral ***\n\n";
    Integral::Dump();

	return;
}


