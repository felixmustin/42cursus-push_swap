/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmustin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 15:02:05 by fmustin           #+#    #+#             */
/*   Updated: 2022/01/05 15:02:07 by fmustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

int	ft_max_bits(t_data *data)
{
	int	max_num;
	int	max_bits;

	max_num = data->size - 1;
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

int	ft_opti_pb(int *buffer, int i)
{
	int	j;
	int	n;

	j = 0;
	n = 0;
	if (buffer[i] == 2)
	{
		while (buffer[i + j] == 2)
		{
			n++;
			j++;
		}
	}
	if (buffer[i + j] == 3)
	{
		while (buffer[i + j] == 3 && n-- > 0)
			i++;
		i += j;
	}
	return (i);
}

void	ft_optimize(int *buffer, int **s_a, int **s_b, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n + 1)
	{
		if (buffer[i] == 1)
			ra(*s_a, data);
		else
		{
			i = ft_opti_pb(buffer, i);
			if (buffer[i] == 3)
				pa(*s_a, *s_b, data);
			else if (buffer[i] == 2)
				pb(*s_a, *s_b, data);
		}
		i++;
	}
}

void	ft_sort_b_stack(int **s_a, int **s_b, int *buffer, t_data *data)
{
	int	k;
	int	i;
	int	j;

	i = -1;
	while (++i < ft_max_bits(data))
	{
		data->n = -1;
		k = 0;
		j = -1;
		while (++j < data->size)
		{
			if (((*(*s_a + j) >> i) & 1) == 1)
				buffer[++data->n] = 1;
			else
			{
				buffer[++data->n] = 2;
				k++;
			}
		}
		while (k-- > 0)
			buffer[++data->n] = 3;
		ft_optimize(buffer, s_a, s_b, data);
	}
}
