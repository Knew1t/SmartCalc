/********************************************************************************
** Form generated from reading UI file 'chart.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHART_H
#define UI_CHART_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_chart
{
public:
    QCustomPlot *widget;

    void setupUi(QDialog *chart)
    {
        if (chart->objectName().isEmpty())
            chart->setObjectName(QString::fromUtf8("chart"));
        chart->resize(730, 632);
        widget = new QCustomPlot(chart);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(60, 100, 611, 411));

        retranslateUi(chart);

        QMetaObject::connectSlotsByName(chart);
    } // setupUi

    void retranslateUi(QDialog *chart)
    {
        chart->setWindowTitle(QCoreApplication::translate("chart", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class chart: public Ui_chart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHART_H
