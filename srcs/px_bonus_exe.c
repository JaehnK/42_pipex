/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_exe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <jaehukim42@student.42gyeong      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:30:34 by jaehukim          #+#    #+#             */
/*   Updated: 2024/06/18 10:36:14 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include  "../includes/pipex.h"

static char	*ft_make_cmd(char *s1, char *s2)
{
	char	*tmp;
	char	*res;

	tmp = ft_strjoin(s1, "/");
	res = ft_strjoin(tmp, s2);
	free(tmp);
	return (res);
}

static void	ft_accessible_path(t_vars *vars, char **ag)
{
	int		idx;
	char	*cmd;

	idx = 0;
	cmd = NULL;
	if (*ag[0] == '/')
	{
		if (!access(*ag, X_OK))
			return ;
		else
			ft_error(2, *ag);
	}
	while (vars->paths[idx])
	{			
		cmd = ft_make_cmd(vars->paths[idx], *ag);
		if (!access(cmd, X_OK))
		{
			free(*ag);
			*ag = cmd;
			return ;
		}
		free(cmd);
		idx++;
	}
	ft_error(2, *ag);
}

void	ft_execute(t_vars *vars, int idx, int ifd, int ofd)
{
	char	**argv_cmd;

	argv_cmd = ft_split(vars->argv[idx], ' ');
	ft_accessible_path(vars, &argv_cmd[0]);
	if (ifd != STDIN_FILENO)
	{
		dup2(ifd, STDIN_FILENO);
		close(ifd);
	}
	if (ofd != STDOUT_FILENO)
	{
		dup2(ofd, STDOUT_FILENO);
		close(ofd);
	}
	execve(argv_cmd[0], argv_cmd, vars->envp);
}
