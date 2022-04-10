/*
© Copyright 2022
    Alexaj Ondrej <xalexa09@stud.fit.vutbr.cz>
    Gurka Oliver <xgurka00@stud.fit.vutbr.cz>
    Magda Jakub <xmagda03@stud.fit.vutbr.cz>
*/

/**
 * @file mainwindow.h
 * @brief GUI interface
 *
 * @author Ondrej Alexaj <xalexa09@stud.fit.vutbr.cz>
 */


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#define MAX_WIDTH 31

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Ceates main window
     */
    MainWindow(QWidget *parent = nullptr);

    /**
     * @brief Destroys main window
     */
    ~MainWindow();

private:
    void variablesSet();

    Ui::MainWindow *ui;
    bool stillZeroFirst = true; /**< Indicates if 0 is still the beginning of the operand */
    bool secondOperand = false; /**< Indicates if secondOperand is currently being typed */
    bool startOfOperand = true; /**< Indicates if the operand is goind to gain it's first digit */
    bool usedDot_1 = false; /**< Indicates if dot was used in 1st operand */
    bool usedDot_2 = false; /**< Indicates if dot was used in 2nd operand */
    bool wasOperation = false; /**< Indicates if operation button was used, to not allow any other */
    bool writingEnable = true; /**< Indicates when is writing enabled (when factorial is typed -> false) */
    bool digitPressed = true; /**< Indicates if some digit was pressed */
    bool operatorNotAllowed = false; /**< Indicates if it is possible to type operator */
    bool nothingPressed = true; /**< Indicates if no input was given from user (or all has been cleared/deleted) */

private slots:
    /**
    * @brief Concatenates digits
    * @detail Does not support 000000xxx or 0789 type of input
    * but 0.xxx is supported
    */
    void on_pushButton_digit_released();

    /**
    * @brief Appends "." to what is displayed
    * @detail More dots within one digit string
    * are not supported (for example 0.12.00 not supp.).
    * Keeps track of dots (in 1st and 2nd operand).
    * Does not allow expr. like 8.+9.
    * Using 2 variables indicating
    * if in operand (1st or 2nd) is dot already
    */
    void on_pushButton_dot_released();

    /**
    * @brief Sends operands to evaluation in form of string
    * @detail Formats in which are operations sent:
    * "154.2+32" ... similarly in case of -,*,/
    * "x√y" means xth root of number y
    * "x!" the format for sending factorials.
    * "x^y" means x to the power of y
    * "logX" means decimal logarigthm of number X
    * "Ans+xxx" or "Ans+Ans" or "xxx+Ans"
    * @todo implementation waiting for interface from file between GUI and math lib.
    */
    void on_pushButton_equals_released();

    /**
    * @brief Loads and displays last shown result under "Ans"
    * @detail Just format of Ans+X, Ans+Ans, X+Ans, logAns or Ans! is supported,
    * where "+" represents any operator.
    */
    void on_pushButton_ans_released();

    /**
    * @brief If possible, adds * to string to know it's multiplication
    */
    void on_pushButton_times_released();

    /**
    * @brief If possible, adds + to string to know sum is desired
    */
    void on_pushButton_plus_released();

    /**
    * @brief If possible, adds / to string to know division is desired
    */
    void on_pushButton_div_released();

    /**
    * @brief If possible,adds - to string to know subtracting is desired
    */
    void on_pushButton_minus_released();

    /**
    * @brief If possible, adds ! to string to know it's factorial
    */
    void on_pushButton_fact_released();

    /**
    * @brief If possible, adds ^ to string to know it's power
    */
    void on_pushButton_power_released();

    /**
    * @brief If possible, adds keyword "ROOT" to specify operation
    *
    */
    void on_pushButton_root_released();

    /**
    * @brief If possible, adds keyword "log" to specify operation
    * @detail Works only when nothing else was typed.
    */
    void on_pushButton_log_released();

    /**
    * @brief Deletes symbols from the right
    * @detail When deleting last symbol, 0
    * is placed (just like on the start).
    * The "log" is deleted all at once (all 3 chars)
    * and 0 is placed instead.
    * The "ans" is also deleted all at once (all 3 chars)
    */
    void on_pushButton_delete_released();

    /**
    * @brief Clears the display and makes the final string empty
    */
    void on_pushButton_clear_released();
};
#endif // MAINWINDOW_H
