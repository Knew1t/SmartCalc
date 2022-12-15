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
  ui->domain_field_min->setText("-100");
  ui->domain_field_max->setText("100");
  ui->range_field_min->setText("-500");
  ui->range_field_max->setText("500");
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
  domain_min_value = ui->domain_field_min->toPlainText().toDouble()*1000;
  domain_max_value = ui->domain_field_max->toPlainText().toDouble()*1000;
  range_min_value = ui->range_field_min->toPlainText().toDouble();
  range_max_value = ui->range_field_max->toPlainText().toDouble();
  int i_max = abs(domain_min_value) + abs(domain_max_value);
  if (0 >= domain_min_value && 0 <= domain_max_value)
    ++i_max;

  int graph_number = 0;
  int add_to_graph_number = 1;
  double nan_point = NAN;
  ui->widget->clearGraphs();
  ui->widget->addGraph();
  // ui->widget->graph(0)->setLineStyle(QCPGraph::lsNone);
  // ui->widget->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc,3));
  ui->widget->xAxis->setLabel("x");
  ui->widget->yAxis->setLabel("y");
  for (int i = domain_min_value, j = 0; i <= domain_max_value && j < i_max;
       ++i, ++j) {
    double x = i / 1000.0;
    std::string x_value_string = std::to_string(x);
    int n = x_value_string.length();
    char x_value_array[n + 1];
    strcpy(x_value_array, x_value_string.data());
    Calculate(store_expression, &answer, x_value_array);
    double y = answer;
    if (!(answer != answer) && answer >= range_min_value &&
        answer <= range_max_value) {
      ui->widget->graph(0)->addData(x, y);
      add_to_graph_number = 1;
      // if (x >= 4 && x <= 5)
      //   printf("x = %lf, y = %lf \n", x, answer);
    } else if (add_to_graph_number == 1) {
      // ui->widget->addGraph();
      ui->widget->graph(0)->addData(nan_point, nan_point);
      graph_number += add_to_graph_number;
      ++add_to_graph_number;
    }
  }
  ui->widget->setInteraction(QCP::iRangeDrag, true);
  ui->widget->setInteraction(QCP::iRangeZoom, true);
  ui->widget->replot();
}

void chart::ReplotPressed() { DrawGraph(0); }
