/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sukwon <sukwon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:37:32 by sukwon            #+#    #+#             */
/*   Updated: 2023/03/06 21:54:33 by sukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char ** path_find(t_arg *stru)
{
    //protect
    int i;
    
    if(!stru->env)
        error_exit(EXIT_PATH/*=1*/,"THERE IS NO GIVEN ENV", NULL);
    i = 0;
    while(stru->env[i])
    {
        if( ft_strncmp(stru->env[i],"PATH=", 5) == 0)
            break;;
        i++;
    }
    if(!stru->env[i])
        error_exit(EXIT_PATH,"Failure by ENV", "There is no PATH");
    stru->path = ft_split(&stru->env[i][5], ':');//path= is until [4] 
    if(stru->path == NULL)
        error_exit(EXIT_PATH,"STRU->PATH FAILURE", "fail in spliting");

    return (stru->path);
}

int count_argv(t_arg *stru, int argc, char **argv)
{
    int i;
    int j;
    
    i = 1;
    j = 0;
    /*argc =1 = program file
       argv[0] = program file
       argv[argc] = NULL*/
    if (argc < 5)
        error_exit(EXIT_ARGC, "FAILURE OF GETTING RIGHT ARGC", NULL);
    while (i < argc - 1)  
    {
        ft_strlcpy(stru->cmd[j], argv[i],ft_strlen(argv[i] + 1));
        if (stru->cmd[j] == NULL)
            error_exit(EXIT_ARGC,"Failure in cpying argv in cmd", NULL);
        i++;
        j++;
    }
    stru->cmd[j] = NULL;
    stru->count_cmd = argc- 3;
    return 0;
}
int add_path(t_arg *stru, int argc, char **argv)
{
    char * temp_path;
    char * temp_wholepath;
    int i;
    i = 0;
    
    path_find(stru);
    if(stru->path == NULL)
        error_exit(EXIT_PATH,"STRU->PATH FAILURE", "fail in spliting");
    while (stru->path[i] != NULL)
    {
        temp_path = ft_strjoin(stru->path[i],"/"); 
        // to check if it malloced well, need temp 
        //each of path /bin will have / at the end as join alway add s2 at the end of s1
        if (temp_path == NULL)
            error_exit(EXIT_PATH,"Did not malloced in ft_strjoin.","temp_path");
        temp_wholepath = ft_strjoin(temp_path, stru->cmd[i]);
        free (temp_path);//no use anymore so free it
        if (temp_path == NULL)
            error_exit(EXIT_PATH,"Did not malloced in ft_strjoin.","temp_wholepath");
        strlcpy(stru->cmd[i],temp_wholepath,ft_strlen(temp_wholepath + 1));
        free (temp_wholepath);
        if (!stru->cmd[i])
            error_exit(EXIT_PATH,"Did not copy properly.","stru->cmd[i]");
        i++;
    }
    stru->cmd[i] = NULL;
    return 0;
}



void check_path_last(t_arg *stru, int argc, char **argv)
{


}