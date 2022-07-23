#include "smartcalc.h"
// Input: total credit amount, term, interest rate, type (annuity,
// differentiated) Output: monthly payment, overpayment on credit, total payment
enum {
    TOTAL_CREDIT_AMOUNT = 0,  //
    TERM = 1,
    INTEREST_RATE = 2,
    TYPE = 3
};
enum {
    ANNUITY = 0,  //
    DIFFERENTIATED = 1,
};

enum {
    MOUNTHLY_PAYMENT = 0,  //
    OVERPAYMENT = 1,
    TOTAL_PAYMENT = 2
};

void credit_calculator(double *input, double *output, double *m_payments, int *code) {
    if (check_valid_credit(input)) *code = INVALID_CREDIT;

    if (input[TYPE] == ANNUITY) {
        annuity_credit(input, output);
    } else if (input[TYPE] == DIFFERENTIATED) {
        for (int i = 1; i < input[TERM]; ++i) {
            m_payments[i] = differentiated_credit_m(input, i);
        }
    }
}

int check_valid_credit(const double *input) {
    return (input[TOTAL_CREDIT_AMOUNT] <= 0 || input[TERM] <= 0 || input[INTEREST_RATE] <= 0 ||
            (input[TYPE] <= 0 || input[TYPE] >= 2));
}

void annuity_credit(double *input, double *output) {
    double i = input[INTEREST_RATE] / 12;
    output[MOUNTHLY_PAYMENT] =
        (input[TOTAL_CREDIT_AMOUNT] * i * pow(1 + i, input[TERM])) / (pow(1 + i, input[TERM]) - 1);
    output[TOTAL_PAYMENT] = output[MOUNTHLY_PAYMENT] * input[TERM];
    output[OVERPAYMENT] = output[TOTAL_PAYMENT] - input[TOTAL_CREDIT_AMOUNT];
}

double differentiated_credit_m(const double *input, int m) {
    //
    double i = input[INTEREST_RATE] / 12;
    return (input[TOTAL_CREDIT_AMOUNT] / input[TERM]) +
           i * (input[TOTAL_CREDIT_AMOUNT] - (input[TOTAL_CREDIT_AMOUNT] * (m - 1)) / input[TERM]);
}
