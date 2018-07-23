//Card Test 1
//Smithy

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
    int players = 2;
    int player1 = 0;
    int player2 = 1;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
	int k[10] = {adventurer, smithy, steward, village, great_hall, gardens, mine, feast, council_room, baron};
    int seed = 100;
    struct gameState state, testState;

    initializeGame(players, k, seed, &state);

    memcpy(&testState, &state, sizeof(struct gameState));
	
	//Test 1: Gain 3 Cards
    cardEffect(smithy, choice1, choice2, choice3, &state, handpos, &bonus);

    printf("\nPlayer1 gains 3 cards\n");
    simpleAssert(state.handCount[player1],testState.handCount[player1]+3);

    printf("\nPlayer1 gains 3 cards from his own pile\n");
    simpleAssert(state.deckCount[player1],testState.deckCount[player1]-3);

	
	//Test 2: Check Victory Cards
	memcpy(&testState, &state, sizeof(struct gameState));
    cardEffect(smithy, choice1, choice2, choice3, &state, handpos, &bonus);
	printf("\nProvince");
    simpleAssert(state.supplyCount[province],testState.supplyCount[province]);
    printf("\nDuchy");
	simpleAssert(state.supplyCount[duchy],testState.supplyCount[duchy]);
    printf("\nEstate");
	simpleAssert(state.supplyCount[estate],testState.supplyCount[estate]);

    return 0;
}