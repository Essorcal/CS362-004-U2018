#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void simpleAssert(int i, int j) {
    if (i == j) {
        printf("simpleAssert: PASS\n");
    }
    else {
        printf("simpleAssert: FAIL\n");
    }
}

int main () 
{
  srand(time(NULL));
  int j = 0;

  for (j = 0; j < 100; j++)
  {
    srand(time(NULL));
    int seed;
    seed = rand() % 100;
	
    int players = 2;

    for (players = 2; players < 5; players++)
    {
		int player1 = 0;
		int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
		int k[10] = {adventurer, smithy, steward, village, great_hall, gardens, mine, feast, council_room, baron};
		struct gameState state, testState;
		memset(&state, 23, sizeof(struct gameState));
		initializeGame(players, k, seed, &state);
		memcpy(&testState, &state, sizeof(struct gameState));
      
		int play;

		play = cardEffect(adventurer, choice1, choice2, choice3, &state, handpos, &bonus);

		if (play > -1)
		 {
			printf("\nPlayer1 gains 2 cards\n");
			simpleAssert(state.handCount[player1],testState.handCount[player1]+2); 
				
			printf("\nPlayer1 gains 2 cards from his own pile\n");
			simpleAssert(state.deckCount[player1],testState.deckCount[player1]-2);
			
		 }
    }
  }

  return 0;

}
