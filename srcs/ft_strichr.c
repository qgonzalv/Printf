/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strichr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgonzalv <qgonzalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 23:15:56 by qgonzalv          #+#    #+#             */
/*   Updated: 2019/08/30 23:15:57 by qgonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t		ft_strichr(const char *feed, char c)
{
	size_t i;

	i = 0;
	if (!feed)
		return (0);
	while (feed[i] != c && feed[i] != '\0')
		i++;
	return (i);
}
