#include "mainwindow.h"
#include "./ui_mainwindow.h"
extern "C" {
#include "backend.h"
}
//#include "QtCore/qobjectdefs.h"

char mathExpression[255] = "";
bool addTrigger = false;
bool divTrigger = false;
bool multTrigger = false;
bool digitTrigger = false;
bool dotTrigger = false;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  setFixedSize(geometry().width(), geometry().height());
  //  ui->Display->setReadOnly(true);
  ui->Display->setText("");
  ui->Display->setAlignment(Qt::AlignRight);
  QPushButton *digitButtons[10];
  for (int i = 0; i < 10; i++) {
    QString buttonName = "button_" + QString::number(i);
    digitButtons[i] = MainWindow::findChild<QPushButton *>(buttonName);
    connect(digitButtons[i], SIGNAL(released()), this, SLOT(digitPressed()));
  }
  connect(ui->button_clear, SIGNAL(released()), this, SLOT(clearPressed()));
  connect(ui->button_plus, SIGNAL(released()), this, SLOT(plusPressed()));
  connect(ui->button_minus, SIGNAL(released()), this, SLOT(minusPressed()));
  connect(ui->button_open_parent, SIGNAL(released()), this,
          SLOT(openParentPressed()));
  connect(ui->button_close_parent, SIGNAL(released()), this,
          SLOT(closeParentPressed()));

  QPushButton *trigonometryButtons[9] = {
      ui->button_sin,  ui->button_cos,  ui->button_tg, ui->button_acos,
      ui->button_asin, ui->button_atan, ui->button_ln, ui->button_log, ui->button_sqrt};
  for (int i = 0; i < 9; i++) {
    connect(trigonometryButtons[i], SIGNAL(released()), this,
            SLOT(trigonometryButtonPressed()));
  }

  connect(ui->button_multiply, SIGNAL(released()), this,
          SLOT(multiplyPressed()));
  connect(ui->button_divide, SIGNAL(released()), this, SLOT(dividePressed()));
  connect(ui->button_equal, SIGNAL(released()), this, SLOT(equalPressed()));
  connect(ui->button_dot, SIGNAL(released()), this, SLOT(dotPressed()));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::trigonometryButtonPressed() {
  QPushButton *button = (QPushButton *)sender();
  QString outputString = button->text() + "(";

  ui->Display->insertPlainText(outputString);
}

void MainWindow::clearPressed() {
  ui->Display->setText("");
  ui->Display->setAlignment(Qt::AlignRight);
  addTrigger = false;
  divTrigger = false;
  multTrigger = false;
  digitTrigger = false;
  dotTrigger = false;
}

void MainWindow::digitPressed() {
  QPushButton *button = (QPushButton *)sender();
  QString buttonValue = button->text();
  // QString displayVal = ui->Display->placeholderText();
  // QString newVal = displayVal + butval;
  ui->Display->insertPlainText(buttonValue);
  digitTrigger = true;
  multTrigger = false;
  divTrigger = false;
  dotTrigger = false;
}
void MainWindow::openParentPressed() {
  if (!dotTrigger)
    ui->Display->insertPlainText("(");
}
void MainWindow::closeParentPressed() {
  if (!dotTrigger)
    ui->Display->insertPlainText(")");
}
void MainWindow::dotPressed() {
  if (!dotTrigger) {
    ui->Display->insertPlainText(".");
    dotTrigger = true;
  }
}
// ============== OPERATIONS =======================
void MainWindow::plusPressed() { ui->Display->insertPlainText("+"); }

void MainWindow::minusPressed() {
  ui->Display->insertPlainText("-");
  dotTrigger = true;
}

void MainWindow::multiplyPressed() {
  if (!multTrigger && !divTrigger) {
    ui->Display->insertPlainText("*");
    multTrigger = true;
    divTrigger = true;
  }
}
void MainWindow::dividePressed() {
  if (!multTrigger && !divTrigger) {
    ui->Display->insertPlainText("/");
    multTrigger = true;
    divTrigger = true;
  }
}
//==================================================
void MainWindow::equalPressed() {
  QByteArray array = ui->Display->toPlainText().toLocal8Bit();
  char *ptr = mathExpression;
  ptr = array.data();
  parseMathExpression(ptr);
  ui->Display->setText(ptr);
  ui->Display->setAlignment(Qt::AlignRight);
  ui->Display->moveCursor(QTextCursor::End);
}
