#include <cstring>

#include "calculator.h"
#include "ui_calculator.h"

#define DELTA 20000

void Calculator::on_enter_clicked() {
    QString input = ui->Display->text();
    char c_input[512] = {0};
    strncpy(c_input, qPrintable(input), 255);

    double x_min = ui->x_min_box->value();
    double x_max = ui->x_max_box->value();
    double y_min = ui->y_min_box->value();
    double y_max = ui->y_min_box->value();

    int code = 0;
    int graph = 0;
    int len = strlen(c_input);
    for (int i = 0; i < len; ++i) {
        if (c_input[i] == 'x') graph = 1;
    }
    if (graph) {
        QVector<double> x(DELTA + 1), y(DELTA + 1);
        int j = 0;
        for (double i = x_min; i <= x_max; i += (x_max - x_min) / DELTA) {
            x[j] = i;
            y[j] = smart_calc(c_input, i, &code);
            if (code != 0) break;
            j++;
        }
        if (code == 0) {
            ui->ResultDisplay->setText("");
            ui->plot->addGraph();
            ui->plot->graph(0)->setData(x, y);
        } else {
            ui->plot->clearGraphs();
            ui->ResultDisplay->setText(" = ERROR ");
        }
    } else {
        double result = smart_calc(c_input, 0, &code);
        if (code == 0) {
            QString result_string = QString::number(result);
            ui->ResultDisplay->setText("= " + result_string);
        } else {
            ui->ResultDisplay->setText(" = ERROR ");
        }
        ui->plot->clearGraphs();
    }
    ui->plot->replot();
}

void Calculator::on_mod_clicked() { clicked_text_add(" mod "); }

void Calculator::on_x_button_clicked() { clicked_text_add("x"); }

void Calculator::on_pow_clicked() { clicked_text_add("^"); }

void Calculator::clicked_text_add(QString toAdd) {
    QString text = ui->Display->text();
    ui->Display->setText(text + toAdd);
}

void Calculator::on_one_clicked() { clicked_text_add("1"); }

void Calculator::on_two_clicked() { clicked_text_add("2"); }

void Calculator::on_three_clicked() { clicked_text_add("3"); }

void Calculator::on_four_clicked() { clicked_text_add("4"); }

void Calculator::on_five_clicked() { clicked_text_add("5"); }

void Calculator::on_six_clicked() { clicked_text_add("6"); }

void Calculator::on_seven_clicked() { clicked_text_add("7"); }

void Calculator::on_eight_clicked() { clicked_text_add("8"); }

void Calculator::on_nine_clicked() { clicked_text_add("9"); }

void Calculator::on_zero_clicked() { clicked_text_add("0"); }

void Calculator::on_plus_clicked() { clicked_text_add("+"); }

void Calculator::on_minus_clicked() { clicked_text_add("-"); }

void Calculator::on_mul_clicked() { clicked_text_add("*"); }

void Calculator::on_div_clicked() { clicked_text_add("/"); }

void Calculator::on_br_l_clicked() { clicked_text_add("("); }

void Calculator::on_br_r_clicked() { clicked_text_add(")"); }

void Calculator::on_back_clicked() {
    QString text = ui->Display->text();
    text.truncate(text.length() - 1);
    ui->Display->setText(text);
}

void Calculator::on_log_clicked() { clicked_text_add("log("); }

void Calculator::on_ln_clicked() { clicked_text_add("ln("); }

void Calculator::on_sqrt_clicked() { clicked_text_add("sqrt("); }

void Calculator::on_sin_clicked() { clicked_text_add("sin("); }

void Calculator::on_cos_clicked() { clicked_text_add("cos("); }

void Calculator::on_tan_clicked() { clicked_text_add("tan("); }

void Calculator::on_asin_clicked() { clicked_text_add("asin("); }

void Calculator::on_acos_clicked() { clicked_text_add("acos("); }

void Calculator::on_atan_clicked() { clicked_text_add("atan("); }

void Calculator::on_dot_clicked() { clicked_text_add("."); }
