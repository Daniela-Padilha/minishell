/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   42_empties_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:50:40 by isabel            #+#    #+#             */
/*   Updated: 2025/06/04 15:05:56 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

bool	emp_1(char *nl, const char *line, int tmp_i)
{
	if ((ft_strncmp("\"\"", nl, 2) == 0 || ft_strncmp("''", nl, 2) == 0)
		&& ((((tmp_i > 0 && ft_strchr(WS, line[tmp_i - 1]))
					&& (nl[2] && ft_strchr(WS, nl[2]))))))
		return (true);
	return (false);
}

bool	emp_2(char *nl, bool fl)
{
	if ((fl && (nl[2] && ft_strchr(WS, nl[2]))) || (fl && !nl[2]))
		return (true);
	return (false);
}

void	first_and_pipe(t_tk_lst ***curr_f, t_tk_lst *curr_p, bool *env)
{
	if (curr_f && (**curr_f))
	{
		while ((**curr_f)->next)
			(**curr_f) = (**curr_f)->next;
	}
	if (curr_p)
	{
		if ((curr_p && curr_p->type == PIPE
				&& ((curr_p->prev && curr_p->prev->type != ENV_CMD)
					|| ((curr_p->prev && curr_p->prev->type == W_SPACE)
						&& (curr_p->prev->prev
							&& curr_p->prev->prev->type != ENV_CMD)))))
			*env = true;
	}
}

void	rm_empties_case(t_tk_lst **curr, bool env)
{
	if ((*curr)->next && (*curr)->next->type == W_SPACE
		&& (*curr)->next->next)
	{
		if (((*curr)->next->next->type == BT_CMD
				|| (*curr)->next->next->type == ARG) && !env)
			empties_rmv_tk(&curr);
	}
	else if ((*curr)->next && ((*curr)->next->type == BT_CMD
			|| (*curr)->next->type == ARG) && !env)
		empties_rmv_tk(&curr);
	else if (!(*curr)->next && (*curr)->prev && !(*curr)->quotes.sp_case
		&& ((*curr)->prev->type == BT_CMD || (*curr)->prev->type == ARG) && !env)
		empties_rmv_tk(&curr);
}
