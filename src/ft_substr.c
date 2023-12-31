/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 17:00:52 by jborner           #+#    #+#             */
/*   Updated: 2023/10/22 14:54:23 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	sub_len;
	int		i;

	if (s == NULL)
		return (NULL);
	sub_len = 0;
	if (start < ft_strlen(s))
		sub_len = ft_strlen(&s[start]);
	if (sub_len < len)
		sub = (char *)malloc(sizeof(char) * (sub_len + 1));
	else
		sub = (char *)malloc(sizeof(char) * len + 1);
	if (sub != NULL)
	{
		i = 0;
		if (start < ft_strlen(s))
			while (s[start] && len--)
				sub[i++] = s[start++];
		sub[i] = '\0';
		return (sub);
	}
	return (NULL);
}
