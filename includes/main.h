/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmustin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 15:02:43 by fmustin           #+#    #+#             */
/*   Updated: 2022/01/05 15:02:45 by fmustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_data
{
	long int	*nbr;
	int			size;
	int			n;
}	t_data;

long int	ft_atoi(const char *str);
void		ft_bzero(void *s, int n);
void		ft_putstr(char *str);
int			ft_isdigit(int c);

int			ft_count_elem(char **args);
int			ft_get_info(char **args, t_data *data);

int			*ft_copy_list(t_data *data);
int			*ft_sort_list(int *cpy, t_data *data);
int			*ft_simplify_list(int *list, int *sorted_list, t_data *data);

int			*ft_create_b(t_data *data);
int			ft_parse_stack(t_data *data, int *stack);
int			ft_create_stack(t_data *data, int **stack);

void		ra(int *s_a, t_data *data);
void		rra(int *s_a, t_data *data);
int			pa(int *s_a, int *s_b, t_data *data);
int			pb(int *s_a, int *s_b, t_data *data);
void		sa(int *s_a, t_data *data);

void		ft_sort_s_stack(int **s_a, int **s_b, t_data *data);
void		ft_sort_b_stack(int **s_a, int **s_b, int *buffer, t_data *data);

#endif
