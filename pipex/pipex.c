/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sukwon <sukwon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:05:37 by sukwon            #+#    #+#             */
/*   Updated: 2023/03/10 17:07:43 by sukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//REFERENCE https://velog.io/@kyj93790/Pipex-%EC%82%AC%EC%9A%A9%EA%B0%80%EB%8A%A5-%ED%95%A8%EC%88%98-
#include "pipex.h"

int main(int argc, char *argv[], char *envp[])
//extern char **environ and int main(int argc, char *argv[], char *envp[])
{
    t_arg   *stru;
    //t_path  *temp;
    
    stru = (t_arg *)ft_calloc(1 , sizeof(t_arg));
    if (stru == NULL)
        error_exit(EXIT_STRU,"MALLOC FAIL","T_ARG");
    stru->env = envp;
    // temp = (t_path *)ft_calloc(1 , sizeof(t_path));
    // if (temp == NULL)
    //     error_exit(EXIT_STRU,"MALLOC FAIL","T_PATH");
    
   
    free(stru);
    return 0;
}

int execute(t_arg *stru)
{
    
}

    
int child_stdout(int pid, int oldfd, int newfile)
{
    if(pid == 0)
    {
        dup2(oldfd,newfile);
        close(fd);
        close(fd);
        execve("argv[2]","argv[1]","argv")

    }
    /*https://velog.io/@kyj93790/Pipex-%ED%99%98%EA%B2%BD%EB%B3%80%EC%88%98environment-variable-PATH*/
    return 0;
}