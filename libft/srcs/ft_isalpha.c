/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvincent <rvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:49:51 by rvincent          #+#    #+#             */
/*   Updated: 2022/05/11 14:56:25 by rvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int	ft_isalpha(char c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
	{
		return (1024);
	}
	return (0);
}

// int	main(void)
// {
// 	char c;
// 	c = 'a';
// 	printf("Result when uppercase alphabet is passed: %d", ft_isalpha(c));
// 	printf("\nResult when uppercase alphabet is passed: %d", isalpha(c));
// 	return (0);
// }