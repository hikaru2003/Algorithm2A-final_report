/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:13:09 by hmorisak          #+#    #+#             */
/*   Updated: 2023/05/26 20:36:11 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count;

void	insert(t_stack *stack, t_stack *new)
{
	new->prev = stack->prev;
	stack->prev->next = new;
	stack->prev = new;
	new->next = stack;
}

void	pop(t_stack *stack)
{
	stack->prev->next = stack->next;
	stack->next->prev = stack->prev;
}

void	push_to(t_stack *to_head, t_stack *from_head)
{
	t_stack	*tmp;

	if (from_head == NULL || from_head->next == from_head)
		return ;
	tmp = from_head->next;
	pop(from_head->next);
	insert(to_head->next, tmp);
}

void	push_to_a(t_stack *a_head, t_stack *b_head)
{
	push_to(a_head, b_head);
	count++;
}

void	push_to_b(t_stack *a_head, t_stack *b_head)
{
	push_to(b_head, a_head);
	count++;
}
