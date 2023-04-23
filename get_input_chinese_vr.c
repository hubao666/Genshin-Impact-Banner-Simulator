#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "get_input_chinese_vr.h"


int get_input(int wishes_total, int num_5_star, int num_5_star_ex, int num_4_star, int num_4_star_ex){
    printf("\n输入多少抽 (0 或 10), (输入 <quit> 退出程序) ");
    char user_input[100];
    int wishes_converted;
    scanf("%s", user_input);
    if (strcmp(user_input, "quit") == 0){
        printf("\n在过去的 %d 抽中, 你获得了:\n%d 五星角色， 其中包含 %d 名UP限定五星角色.\n", wishes_total, num_5_star, num_5_star_ex);
        printf("\n%d 名四星角色，其中包含 %d 名UP限定四星角色.\n", num_4_star, num_4_star_ex);
        printf("\n程序结束...\n");
        exit(0);
    }else if (strcmp(user_input, "kaigua") == 0){
        printf("Enter the number of wishes you want (any number except to 666): ");
        if (scanf("%d", &wishes_converted) == 0){
            printf("You Need a Number !\nEnding program...");
            exit(0);
        }
        return wishes_converted;
    }
    else if ((wishes_converted = atoi(user_input)) != 0)
    {
        if (wishes_converted == 1 || wishes_converted == 10){
            return wishes_converted;
        }
        else{
            printf("\n请输入 1 或者 10， 再试一次...\n");
            wishes_converted = 666; // 666 is an arbitary number that stands for the number given is invalid
            return wishes_converted;
        }
    }else{
        printf("\n格式错误...\n再试一次!\n");
        wishes_converted = 666;
        return wishes_converted;
    }
}

int input_loop(int wishes, int wishes_total, int num_5_star, int num_5_star_ex, int num_4_star, int num_4_star_ex){
    while (wishes == 666){
        wishes = get_input(wishes_total, num_5_star, num_5_star_ex, num_4_star, num_4_star_ex);
    }
    return wishes;
}

int get_num_of_wishes(int wishes, int wishes_total, int num_5_star, int num_5_star_ex, int num_4_star, int num_4_star_ex){
    int num;
    wishes = get_input(wishes_total, num_5_star, num_5_star_ex, num_4_star, num_4_star_ex);
    num = input_loop(wishes, wishes_total, num_5_star, num_5_star_ex, num_4_star, num_4_star_ex);
    return num;
}

