#include <stdio.h>
#include <stdlib.h>

#define PLAYER 'X'
#define AI 'O'
#define EMPTY ' '

void clearScreen() {
    printf("\033[H\033[J"); // ANSI clear console
}

void printBoard(char board[3][3]) {
    clearScreen();
    printf("\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j]==PLAYER)
                printf("\033[1;31m %c \033[0m", board[i][j]); // red X
            else if(board[i][j]==AI)
                printf("\033[1;34m %c \033[0m", board[i][j]); // blue O
            else
                printf(" %c ", board[i][j]);

            if(j<2) printf("|");
        }
        printf("\n");
        if(i<2) printf("---+---+---\n");
    }
    printf("\n");
}

// --- Game logic functions ---
int checkWinner(char board[3][3]) {
    for(int i=0;i<3;i++)
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2] && board[i][0]!=EMPTY)
            return board[i][0];
    for(int j=0;j<3;j++)
        if(board[0][j]==board[1][j] && board[1][j]==board[2][j] && board[0][j]!=EMPTY)
            return board[0][j];
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[0][0]!=EMPTY)
        return board[0][0];
    if(board[0][2]==board[1][1] && board[1][1]==board[2][0] && board[0][2]!=EMPTY)
        return board[0][2];
    return 0;
}

int boardFull(char board[3][3]){
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(board[i][j]==EMPTY) return 0;
    return 1;
}

int minimax(char board[3][3], int depth, int isAI){
    int winner = checkWinner(board);
    if(winner==AI) return 10-depth;
    if(winner==PLAYER) return depth-10;
    if(boardFull(board)) return 0;

    if(isAI){
        int best=-1000;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[i][j]==EMPTY){
                    board[i][j]=AI;
                    int score=minimax(board,depth+1,0);
                    board[i][j]=EMPTY;
                    if(score>best) best=score;
                }
            }
        }
        return best;
    } else {
        int best=1000;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[i][j]==EMPTY){
                    board[i][j]=PLAYER;
                    int score=minimax(board,depth+1,1);
                    board[i][j]=EMPTY;
                    if(score<best) best=score;
                }
            }
        }
        return best;
    }
}

void aiMove(char board[3][3]){
    int bestScore=-1000, moveRow=-1, moveCol=-1;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j]==EMPTY){
                board[i][j]=AI;
                int score=minimax(board,0,0);
                board[i][j]=EMPTY;
                if(score>bestScore){
                    bestScore=score;
                    moveRow=i;
                    moveCol=j;
                }
            }
        }
    }
    board[moveRow][moveCol]=AI;
}

void playerMove(char board[3][3]){
    int row,col;
    do{
        printf("Enter row(1-3) and col(1-3): ");
        scanf("%d %d",&row,&col);
        row--; col--;
    }while(row<0||row>2||col<0||col>2||board[row][col]!=EMPTY);
    board[row][col]=PLAYER;
}

// --- Save and Load ---
void saveGame(char board[3][3], int scorePlayer, int scoreAI){
    FILE *f=fopen("XO_save.txt","w");
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            fprintf(f,"%c",board[i][j]);
    fprintf(f,"%d %d",scorePlayer,scoreAI);
    fclose(f);
    printf("Game saved!\n");
}

int loadGame(char board[3][3], int *scorePlayer, int *scoreAI){
    FILE *f=fopen("XO_save.txt","r");
    if(!f) return 0;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            fscanf(f,"%c",&board[i][j]);
    fscanf(f,"%d %d",scorePlayer,scoreAI);
    fclose(f);
    printf("Game loaded!\n");
    return 1;
}

int main(){
    char board[3][3];
    int rounds=1, scorePlayer=0, scoreAI=0, choice;

    printf("Welcome to X and O Pro + Save/Load!\n");
    printf("Do you want to load previous game? (1=Yes,0=No): ");
    scanf("%d",&choice);
    if(choice==1) loadGame(board,&scorePlayer,&scoreAI);

    printf("Enter number of rounds: ");
    scanf("%d",&rounds);

    for(int r=1;r<=rounds;r++){
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                if(board[i][j]!=PLAYER && board[i][j]!=AI)
                    board[i][j]=EMPTY;

        int winner=0;
        while(!winner && !boardFull(board)){
            printBoard(board);
            playerMove(board);
            winner=checkWinner(board);
            if(winner || boardFull(board)) break;
            aiMove(board);
            winner=checkWinner(board);
        }

        printBoard(board);
        if(winner==PLAYER){ printf("Player wins!\n"); scorePlayer++; }
        else if(winner==AI){ printf("AI wins!\n"); scoreAI++; }
        else printf("It's a tie!\n");

        printf("Score -> Player: %d | AI: %d\n",scorePlayer,scoreAI);
        printf("Do you want to save the game? (1=Yes,0=No): ");
        scanf("%d",&choice);
        if(choice==1) saveGame(board,scorePlayer,scoreAI);

        printf("Press Enter to continue...\n");
        getchar(); getchar();
    }
    printf("Final Score after %d rounds -> Player: %d | AI: %d\n",rounds,scorePlayer,scoreAI);
    printf("Thanks for playing!\n");
}
