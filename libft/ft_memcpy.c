/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongguki <dongguki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 14:25:56 by dongguki          #+#    #+#             */
/*   Updated: 2021/10/13 14:32:44 by dongguki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*ftdst;

	if (!dst && !src)
		return (0);
	ftdst = (unsigned char *)dst;
	while (n-- > 0)
		*ftdst++ = *(unsigned char *)src++;
	return (dst);
}
