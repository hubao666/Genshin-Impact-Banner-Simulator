#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "get_input_chinese_vr.h"
#include "play_game_chinese_vr.h"
#include <time.h>

void five_star_fifty_fifty(bool* is_five_star_fifty_fifty_lose, int* num_ex){
    if (! (*is_five_star_fifty_fifty_lose)){ //如果上次没歪
        double rand_num = get_a_random_num();
        if (rand_num < 0.5){ //歪了
            printf("但是你歪了...下次一定不会歪\n");
            *is_five_star_fifty_fifty_lose = true;
        }else{
            printf("而且获得了UP五星 !!! \n");
            (*num_ex) ++;
        }
    }else{ //如果上次歪了
        printf("因为上次你歪了其他的五星角色, 这次你获得了UP五星!!\n");
        *is_five_star_fifty_fifty_lose = false;
        (*num_ex) ++;
    }
}

void four_star_fifty_fifty(bool* is_four_star_fifty_fifty_lose, int* num_ex){
    if (! (*is_four_star_fifty_fifty_lose)){ //如果上次没歪
        double rand_num = get_a_random_num();
        if (rand_num < 0.5){ //歪了
            printf("但是你歪了其他四星角色（或武器）...下次一定不会歪\n");
            *is_four_star_fifty_fifty_lose = true;
        }else{
            printf("你获得了UP四星角色!!\n");
            (*num_ex) ++;
        }
    }else{ //如果上次歪了
        printf("因为你上次歪了其他四星, 这次你获得了UP四星角色!!\n");
        *is_four_star_fifty_fifty_lose = false;
        (*num_ex) ++;
    }
}

void seed_random() {
    srand(time(NULL));
}

double get_a_random_num(){
    return (double) rand()/ RAND_MAX;
}



void playgame(int wishes, int wishes_total, int num_5_star, int num_5_star_ex, int num_4_star, int num_4_star_ex, int wishes_in_this_turn,
int last_time_got_a_4_star, double prob_five_star, bool is_five_star_fifty_fifty_lose, bool is_four_star_fifty_fifty_lose, double prob_four_star ){
    while (true){
        double random_num;
        wishes = get_num_of_wishes(wishes, wishes_total, num_5_star, num_5_star_ex, num_4_star, num_4_star_ex); 
        for (int i = 0; i < wishes; i ++){
            wishes_in_this_turn ++;
            last_time_got_a_4_star ++;
            wishes_total ++;
            random_num = get_a_random_num();
            // printf("random number is: %0.2f\n", random_num);
            // printf("Probability is: %0.2f\n", prob);
            if(wishes_in_this_turn >= 74){
                prob_five_star = prob_five_star + 0.06;
            }
            if (wishes_in_this_turn == 90){ //出金，吃满90抽小保底
                printf("恭喜你出金了(虽然用了九十抽hhh)!!  ");
                wishes_in_this_turn = 0;
                prob_five_star = 0.006;
                five_star_fifty_fifty(&is_five_star_fifty_fifty_lose, &num_5_star_ex);
                num_5_star++;
                
            }else if (last_time_got_a_4_star == 10){ //10抽出四星保底
                printf("你获得了四星角色!!   ");
                last_time_got_a_4_star = 0;
                four_star_fifty_fifty(&is_four_star_fifty_fifty_lose, &num_4_star_ex);
                num_4_star++;
            }else if (random_num <= prob_five_star){ //出金
                printf("你用 %d 抽出金了!!   ", wishes_in_this_turn);
                wishes_in_this_turn = 0;
                prob_five_star = 0.006;
                five_star_fifty_fifty(&is_five_star_fifty_fifty_lose, &num_5_star_ex);
                num_5_star++;
            }else if (random_num <= prob_four_star){ // 出四星
                printf("你获得了四星角色!!   ");
                last_time_got_a_4_star = 0;
                four_star_fifty_fifty(&is_four_star_fifty_fifty_lose, &num_4_star_ex);
                num_4_star++;
            }
            else{ // 出答辩
                printf("你获得了答辩(3星)\n");
                
                }
            
            }
        printf("\n目前出金率为: %0.1f%%\n", prob_five_star * 100);
        printf("\n距离上次出金抽了 %d发\n", wishes_in_this_turn);


        // printf("\nNumber of wishes so far: %d\n", wishes_total);

    }
}