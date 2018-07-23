//Unit Test 2
//Testing: testCompare()

/* Original Function

int compare(const void* a, const void* b) {
  if (*(int*)a > *(int*)b)
    return 1;
  if (*(int*)a < *(int*)b)
    return -1;
  return 0;
}

*/
#include <stdlib.h>
#include <stdio.h>
#include "dominion.h"
#include "dominion_helpers.h"

void testCompare()
{
  int highVal = 100;
  int lowVal = -100;
  int MaxInt = 2147483647;
  int MinInt = -2147483648;
  
  //compare high value to low value, positive to negative
  if (compare(&highVal, &lowVal) == 1)
    printf("compare function: PASS - High Value > Low Value \n");
  else
    printf("compare function: FAIL - High Value < Low Value \n");

//compare low value to high value, negative to positive
  if (compare(&lowVal, &highVal) == -1)
    printf("compare function: PASS - Low Value < High Value \n");
  else
    printf("compare function: FAIL High Value > Low Value \n");
 
 //compare max integer value to min integer value
  if (compare(&MaxInt, &MinInt) == 1)
    printf("compare function: PASS - High Value > Low Value \n");
  else
    printf("compare function: FAIL - High Value < Low Value \n");
 
 //compare identical values
  if (compare(&highVal, &highVal) == 1)
    printf("compare function: PASS - High Value = High Value \n");
  else
    printf("compare function: FAIL - High Value != High Value \n");
    
}


int main(int argc, char * argv[])
{
  
  testCompare();
  return 0;
}