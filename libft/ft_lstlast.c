
#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last;

	if (!lst)
		return (NULL);
	while (lst)
	{
		if (lst->next == NULL)
			last = lst;
		lst = lst->next;
	}
	return (last);
}
