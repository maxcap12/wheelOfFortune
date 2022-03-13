#include <stdio.h>
#include <string.h>

char transform(char val);
char* turn_wheel(char *wheel[]);
int min(const int array[], int size);
void show_stat(const char *name, int score, int turn);

int main() {

    int players; // number of players (2 or 3)
    printf("How many players are you (2 or 3) : ");
    scanf("%d", &players);

    char *player1; // name of player 1
    char *player2; // name of player 2
    char *player3; // name of player 3
    char* players_names[players]; // array of all players names
    int num_turn[players]; // array which stocks how many turns players have played
    char wheel[] = {}; // the wheel

    char secret_word[] = "some random words"; // the word to guess
    int size = sizeof(secret_word);
    char current_word[size];
    for (int i = 0; i < size-1; i++) {
        current_word[i] = transform(secret_word[i]);
    }
    printf("%s", current_word);

    for (int i = 0; i < players; i++) { // input of players names and setup of turn
        printf("\nPlease enter player %d name : ", i+1);
        if (i == 0) {
            scanf("%s", players_names[0]);
            printf("%s", players_names[0]);
            num_turn[0] = 0;
        }
        else if (i == 1) {
            scanf("%s", players_names[1]);
            num_turn[i] = 0;
        }
        else {
            scanf("%s", players_names[2]);
            num_turn[i] = 0;
        }
    }

    int turn;
    while (1) {
        turn = min(num_turn, players);
        printf("It's ");

        break;
    }

    return 0;
}

// this shit doesn't work
char transform(const char val) {
    if (val == '-' || val == ' ') {
        return val;
    }
    else {
        return '_';
    }
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

void show_stat(const char *name, int score, int turn) {
    printf("\n\n\n\n\n\n\n\n\n");
    printf("=========================\n");
    for (int i = 0; i < (25-strlen(name))/2; i++) {
        printf("%c", ' ');
    }
    printf("%s \n", name);
    printf("=========================\n\n");
    printf(" score : %d \n", score);
    printf(" turns played : %d \n\n", turn);
    printf("=========================\n");
}
