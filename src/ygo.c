#include <stdlib.h>
#include <stdio.h>
#include "./ygo.h"

int main(int argc, char *argv[]){
	int *players;
	players = malloc(sizeof(int) * 2); //Array size for two players 

	if(argc == 1){
		declareLP(players, DefaultLP);
	}
	else if(argc == 2){
		int cusLP = atoi(argv[1]);
		declareLP(players, cusLP);
	}
	else{
		printf("Incorrect number of arguments");
	}

	printf("Player 1: %d   Player 2: %d\n", *players, *(players++));
}

void declareLP(int *players, int LP){
	*players = LP;
	players++;
	*players = LP;
}

int calcLP(int *player, int ogLP){
}
