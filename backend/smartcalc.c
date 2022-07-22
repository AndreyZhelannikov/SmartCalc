#include "smartcalc.h"

double smart_calc(char *input, double x_value, int *code, int validation, int graph) {
    double result = 0;
    lyxems_t lyxems[512] = {0};
    lyxems_t polish[512] = {0};
    validate_lyxems(input, code);
    if (*code == OK) {
        int lyxems_cnt = input_string_converting(input, lyxems);
        if (validation) {
            validate_brackets(lyxems, lyxems_cnt, code);
            validate_binary(lyxems, lyxems_cnt, code);
            validate_numbers_and_functions(lyxems, lyxems_cnt, code);
        }
        if (*code == OK) {
            int polish_cnt = dijkstra_algorithm(lyxems, lyxems_cnt, polish);

            for (int i = 0; i < lyxems_cnt; ++i) {
                if (polish[i].token == PLUS_X) {
                    polish[i].token = NUMBER;
                    polish[i].number = x_value;
                } else if (polish[i].token == MINUS_X) {
                    polish[i].token = NUMBER;
                    polish[i].number = -x_value;
                }
            }
            result = calculate_value(polish, polish_cnt, code, graph);
        }
    }
    return result;
}

void print_lyxems(lyxems_t *lyxems, int len) {
    for (int i = 0; i < len; ++i) {
        if (lyxems[i].token == NUMBER) {
            printf(" %lf ", lyxems[i].number);
        } else {
            print_token(lyxems[i].token);
        }
    }
    printf("\n");
}

void print_token(int token) {
    if (token == -1) printf("ERROR");
    if (token == NUMBER) printf("NUMBER");
    if (token == PLUS_X) printf("x");
    if (token == MINUS_X) printf("~x");
    if (token == PLUS) printf("+");
    if (token == MINUS) printf("-");
    if (token == MUL) printf("*");
    if (token == DIV) printf("/");
    if (token == POW) printf("^");
    if (token == MOD) printf("mod");
    if (token == UNARY_MINUS) printf("~");
    if (token == UNARY_PLUS) printf("±");
    if (token == EQ) printf("=");
    if (token == BRACKET_L) printf("(");
    if (token == BRACKET_R) printf(")");
    if (token == LN) printf("ln");
    if (token == COS) printf("cos");
    if (token == SIN) printf("sin");
    if (token == TAN) printf("tan");
    if (token == LOG) printf("log");
    if (token == ACOS) printf("acos");
    if (token == ASIN) printf("asin");
    if (token == ATAN) printf("atan");
    if (token == SQRT) printf("sqrt");
}

void print_token_raw(int token) {
    if (token == -1) printf("ERROR");
    if (token == NUMBER) printf("NUMBER");
    if (token == PLUS_X) printf("PLUS_X");
    if (token == MINUS_X) printf("MINUS_X");
    if (token == PLUS) printf("PLUS");
    if (token == MINUS) printf("MINUS");
    if (token == MUL) printf("MUL");
    if (token == DIV) printf("DIV");
    if (token == POW) printf("POW");
    if (token == MOD) printf("MOD");
    if (token == UNARY_MINUS) printf("UNARY_MINUS");
    if (token == UNARY_PLUS) printf("UNARY_PLUS");
    if (token == EQ) printf("EQ");
    if (token == BRACKET_L) printf("BRACKET_L");
    if (token == BRACKET_R) printf("BRACKET_R");
    if (token == LN) printf("LN");
    if (token == COS) printf("COS");
    if (token == SIN) printf("SIN");
    if (token == TAN) printf("TAN");
    if (token == LOG) printf("LOG");
    if (token == ACOS) printf("ACOS");
    if (token == ASIN) printf("ASIN");
    if (token == ATAN) printf("ATAN");
    if (token == SQRT) printf("SQRT");
}

// void handle_error(int code) {
//     // system("clear");
//     // printf("\033[%d;%dH", 2, 3);
//     printf("=======================\n");
//     printf("An error has occurred:\n");
//     printf("%s", BHRED);
//     // printf("\033[%d;%dH", 3, 3);
//     if (code == INPUT_FAILURE) {
//         printf("INPUT FAILURE\n");
//     } else if (code == INPUT_IS_TOO_LARGE) {
//         printf("INPUT IS TOO LARGE\n");
//     } else if (code == INVALID_LYXEMS) {
//         printf("INVALID LYXEMS\n");
//     }
//     // printf("\033[%d;%dH", 4, 3);
//     printf("%s", CRESET);
//     printf("code: %d\n", code);
//     printf("=======================\n");
//     // print_rectangle(25, 5);
// }

// void print_rectangle(int x, int y) {
//     setlocale(LC_CTYPE, "");
//     printf("\033[%d;%dH", 0, 0);
//     wprintf(L"%lc", 0x250C);
//     for (int i = 0; i < x; ++i) wprintf(L"%lc", 0x2500);
//     wprintf(L"%lc", 0x2510);

//    for (int i = 2; i < y; ++i) {
//        printf("\033[%d;%dH", i, 0);
//        wprintf(L"%lc", 0x2502);
//        printf("\033[%d;%dH", i, x + 2);
//        wprintf(L"%lc", 0x2502);
//    }

//    printf("\033[%d;%dH", y, 0);
//    wprintf(L"%lc", 0x2514);
//    for (int i = 0; i < x; ++i) wprintf(L"%lc", 0x2500);
//    wprintf(L"%lc", 0x2518);
//    printf("\033[%d;%dH", y + 1, 0);
//}
