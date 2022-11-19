#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_button_1_released();

    void on_button_2_released();

    void on_button_3_released();

    void on_button_4_released();

    void on_button_5_released();

    void on_button_6_released();

    void on_button_7_released();

    void on_button_8_released();

    void on_button_9_released();

    void on_pushButton_0_released();

    void on_button_enter_released();

    void on_button_clear_released();

    void on_button_plus_released();

    void on_button_minus_released();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
