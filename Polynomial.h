/// @file Polynomial.h
///	@brief Declaration of the class Polynomial	

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

/// @class Polynomial
/// @brief Class that describes a polynomial
class Polynomial {

private:
	double* coeffs; // pointer to double that will point to the array of coefficients of the polynomial
	size_t degree; // degree of the polynomial (size_t type returned by sizeof() and alignof() operators, it can store the maximum size of a theoretically possible array or an object)

public:

	/// @name CONSTRUCTORS / DESTRUCTOR
	/// @{
	Polynomial(); 
	Polynomial(const double* coefficients, size_t size);
	Polynomial(const Polynomial& p);
	~Polynomial();
	/// @}

	/// @name OPERATORS
	/// @{
	Polynomial& operator=(const Polynomial& p);
	bool operator==(const Polynomial& p);
	Polynomial operator+(const Polynomial& p); 
	/// @}

	/// @name BASIC HANDLING
	/// @{
	void Init();
	void Init(const Polynomial& p);
	void Reset();
	/// @}

	/// @name GETTERS / SETTERS
	/// @{
	void SetNewParam(const double* new_coeffs, size_t size); // changes coeffs and degree

	size_t GetDegree(); // returns the degree of the polynomial
	double GetValue(double x) const; // returns the value of the polynomail given a specific value of the variable
	/// @}

	/// @name DEBUG / SERIALIZATION
	/// @{
	void Dump();
	void ErrorMessage(const char* string);
	void WarningMessage(const char* string);
	/// @}

};


#endif