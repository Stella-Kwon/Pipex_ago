/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorhandling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sukwon <sukwon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:05:47 by sukwon            #+#    #+#             */
/*   Updated: 2023/03/15 15:36:34 by sukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
//need to store some result in the outfile, so using ft_pustr_fd
int error_exit(int exitnum, char * mess, char * filename)
{
    ft_putstr_fd ("zsh: ", 2);
    if(mess)
        ft_putstr_fd(mess, 2);
    if(filename)
    { 
        ft_putstr_fd(": ", 2);
        ft_putstr_fd(filename, 2);
    }
    ft_putstr_fd("\n", 2);
    return(exitnum);
}

//> < if there is no redirection symbol while using grep, cat then it will give its command name rather than zsh