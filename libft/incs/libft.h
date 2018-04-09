/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 01:35:41 by gudemare          #+#    #+#             */
/*   Updated: 2018/03/01 00:01:30 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <================================= TODO =================================> **
** Write sorting functions (sortinttab)
** Write hash functions
** Write array functions
** Write dynamic array functions
** Write file reading functions
** Generalize get_next_line
** Make variants of ft_printf
** Find other mathematical functions
** strcapitalize, tablen, strnjoin, getopt...
** Malloc variations... (+ memalign, mallopt ... ?)
** Truly generic functons with struct & union ?
** anytoa
** Graph data structure (see wikipedia for functions)
** strip_whitespaces
** double-linked lists
** ft_memalloc buggy ?
*/

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <wchar.h>

/*
** <============================ Array Functions ===========================> **
*/

char					**ft_arr_addstr(char **src, char *new);
char					**ft_arrcollapse(char **src, size_t init_len);
char					**ft_arrcpy(char **dst, char **src);
char					**ft_arrdelone(char **src, int index);
char					**ft_arrdup(char **src);
char					**ft_arrextend(char **src, size_t ext);
char					**ft_arrnew(size_t size);
char					*ft_arrnstr(char **arr, char *str, size_t n);
char					*ft_arrstr(char **arr, char *str);
int						ft_arrnstr_loc(char **arr, char *str, size_t n);
int						ft_arrstr_loc(char **arr, char *str);
size_t					ft_arrlen(char **ar);
void					ft_arrdel_size(char **arr, size_t size);
int						ft_free_arr(char **ar);

/*
** <========================= Binary Tree Functions ========================> **
*/

typedef struct			s_btree
{
	struct s_btree		*left;
	struct s_btree		*right;
	void				*data;
}						t_btree;

int						ft_btree_lvlcount(t_btree *root);
t_btree					*ft_btree_nodenew(void *data);
t_btree					*ft_btree_search_data(t_btree *root, void *data,
	int (*fcmp)(void *, void *));
void					ft_btree_apply_infix(t_btree *root,
	void (*fapply)(void *));
void					ft_btree_apply_prefix(t_btree *root,
	void (*fapply)(void *));
void					ft_btree_apply_suffix(t_btree *root,
	void (*fapply)(void *));
void					ft_btree_insert_data(t_btree **root,
	void *data, int (*fcmp)(void *, void *));
void					ft_btree_treedel(t_btree **root,
	void (*fdel)(void *));

/*
** Future funcions :
** void				ft_btree_nodedel(t_btree *node, void (*fdel)(void *));
** void				ft_btree_apply_breadth(t_btree *root,
**					void (*fapply)(void *));
** void				ft_btree_egalize(t_btree **root);
** Red & Black btree functions
*/

/*
** <=========================== Display functions ==========================> **
*/

void					ft_putarr(char **ar);
void					ft_putarr_fd(char **ar, int fd);
void					ft_putchar(char c);
void					ft_putchar_fd(char c, int fd);
void					ft_putendl(char const *s);
void					ft_putendl_fd(char const *s, int fd);
void					ft_putnbr(int nb);
void					ft_putnbr_fd(int nb, int fd);
void					ft_putnendl(char const *s, size_t n);
void					ft_putnendl_fd(char const *s, int fd, size_t n);
void					ft_putnstr(char const *s, size_t n);
void					ft_putnstr_fd(char const *s, int fd, size_t n);
void					ft_putstr(char const *s);
void					ft_putstr_fd(char const *s, int fd);

/*
** <============================ I/O functions =============================> **
*/

int						ft_read(char *filename, int fd, char **buf, size_t len);
int						get_next_line(const int fd, char **line,
						unsigned int buff_size);

/*
** <============================ List functions ============================> **
** ft_lstpushback
*/

typedef struct			s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}						t_list;

t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list					*ft_lstnew(void const *content, size_t content_size);
t_list					*ft_lstnew_copy(void const *content,
	size_t content_size);
void					ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void					ft_lstdelone(t_list **alst,
	void (*del)(void *, size_t));
void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void					ft_lstpush_back(t_list *alst, t_list *new);
void					ft_lstpush_front(t_list **alst, t_list *new);

/*
** <================================= Math =================================> **
*/

int						ft_isprime(unsigned int nb);
int						ft_max(int a, int b);
int						ft_min(int a, int b);
int						ft_oom(long long int n);
int						ft_sign(int nb);
size_t					ft_max_pos(size_t a, size_t b);
size_t					ft_min_pos(size_t a, size_t b);
unsigned int			ft_abs(int nb);
unsigned int			ft_sqrt(unsigned int nb);
unsigned long long int	ft_power(int nb, unsigned int power);

/*
** <=========================== Memory functions ===========================> **
*/

int						ft_memcmp(const void *s1, const void *s2, size_t n);
void					*ft_memalloc(size_t size);
void					*ft_memccpy(void *dst, const void *src, int c,
	size_t n);
void					*ft_memchr(const void *s, int c, size_t n);
void					*ft_memcpy(void *dst, const void *src, size_t n);
void					*ft_memdup(void *src, size_t n);
void					*ft_memmove(void *dst, const void *src, size_t n);
void					*ft_memrchr(const void *s, int c, size_t n);
void					*ft_memset(void *b, int c, size_t len);
void					ft_bzero(void *s, size_t n);
void					ft_memdel(void **ap);

/*
** <============================ Misc functions ============================> **
*/

char					*ft_basename(const char *filename);
char					*ft_dirname(char *filename);
char					*ft_itoa(int n);
int						ft_arg(int argc, int min_argc, int max_argc,
	char *usage);
int						ft_atoi(const char *s);
int						ft_is_whitespace(int c);
int						ft_isalnum(int c);
int						ft_isalpha(int c);
int						ft_isascii(int c);
int						ft_iscntrl(char c);
int						ft_isdigit(int c);
int						ft_isprint(int c);
int						ft_ispunct(char c);
int						ft_isspace(char c);
int						ft_isxdigit(char c);
int						ft_tolower(int c);
int						ft_toupper(int c);
void					ft_assert(void *ret);
void					ft_sort_inplace(
	char **lst, size_t len, int (*ft_cmp)(char *a, char *b));
void					ft_swap(void **a, void **b);
/*
** <=========================== String functions ===========================> **
*/

char					**ft_strsplit(char const *s, char c);
char					**ft_strsplit_ws(char const *src);
char					*ft_strcasestr(const char *s1, const char *s2);
char					*ft_strcat(char *dst, const char *src);
char					*ft_strchr(const char *s, int c);
char					*ft_strchrnul(const char *s, int c);
char					*ft_strcpy(char *dst, const char *src);
char					*ft_strdup(const char *s);
char					*ft_strextend(char *str, size_t size);
char					*ft_strextjoin(char *s1, char const *s2);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strmap(char const *s, char (*f)(char));
char					*ft_strmapi(char const *s,
	char (*f)(unsigned int, char));
char					*ft_strncat(char *dst, const char *src, size_t n);
char					*ft_strncpy(char *dst, const char *src, size_t n);
char					*ft_strndup(const char *src, size_t n);
char					*ft_strnew(size_t size);
char					*ft_strnstr(const char *s1, const char *s2, size_t n);
char					*ft_strrchr(const char *s, int c);
char					*ft_strstr(const char *s1, const char *s2);
char					*ft_strsub(char const *s, unsigned int start,
	size_t len);
char					*ft_strtrim(char const *s);
int						ft_dprintf(int fd, const char *restrict str, ...);
int						ft_get_word(char **dst, char *str, int word_nb);
int						ft_is_str_ws(char *str);
int						ft_printf(const char *restrict str, ...);
int						ft_strcasecmp(char const *s1, char const *s2);
int						ft_strchr_count(const char *s, int ch);
int						ft_strcmp(char const *s1, char const *s2);
int						ft_strequ(char const *s1, char const *s2);
int						ft_strncmp(char const *s1, char const *s2, size_t n);
int						ft_strnequ(char const *s1, char const *s2, size_t n);
int						ft_vdprintf(int fd, const char *restrict str,
	va_list ap);
int						ft_vprintf(const char *restrict str, va_list ap);
int						get_next_word(char **dst, char *src, int reset);
size_t					ft_str_wordnb(char *str);
size_t					ft_strchr_loc(const char *s, int c);
size_t					ft_strlcat(char *dst, const char *src, size_t size);
size_t					ft_strlen(const char *s);
void					ft_exit(char *message, int display_errno,
	int should_exit, int exit_state);
void					ft_strclr(char *s);
void					ft_strdel(char **as);
void					ft_striter(char *s, void (*f)(char *));
void					ft_striteri(char *s, void (*f)(unsigned int, char *));

/*
**          <==================== Wide String functions ====================> **
*/

int						ft_wcharsize(wchar_t wc);
int						ft_wstrsize(wchar_t *ws);
size_t					ft_wstrlen(wchar_t *ws);
void					ft_putwchar(wchar_t wc);
void					ft_putwchar_fd(wchar_t wc, int fd);
void					ft_putwnstr(wchar_t *ws, size_t len);
void					ft_putwnstr_fd(wchar_t *ws, size_t len, int fd);
void					ft_wmemset(wchar_t *ws, wchar_t wc, size_t len);
void					ft_wstrncpy(wchar_t *dst, const wchar_t *src, size_t n);
wchar_t					*ft_wstrdup(wchar_t *ws);

#endif
