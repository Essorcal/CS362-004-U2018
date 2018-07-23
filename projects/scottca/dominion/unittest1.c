//Unit Test 2
//Testing: whoseTurn()

/* Original Function

int whoseTurn(struct gameState *state) {
  return state->whoseTurn;
}
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>

void testWhoseTurn()
{
	struct gameState testState;
	int players = 2;
	int seed = 100;
	int k[10] = {adventurer, smithy, steward, village, great_hall, gardens, mine, feast, council_room, baron};
	initializeGame(players, k, seed, &testState);

	testState.whoseTurn = 0;
	
	if (0 == whoseTurn(&testState))
	{
		printf("whoseTurn function: PASS - Player 1's turn");
	}
	else
	{
		printf("whoseTurn function: FAIL - Player 2's turn");
	}
	
	testState.whoseTurn = 1;
	
	if (1 == whoseTurn(&testState))
	{
		printf("whoseTurn function: PASS - Player 2's turn");
	}
	else
	{
		printf("whoseTurn function: FAIL - Player 1's turn");
	}
}


int main(int argc, char *argv[])
{
  testWhoseTurn();
  return 0;
}
