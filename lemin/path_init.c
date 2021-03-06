/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molesen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 09:38:32 by molesen           #+#    #+#             */
/*   Updated: 2022/07/15 13:30:59 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/lemin.h"

/*	function that checks if a room is already in use	*/

static int	create_used(t_room *pass)
{
	int	i;

	i = 0;
	pass->used = (int *) malloc(pass->total * sizeof(int));
	if (!pass->used)
		return (ERROR);
	while (i < pass->total)
		pass->used[i++] = FALSE;
	return (0);
}

/*	checks if end has been correctly sorted	*/

static int	is_sorted(t_room *pass)
{
	int	i;

	i = 0;
	while (i < (pass->len - 1))
	{
		if (pass->distance[pass->links[pass->end][i]] > pass->distance[pass->links[pass->end][i + 1]])
			return (FALSE);
		++i;
	}
	return (TRUE);
}

/*	sorts the links of the end. Shortest paths in the beginning	*/

static void	sort_end(t_room *pass)
{
	int	i;
	int	temp;

	i = 0;
	// might remove is sorted from while loop and instead put in bottom - depends what is faster - check with bigger values
	while (is_sorted(pass) == FALSE)
	{
		if (pass->distance[pass->links[pass->end][i]] > pass->distance[pass->links[pass->end][i + 1]])
		{
			temp = pass->links[pass->end][i];
			pass->links[pass->end][i] = pass->links[pass->end][i + 1];
			pass->links[pass->end][i + 1] = temp;
		}
		if (i < (pass->len - 1))
			++i;
		else
			i = 0;
	}
}

int	initialize_path_finder(t_room *pass, char *input)
{
	int i;
	t_path	*path;
	t_path	*final;

	path = NULL;
	final = NULL;
	pass->path_nbr = 1;
	pass->longest_path = 0;
	if (create_used(pass) == ERROR)
		return (error_path(pass, input, TRUE));
	sort_end(pass);
	pass->final_head = NULL;
	path_finder(&path, pass);
	if (!pass->final_head)
		return (error_path(pass, input, TRUE));
	final = pass->final_head;
	i = 0;
	ft_printf("\n{green}finalS:{uncolor} \n");
	while (final)
	{
		final->move = final->move_head;
		ft_printf("final\nnbr: %d	Len: %d	nbr of struct: %d\n", final->nbr, final->len, i);
		while (final->move)
		{
			ft_printf("room: %s\n", pass->rooms[final->move->index]);
			final->move = final->move->next;
		}
		++i;
		final = final->next;
	}
	//error_path(pass, input, FALSE);
	return (0);
}
