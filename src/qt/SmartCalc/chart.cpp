#include "chart.h"
#include "qcustomplot.h"
#include "ui_chart.h"
#include <cstddef>
#include <cstdio>
#include <cstring>
#include <qvector.h>
#include <sstream>

chart::chart(QWidget *parent) : QDialog(parent), ui(new Ui::chart) {
  ui->setupUi(this);
  ui->domain_field_min->setText("-5000");
  ui->domain_field_max->setText("5000");
  ui->range_field_min->setText("-5");
  ui->range_field_max->setText("5");
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

  int graph_number = 0;
  int add_to_graph_number = 1;
  ui->widget->clearGraphs();
  ui->widget->addGraph();
  ui->widget->xAxis->setLabel("x");
  ui->widget->yAxis->setLabel("y");
  for (int i = domain_min_value, j = 0; i <= domain_max_value && j < i_max;
       ++i, ++j) {
    double x = i / 100.0;
    std::string x_value_string = std::to_string(x);
    int n = x_value_string.length();
    char x_value_array[n + 1];
    strcpy(x_value_array, x_value_string.data());
    Calculate(store_expression, &answer, x_value_array);
    double y = answer;
    if (answer >= range_min_value && answer <= range_max_value) {
      ui->widget->graph(graph_number)->addData(x, y);
      add_to_graph_number = 1;
    } else if (add_to_graph_number == 1) {
      ui->widget->addGraph();
      graph_number += add_to_graph_number;
      // printf("%d\n", graph_number);
      ++add_to_graph_number;
    }
  }
  ui->widget->setInteraction(QCP::iRangeDrag, true);
  ui->widget->setInteraction(QCP::iRangeZoom, true);
  ui->widget->replot();
  //=============================================
  // QVector<double> x, y;
  // for (int i = domain_min_value, j = 0; i <= domain_max_value && j < i_max;
  //      ++i, ++j) {
  // x[j] = i / 100.0;
  //   double sup_x = i / 100.0;
  //   std::string x_value_string = std::to_string(sup_x);
  //   int n = x_value_string.length();
  //   char x_value_array[n + 1];
  //   strcpy(x_value_array, x_value_string.data());
  //   Calculate(store_expression, &answer, x_value_array);
  //     x.push_back(sup_x);
  //     y.push_back(answer);
  // }

  // ui->widget->addGraph();
  // ui->widget->graph(0)->setData(x, y);
  // ui->widget->xAxis->setLabel("x");
  // ui->widget->yAxis->setLabel("y");

  // ui->widget->xAxis->setRange(range_min_value, range_max_value);
  // ui->widget->yAxis->setRange(range_min_value, range_max_value);

  // ui->widget->setInteraction(QCP::iRangeDrag, true);
  // ui->widget->setInteraction(QCP::iRangeZoom, true);
  // ui->widget->replot();
}

void chart::ReplotPressed() { DrawGraph(0); }
