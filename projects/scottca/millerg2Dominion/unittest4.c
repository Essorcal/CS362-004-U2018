//Unit Test 4
//Testing: testNumHandCards()

/* Original Function

int numHandCards(struct gameState *state) {
  return state->handCount[ whoseTurn(state) ];
}

*/

#include <stdlib.h>
#include <stdio.h>
#include "dominion.h"
#include "dominion_helpers.h"

void testNumHandCards()
{
	struct gameState testState;
	int players = 2;
	int seed = 100;
	int k[10] = {adventurer, smithy, steward, village, great_hall, gardens, mine, feast, council_room, baron};
	initializeGame(players, k, seed, &testState);	
  
  // At the start of a game, the player should have 5 cards.
  if (numHandCards(&testState) == 5)
    printf("numHandcards function: PASS - Player has the correct number of cards\n");
  else
    printf("numHandCards function: FAIL - Player has the incorrect number of cards\n");
}


int main(int argc, char * argv[])
{
  testNumHandCards();
  return 0;
}