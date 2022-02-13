/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <abonniss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 10:56:34 by abonniss          #+#    #+#             */
/*   Updated: 2022/01/16 17:30:55 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <string.h>
# include <ctype.h>
# include <stdlib.h>
# include <stdbool.h>

# define MAX_BASE			16
# define MIN_BASE			2
# define CHARSET_MAX_BASE	"0123456789ABCDEF"
# define POS 0
# define NEG 1
# define NEG_SIGN '-'
# define FAILURE -1
# define SUCCESS 0
# define HEXA_PREFIX "0X"
# define LOWERCASE_SHIFT 32
# define INT_MIN -2147483648
# define INT_MAX 2147483647

unsigned long		ft_absolute(long number);
int					ft_atoi(const char *str);
long				ft_atol(const char *str);
int					ft_satol(const char *str, long *nb);
int					ft_satoi(const char *str, int *nb);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t count, size_t size);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
bool				ft_isnumber(const char *str);
bool				ft_isinteger(long nbr);
int					ft_isalnum(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strdup(const char *s1);
char				*strcdup(const char *input, const char c);
char				*ft_strnstr(const char *haystack,
						const char *needle, size_t len);
size_t				ft_strlen(const char *s);
size_t				ft_strclen(const char *s, const char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
/*##############################MEMORY FUNCTIONS###########################*/
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memmove(void *dst, const void *src, size_t len);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memalloc(size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strnstr(const char *haystack,
						const char *needle, size_t len);
char				*ft_strsep(char *input, char c, char **output);
char				*ft_itoa(int n);
/*##############################LTOA_BASE##################################*/
char				*ft_ultoa_base(unsigned long number, const int base_number);
char				*ft_ltoa_base(long number, const int base_number);
char				*ft_itoa_base(int number, const int base_number);
char				*ft_itoa_2(int number);
int					ft_add_prefix(char **input, const char *prefix);
bool				ft_is_uppercase(char c);
char				ft_to_uppercase(char c);
bool				ft_is_lowercase(char c);
char				ft_to_lowercase(char c);
char				*ft_str_to_lowercase(char *str);
char				*ft_str_to_uppercase(char *str);

#endif
