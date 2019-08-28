#include "ft_printf.h"
#include <unistd.h>
#include <stdio.h>

static int          get_decimal(t_printf *p, va_list args)
{
    p->arg.base = 10;
    if (p->length == LEN_HH)
        p->arg.value = p_itoa_base(p, (unsigned char)va_arg(args, void*), p->arg.base);
    else if (p->length == LEN_H)
        p->arg.value = p_itoa_base(p, (unsigned short)va_arg(args, void*), p->arg.base);
    else if (p->length == LEN_LL)
        p->arg.value = p_itoa_base(p, (unsigned long long)va_arg(args, void *), p->arg.base);
    else if (p->length == LEN_L)
        p->arg.value = p_itoa_base(p, (unsigned long)va_arg(args, void*), p->arg.base);
    else
        p->arg.value = p_itoa_base(p, (unsigned int)va_arg(args, void*), p->arg.base);
    return (p_strlen(p->arg.value));
}

int                 unsigned_collecting(t_printf *p, va_list args)
{
    p->arg.length = get_decimal(p, args);
    p->width = width_calculating(p);
    p->precision = precision_calculating(p);
    return (write_to_console(p));
}


