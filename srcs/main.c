/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmustin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 15:01:52 by fmustin           #+#    #+#             */
/*   Updated: 2022/01/05 15:01:54 by fmustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

int	main(int argc, char **argv)
{
	t_data	data;
	int		*stack_a;
	int		*stack_b;
	int		buffer[1000];

	if (argc < 2)
		return (0);
	if (!ft_get_info(argv, &data))
	{
		system("leaks push_swap");
		return (0);
	}
	if (ft_create_stack(&data, &stack_a))
	{
		stack_b = ft_create_b(&data);
		if (data.size <= 5)
			ft_sort_s_stack(&stack_a, &stack_b, &data);
		else
			ft_sort_b_stack(&stack_a, &stack_b, buffer, &data);
		free(stack_b);
	}
	free(stack_a);
	free(data.nbr);
}
