#include "mainwindow.h"
#include "./ui_mainwindow.h"
extern "C" {
#include "backend.h"
}
// #include "QtCore/qobjectdefs.h"

char math_expression[255] = {0};
bool plus_trigger = false;
bool div_trigger = false;
bool mult_trigger = false;
bool digit_trigger = false;
bool dot_trigger = false;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  setFixedSize(geometry().width(), geometry().height());
  //  ui->Display->setReadOnly(true);
  ui->Display_2->setReadOnly(true);
  ui->Display_2->setText("");
  ui->X_Display->setText("");
  ui->X_Display->setAlignment(Qt::AlignRight);
  ui->Display->setText(math_expression);
  ui->Display->setAlignment(Qt::AlignRight);
  QPushButton *digitButtons[10];
  for (int i = 0; i < 11; i++) {
    QString buttonName = "button_" + QString::number(i);
    digitButtons[i] = MainWindow::findChild<QPushButton *>(buttonName);
    connect(digitButtons[i], SIGNAL(released()), this, SLOT(digitPressed()));
  }
  connect(ui->button_x, SIGNAL(released()),this, SLOT(xPressed()));
  connect(ui->button_clear, SIGNAL(released()), this, SLOT(clearPressed()));
  connect(ui->button_plus, SIGNAL(released()), this, SLOT(plusPressed()));
  connect(ui->button_minus, SIGNAL(released()), this, SLOT(minusPressed()));
  connect(ui->button_open_parent, SIGNAL(released()), this,
          SLOT(openParentPressed()));
  connect(ui->button_close_parent, SIGNAL(released()), this,
          SLOT(closeParentPressed()));

  QPushButton *trigonometryButtons[9] = {
      ui->button_sin,  ui->button_cos,  ui->button_tg,
      ui->button_acos, ui->button_asin, ui->button_atan,
      ui->button_ln,   ui->button_log,  ui->button_sqrt};
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
  if (digit_trigger && !mult_trigger) {
    ui->Display->insertPlainText("*" + outputString);
    mult_trigger = true;
  } else {
    ui->Display->insertPlainText(outputString);
    mult_trigger = true;
  }
}

void MainWindow::clearPressed() {
  std::fill_n(math_expression, 255, 0);
  if (ui->Display->hasFocus()){
    ui->Display->setText(math_expression);
    ui->Display->setAlignment(Qt::AlignRight);
    plus_trigger = false;
    div_trigger = false;
    mult_trigger = false;
    digit_trigger = false;
    dot_trigger = false;
  } else if (ui->X_Display->hasFocus()){
    ui->X_Display->setText(math_expression);
    ui->X_Display->setAlignment(Qt::AlignRight);
  }
}

void MainWindow::digitPressed() {
  QPushButton *button = (QPushButton *)sender();
  QString buttonValue = button->text();
  // QString displayVal = ui->Display->placeholderText();
  // QString newVal = displayVal + butval;
  if (ui->Display->hasFocus()) {
    ui->Display->insertPlainText(buttonValue);
    digit_trigger = true;
    mult_trigger = false;
    div_trigger = false;
    dot_trigger = false;
  } else if (ui->X_Display->hasFocus()) {
    ui->X_Display->insertPlainText(buttonValue);
  }
}
void MainWindow::openParentPressed() {
  if (!dot_trigger)
    ui->Display->insertPlainText("(");
}
void MainWindow::closeParentPressed() {
  if (!dot_trigger)
    ui->Display->insertPlainText(")");
}
void MainWindow::dotPressed() {
  if (!dot_trigger) {
    ui->Display->insertPlainText(".");
    dot_trigger = true;
  }
}
// ============== OPERATIONS =======================
void MainWindow::plusPressed() {
  if (!plus_trigger)
    ui->Display->insertPlainText("+");
  plus_trigger = true;
  dot_trigger = true;
}

void MainWindow::minusPressed() {
  ui->Display->insertPlainText("-");
  dot_trigger = true;
  plus_trigger = false;
}

void MainWindow::multiplyPressed() {
  if (!mult_trigger && !div_trigger) {
    ui->Display->insertPlainText("*");
    mult_trigger = true;
    div_trigger = true;
  }
}
void MainWindow::dividePressed() {
  if (!mult_trigger && !div_trigger) {
    ui->Display->insertPlainText("/");
    mult_trigger = true;
    div_trigger = true;
  }
}
void MainWindow::xPressed(){
  ui->Display->insertPlainText("x");
}
//=================================================
void MainWindow::GraphButtonPressed(){
  QSplineSeries* graph = new QSplineSeries();
  graph->setName("graph");
  graph->append(0, 6);
  graph->append(2, 4);
  graph->append(3, 8);
  *graph << QPointF(11,1) << QPointF(13,3) << QPointF(17,6);
  QChart *chart = new QChart();


}
//==================================================
void MainWindow::equalPressed() {
  QByteArray array = ui->Display->toPlainText().toLocal8Bit();
  double answer = 0;
  char *ptr = math_expression;
  QByteArray array_x = ui->X_Display->toPlainText().toLocal8Bit();
  char *ptr_x = array_x.data();
  ptr = array.data();
  if (!Calculate(ptr, &answer, ptr_x)) {
    ui->Display_2->setText(QString::number(answer));
    ui->Display_2->setAlignment(Qt::AlignRight);
    ui->Display_2->moveCursor(QTextCursor::End);
  } else {
    ui->Display_2->setText("Achtung!");
    ui->Display_2->setAlignment(Qt::AlignRight);
    ui->Display_2->moveCursor(QTextCursor::End);
  }
}
