#ifndef PLAY_GAME_H
#define PLAY_GAME_H

    double get_a_random_num();
    void seed_random();
    void five_star_fifty_fifty(bool* is_five_star_fifty_fifty_lose, int* num_ex);
    void four_star_fifty_fifty(bool* is_four_star_fifty_fifty_lose, int* num_ex);
    void playgame(int wishes, int wishes_total, int num_5_star, int num_5_star_ex, int num_4_star, int num_4_star_ex, int wishes_in_this_turn,
    int last_time_got_a_4_star, double prob_five_star, bool is_five_star_fifty_fifty_lose, bool is_four_star_fifty_fifty_lose, double prob_four_star);



	
#endif