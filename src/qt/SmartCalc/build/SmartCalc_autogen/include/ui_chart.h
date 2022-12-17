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
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_chart
{
public:
    QCustomPlot *widget;
    QTextEdit *domain_field_min;
    QTextEdit *range_field_min;
    QTextEdit *domain_field_max;
    QTextEdit *range_field_max;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QDialog *chart)
    {
        if (chart->objectName().isEmpty())
            chart->setObjectName(QString::fromUtf8("chart"));
        chart->resize(730, 632);
        widget = new QCustomPlot(chart);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 30, 641, 421));
        domain_field_min = new QTextEdit(chart);
        domain_field_min->setObjectName(QString::fromUtf8("domain_field_min"));
        domain_field_min->setGeometry(QRect(110, 500, 211, 31));
        range_field_min = new QTextEdit(chart);
        range_field_min->setObjectName(QString::fromUtf8("range_field_min"));
        range_field_min->setGeometry(QRect(380, 500, 211, 31));
        domain_field_max = new QTextEdit(chart);
        domain_field_max->setObjectName(QString::fromUtf8("domain_field_max"));
        domain_field_max->setGeometry(QRect(110, 540, 211, 31));
        range_field_max = new QTextEdit(chart);
        range_field_max->setObjectName(QString::fromUtf8("range_field_max"));
        range_field_max->setGeometry(QRect(380, 540, 211, 31));
        label = new QLabel(chart);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(110, 480, 211, 20));
        QFont font;
        font.setFamilies({QString::fromUtf8("Luminari")});
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(chart);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(380, 480, 211, 20));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);
        pushButton = new QPushButton(chart);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(300, 580, 100, 32));
        pushButton->setFont(font);
        label_3 = new QLabel(chart);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(320, 510, 58, 16));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(chart);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(320, 550, 58, 16));
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignCenter);

        retranslateUi(chart);

        QMetaObject::connectSlotsByName(chart);
    } // setupUi

    void retranslateUi(QDialog *chart)
    {
        chart->setWindowTitle(QCoreApplication::translate("chart", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("chart", "set domain", nullptr));
        label_2->setText(QCoreApplication::translate("chart", "set range", nullptr));
        pushButton->setText(QCoreApplication::translate("chart", "Replot", nullptr));
        label_3->setText(QCoreApplication::translate("chart", "\320\234\304\250N", nullptr));
        label_4->setText(QCoreApplication::translate("chart", "\320\234\310\202X", nullptr));
    } // retranslateUi

};

namespace Ui {
    class chart: public Ui_chart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHART_H
