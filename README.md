# Mini-Projects-based-on-C
There are 7 mini projects based on C programming language. 

# 1. Simple Calculator in C:
Introduction

Introduction This is a simple calculator program written in C that performs basic arithmetic operations. The program provides a menu-driven interface to the user for selecting operations such as addition, subtraction, multiplication, division, modulus, and power.


## Deployment

Compile the Program:
```bash
gcc -o simple_calculator 1_simple_calculator.c -lm
```

Run the Program:
```bash
simple_calculator.exe
```


##

1. The program will display a menu with options for various operations. 
2. Enter the corresponding number for the desired operation. 
3. Input the numbers as prompted. 
4. The result of the operation will be displayed.


# 2. Guess the Number Game:
_Introduction_

This is a simple number guessing game written in C. The program generates a random number between 1 and 100, and the user is prompted to guess the number. After each guess, the program provides feedback on whether the guessed number is too high, too low, or correct. The game continues until the user guesses the correct number.


## Deployment

Compile the Program:
```bash
gcc -o guess_the_number guess_the_number.c
```

Run the Program:
```bash
guess_the_number.exe
```


# 3. Digital Clock:
_Introduction_

This is a digital clock program written in C that displays the current time and date. The clock can operate in either 24-hour or 12-hour format, updating every second. It leverages various C standard libraries to achieve its functionality.

## Deployment

Compile the Program:
```bash
gcc -o digital_clock digital_clock.c
```

Run the Program:
```bash
digital_clock.exe
```


##
_Features :_

- Real-Time Clock: Continuously displays the current time and date, updating every second.
- Time Format Options: Allows the user to choose between 24-hour and 12-hour time formats.
- Clear Screen: Clears the terminal screen before updating the time, providing a seamless clock display.
- Cross-Platform Compatibility: Uses conditional compilation to ensure compatibility with both Windows and Unix-like systems.
## Future Scope

- Customization Options: Add options for customizing the date and time format.
- Alarm Feature: Implement an alarm feature that allows users to set alarms.
- GUI Version: Develop a graphical user interface (GUI) version of the clock using libraries like GTK or Qt.
- Timezone Support: Allow users to display the time for different time zones.
##
This digital clock program is a practical example of using C standard libraries for time manipulation and user interaction. It demonstrates the use of conditional compilation for cross-platform compatibility and provides a foundation for further enhancements.


# 4. Progress Bar:
_Introduction_

This program demonstrates a simple progress bar implementation in C. It simulates the progress of multiple tasks, updating the progress bars for each task every second until all tasks are complete.

## Deployment

Compile the Program:
```bash
gcc -o progress_bar progress_bar.c
```

Run the Program:
```bash
progress_bar.exe
```


##
_Features :_

- Multiple Tasks: Simulates multiple tasks, each with its own progress bar.
- Random Step Increments: Each task progresses at a different rate, with random increments.
- Dynamic Display: Continuously updates the display to show the current progress of each task.
- Clear Screen: Clears the terminal screen before each update to provide a seamless progress bar display.
- Cross-Platform Compatibility: Uses conditional compilation to ensure compatibility with both Windows and Unix-like systems.
## 
_Future Scope:_

- Customization Options: Add options for customizing the date and time format.
- Alarm Feature: Implement an alarm feature that allows users to set alarms.
- GUI Version: Develop a graphical user interface (GUI) version of the clock using libraries like GTK or Qt.
- Timezone Support: Allow users to display the time for different time zones.

##
This progress bar program is a practical example of using C standard libraries for simulating task progress and dynamically updating the display. It demonstrates the use of conditional compilation for cross-platform compatibility and serves as a foundation for further enhancements.


# 5. User Management System:
_Introduction_

This project is a simple user management system written in C. It allows users to register, log in, and delete accounts. The system uses standard input/output functions and handles various aspects of user authentication.
## 
_Deployment_
```bash
gcc -o user_manager 5_user_manager_final.c
./user_manager   # For Unix/Linux
user_manager.exe # For Windows
```

##
_Features :_

- User Registration: Users can create an account by providing a username and password.
- User Login: Users can log in with their registered credentials.
- Account Deletion: Users can delete their accounts by providing their credentials.
- Input Handling: Properly handles and sanitizes user input to ensure robust functionality.
- Password Masking: Implements password masking during input for enhanced security.
- Input validation is performed to ensure the entered values are correct.
- Proper feedback is provided to the user in case of incorrect inputs or operations.

##


# 6. Tic-Tac-Toe Game
_Introduction_

This is a simple command-line based Tic-Tac-Toe game written in C. The game allows a player to compete against the computer with two difficulty levels: Human mode and God mode (impossible to win).



### Features
- Two difficulty levels:

    Human mode: The computer makes random moves.

    God mode: The computer plays optimally, making it impossible to win. (You can either draw or loose).
- Keeps track of scores between the player and the computer.
- Displays the game board after each move.
- Asks if the player wants to play again after each game.


### Deployment

Compile the code: 
```bash
gcc -o tic_tac_toe 6_tic_tac_toe.c
```

Run the code: 
```bash
6_tic_tac_toe.exe
```
### How to Play

1. Select the difficulty level:
- Enter 1 for Human mode.
- Enter 2 for God mode.

2. The game randomly selects which player goes first.

3. Enter the row and column numbers to make your move. The rows and columns are indexed from 0 to 2.

4. The game alternates between the player and the computer until someone wins or the game is a draw.

5. After the game ends, you can choose to play again or exit.



#### Error Handling: 
- Ensures valid input for difficulty selection.
- Validates player moves to ensure they are within bounds and the chosen cell is empty.
- Re-prompts for input if invalid moves are made.


##

## Contributing
If you have suggestions for improvements or find any bugs, please feel free to open an issue or submit a pull request.


