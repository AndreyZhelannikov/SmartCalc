#ifndef ABOBA
#define ABOBA

#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

#define MAX_INPUT_LEN 256
#define STRINGIFY(x) STRINGIFY2(x)
#define STRINGIFY2(x) #x

typedef struct lyxems {
    int token;
    int priority;
    double number;
} lyxems_t;

enum {
    NUMBER,
    PLUS_X,
    MINUS_X,
    PLUS,
    MINUS,
    MUL,
    DIV,
    POW,
    MOD,
    UNARY_MINUS,
    UNARY_PLUS,
    EQ,
    BRACKET_L,
    BRACKET_R,
    LN,
    COS,
    SIN,
    TAN,
    LOG,
    ACOS,
    ASIN,
    ATAN,
    SQRT,
};

enum {
    OK = 0,
    INPUT_FAILURE = 1,
    INPUT_IS_TOO_LARGE = 2,
    INVALID_LYXEMS = 3,
    INVALID_CREDIT = 4,
    DIV_ZERO = 5,
};

double smart_calc(char *input, double x_value, int *code, int validation, int graph);

double calculate_value(lyxems_t *lyxems, int lyxems_cnt, int *code, int graph);
double do_operation(int tok, double a, double b, int *code, int graph);
double apply_function(int tok, double n);

void handle_error(int code);
void print_lyxems(lyxems_t *lyxems, int len);
void print_token_raw(int token);
void print_token(int token);

void check_unary_operations(lyxems_t *lyxems, int *lyxems_cnt);
void check_unary_functions(lyxems_t *lyxems, int *lyxems_cnt);

int is_number(int tok);
int is_function(int tok);
int is_unary_binary(int tok);
int is_operator(int tok);

void shift_left(lyxems_t *lyxems, int start, int *lyxems_cnt);
void shift_right(lyxems_t *lyxems, int start, int *lyxems_cnt);
void manage_priorities(lyxems_t *lyxems, int lyxems_cnt);

void get_input_from_stdin(char *input, int *code);

int input_string_converting(char *data, lyxems_t *lyxems);

void string_to_lyxem(char *input, lyxems_t *result);
void shift_by_token_length(char **input, int token);

int get_operation(char *input);
int get_function(char *input);

int dijkstra_algorithm(lyxems_t *lyxems, int lyxems_cnt, lyxems_t *polish);

void validate_lyxems(char *input, int *code);
void validate_brackets(lyxems_t *lyxems, int lyxems_cnt, int *code);
void validate_binary(lyxems_t *lyxems, int lyxems_cnt, int *code);
void validate_numbers_and_functions(lyxems_t *lyxems, int lyxems_cnt, int *code);

void credit_calculator(double *input, double *output, double *m_payments, int *code);
int check_valid_credit(const double *input);
double differentiated_credit_m(const double *input, int m);
void annuity_credit(double *input, double *output);
#endif
