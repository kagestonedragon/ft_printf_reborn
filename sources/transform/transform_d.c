/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 11:14:12 by emedea            #+#    #+#             */
/*   Updated: 2019/08/20 13:07:32 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int			actions(t_printf *pf, int d, int nos)
{
	int		i;
	char	*buffer;

	(void)len;
	i = 0;
	buffer = create_buffer(pf, nos, (d > 0) ? 1 : 0);
	if (pf->flag.minus)
	{
		i = add_sign_to_buffer(buffer,(d > 0) ? 1 : 0, i);
		i = add_precision_to_buffer(buffer, pf, nos, i);
		i = add_number_to_buffer(buffer, i, d);
		i = add_width_to_buffer(buffer, pf, nos, (d > 0) ? 1 : 0, i);
	}
	else if (!pf->flag.minus)
	{
		i = add_width_to_buffer(buffer, pf, nos,  (d > 0) ? 1 : 0, i);
		i = add_sign_to_buffer(buffer, pf, (d > 0) ? 1 : 0, i);
		i = add_precision_to_buffer(buffer, pf, nos, i);
		i = add_number_to_buffer(buffer, i, d);
	}
	else if (pf->flag.zero && !pf->precision.exist)
	{
		i = add_width_to_buffer(buffer, pf, nos, (d > 0) ? 1 : 0, i);
		i = add_number_to_buffer(buffer, i, d);
	}
	return (0);
}

int			choose_length(t_printf *pf, va_list args, int *len)
{
	if (pf->length.exist)
	{
		(pf->length.hh) ? transform_d_hh(pf, args, len) : 0;
		(pf->length.h) ? transform_d_h(pf, args, len) : 0;
		(pf->length.l) ? transform_d_l(pf, args, len) : 0;
		(pf->length.ll) ? transform_d_ll(pf, args, len) : 0;
	}
	else
		transform_d(pf, args, len);
}
	
int     	transform_d(t_printf *pf, va_list args, int *len)
{
    int		d;
	int		nos;

	d = va_arg(args, int);
	nos = number_of_signs(d);
	actions(pf, d, nos, len);
	return (0);
}
