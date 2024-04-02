/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboiraza <iboiraza@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:00:43 by iboiraza          #+#    #+#             */
/*   Updated: 2024/03/28 13:03:54 by iboiraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_pointer(char *base, unsigned long num)
{
	unsigned long	base_total;
	unsigned long	print_len;

	base_total = 0;
	print_len = 1;
	while (base[base_total])
		base_total++;
	if (num < base_total)
		write(1, &base[num], 1);
	else
	{
		print_len += ft_write_num(base, num / base_total);
		write(1, &base[num % base_total], 1);
	}
	return (print_len + 2);
}
