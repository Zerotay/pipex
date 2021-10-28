/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongguki <dongguki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 14:46:01 by dongguki          #+#    #+#             */
/*   Updated: 2021/03/10 09:44:16 by dongguki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char		*ans;
	size_t		len;
	size_t		i;

	if (!f || !s)
		return (0);
	len = ft_strlen(s);
	ans = ft_calloc(len + 1, 1);
	if (!ans)
		return (0);
	i = 0;
	while (i < len)
	{
		ans[i] = f(i, s[i]);
		i++;
	}
	return (ans);
}
