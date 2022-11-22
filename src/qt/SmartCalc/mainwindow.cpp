#include "mainwindow.h"
#include "./ui_mainwindow.h"
//#include "QtCore/qobjectdefs.h"

char math_expression[255] = "";
bool addTrigger = false;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  setFixedSize(geometry().width(), geometry().height());
//  ui->Display->setReadOnly(true);
  ui->Display->setText(QString::fromLocal8Bit(math_expression));
  ui->Display->setAlignment(Qt::AlignRight);
  QPushButton *digitButtons[10];
  for (int i = 0; i < 10; i++){
     QString buttonName = "button_" + QString::number(i);
     digitButtons[i] = MainWindow::findChild<QPushButton *>(buttonName);
     connect(digitButtons[i], SIGNAL (released()),this,  SLOT (digitPressed())) ;
  }

}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::digitPressed(){
   QPushButton *button = (QPushButton *)sender();
   QString buttonValue = button->text();
   //QString displayVal = ui->Display->placeholderText();
   //QString newVal = displayVal + butval;
   ui->Display->insertPlainText(buttonValue);
}




