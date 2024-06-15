/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_exe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <jaehukim42@student.42gyeong      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:30:34 by jaehukim          #+#    #+#             */
/*   Updated: 2024/06/12 16:30:36 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include  "../includes/pipex.h"

char	*ft_make_cmd(char *s1, char *s2)
{
	char	*tmp;
	char	*res;

	tmp = ft_strjoin(s1, "/");
	res = ft_strjoin(tmp, s2);
	free(tmp);
	return (res);
}

char	*ft_accessible_cmd(t_vars *vars, int cnt)
{
	int		j;
	char	*cmd;
	char	*argv[3];

	if (vars->argv[cnt] == NULL)
		ft_error(22, "cnt");
	if (vars->argv[cnt][0] == '/')
	{
		cmd = ft_dbl_slash(&vars->argv[cnt]);
		if (access(&vars->argv[cnt][0], X_OK) == 0)
			return (ft_strdup(&vars->argv[cnt][0]));
		else
			ft_error(22, "NOT VALID");
	}
	j = 0;
	while (vars->paths[j])
	{
		cmd = ft_make_cmd(vars->paths[j], vars->argv[cnt]);
		if (access(cmd, X_OK) == 0)
			return (cmd);
		else
			free(cmd);
		j++;
	}
	return (NULL);
}


void	 ft_execve(t_vars *vars, int idx)
{
	char **sibal = ft_split(vars->argv[idx], ' ');
}