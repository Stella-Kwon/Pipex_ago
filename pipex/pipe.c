/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sukwon <sukwon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:18:02 by sukwon            #+#    #+#             */
/*   Updated: 2023/03/13 14:56:35 by sukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pipe_fd(t_arg *stru)
{
	int	i;

	stru->pfd = (int **)malloc(stru->count_cmd - 1 * sizeof(int *));
	if (!stru->pfd)
		error_exit(EXIT_PFD, "FAILURE MALLOCING PFD", NULL);
	i = 0;
	while (i < stru->count_cmd)
	{
		stru->pfd[i] = (int *)malloc(2 * sizeof(int));
		if (!stru->pfd[i])
			error_exit(EXIT_PFD, "FAILURE MALLOCING PFD[i]", NULL);
		i++;
	}
	return (0);
}

int	pipe_create(t_arg *stru)
{
	int	i;

	i = 0;
	pipe_fd(stru);
	while (i < stru->count_cmd - 1)
	{
		if (pipe(stru->pfd[i]) == -1)
		{
			while (0 <= i)
			{
				close(stru->pfd[i][READ]);
				close(stru->pfd[i][WRITE]);
				i--;
			}
			error_exit(EXIT_PIPE, "ERROR with piping", strerror(errno));
		}
		i++;
	}
	return (0);
}
