/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:32:42 by yurolive          #+#    #+#             */
/*   Updated: 2025/05/15 11:11:38 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "lexer.h"

t_tokens	check_token(int c)
{
	static int	token_arr[3][2] = {
	{'|', PIPE},
	{'>', GREAT},
	{'<', LESS},
	};
	int			i;

	i = 0;
	while (i < 3)
	{
		if (token_arr[i][0] == c)
			return (token_arr[i][1]);
		i++;
	}
	return (0);
}

int	handle_token(char *str, int i, t_lexer **lexer_list)
{
	t_tokens	token;

	token = check_token(str[i]);
	if (token == GREAT && check_token(str[i + 1]) == GREAT)
	{
		if (!add_node(NULL, GREAT_GREAT, lexer_list))
			return (-1);
		return (2);
	}
	else if (token == LESS && check_token(str[i + 1]) == LESS)
	{
		if (!add_node(NULL, LESS_LESS, lexer_list))
			return (-1);
		return (2);
	}
	else if (token)
	{
		if (!add_node(NULL, token, lexer_list))
			return (-1);
		return (1);
	}
	return (0);
}
