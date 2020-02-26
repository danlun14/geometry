#include <stdio.h>
#include "f.h"//  point ; circle; check_oper;
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char all[60];
    printf("Введите входные данные формата:\n");
    printf("circle(x y, r) - для круга\n");
    fgets(all, 60, stdin);
    check_oper(all);
}