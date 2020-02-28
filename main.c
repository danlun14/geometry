#include <stdio.h>
#include "f.h"//  point ; circle; check_oper;
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char all[60];
    int id;
    circle first;
    first.center.x = 0;
    first.center.y = 0;
    printf("Введите входные данные формата:\n");
    printf("circle(x y, r) - для круга\n");
    fgets(all, 60, stdin);
    if (check_oper(all) != 0){
	id = as4041(all, 40);
	if (id !=0){
	    circle_center(&first, all, id);
	}
    }
    printf("%d %d", first.center.x, first.center.y);	
}