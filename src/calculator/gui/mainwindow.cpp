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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_digit_released()
{   

}

void MainWindow::on_pushButton_dot_released()
{

}

void MainWindow::on_pushButton_equals_released()
{

}

void MainWindow::on_pushButton_ans_released()
{

}

void MainWindow::on_pushButton_times_released()
{

}

void MainWindow::on_pushButton_plus_released()
{

}

void MainWindow::on_pushButton_div_released()
{

}

void MainWindow::on_pushButton_minus_released()
{

}

void MainWindow::on_pushButton_fact_released()
{

}

void MainWindow::on_pushButton_power_released()
{

}

void MainWindow::on_pushButton_root_released()
{

}

void MainWindow::on_pushButton_log_released()
{

}

void MainWindow::on_pushButton_delete_released()
{

}

void MainWindow::on_pushButton_clear_released()
{

}
