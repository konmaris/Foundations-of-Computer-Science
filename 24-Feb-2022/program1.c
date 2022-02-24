#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("clear");
    int i_1, i_2, i_3, i_4, i_5, i_6, i_7, i_8, i_9, i_10;
    int *p_1, *p_2, *p_3, *p_4, *p_5, *p_6, *p_7, *p_8, *p_9, *p_10;

    i_1 = 5;
    i_2 = 3;
    i_3 = 6;
    i_4 = 13;
    i_5 = 27;
    i_6 = 16;
    i_7 = 8;
    i_8 = 11;
    i_9 = 23;
    i_10 = 2;

    p_1 = &i_1;
    p_2 = &i_2;
    p_3 = &i_3;
    p_4 = &i_4;
    p_5 = &i_5;
    p_6 = &i_6;
    p_7 = &i_7;
    p_8 = &i_8;
    p_9 = &i_9;
    p_10 = &i_10;

    printf("Integer i_1 has a value of %d and is at memory position %p\n", i_1, &i_1);
    printf("Integer i_2 has a value of %d and is at memory position %p\n", i_2, &i_2);
    printf("Integer i_3 has a value of %d and is at memory position %p\n", i_3, &i_3);
    printf("Integer i_4 has a value of %d and is at memory position %p\n", i_4, &i_4);
    printf("Integer i_5 has a value of %d and is at memory position %p\n", i_5, &i_5);
    printf("Integer i_6 has a value of %d and is at memory position %p\n", i_6, &i_6);
    printf("Integer i_7 has a value of %d and is at memory position %p\n", i_7, &i_7);
    printf("Integer i_8 has a value of %d and is at memory position %p\n", i_8, &i_8);
    printf("Integer i_9 has a value of %d and is at memory position %p\n", i_9, &i_9);
    printf("Integer i_10 has a value of %d and is at memory position %p\n", i_10, &i_10);

    printf("\n");
    return 0;
}