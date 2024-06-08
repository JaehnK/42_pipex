/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_parsepath.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <jaehukim42@student.42gyeong      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 16:31:00 by jaehukim          #+#    #+#             */
/*   Updated: 2024/06/08 16:31:08 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../pipex.h"

static char	*ft_left(char *line, int size)
{
	int		i;
	char	*dst;

	i = 0;
	dst = (char *) malloc(sizeof(char) * (ft_strlen(line) - size + 1));
	while (i < ft_strlen(line) - size)
	{
		dst[i] = line[i + size];
		i++;
	}
	dst[i] = '\0';
	free(line);
	return (dst);
}

char	**ft_parse_path(char **envp)
{
	int		i;
	char	*first;
	char 	**paths;
	
	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", ft_strlen("PATH=")))
		i++;
	paths = ft_split(envp[i], ':');
	paths[0] = ft_left(paths[0], 5);
	return (paths);
}
