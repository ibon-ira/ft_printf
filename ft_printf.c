/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboiraza <iboiraza@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 11:09:29 by iboiraza          #+#    #+#             */
/*   Updated: 2024/03/28 13:13:14 by iboiraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_specifiers(char *str, va_list args)
{
	int		i;

	i = 0;
	if (str[i] == 'd' || str[i] == 'i')
		return (ft_write_num(DEC_DIG, va_arg(args, int)));
	else if (str[i] == 'x')
		return (ft_write_num(HEX_LOW, va_arg(args, unsigned int)));
	else if (str[i] == 'X')
		return (ft_write_num(HEX_UP, va_arg(args, unsigned int)));
	else if (str[i] == 'c')
		return (ft_write_char(va_arg(args, int)));
	else if (str[i] == 'u')
		return (ft_write_num(DEC_DIG, va_arg(args, unsigned int)));
	else if (str[i] == 's')
		return (ft_write_str(va_arg(args, char *)));
	else if (str[i] == 'p')
	{
		write (1, "0x", 2);
		return (ft_write_pointer(HEX_LOW, (unsigned long)va_arg(args, void *)));
	}
	else if (str[i] == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		i;
	int		total;

	i = 0;
	total = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			total += ft_format_specifiers((char *)str + i, args);
		}
		else
			total += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (total);
}
/*
int main()
{
	ft_printf("hello my name is Laura and i'm 23 years old\n");
	printf("hello my name is Laura and i'm 23 years old\n");
	ft_printf("El caracter a escribir es %c\n", 'd');
	ft_printf("Prueba de u: %u\n", -6);
	printf("Prueba de u: %u\n", -6);
	i = ft_printf("Prueba de i: %i\n", 534563422);
	x = printf("Prueba de i: %i\n", 534563422);
	ft_printf("%d\n", i);
	printf("%d\n", x);
	ft_printf("Prueba de d: %d\n", 44);
	printf("Prueba de d: %d\n", 44);
	ft_printf("Prueba de x: %x\n", -3466);
	printf("Prueba de x: %x\n", -3466);
	ft_printf("Prueba de X: %X\n", 3466);
	printf("Prueba de X: %X\n", 3466);
	ft_printf("Prueba de %% \n");
	printf("Prueba de %% \n");
	ft_printf("Prueba de str: %s\n", "hola");
	printf("Prueba de str: %s\n", "hola");
	printf("printf original str vacio: %s\n", NULL);
	printf("Mi printf str vacio: %s\n", NULL);
	int	a = 11;
	ft_printf("Prueba de p: %p\n", (void *)-14523);
	int   b = 11;
	printf("Prueba de p: %p\n", (void *)-14523);
	ft_printf("hello my name is %s and i'm %d years old\n", "Laura", 22);
	printf("hello my name is %s and i'm %d years old\n", "Laura", 22);	
}*/
