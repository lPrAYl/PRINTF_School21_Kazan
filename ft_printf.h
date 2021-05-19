#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# include <stdio.h>     //  убрать это

typedef struct s_printf
{
	char	type;
	int		minus;
	int		plus;
	int		zero;
	int		space;
	int		width;
	int		precision;
	int		iterator;
	int		base;
	int		lenght;
}			t_printf;

int			ft_printf(const char *format, ...);

void		ft_putchar_len(char c, t_printf *spec);
int			ft_strlen(const char *s);
int			ft_isdigit_minus(int c);
void		ft_printing_delimeter(int width, t_printf *spec);
void		ft_putstr_spec(char *str, t_printf *spec);
int			ft_atoi(const char *str);

t_printf	format_parsing(const char *format, va_list ap, t_printf *spec);
t_printf	ft_spec_init(void);
void		ft_flag_parsing(const char *format, t_printf *spec);
void		ft_width_parsing (const char *format, t_printf *spec, va_list ap);
void		ft_precision_parsing(const char *format, t_printf *spec, va_list ap);
void		ft_type_parsing(const char *format, t_printf *spec);

void		ft_printing(t_printf *spec, va_list ap);
void		ft_printing_char(t_printf *spec, int c);
void		ft_printing_percent(t_printf *spec);
void		ft_printing_string(t_printf *spec, char *str);


#endif