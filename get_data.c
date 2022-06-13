#include "main.h"

void validation(char *data, int *code);

void get_data_from_stdin(int *code) {
    char *data[512];
    if (scanf("%s", data) == 1) {
        validation(data, code);
    } else {
        *code = INPUT_FAILURE;
    }
}

void validation(char *data, int *code) {
    //
}
