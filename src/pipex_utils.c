/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:19:22 by yubi42            #+#    #+#             */
/*   Updated: 2023/11/03 12:19:31 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_split(char ***array)
{
	int	i;

	i = 0;
	while ((*array)[i])
	{
		free((*array)[i]);
		i++;
	}
	free(*array);
	*array = NULL;
}

void	free_cmd(char **cmd_path, char ***cmd_split)
{
	if (*cmd_split)
		free_split(cmd_split);
	if (*cmd_path)
		free(*cmd_path);
}

void	str_cpy(char **dst, char *src, int size)
{
	int	i;

	i = 0;
	while (*src != 0 && size-- > 0)
		(*dst)[i++] = *(src++);
	while ((*dst)[i] != 0)
		(*dst)[i++] = 0;
}

char	*join_mult_str(char *str1, char *str2, char *str3)
{
	char	*new_str;
	int		i;

	i = 0;
	new_str = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2)
				+ ft_strlen(str3) + 1));
	if (!new_str)
		return (NULL);
	while (*str1)
		new_str[i++] = *(str1++);
	while (*str2)
		new_str[i++] = *(str2++);
	while (*str3)
		new_str[i++] = *(str3++);
	new_str[i] = 0;
	return (new_str);
}
