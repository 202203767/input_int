#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
//#include "input_int.h"

#define MAX_BUFFER (12 + 1)

int get_input_int(int num) {
    int input_char_code = 0;
    long temp = 0;
    char buffer[MAX_BUFFER];
    while(1) {
        printf("数字を入力してください：");
        fgets(buffer, sizeof(buffer), stdin);
        printf("%s\n", buffer);
        if (strchr(buffer, '\n') == NULL || buffer[0] == '\n') {
            printf("未入力または%d桁を超えています。もう一度入力してください。\n", MAX_BUFFER - 1);
            if(strchr(buffer, '\n') == NULL) {
                while ((input_char_code = getchar()) != '\n' && input_char_code != EOF);
            }
        } else {
            buffer[strcspn(buffer, "\n")] = '\0';
            temp = strtol(buffer, NULL, 10);
            if(temp > INT_MIN || temp < INT_MAX) {
                num = temp;
                break;
            }
            printf("int型の最大値または最小値を超えています。入力しなおしてください。");
        }
    }
    return num;
}

int main() {
    int num = 0;
    num = get_input_int(num);
    printf("%d\n", num);
    return 0;
}