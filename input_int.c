#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
//#include "input_int.h"

#define MAX_BUFFER (10 + 1 + 1)

void printerror(char buffer[]) {
    int input_char_code = 0;
    printf("未入力または10桁を超えています。もう一度入力してください。\n");
    if(strchr(buffer, '\n') == NULL) {
        while ((input_char_code = getchar()) != '\n' && input_char_code != EOF);
    }
}

int get_input_int(int num) {
    long temp = 0;
    char buffer[MAX_BUFFER];
    while(1) {
        printf("数字を入力してください：");
        fgets(buffer, sizeof(buffer), stdin);
        if(buffer[0] == '\n') {
            printerror(buffer);
        } else if(strchr(buffer, '\n') == NULL) {
            printerror(buffer);
        } else if(buffer[0] == '-') {
            if(buffer[12] == '\n') {
                printerror(buffer);
            }
        } else if(buffer[11] == '\n') {
            printerror(buffer);
        }
        buffer[strcspn(buffer, "\n")] = '\0';
        temp = strtol(buffer, NULL, 10);
        if(temp > INT_MIN && temp < INT_MAX) {
            num = temp;
            break;
        }
        printf("int型の最大値または最小値を超えています。入力しなおしてください。\n");
    }
    return num;
}