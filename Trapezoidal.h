/// @file Trapezoidal.h
/// @brief Declaration of class Trapezoidal

#ifndef TRAPEZOIDAL_H
#define TRAPEZOIDAL_H

#include<iostream>
#include<cmath>
#include<cstring>

#include "CIntegral.h"

using namespace std;

/// @class Trapezoidal
/// @brief Class that implements the calculation of an integral using trapezoidal method

class Trapezoidal : public Integral {

protected:

public:

    /// @name Costructors / Destructors
    /// @{
    Trapezoidal();
    Trapezoidal(Polynomial* p);
    Trapezoidal(const Trapezoidal& t);
    ~Trapezoidal();
    /// @}

    /// @name OPERATORS
    /// @{
    Trapezoidal& operator=(const Trapezoidal& t);

    /// @}

    double GetIntegral(double inf, double sup, int intervals = 100);

    /// @name Debug / Serialization
    /// @{
    void ErrorMessage(const char* string);
    void WarningMessage(const char* string);
    void Dump();
    /// @}
};







#endif