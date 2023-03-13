/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sukwon <sukwon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:34:15 by sukwon            #+#    #+#             */
/*   Updated: 2022/11/16 14:13:21 by sukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*head;
	t_list	*tail;

	if (!lst || !del)
		return ;
	if (!(*lst))
		return ;
	head = *lst;
	while (head)
	{
		tail = head -> next;
		ft_lstdelone(head, del);
		head = tail;
	}
	*lst = NULL;
}
