// Переберу все варианты "" + -
// 3^9 = 19 683 - вариантов расположения
// пусть "" = 0, + = 1, - = 2
// будем переводить числа от 0 до 19 682 в троичную систему и исходя из этого ставить знаки
#include "sub_sign.h"

void    strrev(char *str)
{
    int tmp;
    int len = strlen(str);
    int mid = len / 2;

    for (int i = 0; i <= mid; i++) {
        tmp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = tmp;
    }
}

int main(void)
{
    char str[20];
    int digits[10] = {9,8,7,6,5,4,3,2,1,0};
    long triple;
    int tmp;
    int rez;
    int k;

    for (int i = 0; i < 19683; i++) {
        triple = i;
        tmp = 0;
        rez = 0;
        k = 0;
        for (int j = 0; j < 10; j++) {
            if (tmp == 0)
                tmp += j;
            else
                tmp += pow(10, (int)(log10(tmp)) + 1) * j;
            str[k++] = '0' + j;
            switch (triple % 3) {
                case 0:
                    if (j == 9)
                        rez += tmp;
                    break;
                case 1:
                    str[k++] = '-';
                    rez -= tmp;
                    tmp = 0;
                    break;
                case 2:
                    str[k++] = '+';
                    rez += tmp;
                    tmp = 0;
                    break;
            }
            triple = triple / 3;
        }
        str[k] = 0;
        strrev(str);
        if (rez == GOAL)
            printf("%s = %d\n", str, GOAL);
    }
    return (0);
}