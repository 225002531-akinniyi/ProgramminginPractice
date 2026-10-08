#include <stdio.h>
#include <string.h>
#include "utilities.h"

void clear_input_buffer(void) {
    int c;
    while ((c = getchar())!= '\n' && c!= EOF);
}

int get_int_input(const char *prompt) {
    int val;
    printf("%s", prompt);
    scanf("%d", &val);
    clear_input_buffer();
    return val;
}

float get_float_input(const char *prompt) {
    float val;
    printf("%s", prompt);
    scanf("%f", &val);
    clear_input_buffer();
    return val;
}

void get_string_input(const char *prompt, char *buffer, int size) {
    printf("%s", prompt);
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = 0;
}