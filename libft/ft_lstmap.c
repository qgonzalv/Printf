/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgonzalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 15:52:41 by qgonzalv          #+#    #+#             */
/*   Updated: 2017/12/04 20:13:54 by qgonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new;
	t_list		*final;
	t_list		*tmp;

	if (!lst)
		return (NULL);
	new = NULL;
	while (lst)
	{
		tmp = f(lst);
		if (!new)
		{
			new = tmp;
			final = new;
		}
		else if (tmp != NULL)
		{
			new->next = tmp;
			new = new->next;
		}
		lst = lst->next;
	}
	return (final);
}
