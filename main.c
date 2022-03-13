#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* init_word(char word[]);
char* turn_wheel(char *wheel[]);
int min(const int array[], int size);


int main() {

    int players; // number of players (2 or 3)
    printf("How many players are you (2 or 3) : ");
    scanf("%d", &players);

    char player1[20]; // name of player 1
    char player2[20]; // name of player 2
    char player3[20]; // name of player 3
    char* players_names[players]; // array of all players names

    int turn[players]; // array which stocks how many turns players have played
    char wheel[] = {}; // the wheel

    char *secret_word = "some random words"; // the word to guess
    char *current_word = init_word(secret_word);

    for (int i = 0; i < players; i++) { // input of players names and setup of turn
        printf("\nPlease enter player %d name : ", i+1);
        if (i == 0) {
            scanf("%s", player1);
            turn[0] = 0;
        }
        else if (i == 1) {
            scanf("%s", player2);
            turn[i] = 0;
        }
        else {
            scanf("%s", player3);
            turn[i] = 0;
        }
    }

    printf("\nmin : %d", min(turn, players));
    return 0;
}

// this shit doesn't work
char* init_word(char word[]) {
    char *init = "ok";

    for (int i = 0; i < strlen(word); i++) {

        switch (word[i]) {
            case ' ':
                init += ' ';
                break;
            case '-':
                init += '-';
                break;
            default:
                init += '_';
        }
    }
    return init;
}


int min(const int array[], int size) {
    int min = 0;

    for (int i = 0; i < size; i++) {
        if (array[min] > array[i]) {
            min = i;
        }
    }

    return min;
}
