/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_find_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sukwon <sukwon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:04:23 by sukwon            #+#    #+#             */
/*   Updated: 2023/03/21 09:49:43 by sukwon           ###   ########.fr       */
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
	stru->path = ft_split(stru->env[stru->i][5], ':'); //path= is until [4]
	if (stru->path == NULL)
		error_exit(EXIT_PATH, "STRU->PATH FAILURE", "fail in spliting");
	return (0);
}
	/*argc =1 = program file
       argv[0] = program file
       argv[argc] = NULL*/
int	add_path(t_arg *stru, int argc, char **argv)
{   
	int x;
	stru->i = 0;
	stru->j = 2;
    //this needed to be seperated with space as we put arguments with "".
//for example, that "ls -l" will counted as one arguments but here to find the program, we should not put flag like -l togther. Otherwise it will be not able to locate program.
//but what you should consider is that you need to know for "grep " but just think later of those
	if(path_find(stru) == EXIT_PATH)
		error_exit(EXIT_PATH, "Find_Path function FAILURE", NULL);
    if (argc < 5)
 		error_exit(EXIT_ARGC, "FAILURE OF GETTING RIGHT ARGC", NULL);
    while (stru->j++ < argc -1)
    {
        stru->cmds[stru->i]= ft_split(argv[stru->j], ' ');
        if (!stru->cmds[stru->i])
            error_exit(EXIT_ARGC, "Failure spliting cmds[i] ", NULL);
		stru->i++;
    }
	stru->cmds[stru->i] = NULL;
	stru->i = 0;
	while (stru->cmds[stru->i++])//before NULL 
	{
		x = 0; 
		if(check_path_last(stru, x)== EXIT_PATH)
			error_exit(EXIT_PATH, "check_path_last function FAILURE", NULL);
	}
	if(stru->i == argc -3)
		stru->count_cmd = stru->i;
	else 
		error_exit(EXIT_PATH, "stru->count_cmd != argc -3", NULL);
	return (0);
}
/*https://velog.io/@kyj93790/Pipex-%ED%99%98%EA%B2%BD%EB%B3%80%EC%88%98environment-variable-PATH*/

int	check_path_last(t_arg *stru, int x)
{
	while(!stru->path[x++])
	{
		stru->temp_path = ft_strjoin(stru->path[x], "/");
	// to check if it malloced well, need temp
	//each of path /bin will have '/' at the end as join alway add s2 at the end of s1
		if (stru->temp_path == NULL)
			error_exit(EXIT_PATH, "Fail in adding / to tmep_path", NULL);
		stru->temp_wholepath = ft_strjoin(stru->temp_path, stru->cmds[stru->i][0]);
		free(stru->temp_path); //need to free everytime because it is in while loop.
		// strjoin has malloced value everytime its call, need to free.
		//but the difference between A having a value with malloced return or value itself calling a malloc
		//is that when you have B pointer pointinga at A; with malloced return you can just free A but with A value calling a malloc then you should free A and B.
		if (stru->temp_wholepath == NULL)
			error_exit(EXIT_PATH, "Fail in adding path to temp_wholepath.", NULL);
		if (access(stru->temp_wholepath, F_OK) < 0)
			free(stru->temp_wholepath);
		else
		{//(access(stru->temp_wholepath, F_OK) == 0)
            //i need to empty the stru->cmds[stru->j][0] to store new value.
		//because it is string literal and it is only read-only section of memeory, cannot write. bus error will occur
			free(stru->cmds[stru->j][0]);
			stru->cmds[stru->j][0] = (char **)malloc(ft_strlen(stru->temp_wholepath) + 1);
			strlcpy(stru->cmds[stru->j][0], stru->temp_wholepath, ft_strlen(stru->temp_wholepath + 1));
			free(stru->temp_wholepath);
		}
	}
	return (0);
}
