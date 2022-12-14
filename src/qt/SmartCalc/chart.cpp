#include "chart.h"
#include "qcustomplot.h"
#include "ui_chart.h"
#include <cstddef>
#include <cstdio>
#include <cstring>
#include <sstream>

chart::chart(QWidget *parent) : QDialog(parent), ui(new Ui::chart) {
  ui->setupUi(this);
  ui->domain_field_min->setText("-50000");
  ui->domain_field_max->setText("50000");
  ui->range_field_min->setText("0");
  ui->range_field_max->setText("0");
  connect(ui->pushButton, SIGNAL(released()), this, SLOT(ReplotPressed()));
}

chart::~chart() { delete ui; }

void chart::DrawGraph(int initial_call) {
  double answer = 0;
  static char store_expression[255];
  if (initial_call) { // check if it is the first call to a function
    strcpy(store_expression, imported_expression);
  }
  long domain_max_value, domain_min_value, range_max_value, range_min_value;
  domain_min_value = ui->domain_field_min->toPlainText().toDouble();
  domain_max_value = ui->domain_field_max->toPlainText().toDouble();
  range_min_value = ui->range_field_min->toPlainText().toDouble();
  range_max_value = ui->range_field_max->toPlainText().toDouble();
  int i_max = abs(domain_min_value) + abs(domain_max_value);
  if (0 >= domain_min_value && 0 <= domain_max_value)
    ++i_max;

  QVector<double> x, y;
  for (int i = domain_min_value, j = 0; i <= domain_max_value && j < i_max;
       ++i, ++j) {
    // x[j] = i / 100.0;
    double sup_x = i / 2.0;
    std::string x_value_string = std::to_string(sup_x);
    int n = x_value_string.length();
    char x_value_array[n + 1];
    strcpy(x_value_array, x_value_string.data());
    Calculate(store_expression, &answer, x_value_array);
    if (answer >= range_min_value && answer <= range_max_value) {
      x.push_back(sup_x);
      y.push_back(answer);
    }
  }
  ui->widget->addGraph();
  ui->widget->graph(0)->setData(x, y);
  ui->widget->xAxis->setLabel("x");
  ui->widget->yAxis->setLabel("y");
  ui->widget->setInteraction(QCP::iRangeDrag, true);
  ui->widget->setInteraction(QCP::iRangeZoom, true);
  ui->widget->replot();
}

void chart::ReplotPressed() { DrawGraph(0); }
