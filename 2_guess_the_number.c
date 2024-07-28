#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void clear_input_buffer();

int main()
{
    int guessed_number, random_number, no_of_guesses = 0;
    srand(time(NULL));

    printf("\n!!!Welcome to guess the number game!!!\n");
    random_number = rand() % 100 + 1;
    do{
        int temp;
        printf("Please guess a number between 0 to 100: ");
        temp = scanf("%d", &guessed_number);
        if (temp != 1)
        {
            fprintf(stderr, "Please enter a valid number.\n");
            clear_input_buffer();
            continue;
        }
        no_of_guesses++;
        if(guessed_number < 0 || guessed_number > 100){
            printf("Invalid !!! Choose a number between 0 to 100.\n");
        }else if(guessed_number > random_number){
            printf("Please enter a lower number.\n");
        }else if (guessed_number < random_number){
            printf("Please enter a higher number.\n");
        }else{
            printf("\nCongratulations !!!You have successfully guessed the number in %d attempts.", no_of_guesses);
        }
    }while(guessed_number != random_number);

    printf("\nThanks for playing!!!");
    return 0;
}

void clear_input_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}