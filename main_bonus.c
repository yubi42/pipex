/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:52:52 by yubi42            #+#    #+#             */
/*   Updated: 2023/11/07 17:33:22 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_pipex	data;

	if (argc < 5)
	{
		ft_printf_err("Error: Not enough arguments.\n");
		return (1);
	}
	init_set_fds(&data, argv[1], argv[argc - 1]);
	dup2(data.fd[0], STDIN_FILENO);
	data.i = 2;
	while (data.i < (argc - 2))
		new_branch(argv[data.i++], &data, env, 0);
	new_branch(argv[data.i], &data, env, 1);
	close(data.fd[1]);
	close(data.fd[0]);
	exit(EXIT_SUCCESS);
}
