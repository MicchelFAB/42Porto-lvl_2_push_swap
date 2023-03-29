/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:43:18 by mamaral-          #+#    #+#             */
/*   Updated: 2023/03/29 12:52:30 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

// function that execute the instructions
int ft_sa(int *a, int *b);
int	ft_ra(int **a);
int ft_rra(int **a);
int ft_pa(int **a, int **b, int *len_a, int *len_b);


// function that interact with the stack
int *ft_realloc(int *a, int len);
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