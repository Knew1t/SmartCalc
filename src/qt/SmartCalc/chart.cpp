#include "chart.h"
#include "qcustomplot.h"
#include "ui_chart.h"
#include <cstddef>

chart::chart(QWidget *parent) : QDialog(parent), ui(new Ui::chart) {
  ui->setupUi(this);
  ui->domain_field_min->setText("-5000");
  ui->domain_field_max->setText("5000");
  ui->range_field_min->setText("0");
  ui->range_field_max->setText("0");

}

chart::~chart() { delete ui; }

void chart::DrawGraph(char expression[]) {
  double answer = 0;
  int domain_max_value, domain_min_value, range_max_value, range_min_value;
  domain_min_value = ui->domain_field_min->toPlainText().toDouble();
  domain_max_value = ui->domain_field_max->toPlainText().toDouble();
  int i_max = abs(domain_min_value)+abs(domain_max_value);

  QVector<double> x(1000000), y(1000000);
  for (int i = 0; i < i_max; ++i) {
    x[i] = i / 100.0 - (i_max/100.0) / 2.0;
    std::string x_value_string = std::to_string(x[i]);
    int n = x_value_string.length();
    char x_value_array[n + 1];
    strcpy(x_value_array, x_value_string.c_str());
    Calculate(expression, &answer, x_value_array);
    y[i] = answer;
  }
  ui->widget->addGraph();
  ui->widget->graph(0)->setData(x, y);
  ui->widget->xAxis->setLabel("x");
  ui->widget->yAxis->setLabel("y");
  // ui->widget->xAxis->setRange(0, 11);
  // ui->widget->yAxis->setRange(-2, 2);
  ui->widget->setInteraction(QCP::iRangeDrag, true);
  ui->widget->setInteraction(QCP::iRangeZoom, true);
  ui->widget->replot();
}
