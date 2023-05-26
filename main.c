/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:12:45 by hmorisak          #+#    #+#             */
/*   Updated: 2023/05/26 20:46:59 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count;

void	print_stack(t_stack *head)
{
	t_stack	*tmp;

	tmp = head->next;
	while (tmp != head)
	{
		printf("%d ", tmp->num);
		tmp = tmp->next;
	}
	printf("\n");
}

int	count_stack(t_stack *stack_head)
{
	int		count;
	t_stack	*tmp;

	count = 0;
	tmp = stack_head->next;
	while (tmp != stack_head)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

int	creat_stack(t_stack *stack_head, int element_num, t_array *array)
{
	int		i;
	t_stack	*stack;

	i = 0;
	while (i < element_num)
	{
		stack = (t_stack *)malloc(sizeof(t_stack));
		if (!stack)
			return (ft_free(stack_head));
		stack->num = array[i].num;
		insert(stack_head, stack);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	a_head;
	t_array	*array;
	FILE	*infile;
	char	line[512];
	char	**elements;
	char	**tmp;
	int		elements_num;
	clock_t	start_clock, end_clock;
	char	command;

	a_head.next = &a_head;
	a_head.prev = &a_head;
	//コマンドライン引数としてデータを格納したcsvファイルを受け取る
	if (argc != 2)
		return (printf("invalid input\n"));
	infile = fopen(argv[1], "rt+, ccs=UTF-8");
	elements_num = 0;
	while (fgets(line, 512, infile) != NULL)
		elements_num++;
	elements = (char **)malloc(sizeof(char *)*elements_num);
	if (!elements)
		return (printf("malloc error\n"));
	elements_num = 0;
	fseek(infile, 0L, SEEK_SET);
	//データをelementsに格納する
	while (fgets(line, 512, infile) != NULL)
	{
		tmp = ft_split(line, '\n');
		elements[elements_num] = ft_strdup(tmp[0]);
		elements_num++;
	}
	//座標圧縮
	array = pre_sort(elements_num, elements);
	if (!array)
		return (1);
	//データの個数が一つ以下の場合、終了する
	if (elements_num <= 2)
		return (array_free(array));
	//スタックの生成
	if (creat_stack(&a_head, elements_num, &array[1]) != 0)
		return (array_free(array));
	array_free(array);
	//すでにソート済みの場合、終了する
	if (is_sorted(&a_head) == 0)
		return (ft_free(&a_head));

	//各ソートアルゴリズム
	printf("[q]       Quick Sort\n"); //クイックソート
	printf("[r]       Radix Sort\n"); //基数ソート
	printf("[m]       My Sort\n"); //自作アルゴリズム
	printf("[e]       Exit\n");

	//ソートアルゴリズムの選択
	while (1)
	{
		scanf(" %c", &command);
		if (command == 'q' || command == 'r' || command == 'm')
			break ;
		if (command == 'e')
			return (0);
		printf("invalid input. try again!\n");
	}
	printf("now sorting...\n");
	//ソート開始時刻
	start_clock = clock();
	switch (command)
	{
		case 'q':	quick(&a_head, elements_num-1); break;
		case 'r':	radix(&a_head, elements_num); break;
		case 'm':	my_sort(&a_head, elements_num); break;
	}
	//ソート終了時刻
	end_clock = clock();

	printf("<result>\n");
	//ソートが成功しているか確認
	if (is_sorted(&a_head) == 0)
		printf("sorted!!\n");
	else
		printf("not sorted...\n");
	//比較回数・測定時間の表示
	printf("count = %d\n", count);
	printf("time = %f\n", (double)(end_clock - start_clock) / CLOCKS_PER_SEC);
	//スタックを表示
	// print_stack(&a_head);
	
	return (ft_free(&a_head));
}
