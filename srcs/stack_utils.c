/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmustin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 15:02:24 by fmustin           #+#    #+#             */
/*   Updated: 2022/01/05 15:02:25 by fmustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

int	*ft_copy_list(t_data *data)
{
	int	*cpy;
	int	i;

	cpy = malloc(sizeof(int) * data->size);
	if (!cpy)
		return (0);
	i = 0;
	while (i < data->size)
	{
		cpy[i] = data->nbr[i];
		i++;
	}
	return (cpy);
}

int	*ft_sort_list(int *cpy, t_data *data)
{
	int	i;
	int	j;
	int	tmp;
	int	j_tmp;

	i = 0;
	while (i < data->size)
	{
		j = 0;
		tmp = cpy[j];
		j_tmp = 0;
		while (j < data->size - i)
		{
			if (cpy[j] > tmp)
			{
				tmp = cpy[j];
				j_tmp = j;
			}
			j++;
		}
		cpy[j_tmp] = cpy[data->size - 1 - i];
		cpy[data->size - 1 - i] = tmp;
		i++;
	}
	return (cpy);
}

int	*ft_simplify_list(int *list, int *sorted_list, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->size)
	{
		j = 0;
		while (j < data->size)
		{
			if (list[i] == sorted_list[j])
			{
				list[i] = j;
				j = data->size;
			}
			j++;
		}
		i++;
	}
	return (list);
}
