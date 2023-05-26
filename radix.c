/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 11:23:30 by hikaru            #+#    #+#             */
/*   Updated: 2023/05/26 19:24:04 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	main_sort(struct s_stack *a_head, struct s_stack *b_head, int element_num, int max_digit)
{
	int				i;
	int				j;
	int				num;

	i = 0;
	while (i < max_digit)
	{
		j = 0;
		if (is_sorted(a_head) == 0)
			return ;
		while (j < element_num)
		{
			num = a_head->next->num;
			if (((num >> i) & 1) == 0)
				push_to_b(a_head, b_head);
			else
				ra(a_head);
			j++;
		}
		while (b_head->next != b_head)
			push_to_a(a_head, b_head);
		i++;
	}
}

void	radix(t_stack *a_head, int element_num)
{
	int	max_num;
	int	max_digit;
	t_stack	b_head;

	b_head.next = &b_head;
	b_head.prev = &b_head;

	max_num = element_num - 1;
	max_digit = 0;
	while ((max_num >> max_digit) != 0)
		max_digit++;
	main_sort(a_head, &b_head, element_num, max_digit);
}
