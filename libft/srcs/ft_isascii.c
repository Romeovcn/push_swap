/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvincent <rvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:49:55 by rvincent          #+#    #+#             */
/*   Updated: 2022/05/11 11:52:42 by rvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
	{
		return (1);
	}
	return (0);
}

// int	main(void)
// {
// 	char c;
// 	c = 128;
// 	printf("Result when uppercase alphabet is passed: %d", ft_isascii(c));
// 	printf("\n%d", isascii(c));
// 	return (0);
// }