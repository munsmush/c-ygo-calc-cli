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

	int choice = -1;
	
	while(choice != 6){
		system("clear");
		printf("Player 1: %d   Player 2: %d\n\n", *players, players[1]);
	
		printf("1: Subtract Life Points\n");
		printf("2: Add Life Points\n");
		printf("3: Reset Life Points\n");
		printf("4: Flip a coin\n");
		printf("5: Roll a die\n");
		printf("6: Exit\n\n");
		printf("Choose an option: ");

		scanf("%d", &choice);

		switch(choice){
			case 1:
				calcLP(players, choice);
				break;
			case 2:
				calcLP(players, choice);
				break;
			case 3:
				resetLP(players, argc, argv);
				break;
			case 4:
				coin();
				break;
			case 5:
				break;
		}
	}
}

void declareLP(int *players, int LP){
	*players = LP;
	players++;
	*players = LP;
}

void calcLP(int *players, int choice){
	int p; //Amount of points to + or -
	int player;
	
	printf("Choose which player: ");
	scanf("%d", &player);

	printf("Enter amount: ");
	scanf("%d", &p);

	if(choice == 1){
		if(player == 1){
			*players = *players - p;
		}
		else if(player == 2){
			players++;
			*players = *players - p;
		}
		else{
			printf("Error: Wrong input");
		}
	}
	else{
		if(player == 1){
			*players = *players + p;
		}
		else if(player == 2){
			players++;
			*players = *players + p;
		}
		else{
			printf("Error: Wrong input");
		}
	}
}

void resetLP(int *players, int argc, char *argv[]){
	if(argc == 1){
		*players = DefaultLP;
		players++;
		*players = DefaultLP;

	}
	else if(argc == 2){
		int LP = atoi(argv[1]);
		*players = LP;
		players++;
		*players = LP;
	}
}

void coin(){
	system("clear");
	int result = rand() % 2;
	if(result == 1){
		printf("Heads");
	}
	else{
		printf("Tails");
	}
	puts("Press any key to continue...\n");
	while(getchar() != 27);	
}

void dice(){
	
}
