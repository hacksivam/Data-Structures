#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

//Global Variable
char pname[20];
char op[] = {'r', 'p', 's'};
int pturn, cturn;
int count=1;

void menu();
void rules();
void game();
void board();

void fordelay(int j)
{
    int i,k;
    for(i=0; i<j; i++)
    k=i;
}

int gen_rand_num()
{
    srand(time(NULL));
    return rand()%3+1;
}

void board()
{
    system("cls");
    system("color F4");
    FILE *ptr;
    ptr=fopen("boards.dat","r");
    char ch;
    do
    {
        ch=fgetc(ptr);
        printf("%c", ch);
    }while(ch!=EOF);
    printf("\nPress 1 for returning to Main Menu...\n");
    int press;
    scanf("%d", &press);
    if(press==1)
    menu(); 
}

void game()
{
    
    system("cls");
    system("color A3");
    printf("\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Welcome to R.P.S Game - Player VS CPU Mode \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("Player's Name: %s\n", pname);
    printf("\nInitial Score: \nCPU - > 0\n%s - > 0\n", pname);
    int pscore, cscore;
    pscore=0;
    cscore=0;
    for(int i=0; i<3; i++)
    {
        printf("%s's Turn : ", pname);
        scanf("%d", &pturn);
        printf("%s's Chose: %c\n", pname, op[pturn-1]);
        cturn= gen_rand_num();
        printf("CPU's Turn : %d\n", cturn);
        printf("CPU Chose: %c\n", op[cturn-1]);
        if(pturn==1)
        {
            if(cturn==1)
            {
                printf("\nIt's a Draw.\nNo Increment in Points.\n");
            }
            else if(cturn==2)
            {
                cscore++;
            }
            else if(cturn==3)
            {
                pscore++;
            }
        }
        else if(pturn==2)
        {
            if(cturn==1)
            {
                pscore++;
            }
            else if(cturn==2)
            {
                printf("\nIt's a Draw.\nNo Increment in Points.\n");
            }
            else if(cturn==3)
            {
                cscore++;
            }
        }
        else if(pturn==3)
        {
            if(cturn==1)
            {
                cscore++;
            }
            else if(cturn==2)
            {
                pscore++;
            }
            else if(cturn==3)
            {
                printf("\nIt's a Draw.\nNo Increment in Points.\n");
            }
        }
        printf("\n\n\xB2\xB2\xB2\xB2ScoreBoard\xB2\xB2\xB2\xB2\n");
        printf("%s's Score: %d\nCPU's Score: %d\n\n", pname, pscore, cscore);
    }
    if(pscore>cscore)
    {
        printf("%s Wins",pname);
    }
    else if(pscore<cscore)
    {
        printf("CPU Wins");
    }
    else
    {
        printf("It's a Draw\nNO WINS");
    }
    FILE *ptr;
    // ptr=fopen("boards.txt", "a+");
    ptr=fopen("boards.dat", "a+");
        fprintf(ptr,"Score Board\nPlayer Score\t\t\t\tCPU Score\n");
        fprintf(ptr,"%d\t\t\t\t\t\t\t\t\t",pscore);
        fprintf(ptr,"%d\n",cscore);
        fclose(ptr);
    printf("\nThanks For Playing.\n");
    printf("\nPress 1 for returning to Main Menu...\n");
    int press;
    scanf("%d", &press);
    if(press==1)
    menu(); 
}

void rules()
{
    system("cls");
    system("color F3");
    puts("\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 RULES FOR THE GAME \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    puts("Description: Rock Paper Scissors is a zero sum game that is usually played by two people using their hands and no tools. The idea is to make shapes with an outstretched hand where each shape will have a certain degree of power and will lead to an outcome.\n\nThis game is played by children and adults and is popular all over the world. Apart from being a game played to pass time, the game is usually played in situations where something has to be chosen. It is similar in that way to other games like flipping the coin, throwing dice or drawing straws. There is no room for cheating or for knowing what the other person is going to do so the results are usually very satisfying with no room for fighting or error.\n\nAlthough the game has a lot of complexity to it, the rules to play it are pretty simple.The game is played where players deliver hand signals that will represent the elements of the game; rock, paper and scissors. The outcome of the game is determined by 3 simple rules:\n\t\t\t\t1. Rock wins against scissors.\n\t\t\t\t2. Scissors win against paper.\n\t\t\t\t3. Paper wins against rock.\n\n\n\nSource: https://wrpsa.com/the-official-rules-of-rock-paper-scissors/\nIn this game For Playing ...\n1. Press '1' for \"Rock\"\n2. Press '2' for \"Paper\"\n3. Press '3' for \"Scissors\"\nThis game is only for Player vs CPU, In this there are three chances for complete win. If Player Score is greater than CPU then Player wins otherwise CPU wins.\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Thanks and Enjoy the Game. \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("Press 1 for returning to Main Menu...\n");
    int press;
    scanf("%d", &press);
    if(press==1)
    menu(); 
}

void menu()
{
    system("cls");
    system("color B4");
    printf("\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO ROCK PAPER & SCISSORS GAME \xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\n\t\t1.Start Game\n\n\t\t2.Rules\n\n\t\t3.ScoreBoard\n\n\t\t4.Exit\n\n");
    printf("Enter your Choice.\n");
    int choice;
    scanf("%d", &choice);
    while(1)
    {
        switch(choice)
        {
            case 1:
                game();
                break;
            case 2:
                rules();
                break;
            case 3:
                board();
                break;
            case 4:
                printf("Thank You For Using The Program.");
                exit(0);
            default:
                printf("Please Chose Valid Option.\n");
                break;
        }
        printf("Enter your Choice.\n");
        scanf("%d", &choice);
    }
}

//Main Function...
int main()
{
    char passcode[10], password[10]="ilove_rps";
    system("cls");
    for(int j=2; j>=0; j--)
    {
        printf("\xB2\xB2\xB2\xB2\xB2\xB2 LogIn Info \xB2\xB2\xB2\xB2\xB2\xB2\n");
        printf("Enter your Name: ");
        scanf("%s", &pname);
        getchar();
        printf("\nEnter the Login Password ");
        scanf("%s", &passcode);
        if(strcmp(passcode, password)==0)
        {
            printf("\n*** PassCode Recognized ***\n");
            printf("Loading ");
            for(int i=0; i<=10; i++)
            {
                fordelay(100000000);
                printf(".");
            }
            menu();
            break;
        }
        else
        {
            printf("Password Not Recognzed.\n");
            printf("You have only %d Attempts Left.\n", j);
        }
        fordelay(100000000);
        system("cls");
    }
        return 0;
} 
