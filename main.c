#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
    srand(time(0));
    char cardDeck[52][3] = {"CA", "SA", "DA", "HA", "CK", "SK", "DK", "HK", "CQ", "SQ", "DQ", "HQ", "CJ", "SJ", "DJ", "HJ", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "C1", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9", "S1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D1", "H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "H1"};
    int startingBalance = 500;
    int gameRound = 1;
    int playerValueOfHand = 0;
    int dealerValueOfHand = 0;
    int dealerVisibleCardValue = 0;
    int dealerNonVisibleCardValue = 0;
    int valueOfCardDrawn = 0;
    int index = 0;


    //blackjackStart(startingBalance);

    //chipBreakdown(startingBalance);

    deckShuffleChar(cardDeck, 52);

    //blackjackBetting(&startingBalance, &gameRound);

    //printf("startingBalance = %d", startingBalance); Testing Purposes


    dealCards(cardDeck, &index, &playerValueOfHand, &valueOfCardDrawn, &dealerVisibleCardValue, &dealerNonVisibleCardValue, &dealerValueOfHand);



    return 0;
}
