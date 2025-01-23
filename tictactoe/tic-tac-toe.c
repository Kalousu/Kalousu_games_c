#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

short column;
short row;

short lenRow = 3;
short lenCol = 3;

bool player = true;
bool playing = true;

char options[][3][3] = {{"O", "O", "O"},
                        {"O", "O", "O"},
                        {"O", "O", "O"}};

short getInput(){
    short output;
    while(1){
        if(scanf("%hd", &output) != 1){
            printf("Please try again bro. No jokes allowed here.\n");
            while(getchar() != '\n');
            continue;
        };

        if(output < 0 || output > 2){
            printf("Choose an input between 0 and 2.\n");
            while(getchar() != '\n');
            continue;
        }

        break;
    }
    return output;
}

void displayBoard() {
    printf("\nThe current board is:\n\n");
    printf(" %s | %s | %s ", options[0][0], options[0][1], options[0][2]);
    printf("\n----------\n");
    printf(" %s | %s | %s ", options[1][0], options[1][1], options[1][2]);
    printf("\n----------\n");
    printf(" %s | %s | %s \n\n", options[2][0], options[2][1], options[2][2]);
}

int checkWinner(){
    //check rows
    for(int i = 0; i < lenRow; i++){
        if(strcmp(options[i][0], "X") == 0 && strcmp(options[i][0], options[i][1]) == 0 && strcmp(options[i][0], options[i][2]) == 0){
            return 1;
        }
    }

    //check col
    for(int i = 0; i < lenCol; i++){
        if(strcmp(options[0][i], "X") == 0 && strcmp(options[0][i], options[1][i]) == 0 && strcmp(options[0][i], options[2][i]) == 0){
            return 1;
        }
    }

    //check diagonals
    if(strcmp(options[0][0], "X") == 0 && strcmp(options[0][0], options[2][2]) == 0 && strcmp(options[0][0], options[1][1]) == 0){
        return 1;
    }

    if(strcmp(options[2][0], "X") == 0 && strcmp(options[2][0], options[0][2]) == 0 && strcmp(options[2][0], options[1][1]) == 0){
        return 1;
    }
    return 0;
}

void botMove(){
    short rowChoice;
    short colChoice;

    while(1){
        srand(time(0));

        rowChoice = rand() % 3;
        colChoice = rand() % 3;

        if(strcmp(options[rowChoice][colChoice], "X") == 0){
            continue;
        }

        break;
    }

    strcpy(options[rowChoice][colChoice], "X");
    printf("The bot moved.\n");
    displayBoard();
}



int main() {

    displayBoard();

    while(playing){
        while(1){
            printf("Which row are you selecting? (0 - 2): ");
            row = getInput();
            printf("\n\nAnd which column (0 - 2)?: ");
            column = getInput();

            if(strcmp(options[row][column], "X") == 0){
                printf("\nChoose a valid field. Column %hd Row %hd is already taken.\n\n", column, row);
                continue;
            }
            break;
        }

        printf("Your selected column is %d and row is %d\n", column, row);

        strcpy(options[row][column], "X");

        displayBoard();

        if(checkWinner() == 1){
            playing = false;
            printf("You won!\n");
            break;
        }

        botMove();

        if(checkWinner() == 1){
            playing = false;
            printf("The bot won :(.\n");
            break;
        }
    }

    return 0;
}