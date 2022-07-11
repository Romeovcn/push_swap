/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvincent <rvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:13:28 by rvincent          #+#    #+#             */
/*   Updated: 2022/05/11 11:56:45 by rvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>

char	*ft_strchr(const char *str, int c)
{
	while (*str != (char)c && *str)
		str++;
	if (*str == (char)c)
		return ((char *)str);
	return (NULL);
}

// int main(void)
// {
// 	printf("%s-", strchr("saluuut", 117));
// 	printf("%s", ft_strchr("saluuut", 117));
// }