/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:22:16 by nvaubien          #+#    #+#             */
/*   Updated: 2023/05/07 13:54:40 by nvaubien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	tot;
	int		index;
	char	*joined_str;

	index = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	tot = s1_len + s2_len;
	joined_str = (char *)malloc(sizeof(char) * tot + 1);
	if (joined_str == NULL)
		return (NULL);
	while (*s1)
		joined_str[index++] = *s1++;
	while (*s2)
		joined_str[index++] = *s2++;
	joined_str[tot] = '\0';
	return (joined_str);
}
