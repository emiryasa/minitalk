/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyasa <eyasa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:51:51 by eyasa             #+#    #+#             */
/*   Updated: 2024/05/07 17:51:53 by eyasa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbrhexp(unsigned long n)
{
	int	digitcount;

	digitcount = 0;
	ft_putstr("0x");
	digitcount += 2;
	digitcount += ft_putnbrhexllong(n);
	return (digitcount);
}

int	counter(int *a, int b)
{
	*a += b;
	return (*a);
}

void	ft_printfif(va_list *ap, int i, int *count, const char *a)
{
	if (a[i + 1] == 'd')
		counter(count, ft_putnbr(va_arg(*ap, int)));
	else if (a[i + 1] == 's')
		counter(count, ft_putstr(va_arg(*ap, char *)));
	else if (a[i + 1] == 'c')
		counter(count, ft_putchar(va_arg(*ap, int)));
	else if (a[i + 1] == '%')
		counter(count, ft_putchar('%'));
	else if (a[i + 1] == 'x')
		counter(count, ft_putnbrhexl(va_arg(*ap, unsigned int)));
	else if (a[i + 1] == 'X')
		counter(count, ft_putnbrhexb(va_arg(*ap, unsigned int)));
	else if (a[i + 1] == 'p')
		counter(count, ft_putnbrhexp((unsigned long)va_arg(*ap, void *)));
	else if (a[i + 1] == 'u')
		counter(count, ft_putnbru(va_arg(*ap, unsigned int)));
	else if (a[i + 1] == 'i')
		counter(count, ft_putnbr(va_arg(*ap, int)));
}

int	ft_printf(const char *a, ...)
{
	va_list	ap;
	int		count;
	int		i;

	va_start(ap, a);
	count = 0;
	i = 0;
	while (a[i])
	{
		if (a[i] == '%')
		{
			ft_printfif(&ap, i, &count, a);
			i++;
		}
		else
			counter(&count, ft_putchar(a[i]));
		i++;
	}
	va_end(ap);
	return (count);
}
