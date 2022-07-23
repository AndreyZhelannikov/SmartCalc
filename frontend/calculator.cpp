#include "calculator.h"

#include "credit_debit.h"
#include "ui/ui_calculator.h"

Calculator::Calculator(QWidget *parent) : QMainWindow(parent), ui(new Ui::Calculator) {
    ui->setupUi(this);

    double x_min_default = -5;
    double x_max_default = 5;
    double y_min_default = -5;
    double y_max_default = 5;
    ui->plot->xAxis->setLabel("x");
    ui->plot->yAxis->setLabel("y");
    ui->plot->xAxis->setRange(x_min_default, x_max_default);
    ui->plot->yAxis->setRange(y_min_default, y_max_default);
}

Calculator::~Calculator() { delete ui; }

void Calculator::on_x_max_box_valueChanged(double arg1) {
    QCPRange range = ui->plot->xAxis->range();
    if (range.lower >= arg1) {
        ui->x_max_box->setValue(range.lower + 1);
    } else {
        ui->plot->xAxis->setRangeUpper(arg1);
    }
    on_enter_clicked();
}

void Calculator::on_x_min_box_valueChanged(double arg1) {
    QCPRange range = ui->plot->xAxis->range();
    if (range.upper <= arg1) {
        ui->x_min_box->setValue(range.upper - 1);
    } else {
        ui->plot->xAxis->setRangeLower(arg1);
    }
    on_enter_clicked();
}

void Calculator::on_y_min_box_valueChanged(double arg1) {
    QCPRange range = ui->plot->yAxis->range();
    if (range.upper <= arg1) {
        ui->y_min_box->setValue(range.upper - 1);
    } else {
        ui->plot->yAxis->setRangeLower(arg1);
    }
    on_enter_clicked();
}

void Calculator::on_y_max_box_valueChanged(double arg1) {
    QCPRange range = ui->plot->yAxis->range();
    if (range.lower >= arg1) {
        ui->y_max_box->setValue(range.lower + 1);
    } else {
        ui->plot->yAxis->setRangeUpper(arg1);
    }
    on_enter_clicked();
}

void Calculator::on_reset_clicked() {
    ui->Display->setText("");
    ui->ResultDisplay->setText("");
    ui->plot->clearGraphs();
    ui->plot->replot();
    ui->x_min_box->setValue(-5);
    ui->x_max_box->setValue(5);
    ui->y_min_box->setValue(-5);
    ui->y_max_box->setValue(5);
}

void Calculator::on_cd_clicked() {
    credit_debit credit_debit;
    QPoint p = Calculator::pos();
    credit_debit.move(p.x() + 600, p.y() + 0);
    credit_debit.setModal(true);
    credit_debit.exec();
}
