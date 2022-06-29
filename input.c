#include "main.h"

void get_input_from_stdin(char *input, int *code) {
    // Bracket validation
    // fun() brackets validations
    // binary operations validation
    //
    if (scanf("%" STRINGIFY(MAX_INPUT_LEN) "[^\n]s", input) == 1) {
        if (strlen(input) > MAX_INPUT_LEN)
            *code = INPUT_IS_TOO_LARGE;
        else if (input[strlen(input) - 1] != '=')
            *code = INVALID_LYXEMS;
        else
            validation(input, code);
    } else {
        *code = INPUT_FAILURE;
    }
}

void validation(char *input, int *code) {
    //
    validate_lyxems(input, code);
}

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