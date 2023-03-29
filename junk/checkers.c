#include "../push_swap.h"

/*
int ft_check_char(char *str) // check if the string is an integer positive or negative
{
    int i = 0;
    int sign = 0;

    if (str[0] == '-') // check if the string is negative
    {
        sign = 1; // if it is, set sign to 1
        i++;
    }

    while (str[i]) // check if the string is an integer
    {
        if (str[i] < '0' || str[i] > '9') // if the string is out of range of an integer
        {
            return (1); // return 1
        }
        i++;
    }

    if (sign && i == 1) // now we check if the string is just a negative sign
    {
        return (1); // if it is, return 1
    }

    return (0); // if it is not, return 0
}

int ft_check_double(int argc, char **argv) // check if there are any duplicate integers in the stack
{
    int i = 1;
    while (i < argc)
    {
        int num1 = ft_atoi(argv[i]);
        int j = i + 1;
        while (j < argc)
        {
            int num2 = ft_atoi(argv[j]);
            if (num1 == num2)
            {
                printf("Duplicate found: %d at indices %d and %d\n", num1, i, j);
                return (1);
            }
            j++;
        }
        i++;
    }
    return (0);
}

int ft_check_stack(int *a, int len)
{
    int i;
    i = 0;
    while (i < len)
    {
        if (a[i] > 2147483647 || a[i] < -2147483648)
            return (0);
        i++;
    }
    return (1);
}

int main(int argc, char **argv)
{
    int i = 1;
    int *a;

    a = (int*)malloc(sizeof(int) * (argc-1));
    while (i < argc)
    {
        if (ft_check_char(argv[i]) == 1)
        {
            printf("Error: Argument %d is not an integer\n", i);
            free(a);
            return (1);
        }
        a[i-1] = ft_atoi(argv[i]);
        if (ft_check_double(argc, argv) == 1)
        {
            printf("Error: Duplicate integer found\n");
            free(a);
            return (0);
        }
        i++;
    }

    if (!ft_check_stack(a, argc - 1))
    {
        printf("Error: Argument out of int range\n");
        free(a);
        return (1);
    }

    printf("Input stack:\n");
    i = 0;
    while (i < argc - 1)
    {
        printf("%d ", a[i]);
        i++;
    }
    
    free(a);
    return (0);
}
 */

#include <unistd.h>
#include <stdlib.h>


int is_valid_argument(const char *arg)
{
    size_t len = ft_strlen(arg);
    int i = 0;

    if (len == 0)
        return (0);
    if (arg[i] == '-' || arg[i] == '+')
    {
        if (len == 1)
            return (0);
        i++;
    }
    while (arg[i] != '\0')
    {
        if (!ft_isdigit(arg[i]))
            return (0);
        i++;
    }
    return (1);
}

int is_within_integer_limits(const char *arg) // check if the string value is within the limits of an integer
{
	long long num = ft_atol(arg); // convert the string to a long long integer

	if (num > 2147483647 || num < -2147483648) // check if the integer is greater than the max value of an integer or less than the min value of an integer
		return (0);
	return (1);
}

int is_within_stack_limits(const int *stack, int len) // check if the stack is within the limits of an integer
{
	int i = 0;

	while (i < len) // loop through the stack
	{
		if (stack[i] > 2147483647 || stack[i] < -2147483648) // check if the integer is greater than the max value of an integer or less than the min value of an integer
			return (0);
		i++;
	}
	return (1);
}
/* 
int main(int argc, char **argv)
{
    int i;

    i = 1;
    while (i < argc)
    {
        if (!is_valid_argument(argv[i]))
        {
            write(2, "Error\n", 6);
            exit(1);
        }
        i++;
    }
	printf("stack a: \n");
    for (int j = 0; j < argc; j++)
        printf("%s\n", argv[j]);

    // continue with your Push_swap program
    return (0);
}
 */
#include <stdio.h>
#include <limits.h>

int is_within_stack_limits(const int *stack, int len);
int is_within_integer_limits(const char *arg);

int main()
{
    int stack[] = {INT_MIN, -500, -1, 0, 1, 500, INT_MAX};
    int len = sizeof(stack) / sizeof(*stack);

    const char *int_values[] = {"-2147483649", "-2147483648", "-1000", "-1", "0", "1", "1000", "2147483647", "2147483648"};
    int int_values_len = sizeof(int_values) / sizeof(*int_values);

    printf("is_within_stack_limits:\n");
    for (int i = 0; i < len; i++)
        printf("%d: %d\n", stack[i], is_within_stack_limits(&stack[i], 1));

    printf("\nis_within_integer_limits:\n");
    for (int i = 0; i < int_values_len; i++)
        printf("%s: %d\n", int_values[i], is_within_integer_limits(int_values[i]));

    return 0;
}
