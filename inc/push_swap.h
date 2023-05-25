/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:52:08 by mamaral-          #+#    #+#             */
/*   Updated: 2023/05/25 12:35:08 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>

typedef struct s_base
{
	int	min;
	int	min_pos;
	int	max;
	int	*tmp;
	int	*tpm;
	int	*result;
	int	first;
	int	last;
	int	j;
	int	i;
	int	mv_a;
	int	mv_b;
}t_base;

typedef struct s_stack
{
	int		*stack;
	int		len;
	t_base	base;
	int		*moves;
}t_stack;
typedef struct s_check
{
	t_stack	a;
	t_stack	b;
}t_check;
typedef struct s_stash
{
	t_stack		a;
	t_stack		b;
	int			tmp;
	t_base		base;
}t_stash;

// function that execute rotation of the stack
void	ft_rotate(t_stack stack);
void	ft_ra(t_stash a);
void	ft_rb(t_stash b);
void	ft_rr(t_stash ab);

// function that execute reverse rotation of the stack
void	ft_reverse_rotate(t_stack stack);
void	ft_rra(t_stash a);
void	ft_rrb(t_stash b);
void	ft_rrr(t_stash ab);

// function that execute swap of the stack
void	ft_sa(t_stash a);
void	ft_sb(t_stash b);
void	ft_ss(t_stash ab);

// function that execute push of the stack
void	ft_push(t_stack *x, t_stack *y);
void	ft_pa(t_stash *a);
void	ft_pb(t_stash *b);

// function that interact with the stack
void	*ft_realloc(void *ptr, int size);

// function that check the stack for errors
int		ft_all_good(const int argc, char **argv);
int		ft_check_is_int(const char *arg);
int		ft_is_sorted(const t_stack stack);
int		ft_check_double(const int argc, char **argv);
int		ft_integer_limits(const char *arg);
int		ft_check_stack(const t_stack stack);
void	ft_exit_error(void);
int		ft_absolute(int n);

// function that complement the process
int		ft_min(const t_stack stack, int pos);
int		ft_max(t_stack stack);
int		ft_pos_value(const t_stack stack, int pos);
int		ft_find_min_pos_value(t_stack stack, int value);
void	ft_print_stack(t_stack stacka, t_stack stackb);

// sorting functions
void	ft_sort_three(t_stash stash);

int		main(int argc, char **argv);
void	ft_index(t_stash stash);

void	ft_big_numbers(t_stash *stash);
void	ft_send_max(t_stash *half);
void	push_swap(t_stash *stash);

// function that sort the stack
void	ft_less_movement(t_stash *stash);
void	ft_rrr_move(t_stash *stash);
void	ft_rr_move(t_stash *stash);
void	ft_ra_rra(t_stash *stash);
void	ft_rb_rrb(t_stash *stash);
void	ft_fit_a(t_stash *stash);
void	ft_compute_moves(t_stash *stash);
void	ft_last_rotates(t_stash *stash);
void	ft_free_all(t_stash *stash);
void	ft_malloc_all(t_stash *stash, int argc);
#endif