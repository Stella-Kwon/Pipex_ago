/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sukwon <sukwon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:37:32 by sukwon            #+#    #+#             */
/*   Updated: 2023/03/05 16:49:46 by sukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char ** path_find(char **env, t_arg *stru)
{
    //protect
    int i;
    
    if(!env)
        error_exit(EXIT_PATH/*=1*/,"THERE IS NO GIVEN ENV", NULL);
    i = 0;
    while(env[i])
    {
        if( ft_strncmp(env[i],"PATH=", 5) == 0)
            break;;
        i++;
    }
    if(!env[i])
        error_exit(EXIT_PATH,"Failure by ENV", "There is no PATH");
    stru->path = ft_split(&env[i][5], ':');//path= is until [4] 
    if(stru->path == NULL)
        error_exit(EXIT_PATH,"STRU->PATH FAILURE", "fail in spliting");

    return (stru->path);
}
int add_path(char **env, t_arg *stru, int argc, char **argv)
{
    char * temp_path;
    char * temp_wholepath;
    int i;
    i = 0;
    
    while (stru->path[i])
    {
        temp_path = ft_strjoin(stru->path[i],"/"); 
        // to check if it malloced well, need temp 
        //each of path /bin will have / at the end as join alway add s2 at the end of s1
        if (temp_path == NULL)
            error_exit(EXIT_PATH,"Did not malloced in ft_strjoin.",NULL);
        
        temp_wholepath = ft_strjoin(temp_path, stru->cmd[i]);
        
        
    
    }
}
int path_check(char **env, t_arg *stru, int argc, char **argv)
{
    // count_argv(stru, argc, argv);
    // int i;
    // int j;
    
    // i = 0;
    
    // while(i < stru->count_argv -2)
    // {
    //     stru->cmd = path_find(env, stru);
    //     j = ft_strlen(stru->path[i]) - 1;
        
    //     ft_strjoin(stru->path[i][],)
        
    // }
   
}

void count_argv(t_arg *stru, int argc, char **argv)
{
    int i;
    int j;
    
    i = 1;
    j = 0;
    if (argc < 1 && argc != 5)
        error_exit(EXIT_ARGC, "FAILURE OF GETTING RIGHT ARGC", NULL);
    while (i < argc)  
    {
        ft_strlcpy(stru->cmd[j], argv[i],ft_strlen(argv[i] + 1));
        if (stru->cmd[j] == NULL)
            error_exit(EXIT_ARGC,"Failure in cpying cmd", NULL);
        i++;
        j++;
    } 
    
    stru->count_argv = i;

    while ()
    
}