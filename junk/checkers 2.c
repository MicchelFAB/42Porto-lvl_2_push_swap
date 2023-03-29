#include "../push_swap.h"

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
 
int main(int argc, char **argv)
{
    int i;

    i = 1;
    while (i < argc)
    {
        if (ft_check_int(argv[i]))
        {
            write(2, "Error\n", 6);
            exit(1);
        }
        i++;
    }
	printf("stack a: \n");
    for (int j = 1; j < argc; j++)
        printf("%s ", argv[j]);

    // continue with your Push_swap program
    return (0);
}
/* 
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
 */