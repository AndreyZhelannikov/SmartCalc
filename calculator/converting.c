#include "main.h"

int input_string_converting(char *data, lyxems_t *lyxems) {
    int lyxems_cnt = 0;
    while (*data) {
        if (*data == ' ') {
            data += 1;
            continue;
        }
        string_to_lyxem(data, lyxems + lyxems_cnt);
        shift_by_token_length(&data, lyxems[lyxems_cnt].token);
        lyxems_cnt++;
    }
    check_unary_operations(lyxems, &lyxems_cnt);
    check_unary_functions(lyxems, &lyxems_cnt);

    manage_priorities(lyxems, lyxems_cnt);
    return lyxems_cnt;
}

void manage_priorities(lyxems_t *lyxems, int lyxems_cnt) {
    for (int i = 0; i < lyxems_cnt; ++i) {
        if (lyxems[i].token == POW) {
            lyxems[i].priority = 1;
        } else if (lyxems[i].token == MUL || lyxems[i].token == DIV || lyxems[i].token == MOD) {
            lyxems[i].priority = 2;
        } else if (lyxems[i].token == PLUS || lyxems[i].token == MINUS) {
            lyxems[i].priority = 3;
        } else {
            lyxems[i].priority = -1;
        }
    }
}

void check_unary_functions(lyxems_t *lyxems, int *lyxems_cnt) {
    for (int i = 1; i < *lyxems_cnt; ++i) {
        int tok = lyxems[i].token;
        if (is_function(tok)) {
            if (is_unary_binary(lyxems[i - 1].token)) {
                if (i == 1 || is_operator(lyxems[i - 2].token) || lyxems[i - 2].token == BRACKET_L) {
                    i--;
                    shift_right(lyxems, i, lyxems_cnt);
                    lyxems[i].token = NUMBER;
                    lyxems[i].number = 0;
                }
            }
        }
    }
}

void check_unary_operations(lyxems_t *lyxems, int *lyxems_cnt) {
    for (int i = 1; i < *lyxems_cnt; ++i) {
        if (is_number(lyxems[i].token) && is_unary_binary(lyxems[i - 1].token)) {
            if (i == 1 || is_operator(lyxems[i - 2].token) || lyxems[i - 2].token == BRACKET_L) {
                if (lyxems[i - 1].token == PLUS) {
                } else if (lyxems[i - 1].token == MINUS) {
                    if (lyxems[i].token == NUMBER)
                        lyxems[i].number = -lyxems[i].number;
                    else if (lyxems[i].token == PLUS_X)
                        lyxems[i].token = MINUS_X;
                }
                i--;
                shift_left(lyxems, i, lyxems_cnt);
            }
        }
    }
}

void shift_left(lyxems_t *lyxems, int start, int *lyxems_cnt) {
    for (int i = start + 1; i < *lyxems_cnt; ++i) {
        lyxems[i - 1] = lyxems[i];
    }
    *lyxems_cnt -= 1;
}

void shift_right(lyxems_t *lyxems, int start, int *lyxems_cnt) {
    for (int i = *lyxems_cnt + 1; i >= start + 1; --i) {
        lyxems[i] = lyxems[i - 1];
    }
    *lyxems_cnt += 1;
}

void string_to_lyxem(char *data, lyxems_t *lyxems) {
    lyxems->token = -1;

    if (isdigit(*data)) {
        lyxems->number = atof(data);
        lyxems->token = NUMBER;
    }
    if (lyxems->token == -1) lyxems->token = get_function(data);
    if (lyxems->token == -1) lyxems->token = get_operation(data);
    if (lyxems->token == -1) lyxems->token = PLUS_X;
}

void shift_by_token_length(char **data, int token) {
    if (token == 0) {
        while (isdigit(**data) || **data == '.') *data += 1;
    } else if (token >= 1 && token <= 13) {
        if (token == MOD)
            *data += 3;
        else
            *data += 1;
    } else if (token == 14) {
        *data += 2;
    } else if (token >= 15 && token <= 18) {
        *data += 3;
    } else if (token >= 19 && token <= 22) {
        *data += 4;
    }
}

int get_operation(char *data) {
    int token = -1;
    if (*data == '+') token = PLUS;
    if (*data == '-') token = MINUS;
    if (*data == '*') token = MUL;
    if (*data == '/') token = DIV;
    if (*data == '^') token = POW;
    if (*data == '(') token = BRACKET_L;
    if (*data == ')') token = BRACKET_R;
    if (*data == '=') token = EQ;
    if (strstr(data, "mod") == data) token = MOD;
    return token;
}

int get_function(char *data) {
    int token = -1;
    if (strstr(data, "cos") == data) token = COS;
    if (strstr(data, "sin") == data) token = SIN;
    if (strstr(data, "tan") == data) token = TAN;
    if (strstr(data, "acos") == data) token = ACOS;
    if (strstr(data, "asin") == data) token = ASIN;
    if (strstr(data, "atan") == data) token = ATAN;
    if (strstr(data, "sqrt") == data) token = SQRT;
    if (strstr(data, "ln") == data) token = LN;
    if (strstr(data, "log") == data) token = LOG;
    return token;
}