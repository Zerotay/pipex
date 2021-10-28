/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongguki <dongguki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 10:09:29 by dongguki          #+#    #+#             */
/*   Updated: 2021/10/13 14:30:38 by dongguki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strset(char *s, char *set)
{
	int	i;
	int	j;

	if (!s || !set)
		return (-1);
	i = 0;
	while (s[i])
	{
		j = -1;
		while (set[++j])
			if (s[i] == set[j])
				break ;
		if (!set[j])
			return (0);
		i++;
	}
	return (1);
}
