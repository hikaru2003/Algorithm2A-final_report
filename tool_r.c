/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_r.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 20:55:09 by hmorisak          #+#    #+#             */
/*   Updated: 2023/05/26 20:36:18 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count;

void	rotate(t_stack *head)
{
	t_stack	*tmp;
	int		top_num;

	if (head->next == head)
		return ;
	tmp = head->next;
	top_num = tmp->num;
	while (tmp->next != head)
	{
		tmp->num = tmp->next->num;
		tmp = tmp->next;
	}
	tmp->num = top_num;
}

void	ra(t_stack *a_head)
{
	rotate(a_head);
	count++;
}

void	rb(t_stack *b_head)
{
	rotate(b_head);
	count++;
}

void	rr(t_stack *a_head, t_stack *b_head)
{
	rotate(a_head);
	rotate(b_head);
	count++;
}
