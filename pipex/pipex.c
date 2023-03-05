/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sukwon <sukwon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:05:37 by sukwon            #+#    #+#             */
/*   Updated: 2023/03/04 23:46:21 by sukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
int main(int argc, char *argv[], char *env[])
{
    t_arg   *stru;
    
    stru = (t_arg *)ft_calloc(1 , sizeof(t_arg));
    if (stru == NULL)
        return NULL;
    
    
   
    free(stru);
    return 0;
}
int pipe_fd(int argc)
{
    int **pfd;
    pfd = (int **)malloc 
    if (pfd)
}
int exect()
int all_free(char * any)
{
    
}
    
    if(pipe_create(fd) == 1)
        exit (1);

    pid_t pid1;
    pid_t pid2;
    if(fork_handling(pid1) == 2 || fork_handling(pid2) == 2)
        exit (2);
    child_stdout();
    child_stdin();