#ifndef CHART_H
#define CHART_H

#include "qcustomplot.h"
#include <QDialog>
#include <string>
#include <iostream>
extern "C" {
#include "backend.h"
}
namespace Ui {
class chart;
}

class chart : public QDialog {
  Q_OBJECT

public:
  explicit chart(QWidget *parent = nullptr);
  void DrawGraph(int initial_call);
  char* imported_expression = nullptr;
  ~chart();

private slots:
  void ReplotPressed();

private:
  Ui::chart *ui;
  QCustomPlot *new_chart;
};

#endif // CHART_H
