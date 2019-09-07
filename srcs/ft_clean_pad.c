/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_pad.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgonzalv <qgonzalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 23:08:48 by qgonzalv          #+#    #+#             */
/*   Updated: 2019/08/31 16:05:14 by qgonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*clean_pad(char *fin, char c, unsigned int i, int len)
{
	char	*ret;

	ret = fin;
	fin = ft_strcfill(fin, c, i, len);
	ft_strdel(&ret);
	return (fin);
}
