/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sukwon <sukwon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:18:02 by sukwon            #+#    #+#             */
/*   Updated: 2023/03/06 21:20:16 by sukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int pipe_fd(t_arg *stru)
{
    int i;
    
    stru->pfd = (int **)malloc(stru->count_cmd - 1 * sizeof(int*)); //the bigger package one.
    if (!stru->pfd)
        error_exit(EXIT_PFD, "FAILURE MALLOCING PFD", NULL);
    i = 0;
    while (i < stru->count_cmd)
    {
        stru->pfd[i] = (int*)malloc( 2 * sizeof(int));
        if (!stru->pfd[i])
            error_exit(EXIT_PFD, "FAILURE MALLOCING PFD[i]", NULL);
        i++;
    }
    return (i);
}

int pipe_create(t_arg *stru)
{
    int i;
    int pipe_i;
    
    i = 0;
    pipe_i = pipe_fd(stru);
    while(i < pipe_i)
    {
        if(pipe(stru->pfd[i]) == -1)
        {
            while (0 <= i)
            {
                close(stru->pfd[i][read]);
                close(stru->pfd[i][write]);
                i--;
            }
            error_exit(EXIT_PIPE, "There is an error with piping", strerror(errno));
        }
        i++;
    }
    return 0;
} 
