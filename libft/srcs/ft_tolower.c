/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvincent <rvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:51:18 by rvincent          #+#    #+#             */
/*   Updated: 2022/05/11 11:59:39 by rvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_tolower(int character)
{
	if (character >= 65 && character <= 90)
		return (character + 32);
	return (character);
}

// int main(void)
// {
// 	printf("%c", ft_tolower(93));
// }