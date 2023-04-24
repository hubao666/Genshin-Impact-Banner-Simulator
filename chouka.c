#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "get_input.h"
#include "play_game.h"
#include <time.h>



int main(){
    int wishes = 0;
    int wishes_total = 0;
    int wishes_in_this_turn = 0;
    int num_5_star = 0;
    int num_5_star_ex = 0;
    int num_4_star = 0;
    int num_4_star_ex = 0;
    // int num_other;
    seed_random();
    bool is_five_star_fifty_fifty_lose = false;
    bool is_four_star_fifty_fifty_lose = false;
    double prob_five_star = 0.006;
    double prob_four_star = 0.051;
    int last_time_got_a_4_star = 0;
    playgame(wishes, wishes_total, num_5_star, num_5_star_ex, num_4_star, num_4_star_ex, wishes_in_this_turn, 
    last_time_got_a_4_star, prob_five_star, is_five_star_fifty_fifty_lose, is_four_star_fifty_fifty_lose, prob_four_star );
    return 0;
}

