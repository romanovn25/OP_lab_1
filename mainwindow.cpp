#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include "operations.h"
#define MAX_LEN 18

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->btn_number_0, SIGNAL(clicked()), this, SLOT(on_btn_number_clicked()));
    connect(ui->btn_number_1, SIGNAL(clicked()), this, SLOT(on_btn_number_clicked()));
    connect(ui->btn_number_2, SIGNAL(clicked()), this, SLOT(on_btn_number_clicked()));
    connect(ui->btn_number_3, SIGNAL(clicked()), this, SLOT(on_btn_number_clicked()));
    connect(ui->btn_number_4, SIGNAL(clicked()), this, SLOT(on_btn_number_clicked()));
    connect(ui->btn_number_5, SIGNAL(clicked()), this, SLOT(on_btn_number_clicked()));
    connect(ui->btn_number_6, SIGNAL(clicked()), this, SLOT(on_btn_number_clicked()));
    connect(ui->btn_number_7, SIGNAL(clicked()), this, SLOT(on_btn_number_clicked()));
    connect(ui->btn_number_8, SIGNAL(clicked()), this, SLOT(on_btn_number_clicked()));
    connect(ui->btn_number_9, SIGNAL(clicked()), this, SLOT(on_btn_number_clicked()));
    connect(ui->btn_operator_fraction, SIGNAL(clicked()), this, SLOT(on_btn_number_clicked()));
    connect(ui->btn_operator_plus, SIGNAL(clicked()), this, SLOT(on_btn_operator_plus_minus_clicked()));
    connect(ui->btn_operator_minus, SIGNAL(clicked()), this, SLOT(on_btn_operator_plus_minus_clicked()));
    connect(ui->btn_operator_increase, SIGNAL(clicked()), this, SLOT(on_btn_operator_plus_minus_clicked()));
    connect(ui->btn_operator_devide, SIGNAL(clicked()), this, SLOT(on_btn_operator_plus_minus_clicked()));
    connect(ui->btn_trig_cos, SIGNAL(clicked()), this, SLOT(on_btn_operator_plus_minus_clicked()));
    connect(ui->btn_trig_sin, SIGNAL(clicked()), this, SLOT(on_btn_operator_plus_minus_clicked()));
    connect(ui->btn_trig_tg, SIGNAL(clicked()), this, SLOT(on_btn_operator_plus_minus_clicked()));
    connect(ui->btn_trig_ctg, SIGNAL(clicked()), this, SLOT(on_btn_operator_plus_minus_clicked()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_trig_enabled(bool res)
{
    ui->btn_trig_cos->setEnabled(res);
    ui->btn_trig_sin->setEnabled(res);
    ui->btn_trig_tg->setEnabled(res);
    ui->btn_trig_ctg->setEnabled(res);
}

void MainWindow::on_btn_numbers_enabled(bool res)
{
    ui->btn_number_0->setEnabled(res);
    ui->btn_number_1->setEnabled(res);
    ui->btn_number_2->setEnabled(res);
    ui->btn_number_3->setEnabled(res);
    ui->btn_number_4->setEnabled(res);
    ui->btn_number_5->setEnabled(res);
    ui->btn_number_6->setEnabled(res);
    ui->btn_number_7->setEnabled(res);
    ui->btn_number_8->setEnabled(res);
    ui->btn_number_9->setEnabled(res);
}

void MainWindow::on_btn_operations_enabled(bool res)
{
    ui->btn_operator_plus->setEnabled(res);
    ui->btn_operator_minus->setEnabled(res);
    ui->btn_operator_increase->setEnabled(res);
    ui->btn_operator_devide->setEnabled(res);
}

void MainWindow::error_actions()
{
    QMessageBox::information(this,"Error","It is forbidden to divide by zero");
    ui->lbl_display->clear();
    on_btn_operations_enabled(false);
    on_btn_numbers_enabled(true);
    ui->btn_operator_fraction->setEnabled(false);
    ui->btn_number_0->setEnabled(true);
    ui->btn_action_delete->setEnabled(true);
    num_1 = 0;
}

void MainWindow::on_btn_number_clicked()
{
    QPushButton *btn = (QPushButton *)sender();
    QString str = ui->lbl_display->text();
    if (str.size() < MAX_LEN)
    {
        this->ui->lbl_display->setText(ui->lbl_display->text() + btn->text());
        str = ui->lbl_display->text();
        on_btn_trig_enabled(true);
        if (str == "0")
        {
            ui->btn_number_0->setEnabled(false);
            on_btn_numbers_enabled(false);
        }
        if (str == "0.")
        {
            ui->btn_number_0->setEnabled(true);
            on_btn_numbers_enabled(true);
        }
        on_btn_operations_enabled(true);
        if (!ui->lbl_display->text().contains("."))
        {
            ui->btn_operator_fraction->setEnabled(true);
        }
        if (ui->lbl_display->text().contains("."))
        {
            ui->btn_operator_fraction->setEnabled(false);
        }
        if (!num_1.isEmpty())
        {
            this->ui->btn_operator_equal->setEnabled(true);
            on_btn_trig_enabled(false);
        }
    }
    else
    {
        QMessageBox::information(this,"Error","Maximum amount of elements is already raised!");
    }
}

void MainWindow::on_btn_action_clear_clicked()
{
    ui->lbl_display->setText("");
    ui->btn_action_delete->setEnabled(true);
    ui->btn_operator_fraction->setEnabled(false);
    ui->btn_operator_equal->setEnabled(false);
    on_btn_numbers_enabled(true);
    on_btn_operations_enabled(false);
    on_btn_trig_enabled(false);
    num_1.clear();
    operation.clear();
}

void MainWindow::on_btn_action_delete_clicked()
{
    QString str = ui->lbl_display->text();
    str.chop(1);
    if (!str.contains("."))
        ui->btn_operator_fraction->setEnabled(true);
    if (str != "0")
        on_btn_numbers_enabled(true);
    if (str == "0")
        on_btn_numbers_enabled(false);
    if (str.isEmpty())
    {
        on_btn_operations_enabled(false);
        ui->btn_operator_fraction->setEnabled(false);
        on_btn_trig_enabled(false);
    }
    ui->lbl_display->setText(str);
}

void MainWindow::on_btn_operator_plus_minus_clicked()
{
    ui->btn_operator_fraction->setEnabled(false);
    if (!operation.isEmpty())
    {
        MainWindow::on_btn_operator_equal_clicked();
    }
    ui->btn_action_delete->setEnabled(true);
    on_btn_numbers_enabled(true);
    QPushButton *btn = (QPushButton *) sender();
    num_1 = ui->lbl_display->text();
    operation = btn->text();
    if (operation == "cos" || operation == "sin" || operation == "tg" || operation == "ctg")
    {
        ui->btn_operator_equal->setEnabled(true);
        ui->btn_action_delete->setEnabled(false);
        on_btn_numbers_enabled(false);
    }
    ui->lbl_display->setText("");
    on_btn_operations_enabled(false);
    on_btn_trig_enabled(false);
}


void MainWindow::on_btn_operator_equal_clicked()
{
    on_btn_numbers_enabled(true);
    on_btn_operations_enabled(true);
    ui->btn_operator_equal->setEnabled(false);
    struct operation calculation;
    calculation.num_1 = num_1.toDouble();
    calculation.num_2 = ui->lbl_display->text().toDouble();
    QByteArray sign = operation.toLatin1();
    calculation.operation = sign.data();
    double result = calculate(calculation);
    QString check = QString::number(result);
    if (check.contains("."))
        ui->btn_operator_fraction->setEnabled(false);
    if (check.contains("e"))
    {
        on_btn_numbers_enabled(false);
        ui->btn_action_delete->setEnabled(false);
    }
    if (result == ERROR)
    {
        error_actions();
    }
    else
    {
        num_1 = QString::number(result);
        ui->lbl_display->setText(num_1);
        on_btn_trig_enabled(true);
    }
    operation.clear();
    num_1.clear();
}

