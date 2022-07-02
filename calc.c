#include "main.h"

int dijkstra_algorithm(lyxems_t *lyxems, int lyxems_cnt, lyxems_t *polish) {
    lyxems_t stack[512] = {0};
    int stack_ptr = 0;
    int polish_ptr = 0;

    for (int i = 0; i < lyxems_cnt; ++i) {
        int tok = lyxems[i].token;
        if (is_number(tok)) {
            polish[polish_ptr++] = lyxems[i];
        } else if (is_function(tok) || tok == BRACKET_L) {
            stack[stack_ptr++] = lyxems[i];
        } else if (is_operator(tok)) {
            while (stack_ptr > 0 && is_operator(stack[stack_ptr - 1].token) &&
                   stack[stack_ptr - 1].priority <= lyxems[i].priority) {
                polish[polish_ptr++] = stack[--stack_ptr];
            }
            stack[stack_ptr++] = lyxems[i];
        } else if (lyxems[i].token == BRACKET_R) {
            while (stack[stack_ptr - 1].token != BRACKET_L) {
                polish[polish_ptr++] = stack[--stack_ptr];
            }
            --stack_ptr;
            if (is_function(stack[stack_ptr - 1].token)) {
                polish[polish_ptr++] = stack[--stack_ptr];
            }
        }
    }
    while (stack_ptr > 0) {
        polish[polish_ptr++] = stack[--stack_ptr];
    }
    return polish_ptr;
}

// double calculate_value(lyxems_t *lyxems, int lyxems_cnt) {
//     double result = lyxems[0].number;
//     double tmp = 0;

//     for (int i = 1; i < lyxems_cnt; ++i) {
//         if (is_number(lyxems[i].token)) {
//             tmp = lyxems[i].number;
//         } else if (is_operator(lyxems[i].token)) {
//             result = do_operation(lyxems[i].token, result, tmp);
//         } else if (is_function(lyxems[i].token)) {
//             result = apply_function(lyxems[i].token, result);
//         }
//     }
//     printf("RESULT INSIDE : %lf\n", result);
//     return result;
// }
double calculate_value(lyxems_t *lyxems, int lyxems_cnt) {
    double stack[256] = {lyxems[0].number};
    int sp = 1;
    for (int i = 1; i < lyxems_cnt; ++i) {
        if (lyxems[i].token == NUMBER) {
            stack[sp] = lyxems[i].number;
            sp++;
        } else if (is_function(lyxems[i].token)) {
            stack[sp - 1] = apply_function(lyxems[i].token, stack[sp - 1]);
        } else if (is_operator(lyxems[i].token)) {
            stack[sp - 2] = do_operation(lyxems[i].token, stack[sp - 2], stack[sp - 1]);
            sp--;
        }
    }
    return stack[sp - 1];
}

double apply_function(int tok, double n) {
    double result = 0;

    if (tok == COS) result = cos(n);
    if (tok == SIN) result = sin(n);
    if (tok == TAN) result = tan(n);
    if (tok == ACOS) result = acos(n);
    if (tok == ASIN) result = asin(n);
    if (tok == ATAN) result = atan(n);
    if (tok == SQRT) result = sqrt(n);
    if (tok == LN) result = log(n);
    if (tok == LOG) result = log10(n);

    return result;
}

double do_operation(int tok, double a, double b) {
    double result = 0;
    if (tok == PLUS) result = b + a;
    if (tok == MINUS) result = b - a;
    if (tok == MUL) result = b * a;
    if (tok == DIV) result = b / a;
    if (tok == POW) result = pow(b, a);
    if (tok == MOD) result = fmod(b, a);
    return result;
}

int is_operator(int tok) {
    return tok == PLUS || tok == MINUS || tok == MUL || tok == DIV || tok == POW || tok == MOD;
}

int is_function(int tok) {
    return tok == COS || tok == SIN || tok == TAN || tok == ACOS || tok == ASIN || tok == ATAN ||
           tok == SQRT || tok == LN || tok == LOG;
}

int is_unary_binary(int tok) { return tok == PLUS || tok == MINUS; }

int is_number(int tok) { return tok == NUMBER || tok == PLUS_X || tok == MINUS_X; }