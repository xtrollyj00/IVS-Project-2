/*
© Copyright 2022
    Alexaj Ondrej <xalexa09@stud.fit.vutbr.cz>
    Gurka Oliver <xgurka00@stud.fit.vutbr.cz>
    Magda Jakub <xmagda03@stud.fit.vutbr.cz>
*/

/**
 * @file wmath.cpp
 * @author Oliver Gurka <xgurka00@stud.fit.vutbr.cz>
 * @brief Implementation of wmath.h, Math library with basic functions.
 * @version 0.8
 * @date 2022-03-10
 */

#include "wmath.h"
#include "exceptions/exceptions.h"

#include <exception>
#include <cmath>

Answer::Answer(double value) {
    this->value = value;
}

double Answer::GetValue() {
    return this->value;
}

void Answer::SetValue(double value) {
    this->value = value;
}

/*********************************************************/

Math::~Math() {
    delete this->ans;
}

double Math::Add(double a, double b) {
    double result = a + b;

    if (!IsValid(result)) {
        throw Exc::NumberNotValidException("Result of operation is NaN or infinity!");
    }

    this->SetAnswer(result);
    return result;
}

double Math::Subtract(double a, double b) {
    double result = a - b;

    if (!IsValid(result)) {
        throw Exc::NumberNotValidException("Result of operation is NaN or infinity!");
    }

    this->SetAnswer(result);
    return result;
}

double Math::Multiply(double a, double b) {
    double result = a * b;

    if (!IsValid(result)) {
        throw Exc::NumberNotValidException("Result of operation is NaN or infinity!");
    }

    this->SetAnswer(result);
    return result;
}

double Math::Divide(double a, double b) {

    if (b == 0) {
        throw Exc::DivisionByZeroException("Division by zero attempted!");
    }

    double result = a / b;

    if (!IsValid(result)) {
        throw Exc::NumberNotValidException("Result of operation is NaN or infinity!");
    }

    this->SetAnswer(result);
    return result;
}

double Math::Factorial(double a) {

    double result = a;

    if (!IsNatural(a)) {
        throw Exc::InvalidArgumentException("Argument must be natural number!");
    }

    if (a == 0.0) {
        this->SetAnswer(1.0);
        return 1.0;
    }

    for (double i = a - 1; i > 0; i--) {
        result *= i;
    }

    if (!IsValid(result)) {
        throw Exc::NumberNotValidException("Result of operation is NaN or infinity!");
    }

    this->SetAnswer(result);
    return result;
}

double Math::Power(double a, double n) {
    if (!IsNatural(n)) {
        throw Exc::InvalidArgumentException("Exponent must be natural number!");
    }

    double result = std::pow(a, n);
    if (!IsValid(result)) {
        throw Exc::NumberNotValidException("Result of operation is NaN or infinity!");
    }

    this->SetAnswer(result);
    return result;
}

double Math::Root(double a, double n) {

    if (a < 0 || n == 0) {
        throw Exc::InvalidArgumentException("Radicant must be greater or equal than 0 and degree must not be 0!");
    }

    double result = std::pow(a, 1.0 / n);
    if (!IsValid(result)) {
        throw Exc::NumberNotValidException("Result of operation is NaN or infinity!");
    }

    this->SetAnswer(result);
    return result;
}

double Math::Log(double a) {
    if (a <= 0) {
        throw new Exc::InvalidArgumentException("Antilogarithm must be greater then 0!");
    }
    double result = std::log10(a);
    if (!IsValid(result)) {
        throw Exc::NumberNotValidException("Result of operation is NaN or infinity!");
    }
    this->SetAnswer(result);
    return result;
}

bool Math::IsNatural(double a) {
    long double integral = 0;
    return std::modf(a, &integral) == 0.0 && a >= 0.0;
}

bool Math::IsValid(double a) {
    return !std::isnan(a) && !std::isinf(a);
}

Answer* Math::GetAnswer() {
    return this->ans;
}

void Math::SetAnswer(double value) {
    if (!ans) {
        this->ans = new Answer(value);
        return;
    }
    this->ans->SetValue(value);
}

/*** End of file wmath.cpp ***/
