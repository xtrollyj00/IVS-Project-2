/*
© Copyright 2022
    Alexaj Ondrej <xalexa09@stud.fit.vutbr.cz>
    Gurka Oliver <xgurka00@stud.fit.vutbr.cz>
    Magda Jakub <xmagda03@stud.fit.vutbr.cz>
*/

/**
 * @brief This is math library class
 *        providing basic functions for WCalculator.
 */
class Math {
    public:

    /**
     * @brief Returns result of operation ( @b a + @b b ).
     *
     * @param a augent
     * @param b addend
     * @return double sum of @b a and @b b
     */
    double Add(double a, double b);

    /**
     * @brief Returns result of operation ( @b a - @b b ).
     *
     * @param a minuend
     * @param b subtrahend
     * @return double difference of @b a and @b b
     */
    double Subtract(double a, double b);

    /**
     * @brief Returns result of operation ( @b a * @b b ).
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
     * @return unsigned long long int factorail of @b a
     */
    unsigned long long int Factorial(double a);

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
     * @brief Returns result of operation n-th-root(a)
     *
     * @exception Exc::InvalidArgumentException() - Thrown when n == 0 and a < 0
     * @exception Exc::NumberNotValidException() - Thrown when result is not valid number (NaN or infinity)
     *
     * @param a radicand
     * @param n degree
     * @return double n-th-root of a
     */
    double Root(double a, double n);

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
};
