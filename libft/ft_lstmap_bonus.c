/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:39:14 by francoma          #+#    #+#             */
/*   Updated: 2023/01/10 15:21:58 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	_ft_lstmap(t_list *l1, t_list *l2, void *(*f)(void *),
	void (*del)(void *))
{
	void	*content;

	if (l1->next)
	{
		content = f(l1->next->content);
		l2->next = ft_lstnew(content);
		if (!l2->next)
		{
			del(content);
			return (0);
		}
		return (_ft_lstmap(l1->next, l2->next, f, del));
	}
	return (1);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	void	*content;
	t_list	*l2;

	if (!lst || !f || !*f || !del || !*del)
		return (0);
	content = f(lst->content);
	l2 = ft_lstnew(content);
	if (!l2)
	{
		del(content);
		return (NULL);
	}
	if (!_ft_lstmap(lst, l2, f, del))
		ft_lstclear(&l2, del);
	return (l2);
}
