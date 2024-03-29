#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char x1y3 = ' ', x2y3 = ' ', x3y3 = ' ';
char x1y2 = ' ', x2y2 = ' ', x3y2 = ' ';
char x1y1 = ' ', x2y1 = ' ', x3y1 = ' ';

void printBoard();
int validInteger(char *);
int checkForSpace(int, int);
void getCoord(int, int, char);
int checkForWin(char);
void clearBoard();

int main () {

    printf("\nTicTacToe - Made by Eli Gomez - 3/27/2024\n");
    printBoard();

    int XScore = 0, OScore = 0;
    char *strX; 
    char *strY;
    char *command;
    int stop = 0;
    for(int i = 1; stop == 0; i++) {
        if (i % 2 == 1) {
            strX = (char *)malloc(sizeof(char));
            strY = (char *)malloc(sizeof(char));
            printf("\nPlayer X's turn...");
            printf("\n(x)-coordinate: ");
            scanf("%s", strX);
            printf("(y)-coordinate: ");
            scanf("%s", strY);
            if ((validInteger(strX) == 1) && (validInteger(strY) == 1)) {
                int x = strtod(strX, NULL);
                int y = strtod(strY, NULL);
                if (checkForSpace(x, y) == 1) {
                    getCoord(x, y, 'X');
                    printBoard();
                    if (checkForWin('X') == 1) {
                        XScore++;
                        command = (char *)malloc(sizeof(char));
                        printf("\nafter %d turns... PLAYER X WINS!!", i);
                        printf("\nto see the score board, enter 'scores'");
                        printf("\nto end the game, enter 'stop'");
                        printf("\nto restart, enter 'restart'\n");
                        int done = 0;
                        while (done == 0) {
                            printf("\n: ");
                            scanf("%s", command);
                            if (strcmp("scores", command) == 0) {
                                printf("\nPlayer X: %d wins\nPlayer O: %d wins\n", XScore, OScore);
                            } else if (strcmp("stop", command) == 0) {
                                done = 1;
                                stop = 1;
                            } else if (strcmp("restart", command) == 0) {
                                done = 1;
                                clearBoard();
                                i = 0;
                                printBoard();
                            } else {
                                printf("\ninvalid command! try again...\n");
                            }
                        }
                        free(command);
                    }
                } else {
                    printf("\nthere's no space there! try again...\n");
                    i--;
                }
            } else {
                printf("\ninvlaid coordinate! try again...\n");
                i--;
            }
            free(strX);
            free(strY);
        } else if (i % 2 == 0) {
            strX = (char *)malloc(sizeof(char));
            strY = (char *)malloc(sizeof(char));
            printf("\nPlayer O's turn...");
            printf("\n(x)-coordinate: ");
            scanf("%s", strX);
            printf("(y)-coordinate: ");
            scanf("%s", strY);
            if ((validInteger(strX) == 1) && (validInteger(strY) == 1)) {
                int x = strtod(strX, NULL);
                int y = strtod(strY, NULL);
                if (checkForSpace(x, y) == 1) {
                    getCoord(x, y, 'O');
                    printBoard();
                    if (checkForWin('O') == 1) {
                        OScore++;
                        command = (char *)malloc(sizeof(char));
                        printf("\nafter %d turns... PLAYER O WINS!!", i);
                        printf("\nto see the score board, enter 'scores'");
                        printf("\nto end the game, enter 'stop'");
                        printf("\nto restart, enter 'restart'\n");
                        int done = 0;
                        while (done == 0) {
                            printf("\n: ");
                            scanf("%s", command);
                            if (strcmp("scores", command) == 0) {
                                printf("\nPlayer X: %d wins\nPlayer O: %d wins\n", XScore, OScore);
                            } else if (strcmp("stop", command) == 0) {
                                done = 1;
                                stop = 1;
                            } else if (strcmp("restart", command) == 0) {
                                done = 1;
                                clearBoard();
                                i = 0;
                                printBoard();
                            } else {
                                printf("\ninvalid command! try again...\n");
                            }
                        }
                        free(command);
                    }
                } else {
                    printf("\nthere's no space there! try again...\n");
                    i--;
                }
            } else {
                printf("\ninvlaid coordinate! try again...\n");
                i--;
            }
            free(strX);
            free(strY);
        }  
        if (i == 9) {
            command = (char *)malloc(sizeof(char));
            printf("\nafter %d turns... IT ENDS IN A TIE!!", i);
            printf("\nto see the score board, enter 'scores'");
            printf("\nto end the game, enter 'stop'");
            printf("\nto restart, enter 'restart'\n");
            int done = 0;
            while (done == 0) {
                printf("\n: ");
                scanf("%s", command);
                if (strcmp("scores", command) == 0) {
                    printf("\nPlayer X: %d wins\nPlayer O: %d wins\n", XScore, OScore);
                } else if (strcmp("stop", command) == 0) {
                    done = 1;
                    stop = 1;
                } else if (strcmp("restart", command) == 0) {
                    done = 1;
                    clearBoard();
                    i = 0;
                    printBoard();
                } else {
                    printf("\ninvalid command! try again...\n");
                }
            }
            free(command);
        }
    }
    return 0;
}

void printBoard() {
    printf("\n(y)\n"
           "  |---|---|---|\n"
           "3 | %c | %c | %c |\n"
           "  |---|---|---|\n"
           "2 | %c | %c | %c |\n"
           "  |---|---|---|\n"
           "1 | %c | %c | %c |\n"
           "  |---|---|---|\n"
           "    1   2   3  (x)\n",
           x1y3, x2y3, x3y3, x1y2, x2y2, x3y2, x1y1, x2y1, x3y1);
}

int validInteger(char * XY) {
    if (strcmp("1", XY) == 0) {
        return 1;
    } else if (strcmp("2", XY) == 0) {
        return 1;
    } else if (strcmp("3", XY) == 0) {
        return 1;
    } else {
        return 0;
    }
}

int checkForSpace(int x, int y) {
    switch (x) {
        case 1:
            switch (y) {
                case 1:
                    if (x1y1 != ' ') {
                        return 0;
                        exit(0);
                    }
                    break;
                case 2:
                    if (x1y2 != ' ') {
                        return 0;
                        exit(0);
                    }
                    break;
                case 3:
                    if (x1y3 != ' ') {
                        return 0;
                        exit(0);
                    }
                    break;
            }
            break;
        case 2:
            switch (y) {
                case 1:
                    if (x2y1 != ' ') {
                        return 0;
                        exit(0);
                    }
                    break;
                case 2:
                    if (x2y2 != ' ') {
                        return 0;
                        exit(0);
                    }
                    break;
                case 3:
                    if (x2y3 != ' ') {
                        return 0;
                        exit(0);
                    }
                    break;
            }
            break;
        case 3:
            switch (y) {
                case 1:
                    if (x3y1 != ' ') {
                        return 0;
                        exit(0);
                    }
                    break;
                case 2:
                    if (x3y2 != ' ') {
                        return 0;
                        exit(0);
                    }
                    break;
                case 3:
                    if (x3y3 != ' ') {
                        return 0;
                        exit(0);
                    }
                    break;
            }
            break;
    }
    return 1;
}

void getCoord(int x, int y, char XO) {
    switch (x) {
        case 1:
            switch (y) {
                case 1:
                    x1y1 = XO;
                    break;
                case 2:
                    x1y2 = XO;
                    break;
                case 3:
                    x1y3 = XO;
                    break;
            }
            break;
        case 2:
            switch (y) {
                case 1:
                    x2y1 = XO;
                    break;
                case 2:
                    x2y2 = XO;
                    break;
                case 3:
                    x2y3 = XO;
                    break;
            }
            break;
        case 3:
            switch (y) {
                case 1:
                    x3y1 = XO;
                    break;
                case 2:
                    x3y2 = XO;
                    break;
                case 3:
                    x3y3 = XO;
                    break;
            }
            break;
    }        
}

int checkForWin(char XO) {
    if (x1y1 == XO && x1y2 == XO && x1y3 == XO) {
        return 1;
    } else if (x2y1 == XO && x2y2 == XO && x2y3 == XO) {
        return 1;
    } else if (x3y1 == XO && x3y2 == XO && x3y3 == XO) {
        return 1;
    } else if (x1y1 == XO && x2y1 == XO && x3y1 == XO) {
        return 1;
    } else if (x1y2 == XO && x2y2 == XO && x3y2 == XO) {
        return 1;
    } else if (x1y3 == XO && x2y3 == XO && x3y3 == XO) {
        return 1;
    } else if (x1y1 == XO && x2y2 == XO && x3y3 == XO) {
        return 1;
    } else if (x1y3 == XO && x2y2 == XO && x3y1 == XO) {
        return 1;
    } else {
        return 0;
    }
}

void clearBoard() {
    x1y3 = ' ', x2y3 = ' ', x3y3 = ' ';
    x1y2 = ' ', x2y2 = ' ', x3y2 = ' ';
    x1y1 = ' ', x2y1 = ' ', x3y1 = ' ';
}
