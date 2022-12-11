#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <algorithm>
#include <iostream>
#include <qnamespace.h>
#include "QtWidgets/qpushbutton.h"
#include <QtCharts/QLineSeries>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QChartView>
#include <QtCharts/qxyseries.h>
#include "QKeyEvent"
#include <iostream>
#include <QMainWindow>
#include <QToolButton>


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
  //  void keyPressEvent();

private:
  Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
