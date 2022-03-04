/*
© Copyright 2022
    Alexaj Ondrej <xalexa09@stud.fit.vutbr.cz>
    Gurka Oliver <xgurka00@stud.fit.vutbr.cz>
    Magda Jakub <xmagda03@stud.fit.vutbr.cz>
*/

#include "wmath.h"
#include "exceptions/exceptions.h"

#include <exception>
#include <cmath>

double Math::Add(double a, double b) {
    return a + b;
}

double Math::Subtract(double a, double b) {
    return a - b;
}

double Math::Multiply(double a, double b) {
    return a * b;
}

double Math::Divide(double a, double b) {

    if (b == 0) {
        throw Exc::DivisionByZeroException("Division by zero attempted!");
    }

    return a / b;
}

unsigned long long int Math::Factorial(double a) {

    unsigned long long int out = a;

    if (!IsNatural(a)) {
        throw Exc::InvalidArgumentException("Argument must be natural number!");
    }

    if (a == 0) return 1;

    for (unsigned long int i = a - 1; a > 0; i--) {
        out *= i;
    }

    return out;
}

double Math::Power(double a, double n) {
    if (!IsNatural(n)) {
        throw Exc::InvalidArgumentException("Exponent must be natural number!");
    }

    double result = std::pow(a, n);
    if (!IsValid(a)) {
        throw Exc::NumberNotValidException("Result of operation is NaN or infinity!");
    }

    return result;
}

double Math::Root(double a, double n) {

    if (a < 0 && n == 0) {
        throw new Exc::InvalidArgumentException("Radicant must be greater than 0 and degree must not be 0!");
    }

    double result = std::pow(a, 1.0 / n);
    if (!IsValid(a)) {
        throw Exc::NumberNotValidException("Result of operation is NaN or infinity!");
    }

    return result;
}

bool Math::IsNatural(double a) {
    long double integral = 0;
    return std::modf(a, &integral) == 0.0 && a >= 0.0;
}

bool Math::IsValid(double a) {
    return !std::isnan(a) && !std::isinf(a);
}
