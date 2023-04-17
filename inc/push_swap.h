/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:43:18 by mamaral-          #+#    #+#             */
/*   Updated: 2023/04/17 15:44:55 by mamaral-         ###   ########.fr       */
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

// function that execute rotation of the stack
void			ft_rotate(int *stack, int len);
void			ft_ra(int *a, int len_a);
void			ft_rb(int *b, int len_b);
void			ft_rr(int *a, int *b, int len_a, int len_b);

// function that execute reverse rotation of the stack
void			ft_reverse_rotate(int *stack, int len);
void			ft_rra(int *a, int len_a);
void			ft_rrb(int *b, int len_b);
void			ft_rrr(int *a, int *b, int len_a, int len_b);

// function that execute swap of the stack
void			ft_swap(int *stack);
void			ft_sa(int *a);
void			ft_sb(int *b);
void			ft_ss(int *a, int *b);

// function that execute push of the stack
void 			ft_push(int *x, int *y, int *len_x, int *len_y); 
void			ft_pa(int *b, int *a, int *len_b, int *len_a);
void			ft_pb(int *a, int *b, int *len_a, int *len_b);

// function that interact with the stack
void			*ft_realloc(void *ptr, size_t size);
long long int	ft_atol(const char *nptr);

// function that check the stack for errors
int				ft_check_stack(int *a, size_t len);
int				ft_check_double(int argc, char **argv);
int				ft_check_sort(int *a, size_t len);
int				is_valid_argument(const char *arg);
int				ft_check_int(const char *arg);
void			ft_print_stack(int *a, int len_a);
void			ft_sort3(int *stack, int len);
void			ft_sort5(int *stacka, int *stackb, int lena, int lenb);
int				ft_min_if(const int *a, int len_a, int pos);
int				ft_max(int *a, int len_a);

int				is_sorted(const int *stack, int len);
void 			ft_print_stack_all(int *a, int *b, int len_a, int len_b);
void ft_min1(int *a, int *b, int len_a, int len_b);

#endif