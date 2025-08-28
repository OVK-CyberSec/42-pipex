/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decortejohn <decortejohn@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 14:12:18 by jdecorte          #+#    #+#             */
/*   Updated: 2022/02/01 22:42:51 by decortejohn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

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

#endif