/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michel <michel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:43:18 by mamaral-          #+#    #+#             */
/*   Updated: 2023/04/05 00:10:15 by michel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

// function that execute rotation of the stack
void	ft_rotate(int **stack);
void	ft_ra(int **a);
void	ft_rb(int **b);
void	ft_rr(int **a, int **b);

// function that execute reverse rotation of the stack
void ft_reverse_rotate(int **stack);
void ft_rra(int **a);
void ft_rrb(int **b);
void ft_rrr(int **a, int **b);

// function that execute swap of the stack
void ft_swap(int **stack);
void ft_sa(int **a);
void ft_sb(int **b);
void ft_ss(int **a, int **b);

// function that execute push of the stack
void ft_push(int **a, int **b, int *len_a, int *len_b);
void ft_pa(int **a, int **b, int *len_a, int *len_b);
void ft_pb(int **a, int **b, int *len_a, int *len_b);


// function that interact with the stack
void		*ft_realloc(void *ptr, size_t size);
long long int ft_atol(const char *nptr);

// function from libft
size_t	ft_intlen(int *s);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);

// function that check the stack for errors
int ft_check_stack(int *a, int len);
int ft_check_double(int argc, char **argv);
int ft_check_sort(int *a, int len);
int is_valid_argument(const char *arg);
int ft_check_int(const char *arg);


#endif