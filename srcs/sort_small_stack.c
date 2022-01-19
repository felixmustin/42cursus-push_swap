/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmustin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 15:02:12 by fmustin           #+#    #+#             */
/*   Updated: 2022/01/05 15:02:13 by fmustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

int	ft_is_ordered(int *s_a, t_data *data)
{
	int	i;

	i = 0;
	while (s_a[i] < 0)
		i++;
	while (s_a[i] < s_a[i + 1])
	{
		if (i < data->size - 2)
			i++;
		else
			return (0);
	}
	return (1);
}

void	ft_sort_size_3(int *s_a, t_data *data)
{
	int	i;

	i = 0;
	if (!ft_is_ordered(s_a, data))
		return ;
	while (s_a[i] < 0)
		i++;
	if ((s_a[i] > s_a[i + 1]) && (s_a[i] > s_a[i + 2]))
	{
		ra(s_a, data);
		if (s_a[i] > s_a[i + 1])
			sa(s_a, data);
	}
	else if ((s_a[i] < s_a[i + 1]) && (s_a[i] < s_a[i + 2]))
	{
		rra(s_a, data);
		sa(s_a, data);
	}
	else
	{
		if (s_a[i + 1] < s_a[i])
			sa(s_a, data);
		else if (s_a[i + 1] > s_a[i])
			rra(s_a, data);
	}
}

void	ft_sort_size_4(int *s_a, int *s_b, t_data *data)
{
	int	i;

	pb(s_a, s_b, data);
	ft_sort_size_3(s_a, data);
	pa(s_a, s_b, data);
	i = 0;
	while (s_a[i] < 0)
		i++;
	if ((s_a[i] < s_a[i + 1]) && (s_a[i] < s_a[i + 2])
		&& (s_a[i] < s_a[i + 3]))
		return ;
	else if ((s_a[i] > s_a[i + 1]) && (s_a[i] > s_a[i + 2])
		&& (s_a[i] < s_a[i + 3]))
	{
		rra(s_a, data);
		sa(s_a, data);
		ra(s_a, data);
		ra(s_a, data);
	}
	else if ((s_a[i] > s_a[i + 1]) && (s_a[i] > s_a[i + 2])
		&& (s_a[i] > s_a[i + 3]))
		ra(s_a, data);
	else
		sa(s_a, data);
}

void	ft_sort_size_5(int *s_a, int *s_b, t_data *data)
{
	if ((s_a[0] == 2 && s_a[1] == 3) || (s_a[0] == 3 && s_a[1] == 2))
		ra(s_a, data);
	pb(s_a, s_b, data);
	ft_sort_size_4(s_a, s_b, data);
	pa(s_a, s_b, data);
	if (s_a[0] == 1)
		sa(s_a, data);
	if (s_a[0] == 2)
	{
		sa(s_a, data);
		ra(s_a, data);
		sa(s_a, data);
		rra(s_a, data);
	}
	if (s_a[0] == 3)
	{
		rra(s_a, data);
		sa(s_a, data);
		ra(s_a, data);
		ra(s_a, data);
	}
	if (s_a[0] == 4)
		ra(s_a, data);
}

void	ft_sort_s_stack(int **s_a, int **s_b, t_data *data)
{
	if (data->size == 2)
		ft_putstr("sa\n");
	if (data->size == 3)
		ft_sort_size_3(*s_a, data);
	if (data->size == 4)
		ft_sort_size_4(*s_a, *s_b, data);
	if (data->size == 5)
		ft_sort_size_5(*s_a, *s_b, data);
}
