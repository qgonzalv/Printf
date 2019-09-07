/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgonzalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 12:30:48 by qgonzalv          #+#    #+#             */
/*   Updated: 2017/09/05 12:48:59 by qgonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *str)
{
	int		i;
	int		tailletab;
	char	temp;

	i = 0;
	tailletab = 0;
	while (str[tailletab] != '\0')
	{
		tailletab++;
	}
	tailletab--;
	while (i <= tailletab / 2)
	{
		temp = str[i];
		str[i] = str[tailletab - i];
		str[tailletab - i] = temp;
		i++;
	}
	return (str);
}
