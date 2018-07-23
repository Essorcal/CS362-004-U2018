//Unit Test 3
//Testing: testBuyCard()

/* Original Function

int buyCard(int supplyPos, struct gameState *state) {
  int who;
  if (DEBUG){
    printf("Entering buyCard...\n");
  }

  // I don't know what to do about the phase thing.

  who = state->whoseTurn;

  if (state->numBuys < 1){
    if (DEBUG)
      printf("You do not have any buys left\n");
    return -1;
  } else if (supplyCount(supplyPos, state) <1){
    if (DEBUG)
      printf("There are not any of that type of card left\n");
    return -1;
  } else if (state->coins < getCost(supplyPos)){
    if (DEBUG) 
      printf("You do not have enough money to buy that. You have %d coins.\n", state->coins);
    return -1;
  } else {
    state->phase=1;
    //state->supplyCount[supplyPos]--;
    gainCard(supplyPos, state, 0, who); //card goes in discard, this might be wrong.. (2 means goes into hand, 0 goes into discard)
  
    state->coins = (state->coins) - (getCost(supplyPos));
    state->numBuys--;
    if (DEBUG)
      printf("You bought card number %d for %d coins. You now have %d buys and %d coins.\n", supplyPos, getCost(supplyPos), state->numBuys, state->coins);
  }

  //state->discard[who][state->discardCount[who]] = supplyPos;
  //state->discardCount[who]++;
    
  return 0;
}

*/

#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>


void testBuyCard(){
	

	struct gameState *state = (struct gameState *) malloc (sizeof(struct gameState));

	state->numBuys = 0;
	if (buyCard(smithy, state) == -1)
	{
		printf("buyCard function: PASS when no action is available\n");
	} else {
		printf("buyCard function: FAIL bought card when no action is available\n");
	}	
	state->numBuys = 1;
	state->supplyCount[smithy] = 0;
	if (buyCard(smithy, state) == -1)
	{
		printf("buyCard function: PASS when no cards are in the stockpile \n");
	} else {
		printf("buyCard function: FAIL bought card that was not available \n");
	}
	state->numBuys = 1;
	state->coins = 1;
	state->supplyCount[smithy] = 1;
	if (buyCard(smithy, state) == -1)
	{
		printf("buyCard function: PASS when insufficients funds to purchase \n");
	} else {
		printf("buyCard function: FAIL bought card with insufficient coins \n");
	}
	state->numBuys = 1;
	state->coins = 4;
	state->supplyCount[smithy] = 1;
	state->whoseTurn = 0;
	if (buyCard(smithy, state) == 0 && state->coins == 0 && state->numBuys == 0 && state->supplyCount[smithy] == 0)
	{			
		printf("buyCard function: PASS Successfully bought card\n");
	} else {
		printf("buyCard function: FAIL Did not buy card\n");
	}
}


int main(){
	testBuyCard();
	return 0;
}