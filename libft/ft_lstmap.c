/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongguki <dongguki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 12:47:23 by dongguki          #+#    #+#             */
/*   Updated: 2021/10/13 14:33:27 by dongguki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*curr;
	t_list		*ans;

	ans = ft_lstnew(f(lst->content));
	if (!lst || !del || !ans)
		return (0);
	curr = ans;
	lst = lst->next;
	while (lst)
	{
		curr->next = ft_lstnew(f(lst->content));
		if (!curr->next)
		{
			ft_lstclear(&ans, del);
			return (0);
		}
		curr = curr->next;
		lst = lst->next;
	}
	return (ans);
}
