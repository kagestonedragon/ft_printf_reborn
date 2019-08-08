#include "ft_printf.h"
#include "libft.h"

static t_bool   find_length(t_printf *pf, const char *format, int *i)
{
    if (ft_strncmp(&format[*i], "hh", 2))
        return (find_length_hh(pf, i));
    else if (format[*i] == 'h')
        return (find_length_h(pf, i));
    else if (format[*i] == 'l')
        return (find_length_l(pf, i));
    else if (ft_strncmp(&format[*i], "ll", 2))
        return (find_length_ll(pf, i));
    else if (format[*i] == 'L')
        return (find_length_hl(pf, i));
    return (false);
}

int     parse_length(t_printf *pf, const char *format, int *i)
{
    if (find_length(pf, format, i))
        return (0);
    return (0);
}
