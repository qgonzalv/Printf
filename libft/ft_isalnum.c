/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgonzalv <qgonzalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 17:53:26 by qgonzalv          #+#    #+#             */
/*   Updated: 2019/08/31 15:10:31 by qgonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalnum(int c)
{
	int result;

	result = ft_isdigit(c) + ft_isalpha(c);
	if (result > 0)
		return (1);
	else
		return (0);
}
