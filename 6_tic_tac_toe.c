// incomplete multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define X 'X'
#define O 'O'

typedef struct
{
    int player;
    int computer;
    int draw;
} Score;

Score score = {0, 0, 0};
int difficulty;

void input_difficulty();                      // takes the difficulty level
void clear_screen();                          // clears the screen by system command call
void print_board(char board[3][3]);           // print the empty board
void play_game();                             // alternates the player, updates score, asks if want to continue?, exits....
int check_win(char board[3][3], char player); // checks if the plyer has won
int check_draw(char board[3][3]);
void player_move(char board[3][3]);   // assigns players move
void computer_move(char board[3][3]); // assigns computers move.
int valid_move(char board[3][3], int row, int col);

int main()
{
    srand(time(NULL)); // time seed
    int choice;
    input_difficulty();
    do
    {
        play_game();
        printf("Play again? (1 for yes, 0 for no): ");
        scanf("%d", &choice);
    } while (choice == 1);
    printf("\nBye Bye, thanks for playing.");
    return 0;
}

void play_game()
{
    // new board is generated when a new game starts
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '},
    };
    // one player is randomly choosed for first move
    char current_player = (rand() % 2 == 0) ? X : O;

    print_board(board);
    // the game continues with alternate player moves till someone wins or the mathc draws.
    while (1)
    {
        if (current_player == X)
        {
            player_move(board); // plaer x 's move
            print_board(board);
            if (check_win(board, X))
            {
                score.player++;
                print_board(board);
                printf("\nCongratulations! you have won.\n");
                break;
            }
            current_player = O; // alternate the move
        }
        else
        {
            computer_move(board); // computers move
            print_board(board);
            if (check_win(board, O))
            {
                score.computer++;
                print_board(board);
                printf("\nYou loose. Try again later.\n");
                break;
            }
            current_player = X;
        }
        if (check_draw(board))
        {
            score.draw++;
            print_board(board);
            printf("\nIt's a draw!\n");
            break;
        }
    }
}

void player_move(char board[3][3])
{
    // directly counting the empty spaces and placing the 'X' if there's only one
    int empty_spaces = 0, x = -1, y = -1;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                empty_spaces++;
                x = i;
                y = j;
            }
        }
    }
    if (empty_spaces == 1)
    {
        board[x][y] = X;
    }

    int row, col;
    do
    {
        printf("\nPlayer X's turn.");
        printf("\nEnter row and column (1-3) for X: ");
        scanf("%d", &row);
        scanf("%d", &col);
        row--;
        col--; // converting to zero based
    } while (!valid_move(board, row, col));

    board[row][col] = X;
}

int valid_move(char board[3][3], int row, int col)
{
    return !(row < 0 || col < 0 ||
             row > 2 || col > 2 ||
             board[row][col] != ' ');
}

void computer_move(char board[3][3])
{
    // 1. play for the winning move.
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                board[i][j] = O;
                if (check_win(board, O))
                {
                    return;
                }
                board[i][j] = ' ';
            }
        }
    }

    // 2. Play for Immediate Block
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                board[i][j] = X;
                if (check_win(board, X))
                {
                    board[i][j] = O;
                    return;
                }
                board[i][j] = ' ';
            }
        }
    }

    if (difficulty == 2)
    {
        // 3. Play Center if available
        if (board[1][1] == ' ')
        {
            board[1][1] = O;
            return;
        }

        // 4. Play Corner if available
        int corner[4][2] = {
            {0, 0},
            {0, 2},
            {2, 0},
            {2, 2}};
        for (int i = 0; i < 4; i++)
        {
            if (board[corner[i][0]][corner[i][1]] == ' ')
            {
                board[corner[i][0]][corner[i][1]] = O;
                return;
            }
        }
    }

    // 5. Play first available move
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                board[i][j] = O;
                return;
            }
        }
    }
}

void print_board(char board[3][3])
{
    clear_screen();
    printf("Score - Player X: %d, Computer: %d, Draw: %d\n", score.player, score.computer, score.draw);
    printf("Tic-Tac-Toe!!!\n");

    for (int i = 0; i < 3; i++)
    {
        printf("\n");
        for (int j = 0; j < 3; j++)
        {
            printf(" %c ", board[i][j]);
            if (j < 3 - 1)
            {
                printf("|");
            }
        }
        if (i < 2)
        {
            printf("\n---+---+---");
        }
    }
    printf("\n");
}

int check_win(char board[3][3], char player)
{
    for (int i = 0; i < 3; i++)
    {
        // horizontally / columnwise
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return 1;
        // vertically / row wise
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return 1;
        // diagonally
        if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) || (board[2][0] == player && board[1][1] == player && board[0][2] == player))
            return 1;
    }
    return 0;
}

int check_draw(char board[3][3])
{
    // check if not win and the board is not empty then draw if board is empty at any place
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
                return 0;
        }
    }
    return 1; // if all the spaces are filled then draw.
}

void input_difficulty()
{
    while (1)
    {
        printf("Select difficulty level:\n");
        printf("1. Human mode.\n");
        printf("2. God mode(impossible to win).\n");
        printf("Enter your choice: ");
        scanf("%d", &difficulty);

        if (difficulty != 1 && difficulty != 2)
            printf("Incorrect choice enter (1/2)!!!\n");
        else
            break; // takes 1 or 2 as input and breaks otherwise goes with infinite loop.
    }
}

void clear_screen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}