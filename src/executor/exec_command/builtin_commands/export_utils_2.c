/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kerlee <kerlee@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 17:22:35 by kerlee            #+#    #+#             */
/*   Updated: 2026/06/22 17:23:14 by kerlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "minishell.h"

void	sort_export(char **export)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (export[i])
	{
		j = i + 1;
		while (export[j])
		{
			if (ft_strcmp(export[i], export[j]) > 0)
			{
				tmp = export[i];
				export[i] = export[j];
				export[j] = tmp;
			}
			j++;
		}
		i++;
	}
}
