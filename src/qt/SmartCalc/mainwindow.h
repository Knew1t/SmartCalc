#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "QtWidgets/qpushbutton.h"
#include "chart.h"
#include <algorithm>
#include <iostream>
#include <qnamespace.h>
#include "QKeyEvent"
#include <QMainWindow>
#include <QToolButton>
#include <iostream>
extern "C" {
#include "backend.h"
}

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private slots:
  void digitPressed();
  void clearPressed();
  void plusPressed();
  void minusPressed();
  void multiplyPressed();
  void dividePressed();
  void equalPressed();
  void openParentPressed();
  void closeParentPressed();
  void dotPressed();
  void trigonometryButtonPressed();
  void GraphButtonPressed();
  void xPressed();
  void XorPressed();

private:
  Ui::MainWindow *ui;
  chart new_chart;
};
#endif // MAINWINDOW_H
