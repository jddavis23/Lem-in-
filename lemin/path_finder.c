/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molesen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 09:38:32 by molesen           #+#    #+#             */
/*   Updated: 2022/07/12 09:38:35 by molesen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/lemin.h"

static int	calc_max(int nbr1, int nbr2)
{
	if (nbr1 < nbr2)
		return (nbr1);
	return (nbr2);
}

static int	len_array(int *links)
{
	int	i;

	i = 0;
	while (links[i] != -1)
		++i;
	return (i);
}

static void	make_temp(t_room *pass)
{
	// maps/subject3-1.map
	/*distance[0] = 0;
	distance[1] = 1;
	distance[2] = 1;
	distance[3] = 2;
	distance[4] = 2;
	distance[5] = 2;
	distance[6] = 2;
	distance[7] = 1;
	distance[8] = 2;
	distance[9] = 3;
	distance[10] = 0;
	distance[11] = 0;
	distance[12] = 0;
	distance[13] = 0;*/

	// maps/subject-short.map
	pass->distance[0] = 0;
	pass->distance[1] = 1;
	pass->distance[2] = 2;
	pass->distance[3] = pass->total;
}

/*
static void	*copy_struct(t_room *pass, int i)
{
	int	j;
	t_path *new;
	t_path *temp;
	t_path *head;

	j = pass->end;
	new = ft_pathnew();
	temp = pass->head;
	head = new;
	while (temp->index)
	{
		new->len++;
		new->index = ft_indexnew(temp->index->index, temp->index->prev_index);
		ft_indexadd(&head->index, new->index);
		if (new->index->index == i || temp->index->next == NULL)
		{
			new->index->next = NULL;
			break ;
		}
		temp->index = temp->index->next;
		new->index = new->index->next;
	}
	ft_path_add(&pass->head, head);
	return (head);
}*/
/*
static void	find_path(t_path *path, t_room *pass, int i, int prev_index)
{
	int	j;
	int	len;
	int	first;
	t_index *prev_path;
	t_path	*new;

	j = 0;
	prev_path = path->index;
	first = TRUE;
	// if (i == 0)
	// {
	// 	path->index = path->index->next;
	// 	path->index = ft_indexnew(0);
	// 	ft_indexadd(&prev_path, path->index);
	// 	//path->index = path->index->next;
	// 	//path->next = NULL;
	// 	path->len++;
	// 	//
	// 	//put end.
	// }
	// else 
	ft_printf("distance[i]: %d	prev: %d\n", pass->distance[i], prev_index);
		
	if (pass->distance[i] <= pass->distance[prev_index])
	{
		if (!path->index)
		{
			path->index = ft_indexnew(i, prev_index);
			ft_indexadd(&pass->index_head, path->index);
		}
		else
		{
			path->index = path->index->next;
			path->index = ft_indexnew(i, prev_index);
			ft_indexadd(&pass->index_head, path->index);
		}
		path->len++;
		len = len_array(pass->links[i]);
		while (j < len)
		{
			if (pass->links[i][j] == 0)
			{
				ft_printf("FOUND START![%d]\n", path->index->index);
				return ;
			}
			ft_printf("distance[passlinks i j]: %d	prev: %d\n", pass->distance[pass->links[i][j]], pass->distance[prev_index]);
			if (pass->distance[pass->links[i][j]] <= pass->distance[prev_index] && prev_index != pass->end && pass->links[i][j] != pass->end)
			{
				
				if (first == FALSE)
				{
					// ft_printf("HEllo\n");
					// //path = path->next;
					// ft_printf("len: %d\n", path->len);
					t_path *hello;
					
					hello = pass->head;
					// while (pass->head)
					// {
					// 	while (pass->head->index)
					// 	{
					// 		ft_printf("index: %d\n", pass->head->index->index);
					
					// 		pass->head->index = pass->head->index->next;
					// 	}
					// 	pass->head = pass->head->next;
					// }
					new = copy_struct(pass, i);
					ft_printf("new: %d\n", new->len);
					new = new->next;
					find_path(new, pass, pass->links[i][j], pass->distance[pass->links[i][j]]);
					// ft_printf("len: %d\n", pass->head->len);
					
					// pass->head = hello;
					// while (pass->head->next)
					// {
					// 	while (pass->head->index->next)
					// 	{
					// 		ft_printf("index: %d\n", pass->head->index->index);
					// 		pass->head->index = pass->head->index->next;
					// 	}
					// 	pass->head = pass->head->next;
					// }
					// ft_printf("distance links thingy: %d\n", j);
					// pass->head = hello;
					// NEED TO MAKE FUNCTION TO COPY STRUCT
					//copy struct and all its values until certain point
					// until 'i' has been found.
				}
				else
				{
					first = FALSE;
					find_path(path, pass, pass->links[i][j], pass->distance[pass->links[i][j]]);
				}
			}
			++j;
		}
		
		// collect new number to string 
		// update length
		// set next == null.
		//(void)path;
	}
}
*/
/*is it an error if there in the instructions shows a path connected to the same room twice?*/
/*
create a function that handles creating a new node with a variable and putting it to the linked list of indexes
make identical function for the path linked list.
*/

static t_path	*ft_pathnew()
{
	t_path	*new;

	new = (t_path *)malloc(sizeof(t_path));
	if (!new)
		return (NULL);
	new->len = 0;
	new->move = NULL;
	new->next = NULL;
	return (new);
}

static void	ft_path_add(t_path **path, t_path *new)
{
	if (!path || !new)
		return ;
	(*path)->next = new;
	*path = (*path)->next;
}

static void	create_path(t_path **path, t_room *pass)
{
	t_path *new;

	new = *path;
	new = ft_pathnew();
	new->nbr = pass->path_nbr;
	pass->path_nbr++;
	if (*path)
		ft_path_add(path, new);
	else
		*path = new;
}


static t_index	*ft_indexnew(int index, int prev)
{
	t_index	*new_list;

	new_list = (t_index *)malloc(sizeof(t_index));
	if (!new_list)
		return (NULL);
	new_list->index = index;
	new_list->prev_index = prev;
	new_list->next = NULL;
	return (new_list);
}

static void	ft_indexadd(t_index **index, t_index *new)
{
	if (!index || !new)
		return ;
	new->next = *index;
	*index = new;
}

static void	create_index(t_index **move, t_path *path, int i, int prev_index)
{
	t_index	*new;

	new = NULL;
	if (!(*move))
	{
		*move = ft_indexnew(i, prev_index);
		path->index_head = *move;
		path->move = *move;
	}
	else
	{
		new = ft_indexnew(i, prev_index);
		ft_indexadd(&path->index_head, new);
	}
}

int	path_finder(t_room *pass)
{
	int	max;
	int	len;
	int	i;
	//int	index;
	t_path *head;
	t_path	*path;

	len = len_array(pass->links[pass->end]);
	max = calc_max(len_array(pass->links[0]), len);
	if (max < 1)
		return (ERROR);
	make_temp(pass);
	path = NULL;
	i = 0;
	pass->path_nbr = 1;
	create_path(&path, pass);
	head = path;
	ft_printf("created first path\n");
	path->len = i;
	++i;
	int j = 0;
	create_index(&path->move, path, j, j+1);
	++j;
	create_index(&path->move, path, j, j+1);
	++j;
	create_index(&path->move, path, j, j+1);
	++j;
	create_index(&path->move, path, j, j+1);
	++j;
	ft_printf("created first index\n");
	create_path(&path, pass);
	path->len = i;
	++i;
	j = 0;
	create_index(&path->move, path, j, j+1);
	++j;
	create_index(&path->move, path, j, j+1);
	++j;
	create_index(&path->move, path, j, j+1);
	++j;
	create_index(&path->move, path, j, j+1);
	++j;
	ft_printf("created second path\n");
	create_path(&path, pass);
	path->len = i;
	++i;
	j = 0;
	create_index(&path->move, path, j, j+1);
	++j;
	create_index(&path->move, path, j, j+1);
	++j;
	create_index(&path->move, path, j, j+1);
	++j;
	create_index(&path->move, path, j, j+1);
	++j;
	ft_printf("created second path\n");
	create_path(&path, pass);
	path->len = i;
	++i;
	ft_printf("created second path\n");
	create_path(&path, pass);
	path->len = i;
	++i;
	j = 0;
	create_index(&path->move, path, j, j+1);
	++j;
	create_index(&path->move, path, j, j+1);
	++j;
	create_index(&path->move, path, j, j+1);
	++j;
	create_index(&path->move, path, j, j+1);
	++j;
	ft_printf("created second path\n");
	i = 0;

	//head = path;
	// path = ft_pathnew();
	// ft_indexadd(&pass->index_head, path->index);
	// path->index = pass->index_head;
	while (i < len)
	{
		// index = pass->links[pass->end][i];
		// if (index == 0)
		// {
		// 	//use path that leads directly to start. can move everything at the same time
		// 	break ;
		// }
		// else if (i > 0)
		// {
		// 	path->next = ft_pathnew();
		// 	path = path->next;
		// 	pass->head = path;
		// 	path->next = NULL;
		// 	ft_indexadd(&pass->index_head, path->index);
		// 	path->index = pass->index_head;
		// }
		//find_path(path, pass, index, pass->end);
		//move the path
		//path->nextf
		ft_printf("len: %d\n", path->len);
		++i;
	}
	// i = 0;
	// path = pass->head;
	// while (path)
	// {
	// 	path->len = i;
	// 	while (path->index)
	// 	{
	// 		ft_printf("index: %d\n", path->index->index);
	
	// 		path->index = path->index->next;
	// 	}
	// 	++i;
	// 	path = path->next;
	// }
	path = head;
	i = 0;
	while (path)
	{
		path->move = path->index_head;
		ft_printf("path\nnbr: %d	Len: %d	nbr of struct: %d\n", path->nbr, path->len, i);
		while (path->move)
		{
			ft_printf("index: %d\n", path->move->index);
	
			path->move = path->move->next;
		}
		++i;
		path = path->next;
	}
	//find_paths()
	// if shortest path is connected to end - move every ant at once
	// 
	//pass->links[0]
	//return error if no connections are found. ex if every path the first room is connected to has the value 0 and it is not the end we know it hasn't been updated
	// loop through the list of the nbrs and creates paths based on that. keep doing that until no more can be created
	// store everything in a linked list
	/* typedef struct s_paths
	{
		char *str; (easiest to have integers for comparing the paths with eachother)
		int len;
		struct s_paths *next;
	}	t_paths
	keep track of how many paths found starting from each location.

	*/
	return (0);
}


/*
create a function that handles creating a new node with a variable and putting it to the linked list of indexes
make identical function for the path linked list.
*/