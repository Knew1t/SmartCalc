#include "mainwindow.h"
#include "./ui_mainwindow.h"
//#include "QtCore/qobjectdefs.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  setFixedSize(geometry().width(),geometry().height());
  //connect(ui->button_1, SIGNAL (released()), ui->plainTextEdit, SLOT (appendPlainText("1")) );
}

MainWindow::~MainWindow() { delete ui; }


void MainWindow::on_button_1_released() {
    ui->plainTextEdit->insertPlainText("1");
}

void MainWindow::on_button_2_released()
{
    ui->plainTextEdit->insertPlainText("2");

}

void MainWindow::on_button_3_released()
{
    ui->plainTextEdit->insertPlainText("3");

}


void MainWindow::on_button_4_released()
{
    ui->plainTextEdit->insertPlainText("4");

}


void MainWindow::on_button_5_released()
{
    ui->plainTextEdit->insertPlainText("5");
}


void MainWindow::on_button_6_released()
{
    ui->plainTextEdit->insertPlainText("6");
}


void MainWindow::on_button_7_released()
{
    ui->plainTextEdit->insertPlainText("7");
}


void MainWindow::on_button_8_released()
{
    ui->plainTextEdit->insertPlainText("8");
}


void MainWindow::on_button_9_released()
{
    ui->plainTextEdit->insertPlainText("9");
}



void MainWindow::on_pushButton_0_released()
{
    ui->plainTextEdit->insertPlainText("0");
}


void MainWindow::on_button_enter_released()
{

}


void MainWindow::on_button_clear_released()
{

}


void MainWindow::on_button_plus_released()
{

}


void MainWindow::on_button_minus_released()
{

}

