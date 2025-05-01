#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int findValueOfCardDrawn(char cardDeck[52][3], int randomNumber, int valueOfCardDrawn, int valueOfHand) {
    valueOfCardDrawn = 0;
    if (cardDeck[randomNumber][1] == 'K' || cardDeck[randomNumber][1] == 'Q' || cardDeck[randomNumber][1] == 'J') {
        valueOfCardDrawn = 10;
    }
    else if (cardDeck[randomNumber][1] == 'A') {
        valueOfCardDrawn = 11;
        if ((valueOfHand + valueOfCardDrawn) > 21) {
            valueOfCardDrawn = 1;
        }
    }
    else if (cardDeck[randomNumber][1] == '1') {
        valueOfCardDrawn = cardDeck[randomNumber][1] - '0' + 9;
    }
    else {
        valueOfCardDrawn = cardDeck[randomNumber][1] - '0';
    }
    return valueOfCardDrawn;
}

void displayCardDrawn(char cardDeck[52][3], int randomNumber, int valueOfCardDrawn) {
    if ( cardDeck[randomNumber][1] == 'A' || cardDeck[randomNumber][1] == 'K' || cardDeck[randomNumber][1] == 'Q' || cardDeck[randomNumber][1] == 'J') {
        switch (cardDeck[randomNumber][1]) {      //Fix Later: Condition and add nested switch statement
            case 'A':
                printf("You have drawn an Ace!\n");
                break;
            case 'K':
                printf("You have drawn a King!\n");
                break;
            case 'Q':
                printf("You have drawn a Queen!\n");
                break;
            case 'J':
                printf("You have drawn a Jack!\n");
                break;
        }
    }
    else {
        switch (cardDeck[randomNumber][0]) {
            case 'C':
                if (cardDeck[randomNumber][1] == '1') {
                    printf("You have drawn a 10 of Clubs!\n");
                    break;
                }
                else {
                printf("You have drawn a %d of Clubs!\n", valueOfCardDrawn);
                break;
                }
            case 'S':
                if (cardDeck[randomNumber][1] == '1') {
                    printf("You have drawn a 10 of Spades!\n");
                    break;
                }
                else {
                printf("You have drawn a %d of Spades!\n", valueOfCardDrawn);
                break;
                }
            case 'D':
                if (cardDeck[randomNumber][1] == '1') {
                    printf("You have drawn a 10 of Diamonds!\n");
                    break;
                }
                else {
                printf("You have drawn a %d of Diamonds!\n", valueOfCardDrawn);
                break;
                }
            case 'H':
                if (cardDeck[randomNumber][1] == '1') {
                    printf("You have drawn a 10 of Hearts!\n");
                    break;
                }
                else {
                printf("You have drawn a %d of Hearts!\n", valueOfCardDrawn);
                break;
                }
        }
    }
}

void blackjackStart(int startingBalance) {

    char userName[25];
    char userResponse;
    char userYN;

    printf("Welcome! What is your name?\n");
    printf(">>>> ");
    gets(userName);

    do {
        printf("\nHi %s! Welcome to BlackJack. Do you already know how to play? Say Y if yes or N if no.\n", userName);
        printf(">>>> ");
        scanf(" %c", &userResponse);

        if (userResponse != 'y' && userResponse != 'Y' && userResponse != 'n' && userResponse != 'N') {
            printf("\nInvalid input! Please enter Y or N.\n");
        }

    } while (userResponse != 'y' && userResponse != 'Y' && userResponse != 'n' && userResponse != 'N');

    if (userResponse == 'y' || userResponse == 'Y') {
        printf("\nGreat, %s! Let's start you off with $%d\n", userName, startingBalance);
    } else if (userResponse == 'n' || userResponse == 'N') {
        printf("\nNo worries, %s! I'll explain the rules.\n", userName);

        do {
            printf("\nRULES:\n");
            printf("- You will be dealt two cards to start.\n");
            printf("- The goal is to get as close to 21 as possible without going over.\n");
            printf("- Each number card is worth its face value.\n");
            printf("- Face cards (Jack, Queen, King) are worth 10 points.\n");
            printf("- Aces are worth either 1 or 11, whichever helps you more.\n");
            printf("- On your turn, you can choose to 'Hit' to draw another card, or 'Stand' to keep your total.\n");
            printf("- If your total goes over 21, you 'bust' and lose the round.\n");
            printf("- After you finish, the dealer takes their turn. The dealer must keep hitting until they have 17 or more.\n");
            printf("- Whoever is closer to 21 without busting wins!\n\n");

            printf("Do you understand the rules now, %s? Enter Y/N.\n", userName);
            printf(">>>> ");
            scanf(" %c", &userYN);

            if (userYN != 'y' && userYN != 'Y' && userYN != 'n' && userYN != 'N') {
                printf("\nInvalid input! Please enter Y or N.\n");
            } else if (userYN == 'n' || userYN == 'N') {
                printf("\nAlright, %s, let's go over it again.\n", userName);
            }

        } while (userYN != 'y' && userYN != 'Y');

        printf("\nGreat, %s! Let's start you off with $%d.\n", userName, startingBalance);
    }
}

void chipBreakdown(int chipAmount) {

    int chipValues[] = {100, 50, 25, 5, 1};
    int chipCount;

    printf("\n>>> CHIP BREAKDOWN <<<\n");
    for (int i = 0; i < 5; i++) {
        chipCount = chipAmount / chipValues[i];
        chipAmount %= chipValues[i];
        if (chipCount > 0) {
            printf("- %d x $%d chip(s)\n", chipCount, chipValues[i]);
        }
    }
}

void blackjackBetting(int *userBalance, int *gameRound) {

    int userBet;
    int gameOutcome;
    char continueGame;

    //printf("You now have $%d in your balance.\n", userBalance);

    while (*userBalance > 0) {
        printf("\nROUND %d:\n", *gameRound);

        if (gameRound > 1) {
            printf("Your current balance is: $%d\n\n", *userBalance);
        }

        printf("Enter your bet here:\n");
        printf(">>>> ");
        if (scanf("%d", &userBet) != 1) {
            while (getchar() != '\n');
            printf("\nInvalid bet. Please enter an amount between $1 and $%d.\n", *userBalance);
            continue;
        }
        while (getchar() != '\n');

        if (userBet > *userBalance || userBet <= 0) {
            printf("\nInvalid bet. Please enter an amount between $1 and $%d.\n", *userBalance);
            continue;
        }


        if (*userBalance > 0) {
            *userBalance -= userBet;
            *gameRound++;
            break;
        }
    }
}

int deckShuffleChar(char cardDeck[][3], int deckSize){

    char temp[3];

        for(int j = 0; j < ((rand() % 4) + 5); j++){
            for(int i = 0; i < (deckSize); i++){
                    int x = rand() % (deckSize);

                    strcpy(temp, cardDeck[i]);
                    strcpy(cardDeck[i], cardDeck[x]);
                    strcpy(cardDeck[x], temp);

            } // end for i
        } // end for j

// debugging <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
    printf("\n\n%d\n\n", deckSize);

    for (int i = 0; i < deckSize; i++) {
        printf("%s ", cardDeck[i]);
        //Sleep(50);
    } // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
return(1);
}



void dealCards(char cardDeck[52][3], int *index, int *playerValueOfHand, int *valueOfCardDrawn, int *dealerVisibleCardValue, int *dealerNonVisibleCardValue, int *dealerValueOfHand){
    *valueOfCardDrawn = 0;
    for (; *index < 4; (*index)++) {  // Correctly modifying *index
        if (*index == 0 || *index == 2) {
            *valueOfCardDrawn = findValueOfCardDrawn(cardDeck, *index, *valueOfCardDrawn, *playerValueOfHand);
            *playerValueOfHand += *valueOfCardDrawn;
            displayCardDrawn(cardDeck, *index, *valueOfCardDrawn); // Fixed missing parenthesis
            printf("\nValue of  player Hand: %d\n", *playerValueOfHand);  // Added newline
        }
        else if (*index == 1) {
            *valueOfCardDrawn = findValueOfCardDrawn(cardDeck, *index, *valueOfCardDrawn, *dealerValueOfHand);
            *dealerVisibleCardValue += *valueOfCardDrawn;
            printf("\nDealers visible card: %d\n", *dealerVisibleCardValue);
        }
        else if (*index == 3) {
            *valueOfCardDrawn = findValueOfCardDrawn(cardDeck, *index, *valueOfCardDrawn, *dealerValueOfHand);
            *dealerNonVisibleCardValue += *valueOfCardDrawn;
            printf("\nDealers non-visible card: %d\n", *dealerNonVisibleCardValue);
        }
        *dealerValueOfHand = *dealerNonVisibleCardValue + *dealerVisibleCardValue;
    }
    printf("\nThe dealers value of hand: %d\n", *dealerValueOfHand);
}




