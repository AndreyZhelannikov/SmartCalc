#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>

#include "qcustomplot.h"
extern "C" {
#include "calculator/main.h"
}

QT_BEGIN_NAMESPACE
namespace Ui {
class Calculator;
}
QT_END_NAMESPACE

class Calculator : public QMainWindow {
    Q_OBJECT

   public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();

   private slots:
    void on_one_clicked();
    void clicked_text_add(QString toADd);
    void on_three_clicked();

    void on_two_clicked();

    void on_four_clicked();

    void on_five_clicked();

    void on_six_clicked();

    void on_seven_clicked();

    void on_eight_clicked();

    void on_nine_clicked();

    void on_zero_clicked();

    void on_plus_clicked();

    void on_minus_clicked();

    void on_mul_clicked();

    void on_div_clicked();

    void on_br_l_clicked();

    void on_br_r_clicked();

    void on_back_clicked();

    void on_log_clicked();

    void on_ln_clicked();

    void on_sqrt_clicked();

    void on_sin_clicked();

    void on_cos_clicked();

    void on_tan_clicked();

    void on_asin_clicked();

    void on_acos_clicked();

    void on_atan_clicked();

    void on_enter_clicked();

    void on_dot_clicked();

    void on_x_max_box_valueChanged(double arg1);

    void on_x_min_box_valueChanged(double arg1);

    void on_y_min_box_valueChanged(double arg1);

    void on_y_max_box_valueChanged(double arg1);

    void on_mod_clicked();

    void on_pow_clicked();

    void on_x_button_clicked();

    void on_reset_clicked();

   private:
    Ui::Calculator *ui;
};

#endif  // CALCULATOR_H
