#include "credit_debit.h"

#include "ui/ui_credit_debit.h"

credit_debit::credit_debit(QWidget *parent) : QDialog(parent), ui(new Ui::credit_debit) { ui->setupUi(this); }

credit_debit::~credit_debit() { delete ui; }
