#include <stdio.h>
#include <math.h>

double division(double, double);
double modulus(int, int);
void print_menu();
void clear_input_buffer();

int main()
{
    int choice;
    double first, second, result;
    int temp; // Temporary variable to store return value of scanf()

    while (1)
    {
        print_menu();
        temp = scanf("%d", &choice);
        if (temp != 1)
        {
            fprintf(stderr, "Please enter a valid number.\n");
            clear_input_buffer();
            continue;
        }

        if (choice == 7)
            break;
        else if (choice < 1 || choice > 7)
        {
            fprintf(stderr, "Invalid Menu Choice.");
            continue;
        }
        else
        {
            printf("\nPlease enter the first number: ");
            temp = scanf("%lf", &first);
            if (temp != 1)
            {
                fprintf(stderr, "Please enter a valid number.\n");
                clear_input_buffer();
                continue;
            }

            printf("Now, enter the second number: ");
            temp = scanf("%lf", &second);
            if (temp != 1)
            {
                fprintf(stderr, "Please enter a valid number.\n");
                clear_input_buffer();
                continue;
            }

            switch (choice)
            {
            case 1: // Add
                result = first + second;
                break;
            case 2: // Subtract
                result = first - second;
                break;
            case 3: // Multiply
                result = first * second;
                break;
            case 4: // Divide
                result = division(first, second);
                break;
            case 5: // Modulus
                result = modulus(first, second);
                break;
            case 6: // Power
                result = pow(first, second);
                break;
            }
            if (!isnan(result))
            {
                printf("\nResult of operation is: %.2f\n", result);
            }
        }
    }

    return 0;
}

void clear_input_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

double division(double a, double b)
{
    if (b == 0)
    {
        fprintf(stderr, "Invalid Argument for Division");
        return NAN;
    }
    else
    {
        return a / b;
    }
}

double modulus(int a, int b)
{
    if (b == 0)
    {
        fprintf(stderr, "Invalid Argument for Modulus");
        return NAN;
    }
    else
    {
        return a % b;
    }
}

void print_menu()
{
    printf("\n---------------------------------\n");
    printf("Welcome to Simple Calculator");
    printf("\n---------------------------------\n");
    printf("\nChoose one of the following options:");
    printf("\n1. Add");
    printf("\n2. Subtract");
    printf("\n3. Multiply");
    printf("\n4. Divide");
    printf("\n5. Modulus");
    printf("\n6. Power");
    printf("\n7. Exit");
    printf("\nNow, enter your choice: ");
}