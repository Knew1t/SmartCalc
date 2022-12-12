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
  void DrawGraph(char string[]);
  ~chart();

private:
  Ui::chart *ui;
  QCustomPlot *new_chart;
};

#endif // CHART_H
