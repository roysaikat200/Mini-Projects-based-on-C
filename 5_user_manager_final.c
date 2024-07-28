#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <conio.h>
#else
#include <unistd.h>
#include <termios.h>
#endif

#define MAX_USERS 10
#define CREDENTIAL_LENGTH 30

typedef struct
{
  char username[CREDENTIAL_LENGTH];
  char password[CREDENTIAL_LENGTH];
} User;

User users[MAX_USERS];
int user_count = 0;

void register_user();
int login_user(); // returns the user index
int delete_account();
void fix_fgets_input(char *);
void input_credentials(char *username, char *password);

int main()
{
  int option;
  int user_index;
  while (1)
  {
    printf("\nWelcome to User Management");
    printf("\n1. Register");
    printf("\n2. Login");
    printf("\n3. Delete");
    printf("\n4. Exit");
    printf("\nSelect an option: ");
    if (scanf("%d", &option) != 1)
    {
      printf("\nInvalid input. Please enter a number.\n");
      while (getchar() != '\n')
        ; // Clear invalid input from stdin
      continue;
    }
    getchar(); // Consume extra enter

    switch (option)
    {
    case 1:
      register_user();
      printf("Total number of current users: %d\n", user_count);
      break;
    case 2:
      user_index = login_user();
      if (user_index  == -1) 
        printf("\nNo user have registed yet.\n");
      else if ( user_index == -2)
        printf("\nLogin failed! Incorrect username or password.\n");
      else
        printf("\nLogin successful! Welcome, %s!\n", users[user_index].username);
      break;
    case 3:
      user_index = delete_account();
      if (user_index == -1)
        printf("\nNo user have registed yet.\n");
      else if (user_index == -2)
        printf("\nDeleting process failed!!! Please enter valid username or password.\n");
      else
      {
        printf("\nSuccessfully deleted account with username %s\n", users[user_index].username);
        for (int i = user_index; i < user_count - 1; i++)
        {
          users[i] = users[i + 1];
        }
        user_count--;
      }
      break;
    case 4:
      printf("\nExiting Program.\n");
      return 0;
    default:
      printf("\nInvalid option. Please try again.\n");
      break;
    }
  }
  return 0;
}

void register_user()
{
  if (user_count == MAX_USERS)
  {
    printf("\nMaximum %d users are supported! No more registrations allowed!\n", MAX_USERS);
    return;
  }

  int new_index = user_count;
  printf("\nRegister a new user.");
  input_credentials(users[new_index].username, users[new_index].password);
  for (int i = 0; i < user_count; i++)
  {
    if (strcmp(users[user_count].username, users[i].username) == 0)
    {
      printf("\nUsername exists, try again with another username.\n");
      return;
    }
  }
  user_count++;
  printf("\nRegistration successful!\n");
}

int login_user()
{
  if (user_count == 0)
    return -1;

  char username[CREDENTIAL_LENGTH];
  char password[CREDENTIAL_LENGTH];
  printf("\nLogging you in.");
  input_credentials(username, password);

  for (int i = 0; i < user_count; i++)
  {
    if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0)
      return i;
  }
  return -2;
}
int delete_account()
{
  if (user_count == 0)
    return -1;

  char temp_username[CREDENTIAL_LENGTH];
  char temp_password[CREDENTIAL_LENGTH];
  printf("\nDeleting your account.");
  input_credentials(temp_username, temp_password);

  for (int i = 0; i < user_count; i++)
  {
    if (strcmp(temp_username, users[i].username) == 0 && strcmp(temp_password, users[i].password) == 0)
      return i;
  }
  return -2;
}


void input_credentials(char *username, char *password)
{
  printf("\nEnter username: ");
  fgets(username, CREDENTIAL_LENGTH, stdin);
  fix_fgets_input(username);
  printf("Enter password (masking enabled): ");
  fflush(stdout);

#ifdef _WIN32
  char ch;
  int i = 0;
  while ((ch = _getch()) != '\r' && ch != EOF)
  {
    if (ch == '\b' || ch == 127)
    {
      if (i > 0)
      {
        i--;
        printf("\b \b");
      }
    }
    else
    {
      if (i < CREDENTIAL_LENGTH - 1)
      {
        password[i++] = ch;
        printf("*");
      }
    }
  }
  password[i] = '\0';
#else
  struct termios old_props, new_props;
  tcgetattr(STDIN_FILENO, &old_props);
  new_props = old_props;
  new_props.c_lflag &= ~(ECHO | ICANON);
  tcsetattr(STDIN_FILENO, TCSANOW, &new_props);

  char ch;
  int i = 0;
  while ((ch = getchar()) != '\n' && ch != EOF)
  {
    if (ch == '\b' || ch == 127)
    {
      if (i > 0)
      {
        i--;
        printf("\b \b");
      }
    }
    else
    {
      if (i < CREDENTIAL_LENGTH - 1)
      {
        password[i++] = ch;
        printf("*");
      }
    }
  }
  password[i] = '\0';
  tcsetattr(STDIN_FILENO, TCSANOW, &old_props);
#endif
  printf("\n"); // Move to the next line after password input
}

void fix_fgets_input(char *string)
{
  int index = strcspn(string, "\n");
  string[index] = '\0';
}