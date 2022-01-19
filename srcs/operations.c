/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmustin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 15:01:58 by fmustin           #+#    #+#             */
/*   Updated: 2022/01/05 15:02:00 by fmustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

void	rra(int *s_a, t_data *data)
{
	int	i;
	int	tmp;

	i = data->size - 1;
	tmp = s_a[i];
	while (i > 0 && s_a[i - 1] >= 0 && s_a[i] >= 0)
	{
		s_a[i] = s_a[i - 1];
		i--;
	}
	s_a[i] = tmp;
	ft_putstr("rra\n");
}

void	ra(int *s_a, t_data *data)
{
	int	i;
	int	tmp;

	i = 0;
	while (s_a[i] < 0)
		i++;
	tmp = s_a[i];
	while (i < data->size - 1)
	{
		if (s_a[i] >= 0)
			s_a[i] = s_a[i + 1];
		i++;
	}
	s_a[i] = tmp;
	ft_putstr("ra\n");
}

int	pa(int *s_a, int *s_b, t_data *data)
{
	int	i;
	int	k;

	ft_putstr("pa\n");
	i = 0;
	while (i < data->size)
	{
		if (s_b[i] >= 0)
		{
			k = 0;
			while (k < data->size)
			{
				if (s_a[k] < 0 && s_a[k + 1] >= 0)
				{
					s_a[k] = s_b[i];
					s_b[i] = -1;
					return (1);
				}
				k++;
			}
		}
		i++;
	}
	return (0);
}

int	pb(int *s_a, int *s_b, t_data *data)
{
	int	i;
	int	k;

	ft_putstr("pb\n");
	i = -1;
	while (++i < data->size)
	{
		if (s_a[i] >= 0)
		{
			k = -1;
			while (++k < data->size - 1)
			{
				if (s_b[k] < 0 && s_b[k + 1] >= 0)
				{
					s_b[k] = s_a[i];
					s_a[i] = -1;
					return (1);
				}
			}
			s_b[k] = s_a[i];
			s_a[i] = -1;
			return (1);
		}
	}
	return (0);
}

void	sa(int *s_a, t_data *data)
{
	int	i;
	int	tmp;

	i = 0;
	while (s_a[i] < 0)
		i++;
	if (i + 1 < data->size)
	{
		tmp = s_a[i];
		s_a[i] = s_a[i + 1];
		s_a[i + 1] = tmp;
		ft_putstr("sa\n");
	}
}
