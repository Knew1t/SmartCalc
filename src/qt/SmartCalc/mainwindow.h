#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "QtWidgets/qpushbutton.h"
#include <QMainWindow>
#include <QToolButton>
#include "QKeyEvent"

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
//  void keyPressEvent();

private:
  Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
