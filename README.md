# Mini-Projects-based-on-C
There are 7 mini projects based on C programming language. 

# Simple Calculator in C:
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


# Guess the Number Game:
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


# Digital Clock:
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


## Contributing
If you have suggestions for improvements or find any bugs, please feel free to open an issue or submit a pull request.

