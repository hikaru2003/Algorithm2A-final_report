/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 20:55:19 by hmorisak          #+#    #+#             */
/*   Updated: 2023/05/26 20:36:32 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count;

void	swap(t_stack *head)
{
	t_stack	*head_next;
	int		tmp;

	head_next = head->next;
	if (head_next == head || head_next->next == head)
		return ;
	tmp = head_next->num;
	head_next->num = head_next->next->num;
	head_next->next->num = tmp;
}

void	sa(t_stack *a_head)
{
	swap(a_head);
	count++;
}

void	sb(t_stack *b_head)
{
	swap(b_head);
	count++;
}

void	ss(t_stack *a_head, t_stack *b_head)
{
	swap(a_head);
	swap(b_head);
	count++;
}
