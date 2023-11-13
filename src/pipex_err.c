/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:19:06 by yubi42            #+#    #+#             */
/*   Updated: 2023/10/26 17:50:13 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(t_pipex *data)
{
	if (data->fd[1] > 2)
		close(data->fd[1]);
	perror("Error");
	exit(EXIT_FAILURE);
}

void	err_exec_cmd(int fd[2], t_pipex *data, char *cmd_path, char **cmd_split)
{
	close(fd[0]);
	close(fd[1]);
	free_cmd(&cmd_path, &cmd_split);
	error(data);
}
