
chouka_cn.out: chouka_chinese_vr.o get_input_chinese_vr.o play_game_chinese_vr.o
	gcc -g -Wall -Werror -o chouka_cn.out chouka_chinese_vr.o get_input_chinese_vr.o play_game_chinese_vr.o

chouka_cn.o: chouka_chinese_vr.c get_input_chinese_vr.h play_game_chinese_vr.h
	gcc -g -Wall -Werror -c chouka_chinese_vr.c

get_input_chinese_vr.o: get_input_chinese_vr.c get_input_chinese_vr.h
	gcc -g -Wall -Werror -c get_input_chinese_vr.c

play_game_chinese_vr.o: play_game_chinese_vr.c play_game_chinese_vr.h get_input_chinese_vr.h
	gcc -g -Wall -Werror -c play_game_chinese_vr.c

run: 
	./chouka_cn.out



chouka.out: chouka.o get_input.o play_game.o
	gcc -g -Wall -Werror -o chouka.out chouka.o get_input.o play_game.o

chouka.o: chouka.c get_input.h play_game.h
	gcc -g -Wall -Werror -c chouka.c

get_input.o: get_input.c get_input.h
	gcc -g -Wall -Werror -c get_input.c

play_game.o: play_game.c play_game.h get_input.h
	gcc -g -Wall -Werror -c play_game.c

# run:
# 	./chouka.out
clean:
	rm -f *.o *.out
