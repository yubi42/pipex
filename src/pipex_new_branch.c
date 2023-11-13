/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_new_branch.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:35:32 by yubi42            #+#    #+#             */
/*   Updated: 2023/11/07 16:35:35 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_set_fds(t_pipex *data, char *infile, char *outfile)
{
	data->fd[0] = -1;
	data->fd[1] = -1;
	if (access(outfile, F_OK) == -1 || access(outfile, W_OK) != -1)
		data->fd[1] = open(outfile, O_WRONLY | O_TRUNC | O_CREAT, 0777);
	if (data->fd[1] == -1)
		error(data);
	if (access(infile, R_OK) != -1)
		data->fd[0] = open(infile, O_RDONLY);
	if (data->fd[0] == -1)
		error(data);
}

void	exec_cmd(int fd[2], char *cmd, char **env, t_pipex *data)
{
	char	**cmd_split;
	char	*cmd_path;

	cmd_split = NULL;
	cmd_path = NULL;
	cmd_split = ft_split(cmd, ' ');
	if (!cmd_split)
		err_exec_cmd(fd, data, cmd_path, cmd_split);
	if (ft_strchr(cmd_split[0], '/'))
		new_cmd_path(&cmd_path, &cmd_split[0], '/');
	else
		std_cmd_path(env, cmd_split[0], &cmd_path);
	if (!cmd_path)
		err_exec_cmd(fd, data, cmd_path, cmd_split);
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	execve(cmd_path, cmd_split, env);
	free_cmd(&cmd_path, &cmd_split);
	exit(EXIT_FAILURE);
}

void	wait_for_child(pid_t pid, char *cmd)
{
	pid_t	result;
	int		timer;
	int		wstatus;

	timer = 0;
	while (timer++ < 8000)
	{
		result = waitpid(pid, &wstatus, WNOHANG);
		if (result > 0)
		{
			if (WEXITSTATUS(wstatus))
			{
				if (ft_strchr(cmd, '/'))
					ft_printf("bash: %s: No such file or directory\n", cmd);
				else
					ft_printf_err("Command '%s' not found\n", cmd);
			}
			return ;
		}
	}
	exit(EXIT_SUCCESS);
}

void	new_branch(char *cmd, t_pipex *data, char **env, int end)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		error(data);
	pid = fork();
	if (pid == -1)
		error(data);
	if (pid == 0)
	{
		if (!end)
			exec_cmd(fd, cmd, env, data);
		else
			exec_cmd(data->fd, cmd, env, data);
	}
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	wait_for_child(pid, cmd);
}
