/*
© Copyright 2022
    Alexaj Ondrej <xalexa09@stud.fit.vutbr.cz>
    Gurka Oliver <xgurka00@stud.fit.vutbr.cz>
    Magda Jakub <xmagda03@stud.fit.vutbr.cz>
*/

/**
 * @file wmath.h
 * @brief Math library interface
 *
 * @author Oliver Gurka <xgurka00@stud.fit.vutbr.cz>
 */

/**
 * @brief Class containing result of last operation
 *        done by this library.
 */
class Answer {
    private:
    /**
     * @brief Result of last sucessful operation.
     *
     */
    double value;

    public:

    /**
     * @brief Construct a new Answer object with initial value.
     *
     * @param value - initial value to store.
     */
    Answer(double value);

    /**
     * @brief Returns value, which this object stores.
     *
     * @return double value stored inside this object.
     */
    double GetValue();

    /**
     * @brief Sets value stored by this object to @b value.
     *
     * @param value - value to store.
     */
    void SetValue(double value);
};


/**
 * @brief This is math library class
 *        providing basic functions for WCalculator.
 */
class Math {

    private:
    /**
     * @brief Contains the result of last operation done by this object.
     */
    Answer* ans = nullptr;

    public:

    ~Math();

    /**
     * @brief Returns result of operation ( @b a + @b b ).
     *
     * @param a augent
     * @param b addend
     * 
     * @exception Exc::NumberNotValidException() - Thrown when result is not valid number (NaN or infinity).
     * 
     * @return double sum of @b a and @b b
     */
    double Add(double a, double b);

    /**
     * @brief Returns result of operation ( @b a - @b b ).
     * 
     * @exception Exc::NumberNotValidException() - Thrown when result is not valid number (NaN or infinity).
     *
     * @param a minuend
     * @param b subtrahend
     * @return double difference of @b a and @b b
     */
    double Subtract(double a, double b);

    /**
     * @brief Returns result of operation ( @b a * @b b ).
     * 
     * @exception Exc::NumberNotValidException() - Thrown when result is not valid number (NaN or infinity).
     *
     * @param a multiplier
     * @param b multiplicand
     * @return double product of @b a and @b b
     */
    double Multiply(double a, double b);

    /**
     * @brief Returns result of operation ( @b a / @b b ).
     * @details Checks for division by zero and executes the operation.
     *
     * @exception Exc::DivisionByZeroException() - Thrown when division by zero was attempted.
     *
     * @param a divident
     * @param b divisor
     * @return double ratio of @b a and @b b
     */
    double Divide(double a, double b);

    /**
     * @brief Return result of operation a!
     * @details Returns factorial of natural number @b a (including 0)
     *
     * @exception Exc::InvalidArgumentException - Thrown when @b a is not a natural number.
     *
     * @param a operator of factorial
     * @return double factorail of @b a
     */
    double Factorial(double a);

    /**
     * @brief Returns result of operation a^n.
     *
     * @exception Exc::InvalidArgumentException - Thrown when @b n is not a natural number.
     *
     * @param a base
     * @param n natural exponent (including 0)
     * @return double power of @b a and @b n
     */
    double Power(double a, double n);

    /**
     * @brief Returns result of operation n-th-root(a).
     *
     * @exception Exc::InvalidArgumentException() - Thrown when n == 0 or a < 0.
     * @exception Exc::NumberNotValidException() - Thrown when result is not valid number (NaN or infinity).
     *
     * @param a radicand
     * @param n degree
     * @return double n-th-root of a
     */
    double Root(double a, double n);

    /**
     * @brief Returns result of operation log(a) (decadic logarithm).
     * 
     * @exception Exc::InvalidArgumentException() - Thrown when @b a <= 0.
     * @exception Exc::NumberNotValidException() - Thrown when result is not valid number (NaN or infinity).
     * 
     * @param a antilogarithm
     * @return double logarithm
     */
    double Log(double a);

    /**
     * @brief Returns pointer result of last sucessful operation.
     *
     * @details If operation #1 was sucessful and returns @b Answer contaning value=3.14 and
     *          operation #2 was unsucessful (exception was thrown), value in
     *          this object will be result of operation #1, value=3.14.
     *
     * @return Answer object containg the result. If there is no last valid result
     *         of operation, returns @b nullptr.
     */
    Answer* GetAnswer();

    private:

    /**
     * @brief Checks if @b a is natural number.
     * @details Checks if @b a is in set {0, 1, 2, 3, 4, ...}
     *
     * @param a number to check
     * @return true - if number is natural (including 0)
     * @return false - otherwise
     */
    bool IsNatural(double a);

    /**
     * @brief Checks if @b a is valid number.
     * @details Checks if @b a is not NaN or infinity.
     *
     * @param a number to check
     * @return true - if number is valid
     * @return false - otherwise
     */
    bool IsValid(double a);

    /**
     * @brief Sets value stored in @b ans. If @b ans is @b nullptr,
     *        new instance is created.
     *
     * @param value - value to store.
     */
    void SetAnswer(double value);
};

/*** End of file wmath.h ***/
