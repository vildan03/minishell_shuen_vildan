/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vikaradu <vikaradu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:54:41 by vikaradu          #+#    #+#             */
/*   Updated: 2025/11/20 18:07:27 by vikaradu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temporary;

	if (!del || !lst)
		return ;
	while (*lst)
	{
		temporary = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = temporary;
	}
	*lst = NULL;
}
