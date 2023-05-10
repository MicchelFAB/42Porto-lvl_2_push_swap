/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:43:18 by mamaral-          #+#    #+#             */
/*   Updated: 2023/05/10 08:06:15 by mamaral-         ###   ########.fr       */
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

typedef struct s_stack
{
	int	*stack;
	int	len;	
}t_stack;

typedef struct s_stash
{
	t_stack	*a;
	t_stack *b;
}t_stash;
	// function that execute rotation of the stack
/* void			ft_rotate(t_stash stash);
void			ft_ra(t_stash stash);
void			ft_rb(t_stash stash);
void			ft_rr(t_stash stash);
 */
// function that execute reverse rotation of the stack
/* void			ft_reverse_rotate(int *stack, int len);
void			ft_rra(t_stash stash);
void			ft_rrb(t_stash stash);
void			ft_rrr(t_stash stash);
 */
// function that execute swap of the stack
/* void			ft_sa(t_stash stash);
void			ft_sb(t_stash stash);
void			ft_ss(t_stash stash);
 */
// function that execute push of the stack
void			ft_push(t_stack x, t_stack y);
void			ft_pa(t_stash stash);
void			ft_pb(t_stash stash);

// function that interact with the stack
void			*ft_realloc(void *ptr, size_t size);
long long int	ft_atol(const char *nptr);

// function that check the stack for errors
/* int				ft_check_stack(const t_stash stash);
int				ft_check_double(const int argc, char **argv);
int				ft_check_sort(const t_stash stash);
int				ft_integer_limits(const char *arg);
int				ft_is_sorted(const t_stash stash);
int				is_valid_argument(const char *arg);
int				ft_check_is_int(const char *arg);
void			ft_sort3(t_stash stash);
void			*ft_sort5(t_stash stash);
int				ft_min_if(const t_stash stash, int pos);
int				ft_max(t_stash stash);
 */
// function that helps debbuging
void			ft_exit_error(void);
/* void			ft_print_stack(t_stash stash);
void			ft_min1(t_stash stash);
int				ft_find_min_pos_if(const t_stash stash, int n);
 */
#endif