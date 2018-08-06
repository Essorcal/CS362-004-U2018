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
    int t;
    t = rand() % 100;
	
    int players = 2;

    for (i = 2; i < 5; i++)
    {
		int player1 = 0;
		int player2 = 1;
		int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
		int k[10] = {adventurer, smithy, steward, village, great_hall, gardens, mine, feast, council_room, baron};
		struct gameState G, prevG;
		memset(&G, 23, sizeof(struct gameState));
		initializeGame(players, k, t, &G);
		memcpy(&prevG, &G, sizeof(struct gameState));
      
		int play;

		play = cardEffect(smithy, choice1, choice2, choice3, &G, handpos, &bonus);

		if (play > -1)
		 {
			printf("\nPlayer1 gains 3 cards\n");
			simpleAssert(state.handCount[player1],testState.handCount[player1]+3); 
				
			printf("\nPlayer1 gains 3 cards from his own pile\n");
			simpleAssert(state.deckCount[player1],testState.deckCount[player1]-3);
		 }
    }
  }

  return 0;

}
