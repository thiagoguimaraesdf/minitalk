/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguimara <tguimara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 09:20:24 by tguimara          #+#    #+#             */
/*   Updated: 2021/06/07 16:54:14 by tguimara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*nextdel;

	if (lst == NULL || del == NULL)
		return ;
	while (lst[0] != NULL)
	{
		del(lst[0]->content);
		nextdel = lst[0];
		lst[0] = nextdel->next;
		free(nextdel);
	}
	lst = NULL;
}
