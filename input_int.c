#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include "input_int.h"

#define MAX_BUFFER (10 + 1 + 1 + 1)

void printerror(char buffer[]) {
    int input_char_code = 0;
    printf("未入力または10桁を超えています。もう一度入力してください。\n");
    if(strchr(buffer, '\n') == NULL) {
        while ((input_char_code = getchar()) != '\n' && input_char_code != EOF);
    }
}

int get_input_int() {
    char buffer[MAX_BUFFER];
    char *endptr;
    long temp = 0;
    int num = 0;
    int input_char_code;
    while(1) {
        fgets(buffer, sizeof(buffer), stdin);
        if(buffer[0] == '-') {
            if(strchr(buffer, '\n') == NULL || buffer[13] == '\n') {
                printerror(buffer);
                continue;
            }
        }else if(strchr(buffer, '\n') == NULL || buffer[0] == '\n' || buffer[11] == '\n') {
            printerror(buffer);
            continue;
        }
        buffer[strcspn(buffer, "\n")] = '\0';
        temp = strtol(buffer, &endptr, 10);
        if (*endptr != '\0') {
            printf("文字が入っています整数を入力してください。\n");
            continue;
        }
        if (temp < INT_MIN || temp > INT_MAX) {
            printf("int型の範囲外です。入力しなおしてください。\n");
            continue;
        }
        num = temp;
        return num;
    }
}