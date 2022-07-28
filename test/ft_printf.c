#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

//str 1 char 2
int	ft_putstr(char *s, char c, int i)
{
	int	count;

	count = 0;
	if (!s && i == 1)
		count += ft_putstr("(null)", 0, 1);
	else if (i == 2)
	{
		write(1, &c, 1);
		return (1);
	}
	else if (s && i == 1)
		while (s[count])
			count += ft_putstr(0, s[count], 2);
	return (count);
}

int	ft_putnbr(long l)
{
	int	argptr;

	argptr = 0;
	if (l < 0)
	{
		l *= -1;
		write(1, "-", 1);
		argptr++;
	}
	if (l > 9)
		argptr += ft_putnbr(l / 10);
	ft_putstr(0, l % 10 + 48, 2);
	argptr++;
	return (argptr);
}

int	ft_puthex(unsigned long n, char c)
{
	char	*str;
	int		argptr;

	argptr = 0;
	if (c == 'X')
		str = "0123456789ABCDEF";
	else if (c == 'x')
		str = "0123456789abcdef";
	else if (c == 'p')
	{
		if ((unsigned int) n / 16 > 0)
			argptr += ft_puthex(unsigned long)n / 16, c, 0);
	}
	/*else
	{
		if ((unsigned int)n / 16 > 0)
			argptr += ft_puthex((unsigned int)n / 16, c, 0);
	}*/
	ft_putstr(0, str[n % 16], 2);
	argptr++;
	return (argptr);
}

int	ft_eval(const char *str, int *i, va_list args)
{
	if (str[*i] == 'c')
		return (ft_putstr(0, va_arg(args, int), 2));
	else if (str[*i] == 's')
		return (ft_putstr(va_arg(args, char *), 0, 1));
	else if (str[*i] == 'p')
	{
		write(1, "0x", 2);
		return (ft_puthex(va_arg(args, unsigned long), str[*i]));
	}
	else if (str[*i] == 'd' || str[*i] == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (str[*i] == 'u')
		return (ft_putnbr(va_arg(args, unsigned int)));
	else if (str[*i] == 'x' || str[*i] == 'X' || str[*i] == 'p')
		return (ft_puthex(va_arg(args, unsigned long), str[*i]);
	else if (str[*i] == '%')
		return (ft_putstr(0, '%', 2));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		argptr;
	int		i;

	va_start(args, str);
	i = 0;
	argptr = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			argptr += ft_eval(str, &i, args);
			i++;
		}
		else
			argptr += ft_putstr(0, str[i++], 2);
	}
	va_end(args);
	return (argptr);
}
