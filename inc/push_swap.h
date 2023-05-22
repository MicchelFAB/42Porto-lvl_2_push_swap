/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:43:18 by mamaral-          #+#    #+#             */
/*   Updated: 2023/05/22 16:01:27 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_base
{
	int	min;
	int	min_pos;
	int	max;
	int	*tmp;
	int	*tpm;
	int	result;
	int	first;
	int	last;
	int	j;
	int	i;
}t_base;

typedef struct s_stack
{
	int		*stack;
	int		len;
	t_base	base;
	int		*moves;
}t_stack;

typedef struct s_stash
{
	t_stack	a;
	t_stack	b;
}t_stash;

// function that execute rotation of the stack
void			ft_rotate(t_stack stack);
void			ft_ra(t_stash a);
void			ft_rb(t_stash b);
void			ft_rr(t_stash ab);

// function that execute reverse rotation of the stack
void			ft_reverse_rotate(t_stack stack);
void			ft_rra(t_stash a);
void			ft_rrb(t_stash b);
void			ft_rrr(t_stash ab);

// function that execute swap of the stack
void			ft_sa(t_stash a);
void			ft_sb(t_stash b);
void			ft_ss(t_stash ab);

// function that execute push of the stack
void			ft_push(t_stack *x, t_stack *y);
void			ft_pa(t_stash *a);
void			ft_pb(t_stash *b);

// function that interact with the stack
void			*ft_realloc(void *ptr, int size);
long long int	ft_atol(const char *nptr);

// function that check the stack for errors
int				ft_all_good(const int argc, char **argv);
int				ft_check_is_int(const char *arg);
int				ft_is_sorted(const t_stack stack);
int				ft_check_double(const int argc, char **argv);
int				ft_integer_limits(const char *arg);
int				ft_check_stack(const t_stack stack);
void			ft_exit_error(void);
int				absolute(int n);

// function that complement the process
int				ft_min_if(const t_stack stack, int pos);
int				ft_max(t_stack stack);
int				ft_find_min_pos_if(const t_stack stack, int pos);
int				ft_find_min_pos_value(t_stack stack, int value);
void			ft_print_stack(t_stash stash);

// sorting functions
void			ft_sort3(t_stash stash);

int				main(int argc, char **argv);
void			ft_index(t_stack stack);

void			ft_big_numbers(t_stash *stash);
void			ft_send_half(t_stash *half);
void			push_swap(t_stash *stash);

// function that sort the stack
void			less_moves_sort(t_stash *stash);
void			reverse_both(t_stash *stash);
void			rotate_both(t_stash *stash);
void			rotate_a(t_stash *stash);
void			rotate_b(t_stash *stash);
void	ft_fit_a(t_stash *stash);
void	ft_calc_moviment(t_stash *stash);
void	last_rotates(t_stash *stash);
void	ft_free_all(t_stash *stash);
#endif