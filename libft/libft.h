/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohifdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:25:55 by mohifdi           #+#    #+#             */
/*   Updated: 2025/11/03 14:25:57 by mohifdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdint.h>

int		ft_strcmp(char *s1, char *s2);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc( size_t elementCount, size_t elementSize );
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy( char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *theString);
int		ft_strncmp(const char *first, const char *second, size_t length);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);

#endif
