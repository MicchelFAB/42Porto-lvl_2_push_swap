/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 10:40:11 by athekkep          #+#    #+#             */
/*   Updated: 2023/05/25 15:33:26 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHECK_H
# define FT_CHECK_H	

# include "push_swap.h"

int		ft_checker(t_stack s, char c);
void	ft_do_operation(t_check *instruct, char *ln, int i);
void	ft_send_moves(char *ln, t_check *instruct);
void	ft_process_moves(t_check *inst);

#endif