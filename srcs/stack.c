/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmustin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 15:02:18 by fmustin           #+#    #+#             */
/*   Updated: 2022/01/05 15:02:19 by fmustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

int	*ft_create_b(t_data *data)
{
	int	i;
	int	*stack_b;

	stack_b = malloc(sizeof(int) * data->size);
	if (!stack_b)
		return (0);
	i = 0;
	while (i < data->size)
	{
		stack_b[i] = -1;
		i++;
	}
	return (stack_b);
}

int	ft_ordered(t_data *data, int *stack)
{
	int	i;

	i = 0;
	while (stack[i] < stack[i + 1])
	{
		if (i < data->size - 2)
			i++;
		else
			return (0);
	}
	return (1);
}

int	ft_parse_stack(t_data *data, int *stack)
{
	int	i;
	int	j;

	if (data->size == 1)
		return (0);
	if (!ft_ordered(data, stack))
		return (0);
	i = -1;
	while (++i < data->size)
	{
		j = i + 1;
		while (j < data->size)
		{
			if (stack[j] != stack[i])
				j++;
			else
				return (-1);
		}
	}
	return (1);
}

int	ft_create_stack(t_data *data, int **stack)
{
	int	*sorted_cpy;
	int	ret;

	*stack = ft_copy_list(data);
	if (!*stack)
		return (0);
	sorted_cpy = ft_sort_list(ft_copy_list(data), data);
	if (!sorted_cpy)
		return (0);
	ft_simplify_list(*stack, sorted_cpy, data);
	free(sorted_cpy);
	ret = ft_parse_stack(data, *stack);
	if (ret < 0)
	{
		ft_putstr("Error\n");
		return (0);
	}
	else if (ret == 0)
		return (0);
	return (1);
}
