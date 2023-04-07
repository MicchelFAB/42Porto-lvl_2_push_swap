/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:43:18 by mamaral-          #+#    #+#             */
/*   Updated: 2023/04/07 15:17:22 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

// function that execute rotation of the stack
void	ft_rotate(int **stack, size_t len);
void	ft_ra(int **a, size_t len_a);
void	ft_rb(int **b, size_t len_b);
void	ft_rr(int **a, int **b, size_t len_a, size_t len_b);

// function that execute reverse rotation of the stack
void ft_reverse_rotate(int **stack, size_t len);
void ft_rra(int **a, size_t len_a);
void ft_rrb(int **b, size_t len_b);
void ft_rrr(int **a, int **b, size_t len_a, size_t len_b);

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
void	*ft_realloc(void *ptr, size_t size);
long long int ft_atol(const char *nptr);

// function from libft
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);

// function that check the stack for errors
int ft_check_stack(int *a, size_t len);
int ft_check_double(int argc, char **argv);
int ft_check_sort(int *a, size_t len);
int is_valid_argument(const char *arg);
int ft_check_int(const char *arg);
void ft_print_stack(int *a, int len_a);
void *ft_sort3(int **stack, int len);
void *ft_sort5(int **stacka, int **stackb, int lena, int lenb);
int ft_min(int *a, int len_a);
int ft_max(int *a, int len_a);

#endif