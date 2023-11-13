/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:36:14 by yubi42            #+#    #+#             */
/*   Updated: 2023/11/07 18:10:06 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_pipex
{
	int	fd[2];
	int	i;
}		t_pipex;

// --------- FROM PIPEX ---------

// pipex_err.c

void	error(t_pipex *data);
void	err_exec_cmd(int fd[2], t_pipex *data, char *cmd_path,
			char **cmd_split);

// pipex_new_branch.c

void	init_set_fds(t_pipex *data, char *infile, char *outfile);
void	exec_cmd(int fd[2], char *cmd, char **env, t_pipex *data);
void	wait_for_child(pid_t pid, char *cmd);
void	new_branch(char *cmd, t_pipex *data, char **env, int end);

// pipex_path.c

void	new_cmd_path(char **cmd_path, char **first_split, char c);
void	std_cmd_path(char **env, char *cmd, char **cmd_path);

// pipex_utils.c

void	free_split(char ***array);
void	free_cmd(char **cmd_path, char ***cmd_split);
void	str_cpy(char **dst, char *src, int size);
char	*join_mult_str(char *str1, char *str2, char *str3);

// --------- PREV CODE ---------

// libft

void	*ft_memcpy(void *dest, const void *src, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);

// ft_printf

int		ft_printf(const char *str, ...);
void	check_type(char c, va_list list, int *count);
void	ft_putchar(char c, int *count);
void	ft_puthex(unsigned long num, char c, int *count);
void	ft_putnbr(long num, int *count);
void	ft_putstr(char *s, int *count);
void	ft_putpoint(unsigned long num, int *count);

// ft_printf_err

int		ft_printf_err(const char *str, ...);
void	check_type_err(char c, va_list list, int *count);
void	ft_putchar_err(char c, int *count);
void	ft_puthex_err(unsigned long num, char c, int *count);
void	ft_putnbr_err(long num, int *count);
void	ft_putstr_err(char *s, int *count);
void	ft_putpoint_err(unsigned long num, int *count);

#endif
