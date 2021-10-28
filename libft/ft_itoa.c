/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongguki <dongguki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 13:11:31 by dongguki          #+#    #+#             */
/*   Updated: 2021/10/13 15:29:20 by dongguki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	check_length(int n)
{
	int	i;

	i = 0;
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*ans;
	size_t	i;
	int		j;

	i = 1;
	if (n < 0)
		i = 2;
	j = n;
	i += check_length(n);
	ans = ft_calloc(i + 1, 1);
	if (!ans)
		return (0);
	ans[0] = '0';
	if (j < 0)
		ans[0] = '-';
	while (j)
	{
		n = j % 10;
		if (n < 0)
			n *= -1;
		ans[--i] = '0' + n;
		j /= 10;
	}
	return (ans);
}
