#include "chart.h"
#include "qcustomplot.h"
#include "ui_chart.h"
#include <cstddef>
#include <cstdio>
#include <cstring>
#include <math.h>
#include <qvector.h>
#include <sstream>
#include <string>

chart::chart(QWidget *parent) : QDialog(parent), ui(new Ui::chart) {
  ui->setupUi(this);
  ui->domain_field_min->setText("-10");
  ui->domain_field_max->setText("10");
  ui->range_field_min->setText("-10");
  ui->range_field_max->setText("10");
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
  double domain_multiplier = 1000;
  domain_min_value = ui->domain_field_min->toPlainText().toDouble();
  domain_max_value = ui->domain_field_max->toPlainText().toDouble();
  range_min_value = ui->range_field_min->toPlainText().toDouble();
  range_max_value = ui->range_field_max->toPlainText().toDouble();
  // if (0 >= domain_min_value && 0 <= domain_max_value)
  //   ++i_max;

  int add_to_graph_number = 1;
  double nan_point = NAN;
  ui->widget->clearGraphs();
  ui->widget->addGraph();
  ui->widget->xAxis->setLabel("x");
  ui->widget->yAxis->setLabel("y");
  ui->widget->setInteraction(QCP::iRangeDrag, true);
  ui->widget->setInteraction(QCP::iRangeZoom, true);
  int i_max = abs(domain_min_value) + abs(domain_max_value);
  if (i_max > 10000) {
    domain_multiplier = 250;
    ui->widget->graph(0)->setLineStyle(QCPGraph::lsNone);
    ui->widget->graph(0)->setScatterStyle(
        QCPScatterStyle(QCPScatterStyle::ssDisc, 1));
  }
  if (i_max > 100000) {
    domain_multiplier = 10;
    ui->widget->graph(0)->setLineStyle(QCPGraph::lsNone);
    ui->widget->graph(0)->setScatterStyle(
        QCPScatterStyle(QCPScatterStyle::ssDisc, 5));
  }
  domain_min_value *= domain_multiplier;
  domain_max_value *= domain_multiplier;
  for (int i = domain_min_value; i <= domain_max_value; ++i) {
    double x = i / domain_multiplier;
    std::string x_value_string = std::to_string(x);
    int n = x_value_string.length();
    char x_value_array[n + 1];
    strcpy(x_value_array, x_value_string.data());
    Calculate(store_expression, &answer, x_value_array);
    double y = answer;
    if (!(y != y) && y >= range_min_value && y <= range_max_value) {
      ui->widget->graph(0)->addData(x, y);
      add_to_graph_number = 1;
    } else if (add_to_graph_number == 1) {
      ui->widget->graph(0)->addData(nan_point, nan_point);
      ++add_to_graph_number;
    }
  }
  ui->widget->replot();
}

void chart::ReplotPressed() { DrawGraph(0); }
