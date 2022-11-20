#include "mainwindow.h"
#include "./ui_mainwindow.h"
//#include "QtCore/qobjectdefs.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  setFixedSize(geometry().width(), geometry().height());
  ui->plainTextEdit->setReadOnly(true);
  QPushButton *digitButtons[] = {ui->button_0, ui->button_1, ui->button_1,
                                 ui->button_2, ui->button_3, ui->button_4,
                                 ui->button_5, ui->button_6, ui->button_7,
                                 ui->button_8, ui->button_9};
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::digitClicked() {
  QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
  double digitValue = clickedButton->text().toDouble();
  ui->plainTextEdit->appendPlainText(QString::number(digitValue));
}



void MainWindow::on_button_1_released()
{

}

