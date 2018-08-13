//Card Test 2
//Village

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

void simpleAssert(int i, int j) {
    if (i == j) {
        printf("simpleAssert: PASS\n");
    }
    else {
        printf("simpleAssert: FAIL\n");
    }
}

int main () {
    int i;
    int players = 1;
    int player1 = 0;
    int handpos = 0, choice1 = -1, choice2 = -1, choice3 = -1, bonus = 0;
	int k[10] = {adventurer, smithy, steward, village, great_hall, gardens, mine, feast, council_room, baron};
    int seed = 1000;
    struct gameState state, testState;

    initializeGame(players, k, seed, &state);

    memcpy(&testState, &state, sizeof(struct gameState));
	
	//Test 1: Gain 1 Card
    cardEffect(village, choice1, choice2, choice3, &state, handpos, &bonus);

    printf("\nPlayer1 gains 1 cards\n");
    simpleAssert(state.handCount[player1],testState.handCount[player1]+1);
	//printf("\nCards in hand at beginning: %d",state.handCount[player1]);
	//printf("\nCards in hand at end: %d",testState.handCount[player1]);

    printf("\nPlayer1 gains 2 actions cards\n");
    simpleAssert(state.numActions,testState.numActions+2);
    return 0;
}