/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvincent <rvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:52:12 by rvincent          #+#    #+#             */
/*   Updated: 2022/07/07 22:50:59 by rvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "ft_printf.h"
# include <stdio.h>
# include <unistd.h>

int	ft_putchar(char c);
int	ft_putnbr_hexa(long nbr, int upper);
int	ft_putnbr(int nb);
int	ft_putstr(char *s);
int	ft_putnbr_u(unsigned int nb);
int	ft_putnbr_adress(unsigned long nbr);
int	ft_printf(const char *str, ...);

#endif