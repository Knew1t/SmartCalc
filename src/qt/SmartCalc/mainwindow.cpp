#include "mainwindow.h"
#include "./ui_mainwindow.h"

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
  ui->Display_2->setReadOnly(true);
  ui->Display_2->setText("");
  ui->X_Display->setText("");
  ui->X_Display->setAlignment(Qt::AlignRight);
  ui->Display->setText("sin(x)");
  ui->Display->setAlignment(Qt::AlignRight);
  ui->Display->setFocus();
  ui->Display->setFocusPolicy(Qt::ClickFocus);
  QPushButton *digitButtons[10];
  for (int i = 0; i < 10; i++) {
    QString buttonName = "button_" + QString::number(i);
    digitButtons[i] = MainWindow::findChild<QPushButton *>(buttonName);
    connect(digitButtons[i], SIGNAL(released()), this, SLOT(digitPressed()));
    digitButtons[i]->setFocusPolicy(Qt::NoFocus);
  }
  connect(ui->button_x, SIGNAL(released()), this, SLOT(xPressed()));
  ui->button_x->setFocusPolicy(Qt::NoFocus);
  connect(ui->button_clear, SIGNAL(released()), this, SLOT(clearPressed()));
  ui->button_clear->setFocusPolicy(Qt::NoFocus);
  connect(ui->button_plus, SIGNAL(released()), this, SLOT(plusPressed()));
  ui->button_plus->setFocusPolicy(Qt::NoFocus);
  connect(ui->button_minus, SIGNAL(released()), this, SLOT(minusPressed()));
  ui->button_minus->setFocusPolicy(Qt::NoFocus);
  connect(ui->button_open_parent, SIGNAL(released()), this,
          SLOT(openParentPressed()));
  ui->button_open_parent->setFocusPolicy(Qt::NoFocus);
  connect(ui->button_close_parent, SIGNAL(released()), this,
          SLOT(closeParentPressed()));
  ui->button_close_parent->setFocusPolicy(Qt::NoFocus);

  QPushButton *trigonometryButtons[9] = {
      ui->button_sin,  ui->button_cos,  ui->button_tg,
      ui->button_acos, ui->button_asin, ui->button_atan,
      ui->button_ln,   ui->button_log,  ui->button_sqrt};
  for (int i = 0; i < 9; i++) {
    connect(trigonometryButtons[i], SIGNAL(released()), this,
            SLOT(trigonometryButtonPressed()));
    trigonometryButtons[i]->setFocusPolicy(Qt::NoFocus);
  }

  connect(ui->button_multiply, SIGNAL(released()), this,
          SLOT(multiplyPressed()));
  ui->button_multiply->setFocusPolicy(Qt::NoFocus);
  connect(ui->button_divide, SIGNAL(released()), this, SLOT(dividePressed()));
  ui->button_divide->setFocusPolicy(Qt::NoFocus);
  connect(ui->button_equal, SIGNAL(released()), this, SLOT(equalPressed()));
  ui->button_equal->setFocusPolicy(Qt::NoFocus);
  connect(ui->button_dot, SIGNAL(released()), this, SLOT(dotPressed()));
  ui->button_dot->setFocusPolicy(Qt::NoFocus);
  connect(ui->button_xor, SIGNAL(released()), this, SLOT(XorPressed()));
  ui->button_xor->setFocusPolicy(Qt::NoFocus);
  connect(ui->graph_button, SIGNAL(released()), this,
          SLOT(GraphButtonPressed()));
  ui->graph_button->setFocusPolicy(Qt::NoFocus);
}

MainWindow::~MainWindow() {
  delete ui;
}

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
  if (ui->Display->hasFocus()) {
    ui->Display->setText(math_expression);
    ui->Display->setAlignment(Qt::AlignRight);
    plus_trigger = false;
    div_trigger = false;
    mult_trigger = false;
    digit_trigger = false;
    dot_trigger = false;
  } else if (ui->X_Display->hasFocus()) {
    ui->X_Display->setText(math_expression);
    ui->X_Display->setAlignment(Qt::AlignRight);
  }
}

void MainWindow::digitPressed() {
  QPushButton *button = (QPushButton *)sender();
  QString buttonValue = button->text();
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

void MainWindow::XorPressed() { ui->Display->insertPlainText("^"); }

void MainWindow::xPressed() { ui->Display->insertPlainText("x"); }

//=================================================
void MainWindow::GraphButtonPressed() {
  QByteArray function_string = ui->Display->toPlainText().toLocal8Bit();
  char *ptr_display = function_string.data();
  new_chart.imported_expression = ptr_display;
  new_chart.DrawGraph(1);
  new_chart.show();
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
