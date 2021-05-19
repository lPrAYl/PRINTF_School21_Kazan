#include "ft_printf.h"

void	ft_putchar_len(char c, t_printf *spec)
{	
	static size_t	len;

	write (1, &c, 1);
	len++;
	spec->lenght = len;
}

int	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*(s + i))
		i++;
	return (i);
}

void	ft_putstr_spec(char *str, t_printf *spec)
{
	unsigned int	i;
	unsigned int	len;

	if (!str)
		return ;
	i = 0;
	if (spec->precision == -1 || spec->precision >= ft_strlen(str))
		len = ft_strlen(str);
	else
	{
		if (spec->precision < 1)
			spec->precision = 0;
		len = spec->precision;
	}
	while (i < len)
	{
		ft_putchar_len(*(str + i), spec);
		i++;
	}
}

void	ft_printing_delimeter(int width, t_printf *spec)
{
	while (--width > 0)
	{
		if (spec->zero && !spec->minus)
			ft_putchar_len('0', spec);
		else
			ft_putchar_len(' ', spec);
	}
}

int	ft_isdigit_minus(int c)
{
	if ((c > 47 && c < 58) || c == '-')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	nbr;
	int	sign;
	int	digit;

	i = 0;
	nbr = 0;
	sign = 1;
	digit = 18;
	while ((*(str + i) > 8 && *(str + i) < 14) || *(str + i) == 32)
		i++;
	if (*(str + i) == 43 || *(str + i) == 45)
	{
		if (*(str + i) == 45)
			sign = -1;
		i++;
	}
	while (*(str + i) > 47 && *(str + i) < 58)
	{
		if (!digit--)
			return ((sign + 1) / (-2));
		nbr = nbr * 10 + (*(str + i) - 48);
		i++;
	}
	return (nbr * sign);
}
