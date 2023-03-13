/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sukwon <sukwon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:37:32 by sukwon            #+#    #+#             */
/*   Updated: 2023/03/13 15:01:16 by sukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	path_find(t_arg *stru)
{
	//protect
	stru->i = 0;
	if (!stru->env)
		error_exit(EXIT_PATH /*=1*/, "THERE IS NO GIVEN ENV", NULL);
	while (stru->env[stru->i])
	{
		if (ft_strncmp(stru->env[stru->i], "PATH=", 5) == 0)
			break ;
		stru->i++;
	}
	if (!stru->env[stru->i])
		error_exit(EXIT_PATH, "Failure by ENV", "There is no PATH");
	stru->path = ft_split(&stru->env[stru->i][5], ':'); //path= is until [4]
	if (stru->path == NULL)
		error_exit(EXIT_PATH, "STRU->PATH FAILURE", "fail in spliting");
	return (0);
}

int	count_argv(t_arg *stru, int argc, char **argv)
{
	stru->i = 2;
	stru->j = 0;
	/*argc =1 = program file
       argv[0] = program file
       argv[argc] = NULL*/
	if (argc < 5)
		error_exit(EXIT_ARGC, "FAILURE OF GETTING RIGHT ARGC", NULL);
	while (stru->j < argc - 3 && argv[stru->i] != NULL)
	{
		ft_strlcpy(stru->cmd[stru->j], argv[stru->i], ft_strlen(argv[stru->i]
					+ 1));
		if (stru->cmd[stru->j] == NULL)
			error_exit(EXIT_ARGC, "Failure in cpying argv in cmd", NULL);
		stru->i++;
		stru->j++;
	}
	stru->cmd[stru->j] = NULL;
	stru->count_cmd = argc - 3;
	return (0);
}
int	add_path(t_arg *stru, int argc, char **argv)
{
	stru->i = 0;
	stru->j = 0;
	while (stru->cmd[stru->j] != NULL)
	{
		stru->temp_path = ft_strjoin(stru->path[stru->i], "/");
		// to check if it malloced well, need temp
		//each of path /bin will have '/' at the end as join alway add s2 at the end of s1
		if (stru->temp_path == NULL)
			error_exit(EXIT_PATH, "Did not malloced in ft_strjoin.",
					"temp_path");
		stru->temp_wholepath = ft_strjoin(stru->temp_path, stru->cmd[stru->j]);
		free(stru->temp_path); //no use anymore so free it
			// strjoin has malloced value everytime its call, need to free
		if (stru->temp_wholepath == NULL)
			error_exit(EXIT_PATH, "Did not malloced in ft_strjoin.",
					"temp_wholepath");
		if (access(stru->temp_wholepath, F_OK) < 0)
			error_exit(EXIT_PATH, "ACCESS ERROR", NULL);
		if (access(stru->temp_wholepath, F_OK) == 0)
		{
			strlcpy(stru->cmd[stru->j], stru->temp_wholepath,
					ft_strlen(stru->temp_wholepath + 1));
			free(stru->temp_wholepath);
			stru->j++;
			// if (!stru->cmd[i])
			//     error_exit(EXIT_PATH,"Did not copy properly.","stru->cmd[i]");
		}
		free(stru->temp_wholepath);
		stru->i++;
	}
	stru->cmd[stru->j] = NULL;
	return (0);
}
/*https://velog.io/@kyj93790/Pipex-%ED%99%98%EA%B2%BD%EB%B3%80%EC%88%98environment-variable-PATH*/

int	check_path_last(t_arg *stru, int argc, char **argv)
{
	path_find(stru);
	// if(stru->path == NULL)
	//     error_exit(EXIT_PATH,"STRU->PATH FAILURE", "fail in spliting");
	count_argv(stru, argc, argv);
	add_path(stru, argc, argv);
	if (stru->cmd == NULL)
		error_exit(EXIT_PATH, "STRU->CMD FAILURE", "fail in ADD_PATH");
	return (0);
}