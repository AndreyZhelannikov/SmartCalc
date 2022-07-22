#ifndef CREDIT_DEBIT_H
#define CREDIT_DEBIT_H

#include <QDialog>

namespace Ui {
class credit_debit;
}

class credit_debit : public QDialog {
    Q_OBJECT

   public:
    explicit credit_debit(QWidget *parent = nullptr);
    ~credit_debit();

   private:
    Ui::credit_debit *ui;
};

#endif  // CREDIT_DEBIT_H
