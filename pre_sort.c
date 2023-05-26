/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:20:17 by hmorisak          #+#    #+#             */
/*   Updated: 2023/05/26 15:42:10 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a_head)
{
	t_stack	*tmp;

	tmp = a_head->next;
	while (tmp != a_head && tmp->next != a_head)
	{
		if (tmp->num > tmp->next->num)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

t_array	*scale_down(t_array *array, int min_index, int element_num)
{
	int	cnt;
	int	i;

	cnt = 0;
	while (cnt < element_num)
	{
		i = 1;
		min_index = 0;
		while (i < element_num + 1)
		{
			if (array[i].flag != 1 && array[i].tmp < array[min_index].tmp)
				min_index = i;
			i++;
		}
		array[min_index].num = cnt;
		array[min_index].flag = 1;
		cnt++;
	}
	return (array);
}

t_array	*pre_sort(int element_num, char **argv)
{
	t_array	*array;
	int		i;
	int		min_index;

	i = 0;
	min_index = 0;
	array = (t_array *)malloc(sizeof(t_array) * (element_num + 2));
	if (!array)
		return (NULL);
	array[0].num = LONG_MAX;
	array[0].tmp = LONG_MAX;
	while (i < element_num)
	{
		array[i+1].tmp = atof(argv[i]);
		array[i+1].flag = 0;
		i++;
	}
	array[i + 1].flag = 2;
	return (scale_down(array, min_index, element_num));
}
