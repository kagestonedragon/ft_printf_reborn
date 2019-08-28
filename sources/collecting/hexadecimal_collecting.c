#include "ft_printf.h"
#include <unistd.h>
#include <stdio.h>

static unsigned long long get_sign(t_printf *p, unsigned long long value)
{
    if (p->flag.hash)
    {
        if (p->type == TYPE_LX)
            p->sign.value = new_string("0x");
        else
            p->sign.value = new_string("0X");
    }
    p->sign.length = p_strlen(p->sign.value);
    return (value);
}

static int          get_decimal(t_printf *p, va_list args)
{
    p->arg.base = 16;
    if (p->length == LEN_HH)
        p->arg.value = p_itoa_base(p, get_sign(p, (unsigned char)va_arg(args, void*)), p->arg.base);
    else if (p->length == LEN_H)
        p->arg.value = p_itoa_base(p, get_sign(p, (unsigned short)va_arg(args, void*)), p->arg.base);
    else if (p->length == LEN_LL)
        p->arg.value = p_itoa_base(p, get_sign(p, (unsigned long long)va_arg(args, void *)), p->arg.base);
    else if (p->length == LEN_L)
        p->arg.value = p_itoa_base(p, get_sign(p, (unsigned long)va_arg(args, void*)), p->arg.base);
    else
        p->arg.value = p_itoa_base(p, get_sign(p, (unsigned int)va_arg(args, void*)), p->arg.base);
    return (p_strlen(p->arg.value));
}

int                 hexadecimal_collecting(t_printf *p, va_list args)
{
    p->arg.length = get_decimal(p, args);
    to_lower(p);
    p->width = width_calculating(p);
    p->precision = precision_calculating(p);
    return (write_to_console(p));
}


