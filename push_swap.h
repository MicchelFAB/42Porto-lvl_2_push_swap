/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:43:18 by mamaral-          #+#    #+#             */
/*   Updated: 2023/03/27 20:30:02 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

// function that execute the instructions
int ft_sa(int *a, int *b);
int	ft_ra(int **a);
int ft_rra(int **a);
int	ft_atoi(const char *nptr);
int ft_pa(int **a, int **b, int *len_a, int *len_b);

// function that interact with the stack
int *ft_realloc(int *a, int len);
long long int ft_atol(const char *nptr);

// function from libft
size_t	ft_strlen(int *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);

// function that check the stack for errors
int ft_check_stack(int *a, int len);
int ft_check_double(int *a, int len);
int ft_check_sort(int *a, int len);
char *ft_check_char(char *str);

#endif