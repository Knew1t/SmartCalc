#include "chart.h"
#include "ui_chart.h"

chart::chart(QWidget *parent) : QDialog(parent), ui(new Ui::chart) {
  ui->setupUi(this);
}

chart::~chart() { delete ui; }

void chart::DrawGraph(char expression[], char x_value[]) {
  QVector<double> x(2002), y(2002);
  double answer = 0;
  for (double i = 0; i < 250; ++i) {
    std::string x_v = std::to_string(i/10) ;
    int n = x_v.length();
    char x_array[n+1];
    strcpy(x_array, x_v.c_str());
    x[i]= i;
    Calculate(expression, &answer,x_array );
    y[i] = answer;
    std::cout << i;
    std::cout << answer;
  }
  ui->widget->addGraph();
  ui->widget->graph(0)->setData(x, y);
  ui->widget->xAxis->setLabel("x");
  ui->widget->yAxis->setLabel("y");
  ui->widget->xAxis->setRange(-10, 10);
  ui->widget->yAxis->setRange(-1, 1);
  ui->widget->replot();
}
