/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 20:09:04 by hikaru            #+#    #+#             */
/*   Updated: 2023/05/26 11:12:16 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_b_stack(t_stack *a_head, t_stack *b_head, int max, int b_stack_num)
{
	int	flag;
	int	tmp;

	tmp = b_stack_num;
	while (b_head->next != b_head)
	{
		flag = max_to_a(a_head, b_head, max,
				find_max_pos(b_head, max, b_stack_num));
		if (flag == 1)
		{
			max -= 2;
			b_stack_num -= 2;
		}
		else
		{
			max -= 1;
			b_stack_num -= 1;
		}
	}
	while (tmp--)
		ra(a_head);
}

void	half_sort(t_stack *a_head, t_stack *b_head)
{
	int		b_stack_num;
	int		half;
	int		pivot;

	b_stack_num = count_stack(b_head);
	half = 0;
	pivot = 0;
	if (b_stack_num <= 6)
		sort_b_stack(a_head, b_head, find_min(b_head, count_stack(b_head)) + count_stack(b_head) - 1, b_stack_num);
	else
	{
		half = b_stack_num / 2;
		pivot = find_min(b_head, count_stack(b_head)) + half;
		while (count_stack(b_head) > half)
		{
			if (b_head->next->num < pivot)
				rb(b_head);
			else
				push_to_a(a_head, b_head);
		}
		half_sort(a_head, b_head);
		while (b_stack_num - half > 0)
		{
			push_to_b(a_head, b_head);
			b_stack_num--;
		}
		half_sort(a_head, b_head);
	}
}

void	quick(t_stack *a_head, int element_num)
{
	int	half;
	t_stack	b_head;

	half = element_num / 2;
	b_head.next = &b_head;
	b_head.prev = &b_head;
	while (count_stack(&b_head) < half)
	{
		if (0 <= a_head->next->num && a_head->next->num < half)
			push_to_b(a_head, &b_head);
		ra(a_head);
	}
	half_sort(a_head, &b_head);
	while (count_stack(a_head) - half > 0)
		push_to_b(a_head, &b_head);
	half_sort(a_head, &b_head);
}