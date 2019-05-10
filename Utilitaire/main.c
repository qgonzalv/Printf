/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgonzalv <qgonzalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 16:03:26 by qgonzalv          #+#    #+#             */
/*   Updated: 2019/05/10 16:41:04 by qgonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int main ()
{
    ft_printf("Ceci est un test de printf : \nEntier avec d : %d \n Entier avec i: %i", 21, 42);
    ft_printf("Pour des string : %s\n Pour des char : %c\n", "Le string", 'c');

    return (0);
}
