#include "main.h"

void smart_calc(int argc, char **argv, int *code);
void print_rectangle(int x, int y);

int main(int argc, char **argv) {
    int code = 0;
    smart_calc(argc, argv, &code);

    if (code != OK) handle_error(code);

    return 0;
}

void smart_calc(int argc, char **argv, int *code) { get_data_from_stdin(code); }

void handle_error(int code) {
    system("clear");
    printf("\033[%d;%dH", 2, 3);
    printf("An error has occurred:");
    printf("%s", BHRED);
    printf("\033[%d;%dH", 3, 3);
    if (code == INPUT_FAILURE) {
        printf("INPUT FAILURE");
    }
    printf("\033[%d;%dH", 4, 3);
    printf("%s", CRESET);
    printf("code: %d", code);
    print_rectangle(25, 5);
}

void print_rectangle(int x, int y) {
    setlocale(LC_CTYPE, "");
    printf("\033[%d;%dH", 0, 0);
    wprintf(L"%lc", 0x250C);
    for (int i = 0; i < x; ++i) wprintf(L"%lc", 0x2500);
    wprintf(L"%lc", 0x2510);

    for (int i = 2; i < y; ++i) {
        printf("\033[%d;%dH", i, 0);
        wprintf(L"%lc", 0x2502);
        printf("\033[%d;%dH", i, x + 2);
        wprintf(L"%lc", 0x2502);
    }

    printf("\033[%d;%dH", y, 0);
    wprintf(L"%lc", 0x2514);
    for (int i = 0; i < x; ++i) wprintf(L"%lc", 0x2500);
    wprintf(L"%lc", 0x2518);
    printf("\033[%d;%dH", y + 1, 0);
}

void open_window(int argc, char **argv) {
    GtkWidget *window;
    GtkWidget *button;
    GtkWidget *halign;

    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Smart Calc");
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 800);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_container_set_border_width(GTK_CONTAINER(window), 15);

    button = gtk_button_new_with_label("Aboba");
    gtk_widget_set_tooltip_text(button, "aboba button");

    gtk_widget_set_halign(button, 5);
    gtk_widget_set_valign(button, 5);

    // halign = gtk_alignment_new(0, 0, 0, 0);
    // gtk_container_add(GTK_CONTAINER(window), halign);

    gtk_container_add(GTK_CONTAINER(window), button);

    gtk_widget_show_all(window);

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_main();
}