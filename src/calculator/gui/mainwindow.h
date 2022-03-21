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

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    /**
    * @brief Concatenates digits
    */
    void on_pushButton_digit_released();

    /**
    * @brief Appends "." to what is displayed
    */
    void on_pushButton_dot_released();

    /**
    * @brief Sends operands to evaluation in form of string
    * Formats in which are operations sent:
    * "154.2+32" ... similarly in case of -,*,/
    * "xROOTy" means xth root of number y
    * "x!" the format for sending factorials.
    * "x^y" means x to the power of y
    * "logX" means decimal logarigthm of number X
    */
    void on_pushButton_equals_released();

    /**
    * @brief Loads and displays last shown result
    */
    void on_pushButton_ans_released();

    /**
    * @brief Adds * to string know it's multiplication
    */
    void on_pushButton_times_released();

    /**
    * @brief Adds + to string to know sum is desired
    */
    void on_pushButton_plus_released();

    /**
    * @brief Adds / to string to know division is desired
    */
    void on_pushButton_div_released();

    /**
    * @brief Adds - to string to know subtracting is desired
    */
    void on_pushButton_minus_released();

    /**
    * @brief Adds ! to string to know it's factorial
    */
    void on_pushButton_fact_released();

    /**
    * @brief Adds ^ to string to know it's power
    */
    void on_pushButton_power_released();

    /**
    * @brief Adds keyword "ROOT" to specify operation
    *
    */
    void on_pushButton_root_released();

    /**
    * @brief Adds keyword "log" to specify operation
    */
    void on_pushButton_log_released();

    /**
    * @brief Deletes the last entered symbol
    */
    void on_pushButton_delete_released();

    /**
    * @brief Clears the display and makes the final string empty
    */
    void on_pushButton_clear_released();
};
#endif // MAINWINDOW_H
