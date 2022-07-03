#include "calculator.h"
#include "ui_calculator.h"
#include <cstring>



void Calculator::on_enter_clicked()
{
    QString input = ui->Display->text();
    char c_input[512];
    strncpy(c_input, qPrintable(input), 255);
    double result = smart_calc(c_input);
    QString result_string = QString::number(result);
    ui->ResultDisplay->setText("= " + result_string);
//    qDebug() << result;
}

void Calculator::clicked_text_add(QString toAdd)
{
   QString text = ui->Display->text();
   ui->Display->setText(text + toAdd);
}

void Calculator::on_one_clicked()
{
    clicked_text_add("1");
}

void Calculator::on_two_clicked()
{
    clicked_text_add("2");
}

void Calculator::on_three_clicked()
{
    clicked_text_add("3");
}

void Calculator::on_four_clicked()
{
    clicked_text_add("4");
}


void Calculator::on_five_clicked()
{
    clicked_text_add("5");
}


void Calculator::on_six_clicked()
{
    clicked_text_add("6");
}


void Calculator::on_seven_clicked()
{
    clicked_text_add("7");
}


void Calculator::on_eight_clicked()
{
    clicked_text_add("8");
}


void Calculator::on_nine_clicked()
{
    clicked_text_add("9");
}


void Calculator::on_zero_clicked()
{
    clicked_text_add("0");
}

void Calculator::on_plus_clicked()
{
    clicked_text_add("+");
}


void Calculator::on_minus_clicked()
{
    clicked_text_add("-");
}


void Calculator::on_mul_clicked()
{
    clicked_text_add("*");
}


void Calculator::on_div_clicked()
{
    clicked_text_add("/");
}


void Calculator::on_br_l_clicked()
{
    clicked_text_add("(");
}


void Calculator::on_br_r_clicked()
{
    clicked_text_add(")");
}

void Calculator::on_arrow_l_clicked()
{
    ui->Display->cursorBackward(0 , 1);
}


void Calculator::on_arrow_r_clicked()
{
    ui->Display->cursorForward(0 , 1);
}


void Calculator::on_back_clicked()
{
    QString text = ui->Display->text();
    text.truncate(text.length() - 1);
    ui->Display->setText(text);
}


void Calculator::on_log_clicked()
{
    clicked_text_add("log(");
}


void Calculator::on_ln_clicked()
{
    clicked_text_add("ln(");
}


void Calculator::on_sqrt_clicked()
{
    clicked_text_add("sqrt(");
}


void Calculator::on_sin_clicked()
{
    clicked_text_add("sin(");
}


void Calculator::on_cos_clicked()
{
    clicked_text_add("cos(");
}


void Calculator::on_tan_clicked()
{
    clicked_text_add("tan(");
}


void Calculator::on_asin_clicked()
{
    clicked_text_add("asin(");
}


void Calculator::on_acos_clicked()
{
    clicked_text_add("acos(");
}


void Calculator::on_atan_clicked()
{
    clicked_text_add("atan(");
}

void Calculator::on_dot_clicked()
{
    clicked_text_add(".");
}
