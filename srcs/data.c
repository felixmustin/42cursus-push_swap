/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmustin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 15:01:38 by fmustin           #+#    #+#             */
/*   Updated: 2022/01/05 15:01:41 by fmustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

int	ft_count_elem(char **args)
{
	int	n;
	int	i;

	i = 0;
	while (args[++i])
		n = ft_atoi(args[i]);
	i--;
	return (i);
}

int	ft_check_numeric(char *str)
{
	int	k;

	k = 0;
	while (str[k] != '\0')
	{
		if (!ft_isdigit(str[k]) && str[k] != 45)
			return (0);
		k++;
	}
	return (1);
}

int	ft_get_info(char **args, t_data *data)
{
	int	i;
	int	j;

	data->size = ft_count_elem(args);
	data->nbr = malloc(sizeof(long int) * data->size);
	if (!data->nbr)
		return (0);
	i = 0;
	j = 0;
	while (args[++i])
	{
		data->nbr[j++] = ft_atoi(args[i]);
		if (!ft_check_numeric(args[i]) || (data->nbr[j - 1] > 2147483647)
			|| (data->nbr[j - 1] < -2147483647))
		{
			ft_putstr("Error\n");
			free(data->nbr);
			return (0);
		}	
	}
	return (1);
}
