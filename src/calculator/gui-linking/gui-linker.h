/*
© Copyright 2022
    Alexaj Ondrej <xalexa09@stud.fit.vutbr.cz>
    Gurka Oliver <xgurka00@stud.fit.vutbr.cz>
    Magda Jakub <xmagda03@stud.fit.vutbr.cz>
*/

/**
 * @file gui-linker.h
 * @author Jakub Magda (xmagda03@stud.fit.vutbr.cz>)
 * @brief Header file for linker between wmath library and gui
 * @date 2022-04-20
 */


/**
 * @brief Functon convert string of chars to number, if char is Ans function return value of last answer
 *
 * @param operand string of number
 * @return double value of number
 */
double toNumber(std::string operand);

/**
 * @brief Function delete zeroes at the end of number
 *
 * @param arr string
 * @return string without zeroes
 */
std::string zeroDelete(std::string arr);

/**
 * @brief Main function of linker, call wmath library and send result as string of chars or error message
 *
 * @param expression string with expression to calculate
 * @return string with result or string with error
 */
std::string result(std::string expression);
