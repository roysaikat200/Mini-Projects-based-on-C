#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define max_question_len 500
#define max_option_len 300

const char *COLOR_END = "\033[0m";
const char *RED = "\033[1;31m";
const char *GREEN = "\033[1;32m";
const char *YELLOW = "\033[1;33m";
const char *BLUE = "\033[1;34m";
const char *PINK = "\033[1;35m";
const char *AQUA = "\033[1;36m";

typedef struct
{
    char text[max_question_len];
    char options[4][max_option_len];
    char answer;
    int prize_money;
} Question;

int get_question(Question **);
void print_question(Question);
void play_game(Question *questions, int no_of_questions);
char check_option(char ch);
int use_lifeline(Question *questions, int *);

int main()
{
    srand(time(NULL));
    printf("\t\t%sToh Chaliye Suru Karte hai Ye advut Khela Jiska Naam Hai KAUN BANEGA CARORPATI!!!%s\n\n\n", PINK, COLOR_END);

    Question *questions;
    int no_of_questions = get_question(&questions);

    play_game(questions, no_of_questions);

    free(questions);
    return 0;
}

void play_game(Question *questions, int no_of_questions)
{
    int money_win = 0;
    int life_lines[2] = {1, 1};

    for (int i = 0; i < no_of_questions; i++)
    {
        // prints the question
        print_question(questions[i]);
        // takes input character
        char ch;
        printf("%sEnter your answer (A, B, C, or D) or L for lifeline:%s\n", YELLOW, COLOR_END);
        scanf(" %c", &ch); // Adding a space before %c to consume the leftover newline
        ch = check_option(ch);

        if (ch == 'L')
        {
            int value = use_lifeline(&questions[i], life_lines);
            if (value == 1)
                continue;
            else if (value == 2){
                i--;
                continue;
            }
            else{
                i--;
                continue;
            }
        }
        if (ch == questions[i].answer)
        {
            printf("%sCORRECT!!!\n%s", GREEN, COLOR_END);
            money_win += questions[i].prize_money;
            printf("%sYou have won %d rupees.\n%s", BLUE, money_win, COLOR_END);
        }
        else
        {
            printf("%sWrong!!! The correct option is %c.%s\n", RED, questions[i].answer, COLOR_END);
            break;
        }
    }
    printf("\n\n%sGame over!!! Your total winnings are: Rs %d%s\n", BLUE, money_win, COLOR_END);
}

int use_lifeline(Question *questions, int *life_line)
{
    printf("\n%sAvailable Lifelines:%s", PINK, COLOR_END);
    if (life_line[0])printf("\n%s1. Fifty-Fifty (50/50)%s", BLUE, COLOR_END);
    if (life_line[1]) printf("\n%s2. Skip the Question%s", BLUE, COLOR_END);
    printf("\n%sChoose a lifeline or 0 to return: %s", PINK, COLOR_END);

    char ch;
    scanf(" %c", &ch); // Changed to scanf to properly read the input

    switch (ch)
    {
    case '1': // 50 50 
        if (life_line[0])
        {
            life_line[0] = 0;
            int removed = 0;
            while (removed < 2)
            {
                int num = rand() % 4;
                if (num + 'A' != questions->answer && questions->options[num][0] != '\0') // Fixed comparison
                {
                    questions->options[num][0] = '\0';
                    removed++;
                }
            }
            return 2;
        }
        break;
    case '2': // skip the question
        if (life_line[1])
        {
            life_line[1] = 0;
            return 1;
        }
        break;
    default:
        printf("\nReturning to the question.\n");
        break;
    }
    return 0;
}

int get_question(Question **questions)
{
    FILE *fp = fopen("questions.txt", "r"); // File opened with file pointer fp in read only mode
    // If the file is empty then exits with a message
    if (fp == NULL)
    {
        printf("Unable to open the question bank.\n");
        exit(0);
    }

    char str[max_question_len];
    int no_of_lines = 0;

    while (fgets(str, max_question_len, fp)) // iterates through all the lines and calculates the total number of lines in the file
        no_of_lines++;

    int no_of_questions = no_of_lines / 7;
    *questions = (Question *)malloc(no_of_questions * sizeof(Question));

    rewind(fp); // Starting of the file

    for (int i = 0; i < no_of_questions; i++)
    {
        // Reads the question
        fgets((*questions)[i].text, max_question_len, fp);

        // Reads the options
        for (int j = 0; j < 4; j++)
            fgets((*questions)[i].options[j], max_option_len, fp);

        // Correct option as answer
        (*questions)[i].answer = fgetc(fp);
        fgetc(fp); // to consume the new line after the character input

        // Prize money
        fgets(str, sizeof(str), fp);
        (*questions)[i].prize_money = atoi(str);
    }

    fclose(fp);
    return no_of_questions;
}

void print_question(Question question)
{
    printf("\n%sQ.%s%s", YELLOW, question.text, COLOR_END);
    for (int i = 0; i < 4; i++)
    {
        if (question.options[i][0] != '\0') // Only print non-removed options
        {
            printf("%s%c.%s%s", AQUA, ('A' + i), question.options[i], COLOR_END);
        }
    }
}

char check_option(char ch)
{
    if (ch == 'a' || ch == 'A')
        return 'A';
    if (ch == 'b' || ch == 'B')
        return 'B';
    if (ch == 'c' || ch == 'C')
        return 'C';
    if (ch == 'd' || ch == 'D')
        return 'D';
    if (ch == 'l' || ch == 'L')
        return 'L';

    printf("Please enter a valid option!!!\n");
    char temp;
    scanf(" %c", &temp);
    return check_option(temp);
}
