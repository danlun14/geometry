#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int x;
    int y;
} point;

typedef struct {
    point center;
    int radius;
} circle;

int char_to_number(char ascii){
    int i = ascii;
    return i - 48;
}

int check(char* arr1, char* arr2,int n){
    for (int i = 0; i < n; i++){
	if(arr1[i] != arr2[i]){
	    return 0;
	}
    }
    return 1;
}
int check_oper(char* arr) {
    printf("%s", arr);
    char name[8], CIRCLE[7] = "CIRCLE", TRIANGLE[9] = "TRIANGLE";
    int i = 0, j = 0, num, stop = 1, b = 0;
    while (arr[b] != '\n'){
	    num = arr[b];
	    if (((num >= 'a') && (num <= 'z')) ||  ((num >= 'A') && (num <= 'Z'))){
		if (i < 2){
		    name[j] = toupper(num);
		    j++;
		    i = 1;
		} else if(i == 2) {
		    printf("incorrect format of operation name\n");
		    return 0;
		}
	    }else if (num == ' '){
		if (i == 1){
		    i = 2;
		}
	    } else if (num == '('){
	        break;
	    }else if((num < 'A') || (num > 'z') || ((num > 'Z') && (num < 'a')) ) {
		printf("incorrect format of operation namen\n");
		return 0;
	    } 
	b++;
	}
    printf("%s",name);
    if (check(name, CIRCLE, 6) == 1){
	return 1;
    } else if (check(name, TRIANGLE, 8)){
	return 2;
    } else {
	printf("incorrect input operation name\n");
	return 0;
    }
}

int as4041(char* arr, int type){
    int i;
    int num;
    for(i = 0; i < 50; i++){
	num = arr[i];
	if (type == 40){
	    if (num == '('){
		printf("%d\n", i);
		return i;
	    }
	} else if (type == 41) {
	    if (num == ')'){
		printf("%d\n", i);
		return i;
	    }
	}
	if (num == '\0'){
	    printf("error: incorrect \"(\"");
	    return 0;
	}
    }
}

int circle_center(circle *a, char *arr, int as40){
    int count = 0, count2 = 0, temp = 0, cur = 0, id = as40 + 1, num = arr[id];
    while(num == ' ')
    {
	id += 1;
	num = arr[id];
    }
    while(num != '\0')
    {
	if ((num >= '0') && (num <= '9'))
	{
	    if (count == 0)
	    {
		temp = char_to_number(arr[id]);
		cur = a->center.x;
		a->center.x = cur * 10 + temp;
	    } else if (count == 1) {
		temp = char_to_number(arr[id]);
		cur = a->center.y;
		a->center.y = cur * 10 + temp;
		count2 = 2;
	    } else if (count == 3){
		printf("incorrect coordinates\n");
		return 0;
	    }
	} else if (num == ' '){
	    if (count == 0){
		count = 1;
	    } else if (count2 == 2){
		count = 3;
	    }
	} else if (num == ','){
	    if (count2 == 2 || count == 3)
	    {
		return id;
	    }
	} else {
	    printf("wrong symbols\n");
	    return 0;
	}
	id++;
	num = arr[id];
    }
    return 0;
}

int radius()
{
    
}