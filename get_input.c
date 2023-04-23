#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "get_input.h"

int get_input(int wishes_total, int num_5_star, int num_5_star_ex, int num_4_star, int num_4_star_ex){
    printf("\nEnter the number of wishes (1 or 10. To quit the program, enter <quit>): ");
    char user_input[100];
    int wishes_converted;
    scanf("%s", user_input);
    if (strcmp(user_input, "quit") == 0){
        printf("\nIn the previous %d wishes, you got:\n%d five-star character(s) with %d five-star exclusive character(s).\n", wishes_total, num_5_star, num_5_star_ex);
        printf("\n%d four-star character(s) with %d four-star exclusive character(s).\n", num_4_star, num_4_star_ex);
        printf("\nProgram ended...\n");
        exit(0);
    }else if (strcmp(user_input, "kaigua") == 0){
        printf("Enter the number of wishes you want (any number between 1 ~ 100): ");
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
            printf("\nPlease enter either 1 or 10!!\nTry again!\n");
            wishes_converted = 666; // 666 is an arbitary number that stands for the number given is invalid
            return wishes_converted;
        }
    }else{
        printf("\nInvalid input...\nTry again!\n");
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

