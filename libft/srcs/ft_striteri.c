/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvincent <rvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:50:43 by rvincent          #+#    #+#             */
/*   Updated: 2022/05/11 14:55:52 by rvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}

// void	ft_test(unsigned int i, char *str)
// {
// 	unsigned int	j;

// 	j = 0;
// 	*str = 'o';
// }

// int main(void)
// {
// 	char s[] = "salut";
// 	ft_striteri(s, &ft_test);
// 	printf("%s", s);
// }