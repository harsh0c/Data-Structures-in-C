#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <ctype.h>
#include <windows.h>
#include <process.h>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define SIZE 4
#define BORDER 219
#define ESC 27
#define PR 2

int max = 1;
int f = 0;
int r = -1;
int Matrix[SIZE + 1][SIZE + 1] = {0};
int queue[1000000];
int score = 2048, last = 0;

void starting();
void Display();
void print_ever();
void Action(int);
void Random_creator();
void Starting_Random();
int Temp_counter();
void Down();
void Up();
void Left();
void Right();


void starting(){
    printf("=====================2048 GAME===========================");
    printf("\n\n\n\t\t\tINSTRUCTIONS:\n\n\n");
    printf(" -> Enter arrow key to move\n\n");
    printf(" -> For wining this game any one box have value 2048\n\n");
    printf(" -> You have maximum 2048 try to win the game\n\n\n\n");
    printf("\t\t\t\t\t\tPRESS ANY KEY TO PLAY\n");
    while (!kbhit());
}

void Action(int Arrow){
    switch (Arrow){
        case UP:
        {
            Up();
            break;
        }
        case DOWN:{
            Down();
            break;
        }
        case LEFT:
        {
            Left();
            break;
        }
        case RIGHT:
        {
            Right();
            break;
        }
        default:
        {
            return;
        }
    }
    score--;
    Random_creator();
    Display();
}

void Random_creator(){
    int temp1, temp2, add, i, j;

    srand(time(NULL));
    temp1 = rand() % SIZE;   // i
    srand(time(NULL));
    temp2 = rand() % SIZE;   // j

    if ((temp1 + temp2) % 2 == 0)
        add = 2;
    else
        add = 4;

    for (i = 0; i < temp1; i++){
        for (j = temp2; j < SIZE; j++)
        {
            if (Matrix[i][j] == 0)
            {
                Matrix[i][j] = add;
                return;
            }
        }
    }
}

void Display(){
    int i,j;
    system("cls");
    print_ever();
    for(i=0;i<SIZE;i++)
    {
        printf("\t\t\t %c",BORDER);
        for(j=0;j<SIZE;j++)
        {
            if(Matrix[i][j]==0)
            {
                printf("      ");
            }
            else
                printf(" %4d ",Matrix[i][j]);
        }
        printf("%c\n\t\t\t %c                        %c\n",BORDER,BORDER,BORDER);
    }
    printf("\t\t\t %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n",BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER);
}

void print_ever(){
    printf("\n\n\n\t\t\t2048\n");
    printf("\t\t\t\t\t\t\t\t SCORE : %d\n\n\n\n", score);
    printf("\t\t\t %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", BORDER, BORDER, BORDER, BORDER, BORDER, BORDER, BORDER, BORDER, BORDER, BORDER, BORDER, BORDER, BORDER, BORDER, BORDER, BORDER, BORDER, BORDER, BORDER, BORDER, BORDER, BORDER, BORDER, BORDER, BORDER, BORDER);
}

void Starting_Random(){
    Matrix[3][1] = 8;
    Matrix[3][2] = 32;
    Matrix[3][3] = 16;
    Matrix[2][2] = 8;
    Matrix[2][3] = 8;
    Matrix[1][2] = 8;
    Display();
}

int Temp_counter(){
    int temp = 0, i, j;
    if (queue[r] == 2048)
    {
        return 1;
    }

    for (i = 0; i < SIZE; i++){
        for (j = 0; j < SIZE; j++)
        {
            if (Matrix[i][j] >= max)
            {
                max = Matrix[i][j];
                r++;
                queue[r] = Matrix[i][j];
                printf(" Max from matrix is :%d ", queue[r]);
                f++; 
            }

            if (Matrix[i][j] == 0)
                temp = 1;
        }
    }

    if (temp == 1)
    {
        last = 0;
        return (-99);
    }
    else
    {
        if (last == 1)
        {
            return (0);
        }
        last = 1;
        return (-99);
    }
}

void Down(){
    int i, j;
    for (j = 0; j < SIZE; j++)
    {
        i = 2;
        while (1){
            while (Matrix[i][j] == 0)
            {
                if (i == -1)
                    break;
                i--;
            }

            if (i == -1)
                break;
            while (i < SIZE - 1 && (Matrix[i + 1][j] == 0 || Matrix[i][j] == Matrix[i + 1][j]))
            {
                Matrix[i + 1][j] += Matrix[i][j];
                Matrix[i][j] = 0;
                i++;
            }
            i--;
        }
    }
}

void Up(){
    int i, j;
    for (j = 0; j < SIZE; j++)
    {
        i = 1;
        while (1)
        {
            while (Matrix[i][j] == 0)
            {
                if (i == SIZE)
                    break;
                i++;
            }
            if (i == SIZE)
                break;
            while (i > 0 && (Matrix[i - 1][j] == 0 || Matrix[i][j] == Matrix[i - 1][j]))
            {
                Matrix[i - 1][j] += Matrix[i][j];
                Matrix[i][j] = 0;
                i--;
            }
            i++;
        }
    }
}

void Right(){
    int i, j;
    for (i = 0; i < SIZE; i++)
    {
        j = 2;
        while (1)
        {
            while (Matrix[i][j] == 0)
            {
                if (j == -1)
                    break;
                j--;
            }
            if (j == -1)
                break;
            while (j < SIZE - 1 && (Matrix[i][j + 1] == 0 || Matrix[i][j] == Matrix[i][j + 1]))
            {
                Matrix[i][j + 1] += Matrix[i][j];
                Matrix[i][j] = 0;
                j++;
            }
            j--;
        }
    }
}

void Left(){
    int i, j;
    for (i = 0; i < SIZE; i++)
    {
        j = 1; // as we want to move left
        while (1)
        {
            while (Matrix[i][j] == 0)
            {
                if (j == SIZE)
                    break;
                j++;
            }
            if (j == SIZE)
                break;
            while (j > 0 && (Matrix[i][j - 1] == 0 || Matrix[i][j] == Matrix[i][j - 1]))
            {
                Matrix[i][j - 1] += Matrix[i][j];
                Matrix[i][j] = 0;
                j--;
            }
            j++;
        }
    }
}

void main(){
    int aro;
    char Arrow;
    char s[] = "THANKS FOR PLAYING, GOOD LUCK FOR NEXT TIME ";
    int temp;
    starting();
    Starting_Random();
    Arrow = DOWN;
    while (Arrow != ESC) //  HERE IF USER WANT TO EXIT THEN PRESS ESC KEY
    {
        Arrow = getch();
        aro = Arrow;
        Action(Arrow);
        temp = Temp_counter();
        if (temp == 1)
        {
            printf("\n\t\t\tYOU WON");
            break;
        }
        if (temp == 0 || score < 0)
        {
            printf("\n\t\t\tSORRY ! GAME OVER\n");
            break;
        }
    }

    system("cls");
    printf("\n\n\n\t");
    printf("%s",s);
}