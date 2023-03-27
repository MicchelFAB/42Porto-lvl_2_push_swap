/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:43:18 by mamaral-          #+#    #+#             */
/*   Updated: 2023/03/27 11:19:01 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int ft_sa(int *a, int *b);
int	ft_ra(int **a);
int ft_rra(int **a);
int	ft_atoi(const char *nptr);
size_t	ft_strlen(int *s);
int ft_pa(int **a, int **b, int *len_a, int *len_b);
void	*ft_memcpy(void *dest, const void *src, size_t n);
long long int ft_atol(const char *nptr);
int *ft_realloc(int *a, int len);
void	*ft_memmove(void *dest, const void *src, size_t n);
int ft_pb(int **a, int **b, int *len_a, int *len_b);
void	*ft_memset(void *s, int c, size_t n);
#endif