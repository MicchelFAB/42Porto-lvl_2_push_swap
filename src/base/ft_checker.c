/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 23:04:41 by mamaral-          #+#    #+#             */
/*   Updated: 2023/05/25 15:37:22 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_check.h"

/* ft_checker() function that checks if the stack is sorted.	*/

int	ft_checker(t_stack s, char c)
{
	if (s.len == 0)
		return (1);
	while (--s.len > 0)
	{
		if (s.stack[s.len - 1] > s.stack[s.len] && c == 'a')
			return (0);
		if (s.stack[s.len - 1] < s.stack[s.len] && c == 'd')
			return (0);
	}
	return (1);
}

/* ft_do_operation() function that executes	*
the instructions given by the user.			*/

void	ft_do_operation(t_check *instruct, char *ln, int i)
{
	if (!ft_strncmp(ln, "pa\n", i))
		ft_push(&instruct->b, &instruct->a);
	if (!ft_strncmp(ln, "pb\n", i))
		ft_push(&instruct->a, &instruct->b);
	if (!ft_strncmp(ln, "sa\n", i) || !ft_strncmp(ln, "ss\n", i))
		ft_swap(&instruct->a.stack[0], &instruct->a.stack[1]);
	if (!ft_strncmp(ln, "sb\n", i) || !ft_strncmp(ln, "ss\n", i))
		ft_swap(&instruct->b.stack[0], &instruct->b.stack[1]);
	if (!ft_strncmp(ln, "ra\n", i) || !ft_strncmp(ln, "rr\n", i))
		ft_rotate(instruct->a);
	if (!ft_strncmp(ln, "rb\n", i) || !ft_strncmp(ln, "rr\n", i))
		ft_rotate(instruct->b);
	if (!ft_strncmp(ln, "rra\n", i) || !ft_strncmp(ln, "rrr\n", i))
		ft_reverse_rotate(instruct->a);
	if (!ft_strncmp(ln, "rrb\n", i) || !ft_strncmp(ln, "rrr\n", i))
		ft_reverse_rotate(instruct->b);
}

/* ft_send_moves() function that send the moves to the stack, if the	*
 * move in not found in the list of moves, the program will call 		*
 * ft_error() function and exit the program.							*/

void	ft_send_moves(char *ln, t_check *instruct)
{
	instruct->i = 0;
	while (ln[instruct->i])
	{	
		if ((ln[instruct->i] >= 'A' && ln[instruct->i] <= 'Z'))
			ln[instruct->i] = ln[instruct->i] + 32;
		instruct->i++;
	}
	instruct->i = 3;
	if ((!ft_strncmp(ln, "pb\n", instruct->i)
			|| !ft_strncmp(ln, "sa\n", 3) || !ft_strncmp(ln, "ra\n", 3)
			|| !ft_strncmp(ln, "rra\n", 4)) && instruct->a.len > 0)
		ft_do_operation(instruct, ln, 3);
	else if ((!ft_strncmp(ln, "pa\n", 3) || !ft_strncmp(ln, "sb\n", 3)
			|| !ft_strncmp(ln, "rb\n", 3) || !ft_strncmp(ln, "rrb\n", 4))
		&& instruct->b.len > 0)
		ft_do_operation(instruct, ln, 3);
	else if ((!ft_strncmp(ln, "ss\n", 3) || !ft_strncmp(ln, "rr\n", 3)
			|| !ft_strncmp(ln, "rrr\n", 4)) && (instruct->a.len > 0
			&& instruct->b.len > 0))
		ft_do_operation(instruct, ln, 3);
	else
	{
		ft_exit_error();
	}
}

/* ft_process_moves() function will read the movements from the		*
 * terminal and will send them to the ft_send_moves() function.		*
 * It will also check if the stack is sorted and will print OK or 	*
 * KO, depending on the result. If the movement name is not valid,	*
 * it will exit the program.										*/

void	ft_process_moves(t_check *inst)
{
	char	*ln;
	char	*c;

	ln = ft_calloc(1, 1);
	c = ft_calloc(2, 1);
	while (read(0, c, 1) > 0)
	{
		ln = ft_strjoin(ln, ft_strdup(c));
		if (*c == '\n')
		{
			ft_send_moves(ln, inst);
			free(ln);
			ln = ft_calloc(1, 1);
		}
	}
	if (*ln != '\0')
		ft_send_moves(ln, inst);
	free(ln);
	free(c);
	if (ft_checker(inst->a, 'a') && inst->b.len == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

/* main() function will receive the arguments from the terminal to	*
 * check if a group of movements will sort the stack. It starts by	*
 * checking if the arguments are valid, then it will create a		*
 * structure to store the stacks and the length of each one.		*
 * After that, it will store the arguments in the stack A and		*
 * finally it will start the process of checking the movements.		*/

int	main(int argc, char **argv)
{
	t_check	check;
	int		i;

	if (argc == 1)
		exit(1);
	ft_all_good(argc, argv);
	check.a.stack = ft_calloc(argc - 1, sizeof(long));
	check.b.stack = ft_calloc(argc - 1, sizeof(long));
	i = 0;
	while (++i < argc)
		check.a.stack[i - 1] = ft_atol(argv[i]);
	check.a.len = argc - 1;
	check.b.len = 0;
	ft_process_moves(&check);
	return (0);
}
