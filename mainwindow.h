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
    void error_actions();



private slots:
    void on_btn_number_clicked();
    void on_btn_action_clear_clicked();
    void on_btn_action_delete_clicked();
    void on_btn_operator_equal_clicked();
    void on_btn_operator_plus_minus_clicked();
    void on_btn_numbers_enabled(bool res);
    void on_btn_operations_enabled(bool res);
    void on_btn_trig_enabled(bool res);

private:
    Ui::MainWindow *ui;

    QString num_1;
    QString operation;
};
#endif // MAINWINDOW_H
