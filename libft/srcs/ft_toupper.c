/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvincent <rvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 18:14:57 by rvincent          #+#    #+#             */
/*   Updated: 2022/05/11 11:59:48 by rvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>
#include <unistd.h>

int	ft_toupper(int character)
{
	if (character >= 97 && character <= 122)
		return (character - 32);
	return (character);
}

// int main(void)
// {
// 	printf("%c", ft_toupper(97));
// }