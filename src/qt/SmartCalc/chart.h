#ifndef CHART_H
#define CHART_H

#include "qcustomplot.h"
#include <QDialog>

namespace Ui {
class chart;
}

class chart : public QDialog {
  Q_OBJECT

public:
  explicit chart(QWidget *parent = nullptr);
  ~chart();

private:
  Ui::chart *ui;
  QCustomPlot *new_chart;
  void DrawGraph(QCustomPlot * new_chart);
};

#endif // CHART_H
