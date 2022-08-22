/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_lltoa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 13:35:19 by ldurieux          #+#    #+#             */
/*   Updated: 2022/08/21 13:35:19 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

#define LLONG_MAX_SIZE 22

char	*ft_printf_ulltoa(t_uint64 value, t_printf_conversion conv,
						char *base, t_size *res_len)
{
	char	buf[LLONG_MAX_SIZE + 1];
	char	*buf_ptr;
	char	*res;
	t_size	raddix;

	raddix = ft_strlen(base);
	buf_ptr = &buf[LLONG_MAX_SIZE];
	if (value == 0 && conv.precision != 0)
		*buf_ptr-- = '0';
	while (value != 0)
	{
		*buf_ptr-- = base[value % raddix];
		value /= (long long)raddix;
	}
	*res_len = (int)(&buf[LLONG_MAX_SIZE] - buf_ptr);
	res = malloc(sizeof(char) * (*res_len + 1));
	if (!res)
		return (NULL);
	ft_memcpy(res, buf_ptr + 1, *res_len);
	res[*res_len] = '\0';
	return (res);
}

char	*ft_printf_lltoa(t_int64 value, t_printf_conversion conv,
						char *base, t_size *res_len)
{
	char	buf[LLONG_MAX_SIZE + 1];
	char	*buf_ptr;
	char	*res;
	t_size	raddix;

	raddix = ft_strlen(base);
	buf_ptr = &buf[LLONG_MAX_SIZE];
	if (value == 0 && conv.precision != 0)
		*buf_ptr-- = '0';
	while (value != 0)
	{
		*buf_ptr-- = base[ft_abs(value % (t_int64)raddix)];
		value /= (long long)raddix;
	}
	*res_len = (int)(&buf[LLONG_MAX_SIZE] - buf_ptr);
	res = malloc(sizeof(char) * (*res_len + 1));
	if (!res)
		return (NULL);
	ft_memcpy(res, buf_ptr + 1, *res_len);
	res[*res_len] = '\0';
	return (res);
}
