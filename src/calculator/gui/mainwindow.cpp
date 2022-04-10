/*
© Copyright 2022
    Alexaj Ondrej <xalexa09@stud.fit.vutbr.cz>
    Gurka Oliver <xgurka00@stud.fit.vutbr.cz>
    Magda Jakub <xmagda03@stud.fit.vutbr.cz>
*/

/**
 * @file mainwindow.cpp
 * @brief Implementation of GUI
 *
 * @author Ondrej Alexaj <xalexa09@stud.fit.vutbr.cz>
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "../math/wmath.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_0, SIGNAL(released()), this, SLOT(on_pushButton_digit_released()));
    connect(ui->pushButton_1, SIGNAL(released()), this, SLOT(on_pushButton_digit_released()));
    connect(ui->pushButton_2, SIGNAL(released()), this, SLOT(on_pushButton_digit_released()));
    connect(ui->pushButton_3, SIGNAL(released()), this, SLOT(on_pushButton_digit_released()));
    connect(ui->pushButton_4, SIGNAL(released()), this, SLOT(on_pushButton_digit_released()));
    connect(ui->pushButton_5, SIGNAL(released()), this, SLOT(on_pushButton_digit_released()));
    connect(ui->pushButton_6, SIGNAL(released()), this, SLOT(on_pushButton_digit_released()));
    connect(ui->pushButton_7, SIGNAL(released()), this, SLOT(on_pushButton_digit_released()));
    connect(ui->pushButton_8, SIGNAL(released()), this, SLOT(on_pushButton_digit_released()));
    connect(ui->pushButton_9, SIGNAL(released()), this, SLOT(on_pushButton_digit_released()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::variablesSet()
{
    writingEnable = true;
    wasOperation = true;
    stillZeroFirst = false;
    secondOperand = true;
    digitPressed = false;
}

void MainWindow::on_pushButton_digit_released()
{
    if(writingEnable && (ui->label->text()).size()<MAX_WIDTH){
        digitPressed = true;
        QPushButton * signalSender = (QPushButton*)sender();

        if(!secondOperand)
        {
            if(stillZeroFirst && signalSender->text() == "0")
                return;
            if(stillZeroFirst && !usedDot_1)
                ui->label->setText("");
            if(signalSender->text() != "0")
                stillZeroFirst = false;
        }
        else
        {
            if(startOfOperand && signalSender->text() == "0")
            {
                stillZeroFirst = true;
            }
            else if(stillZeroFirst && signalSender->text() == "0")
                return;
            else if(stillZeroFirst && !usedDot_2)
                return;
            else if(signalSender->text() != "0")
                stillZeroFirst = false;
        }

        operatorNotAllowed = false;
        startOfOperand = false;
        nothingPressed = false;
        ui->label->setText(ui->label->text() + signalSender->text());
    }
}

void MainWindow::on_pushButton_dot_released()
{
    if(!usedDot_1 && !secondOperand && writingEnable && digitPressed && (ui->label->text()).size()<MAX_WIDTH)
    {
        ui->label->setText(ui->label->text() + ".");
        usedDot_1 = true;
        stillZeroFirst = false;
        operatorNotAllowed = true;
    }
    else if(!usedDot_2 && secondOperand && writingEnable && digitPressed && (ui->label->text()).size()<MAX_WIDTH)
    {
        ui->label->setText(ui->label->text() + ".");
        usedDot_2 = true;
        stillZeroFirst = false;
        operatorNotAllowed = true;
    }
}

void MainWindow::on_pushButton_equals_released()
{
    // TODO
}

void MainWindow::on_pushButton_ans_released()
{
    // Can't concatenate  with result of "789Ans" for example
    if(startOfOperand && !secondOperand)
    {
        ui->label->setText("Ans");
        usedDot_1 = true;
        stillZeroFirst = false;
        writingEnable = false;
        startOfOperand = false;
    }
    else if(startOfOperand && secondOperand)
    {
        ui->label->setText(ui->label->text() + "Ans");
        usedDot_2 = true;
        stillZeroFirst = false;
        writingEnable = false;
        startOfOperand = false;
    }
}

void MainWindow::on_pushButton_times_released()
{
    if(!wasOperation && !operatorNotAllowed && (ui->label->text()).size()<MAX_WIDTH)
    {
        ui->label->setText(ui->label->text() + "*");
        wasOperation = true;
        stillZeroFirst = false;
        secondOperand = true;
        startOfOperand = true;
        digitPressed = false;
    }
}

void MainWindow::on_pushButton_plus_released()
{
    if(!wasOperation && !operatorNotAllowed && (ui->label->text()).size()<MAX_WIDTH)
    {
        ui->label->setText(ui->label->text() + "+");
        variablesSet();
        startOfOperand = true;
    }
}

void MainWindow::on_pushButton_div_released()
{
    if(!wasOperation && !operatorNotAllowed && (ui->label->text()).size()<MAX_WIDTH)
    {
        ui->label->setText(ui->label->text() + "/");
        variablesSet();
        startOfOperand = true;
    }
}

void MainWindow::on_pushButton_minus_released()
{
    if(!wasOperation && !operatorNotAllowed && (ui->label->text()).size()<MAX_WIDTH)
    {
        ui->label->setText(ui->label->text() + "-");
        variablesSet();
        startOfOperand = true;
    }
}

void MainWindow::on_pushButton_fact_released()
{
    if(!wasOperation && !operatorNotAllowed && (ui->label->text()).size()<MAX_WIDTH)
    {
        ui->label->setText(ui->label->text() + "!");
        variablesSet();
        writingEnable = false;
    }
}

void MainWindow::on_pushButton_power_released()
{
    if(!wasOperation && !operatorNotAllowed && (ui->label->text()).size()<MAX_WIDTH)
    {
        ui->label->setText(ui->label->text() + "^");
        variablesSet();
        startOfOperand = true;
    }
}

void MainWindow::on_pushButton_root_released()
{
    if(!wasOperation && !operatorNotAllowed && (ui->label->text()).size()<MAX_WIDTH)
    {
        ui->label->setText(ui->label->text() + "√");
        variablesSet();
        startOfOperand = true;
    }
}

void MainWindow::on_pushButton_log_released()
{
    if(!wasOperation && !operatorNotAllowed && nothingPressed)
    {
        ui->label->setText("log");
        variablesSet();
    }
}

void MainWindow::on_pushButton_delete_released()
{
    QString operations = "+-*/!^√";
    QString displayed = ui->label->text();

    if(displayed.length() != 1)
    {
        QChar removed = displayed.back();
        displayed.chop(1);
        QChar toBeRemovedNext = displayed.back();

        // If length of displayed after removal is 1,
        // it needs to be checked if 0 is next char to be removed.
        // If yes, variables describing this state are set
        if(displayed.length() == 1)
        {
            if(toBeRemovedNext == "0")
            {
                stillZeroFirst = true;
                digitPressed = true;
                nothingPressed = true;
            }
        }

        // If removed char was operation, variables are set to
        // state corresponding with no operation
        if(operations.contains(removed, Qt::CaseSensitive))
        {
            wasOperation = false;
            writingEnable = true;
            startOfOperand = false;
            secondOperand = false;
            digitPressed = true;
        }
        // If "g" was removed, it could be "log",
        // therefore following 2 chars ("og") are also removed
        // and variables are set to state like nothing was typed
        else if(removed == "g")
        {
            displayed.chop(2);
            wasOperation = false;
            stillZeroFirst = true;
            startOfOperand = true;
            secondOperand = false;
            digitPressed = true;
            nothingPressed = true;
            ui->label->setText("0");
            return;
        }
        else if(removed == ".")
        {
            operatorNotAllowed = false;
            if(secondOperand)
                usedDot_2 = false;
            else
                usedDot_1 = false;
        }

        // When char, that could poosibly be remvoed next time, is
        // operation, variables are set to corresponding state
        if(operations.contains(toBeRemovedNext, Qt::CaseSensitive))
        {
            startOfOperand = true;
            secondOperand = true;
            stillZeroFirst = false;
            digitPressed = false;
        }

        // When char, that could poosibly be remvoed next time, is
        // dot, means something like xx. is on display, therefore
        // operator is not allowed
        if(toBeRemovedNext == ".")
        {
            operatorNotAllowed = true;
        }

        // If operation was typed, we need to check which char
        // could be removed next next time. Because in case it is
        // operation, we need to check which char follows the operation.
        // If it is "0", we need to be aware of that (in case of
        // typing new chars not to allow something like 789+000 or 789+035)
        if(wasOperation)
        {
            QChar toBeRemovedNextNext = displayed[displayed.length()-2];
            if(operations.contains(toBeRemovedNextNext, Qt::CaseSensitive))
            {
                if(toBeRemovedNext == "0")
                {
                    secondOperand = true;
                    stillZeroFirst = true;
                }
            }
        }

        ui->label->setText(displayed);
    }

    else
    {
        wasOperation = false;
        stillZeroFirst = true;
        startOfOperand = true;
        secondOperand = false;
        digitPressed = true;
        nothingPressed = true;
        ui->label->setText("0");
    }
}

void MainWindow::on_pushButton_clear_released()
{
    ui->label->setText("0");
    stillZeroFirst = true;
    secondOperand = false;
    startOfOperand = true;
    wasOperation = false;
    writingEnable = true;
    digitPressed = true;
    usedDot_1 = false;
    usedDot_2 = false;
    nothingPressed = true;
    operatorNotAllowed = false;
}
