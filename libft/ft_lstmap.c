/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonhki <hyeonhki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 23:01:14 by hyeonhki          #+#    #+#             */
/*   Updated: 2021/01/08 20:46:59 by hyeonhki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *temp;
	t_list *new;
	t_list *start;

	if (lst)
	{
		temp = lst;
		if (!(start = ft_lstnew(f(temp->content))))
			return (0);
		temp = temp->next;
		while (temp)
		{
			if (!(new = ft_lstnew(f(temp->content))))
			{
				ft_lstclear(&start, del);
				return (0);
			}
			ft_lstadd_back(&start, new);
			temp = temp->next;
		}
		return (start);
	}
	return (0);
}
