/*
© Copyright 2022
    Alexaj Ondrej <xalexa09@stud.fit.vutbr.cz>
    Gurka Oliver <xgurka00@stud.fit.vutbr.cz>
    Magda Jakub <xmagda03@stud.fit.vutbr.cz>
*/

/**
 * @file gui-linker.cpp
 * @author Jakub Magda (xmagda03@stud.fit.vutbr.cz>)
 * @brief Linker between wmath library and gui
 * @date 2022-04-09
 */

#include "../math/wmath.h"
#include "../math/exceptions/exceptions.h"

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

#define PRECISION 14

// declaration of object compute
Math compute;

double toNumber(std::string operand){
    double number;
    if (operand == "Ans")
    {
        return compute.GetAnswer()->GetValue();
    }
    // if number is negative function stod can not convert it
    // we send to stod only positive part and then negate it
    if (operand[0] == '-'){
        operand = operand.substr(1);
        number = std::stod(operand);
        number = - number;
    }
    else{
        number = std::stod(operand);
    }
    return number;

}

std::string zeroDelete(std::string arr){
    int length = arr.length();
    for (int i = length-1; i >= 0; i--){
        if (arr[i] == '0'){
            arr = arr.substr(0,i);
        }
        else if (arr[i] == ','){
            arr = arr.substr(0,i);
            break;
        }
        else{
            break;
        }
    }
    return arr;
}

std::string result(std::string expression){
    int dlimiter;
    std::string tmp1;
    std::string tmp2;
    double result = 0;
    std::string return_value;

    // find operation in string expression and call wmath library to solve problem
    if ((dlimiter = expression.find('+')) != -1)
    {
        // cut string to 2 substring of numbers
        tmp1 = expression.substr(0,dlimiter);
        tmp2 = expression.substr(dlimiter+1);

        // convert string to number
        double operand1 = toNumber(tmp1);
        double operand2 = toNumber(tmp2);

        // compute result and convert to string
        try{result = compute.Add(operand1,operand2);
            return_value = std::to_string(result);
            return_value = zeroDelete(return_value);}
        catch(Exc::InvalidArgumentException& e){return_value = "Math ERROR";}
    }

    else if ((dlimiter = expression.find('*')) != -1)
    {
        tmp1 = expression.substr(0,dlimiter);
        tmp2 = expression.substr(dlimiter+1);

        double operand1 = toNumber(tmp1);
        double operand2 = toNumber(tmp2);

        try{result = compute.Multiply(operand1,operand2);
            return_value = std::to_string(result);
            return_value = zeroDelete(return_value);}
        catch(Exc::InvalidArgumentException& e){return_value = "Math ERROR";}
    }

    else if ((dlimiter = expression.find('/')) != -1)
    {
        tmp1 = expression.substr(0,dlimiter);
        tmp2 = expression.substr(dlimiter+1);

        double operand1 = toNumber(tmp1);
        double operand2 = toNumber(tmp2);

        // catch exception and print error message if wmath library can ot calculate problem
        try{result = compute.Divide(operand1,operand2);
            return_value = std::to_string(result);
            return_value = zeroDelete(return_value);}
        catch(Exc::InvalidArgumentException& e){return_value = "Math ERROR";}
        catch(Exc::DivisionByZeroException& e){return_value = "Math ERROR";}
    }

    else if ((dlimiter = expression.find('^')) != -1)
    {
        tmp1 = expression.substr(0,dlimiter);
        tmp2 = expression.substr(dlimiter+1);

        double operand1 = toNumber(tmp1);
        double operand2 = toNumber(tmp2);

        try{result = compute.Power(operand1,operand2);
            return_value = std::to_string(result);
            return_value = zeroDelete(return_value);}
        catch(Exc::InvalidArgumentException& e){return_value = "Math ERROR";}
        catch(Exc::NumberNotValidException& e){return_value = "Math ERROR";}
    }

    else if ((dlimiter = expression.find('√')) != -1)
    {
        tmp1 = expression.substr(0,dlimiter);
        tmp2 = expression.substr(dlimiter+1);

        double operand1 = toNumber(tmp1);
        double operand2 = toNumber(tmp2);

        try{result = compute.Root(operand2,operand1);
            return_value = std::to_string(result);
            return_value = zeroDelete(return_value);}
        catch(Exc::InvalidArgumentException& e){return_value = "Math ERROR";}
        catch(Exc::NumberNotValidException& e){return_value = "Math ERROR";}
    }
    // factorial calculation
    else if ((dlimiter = expression.find('!')) != -1)
    {
        tmp1 = expression.substr(0,dlimiter);

        double operand1 = toNumber(tmp1);

        try{result = compute.Factorial(operand1);
            return_value = std::to_string(result);
            return_value = zeroDelete(return_value);}
        catch(Exc::InvalidArgumentException& e){return_value = "Math ERROR";}
        catch(Exc::NumberNotValidException& e){return_value = "Math ERROR";}
    }

    // logarithm calculation
    else if ((dlimiter = expression.find('g')) != -1)
    {
        tmp1 = expression.substr(dlimiter+1);

        double operand1 = toNumber(tmp1);

        try{result = compute.Log(operand1);
            return_value = std::to_string(result);
            return_value = zeroDelete(return_value);}
        catch(Exc::InvalidArgumentException& e){return_value = "Math ERROR";}
        catch(Exc::NumberNotValidException& e){return_value = "Math ERROR";}
    }

    else if ((dlimiter = expression.find('-')) != -1)
    {
        // we have to choose right '-' - of operation
        // otherwise we could choose '-' of number positivity

        // count number of '-' in string
        int counter = 0;
        for (int i = 0; i < expression.length(); i++){
            if (expression[i] == '-'){
                counter++;
            }
        }

        // if '-' is on the position 0 in string
        // second '-' is indicator of operation subtract
        // otherwise it is the first '-'
        if (counter == 2){
            if ((dlimiter = expression.find('-')) == 0){
                dlimiter = expression.find('-',dlimiter+1);
            }
        }

        // second '-' will be always indicator of operation subtract
        else if (counter == 3){
            dlimiter = expression.find('-',dlimiter+1);
        }

        tmp1 = expression.substr(0,dlimiter);
        tmp2 = expression.substr(dlimiter+1);

        double operand1 = toNumber(tmp1);
        double operand2 = toNumber(tmp2);

        try{result = compute.Subtract(operand1,operand2);
            return_value = std::to_string(result);
            return_value = zeroDelete(return_value);}
        catch(Exc::InvalidArgumentException& e){return_value = "Math ERROR";}
    }

    // check if number isnt too long to printing on display
    // if it is convert it to scientific form
    if (return_value.length() >= PRECISION){
        std::stringstream buffer;
        buffer << std::setprecision(PRECISION) << std::scientific << result;
        return_value = buffer.str();
    }

    return return_value;
}
