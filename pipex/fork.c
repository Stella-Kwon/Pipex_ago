/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sukwon <sukwon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:20:42 by sukwon            #+#    #+#             */
/*   Updated: 2023/03/11 20:29:23 by sukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int excution(t_arg stru, char **argv)
{
    pid_t pid;

    pid = fork();
    if(pid < 0)
        exit_error(EXIT_FAILURE,"fork failure", strerror(errno));
    
    if(pid == 0)
    {
        
    }
    else
    {

    }

    
    
    
}
int infile(int argc, char **argv)
{
    int infile;
    int infile2;
    
    infile = open(argv[1], O_RDONLY|O_TRUNC|O_CREAT, 0777);
    if(infile < 0)
        exit_error(EXIT_FAILURE,"infile open fail",NULL);
    infile2 = dup2(infile,STDIN_FILENO);
    if(infile2 < 0)
        exit_error(EXIT_FAILURE,"infile dup2 fail",strerror(errno));
    close(infile);
}

int outfile(int argc, char **argv)
{
    int outfile;
    int outfile2;
    
    outfile = open(argv[argc -1], O_WRONLY|O_TRUNC|O_CREAT, 0777);
    if(outfile < 0)
        exit_error(EXIT_FAILURE,"outfile open fail",NULL);
    outfile2 = dup2(outfile,STDOUT_FILENO);
    if(outfile2 < 0)
        exit_error(EXIT_FAILURE,"outfile dup2 fail",strerror(errno));
    close(outfile);
}