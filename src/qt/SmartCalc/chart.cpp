#include "chart.h"
#include "ui_chart.h"

chart::chart(QWidget *parent) : QDialog(parent), ui(new Ui::chart) {
  ui->setupUi(this);
}

chart::~chart() { delete ui; }

void chart::DrawGraph(char expression[], char x_value[]) {
  double answer = 0;
  QVector<double> x(1000000), y(1000000);
  for (int i = 0; i < 1000000; ++i) {
    std::string x_v = std::to_string(i/100.0) ;
    int n = x_v.length();
    char x_array[n+1];
    strcpy(x_array, x_v.c_str());
    x[i]= i/100.0;
    Calculate(expression, &answer,x_array );
    y[i] = answer;
  }
  ui->widget->addGraph();
  ui->widget->graph(0)->setData(x, y);
  ui->widget->xAxis->setLabel("x");
  ui->widget->yAxis->setLabel("y");
  ui->widget->xAxis->setRange(0, 10);
  ui->widget->yAxis->setRange(-2, 2);
  ui->widget->replot();
}
