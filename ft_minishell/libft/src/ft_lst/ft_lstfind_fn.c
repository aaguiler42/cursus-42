/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind_fn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 19:19:07 by ngonzale          #+#    #+#             */
/*   Updated: 2023/01/23 03:51:49 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfind_fn(t_list *lst, void *data_ref, int (*cmp)())
{
	t_list	*l;

	l = lst;
	while (l && cmp(l->content, data_ref, 5))
		l = l->next;
	return (l);
}
