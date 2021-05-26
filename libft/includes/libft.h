/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mironbel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 16:54:04 by cport             #+#    #+#             */
/*   Updated: 2020/08/12 23:12:17 by mironbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define BUFF_SIZE 512

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

# include <stdarg.h>
# include <limits.h>
# include <stdint.h>
# include <stddef.h>
# include "libft.h"

# define F_NUL	0b0000000000000000
# define F_MNS	0b0000000000001000
# define F_PLS	0b0000000000000100
# define F_ZER	0b0000000000000010
# define F_SPC	0b0000000000000001
# define F_HSH	0b0000000000100000
# define F_AP	0b0000000000010000

# define AST	0b0000000010000000
# define DOL	0b0000000001000000
# define DOT	0b0000001000000000
# define UP		0b0000000100000000

# define S_H	0b0000000000000001
# define S_HH	0b0000000000000010
# define S_T	0b0000000000000100
# define S_Z	0b0000000000001000
# define S_J	0b0000000000010000
# define S_L	0b0000000000100000
# define S_LL	0b0000000001000000
# define S_LLL	0b0000000010000000
# define S_I	0b0000000100000000
# define S_ZER	0b0000001000000000

# define ERR	(-1)

typedef	struct		s_directive
{
	char			*format;
	va_list			arg;
	short			flag;
	unsigned int	width;
	int				precis;
	short			size;
	unsigned int	con;
	int				fd;
	size_t			i;
	int				done;
	int				var;
	int				temp;
}					t_dir;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_line
{
	int				fd;
	char			*memorized;
	struct s_line	*next;
}					t_line;

int					ft_printf(const char *format, ...);
void				parse_process(t_dir *x);
void				process_str(t_dir *x);
void				process_chr(t_dir *x);
void				process_pct(t_dir *x);
void				put_snb(t_dir *x);
void				put_unb(t_dir *x);
void				put_pnb(t_dir *x);
void				put_nbf(t_dir *x);
void				put_nbl(t_dir *x);
int					check_directive(const char *str, size_t *i);
int					set_prefix(int prefix, t_dir *x, int base);
int					is_dirs(const char d);
void				make_align(int prefix, t_dir *x, int base);
int					pf_atoi(char **nptr);
void				pf_print_base(uintmax_t num, int minus, int base, t_dir *x);

int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isgraph(int c);
int					ft_isspace(int c);
int					ft_isprint(int c);
int					ft_ispunct(int c);
int					ft_islower(int c);
int					ft_isupper(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_isnum(char *s);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
int					ft_atoi(const char *nptr);
char				*ft_itoa(int n);
size_t				ft_strlen(const char *s);
int					ft_intlen(int n);
int					ft_intlenb(uintmax_t nb, int base);
size_t				ft_lstlen(t_list *lst);
int					ft_overint(int n1, int n2);
int					ft_oversiz(size_t n1, size_t n2);
void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memmove(void *s1, const void *s2, size_t n);
char				*ft_strdup(const char *s);
char				*ft_strcpy(char *s1, const char *s2);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncpy(char *s1, const char *s2, size_t n);
void				*ft_memcpy(void *s1, const void *s2, size_t n);
void				*ft_memccpy(void *s1, const void *s2, int c, size_t n);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
int					ft_strchri(const char *s, int c);
void				*ft_memchr(const void *s, int c, size_t n);
char				*ft_strrchr(const char *s, int c);
void				*ft_memchr(const void *s, int c, size_t n);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t size);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *s));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
void				ft_strsplitdel(char ***tokens);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				*ft_realloc(void *ptr, size_t size);
int					get_next_line(const int fd, char **line);
size_t				ft_wcharlen(unsigned c);
int					ft_mod(int x);

#endif
