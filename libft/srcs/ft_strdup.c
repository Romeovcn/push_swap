/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvincent <rvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:50:39 by rvincent          #+#    #+#             */
/*   Updated: 2022/05/11 11:56:57 by rvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strdup(const char *source)
{
	char	*copy;
	int		i;

	copy = malloc((ft_strlen(source) + 1) * sizeof(char));
	i = 0;
	while (source[i])
	{
		copy[i] = source[i];
		i++;
	}
	copy[i] = 0;
	return (copy);
}

// int main()
// {

// 	char *str = "salut c moi";
// 	char *copy = ft_strdup(str);
// 	printf("%s", copy);
// }
