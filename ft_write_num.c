/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboiraza <iboiraza@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:00:10 by iboiraza          #+#    #+#             */
/*   Updated: 2024/03/28 13:03:42 by iboiraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_num(char *base, long int num)
{
	int	base_total;
	int	print_len;

	base_total = 0;
	print_len = 1;
	if (num < 0)
	{
		print_len += ft_write_str("-");
		num *= -1;
	}
	while (base[base_total])
		base_total++;
	if (num < base_total)
		write(1, &base[num], 1);
	else
	{
		print_len += ft_write_num(base, num / base_total);
		write(1, &base[num % base_total], 1);
	}
	return (print_len);
}
