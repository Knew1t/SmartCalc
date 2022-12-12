#include "chart.h"
#include "qcustomplot.h"
#include "ui_chart.h"

chart::chart(QWidget *parent) : QDialog(parent), ui(new Ui::chart) {
  ui->setupUi(this);
  //new_chart = new QCustomPlot();
  QVector<double> x1(5), y1(5);
  x1[0] = -45;
  y1[0] = -43;
  x1[1] = 46;
  y1[1] = 42;
  x1[2] = -25;
  y1[2] = -24;
  x1[3] = -12;
  y1[3] = 10;
  x1[4] = 25;
  y1[4] = 26;

//  new_chart->addGraph(new_chart->xAxis, new_chart->yAxis);
  ui->widget->addGraph(ui->widget->xAxis, ui->widget->yAxis);
  ui->widget->graph(0)->setData(x1,y1);
  ui->widget->xAxis->setRange(-50, 50);
  ui->widget->yAxis->setRange(-50, 50);

  ui->widget->replot();
}

chart::~chart() { delete ui; }

void DrawGraph() {
}
