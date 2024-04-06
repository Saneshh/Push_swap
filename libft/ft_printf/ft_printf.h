/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsolet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:16:32 by hsolet            #+#    #+#             */
/*   Updated: 2023/11/17 22:03:01 by hsolet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

size_t	ft_str_len(const char *s);
int		ft_putchar(char c, int fd);
int		ft_putnbr(int n, int fd);
int		ft_putnbr_base(unsigned int nbr, char *base, int fd);
int		ft_putstr(char *s, int fd);
int		ft_void_hexa(unsigned long n, char *base, int fd);
int		ft_printf(const char *format, ...);
int		ft_count_nbr(long long int n);
int		ft_count_hexa(unsigned long int n);

#endif
