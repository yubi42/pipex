/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 23:58:06 by yubi42            #+#    #+#             */
/*   Updated: 2023/11/03 13:21:41 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	new_cmd_path(char **cmd_path, char **first_split, char c)
{
	int	i;
	int	len;

	len = ft_strlen(*first_split);
	*cmd_path = malloc(sizeof(char) * (len + 1));
	if (!*cmd_path)
		return ;
	*cmd_path = ft_memcpy(*cmd_path, *first_split, len);
	(*cmd_path)[len] = 0;
	i = len - 1;
	while ((*first_split)[i] != c)
		i--;
	i++;
	str_cpy(first_split, &(*cmd_path)[i], ft_strlen(&(*cmd_path)[i]));
}

void	std_cmd_path(char **env, char *cmd, char **cmd_path)
{
	char	**env_split;
	int		i;

	i = 0;
	while (ft_strncmp("PATH=", env[i], 5) != 0)
		i++;
	env_split = ft_split(&env[i][5], ':');
	if (!env_split)
		return ;
	i = 0;
	while (env_split[i])
	{
		*cmd_path = join_mult_str(env_split[i++], "/", cmd);
		if (!*cmd_path)
			return ;
		if (access(*cmd_path, X_OK) == 0)
		{
			free_split(&env_split);
			return ;
		}
		if (env_split[i])
			free(*cmd_path);
	}
	free_split(&env_split);
}
