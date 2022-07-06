#include "main.h"

void validate_lyxems(char *input, int *code) {
    char valid_input_tokens[64][8] = {
        "+", "-", "*", "/", "=", "^", "mod", "cos", "sin", "tan", "acos", "asin", "atan", "sqrt", "ln", "log",
        "x", " ", "1", "2", "3", "4", "5",   "6",   "7",   "8",   "9",    "0",    "(",    ")",    ".",
    };
    while (*input) {
        int i = 0;
        int correct = 0;
        for (; i < 31; ++i) {
            if (strstr(input, valid_input_tokens[i]) == input) {
                correct = 1;
                break;
            }
        }
        if (!correct) {
            *code = INVALID_LYXEMS;
            break;
        }
        input += strlen(valid_input_tokens[i]);
    }
}

void validate_brackets(lyxems_t *lyxems, int lyxems_cnt, int *code) {
    int sp = 0;
    for (int i = 0; i < lyxems_cnt; ++i) {
        if (lyxems[i].token == BRACKET_L) ++sp;
        if (lyxems[i].token == BRACKET_R) --sp;
        if (sp < 0) break;
    }
    if (sp != 0) *code = INVALID_LYXEMS;
}

void validate_binary(lyxems_t *lyxems, int lyxems_cnt, int *code) {
    if (is_operator(lyxems[0].token)) *code = INVALID_LYXEMS;
    for (int i = 1; i < lyxems_cnt - 1; ++i) {
        if (is_operator(lyxems[i].token) &&
            (!is_number(lyxems[i + 1].token) || lyxems[i + 1].token == BRACKET_L ||
             is_function(lyxems[i + 1].token) || is_number(lyxems[i - 1].token) ||
             lyxems[i - 1].token == BRACKET_R))
            *code = INVALID_LYXEMS;
    }
    if (is_operator(lyxems[lyxems_cnt - 1].token)) *code = INVALID_LYXEMS;
}

void validate_numbers(lyxems_t *lyxems, int lyxems_cnt, int *code) {
    for (int i = 0; i < lyxems_cnt - 1; ++i) {
        if (is_number(lyxems[i].token) && is_number(lyxems[i + 1].token)) *code = INVALID_LYXEMS;
    }
}