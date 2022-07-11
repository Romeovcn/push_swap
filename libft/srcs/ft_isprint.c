/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvincent <rvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:50:03 by rvincent          #+#    #+#             */
/*   Updated: 2022/05/11 11:53:08 by rvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
	{
		return (16384);
	}
	return (0);
}

// int main(void)
// {
//     int c;
//     c = 0;
//     while (c <= 127)
//     {
//         printf("%c = %d == %d : %d\n", c, c, isprint(c), ft_isprint(c));
//         c++;
//     }
//     return (0);
// }