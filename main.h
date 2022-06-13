#ifndef ABOBA
#define ABOBA

#include <gtk/gtk.h>
#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

#include "colors.h"

enum {
    OK = 0,
    INPUT_FAILURE = 1,
};

void get_data_from_stdin(int *code);
void handle_error(int code);

#endif