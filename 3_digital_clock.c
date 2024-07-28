#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void fill_time(char *, int); // fills the time using time.h library
void fill_date(char *);      // fills the time using time.h library
void clear_screen();         // clears the terminal when the code is executed

int main()
{
    char time[50], date[100];

    // taking input of the format
    int format;
    printf("Choose the time format:\n");
    printf("1. 24 hour format (default)\n");
    printf("2. 12 hour format\n");
    printf("Make a choice(1/2): ");
    scanf("%d", &format);

    while (1)
    {
        fill_time(time, format); // fill the format of time
        fill_date(date);         // fill the format of date
        clear_screen();          //clear the screen
        printf("Current Time: %s\n", time);
        printf("Date: %s\n", date);
        sleep(1);                // sleep for 1 sec and show the cureent time ( it basically gives one sec time interval before printing the updated time)
    }

    return 0;
}

void clear_screen(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void fill_time(char *buffer, int format)
{
    time_t raw_time; // veriable declaration of raw time
    struct tm *current_time;

    time(&raw_time);                     // seeding the current time
    current_time = localtime(&raw_time); // define time zone.
    if (format == 1)
    {
        strftime(buffer, 50, "%H:%M:%S", current_time);
    }
    else
    {
        strftime(buffer, 50, "%I:%M:%S %p", current_time);
    }
}

void fill_date(char *buffer)
{
    time_t raw_time; // veriable declaration of raw time
    struct tm *current_time;

    time(&raw_time);                     // seeding the current time
    current_time = localtime(&raw_time); // define time zone.
    strftime(buffer, 100, "%A %d %B %Y\n", current_time);
}