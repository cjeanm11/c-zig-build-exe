#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <wchar.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdint.h>
# include <sys/time.h>

# define PI 3.14159265358979323846
# define PI_F (float)PI

# define WHITESPACE " \t\n\v\f\r"

/*
** ANSI Colors
*/

# define FT_RST "\033[0m"
# define FT_BOLD "\033[1m"

# define FT_BLA "\033[30m"
# define FT_RED "\033[31m"
# define FT_GRE "\033[32m"
# define FT_YEL "\033[33m"
# define FT_BLU "\033[34m"
# define FT_MAG "\033[35m"
# define FT_CYA "\033[36m"
# define FT_WHI "\033[37m"

# define FT_BBLA "\033[90m"
# define FT_BRED "\033[91m"
# define FT_BGRE "\033[92m"
# define FT_BYEL "\033[93m"
# define FT_BBLU "\033[94m"
# define FT_BMAG "\033[95m"
# define FT_BCYA "\033[96m"
# define FT_BWHI "\033[97m"

/*
** Memory functions
*/

// Allocate memory
// RETURN: ptr to memory block or exit program if failed
void		*ft_xmalloc(size_t size);

// Allocate memory and initialize to 0
// RETURN: ptr to memory block or NULL if failed
void		*ft_calloc(size_t count, size_t size);

// Allocate memory and initialize to 0
// RETURN: ptr to memory block or exit program if failed
void		*ft_xcalloc(size_t count, size_t size);

// Change size of memory block ptr to size
// RETURN: ptr to memory block or NULL if failed or size == 0
void		*ft_realloc(void *ptr, size_t oldsize, size_t size);

// Set memory block to c
// RETURN: b
void		*ft_memset(void *b, int8_t c, size_t len);

// Copy src memory block to dst
// RETURN: dst
void		*ft_memcpy(void *dst, const void *src, size_t n);

// Copy src memory block to dst. Stop if c is found
// RETURN: ptr to the next character in dest after c or NULL if not found
void		*ft_memccpy(void *dst, const void *src, int8_t c, size_t n);

// Copy src memory block to dst. Dst and src can overlap
// RETURN: dst
void		*ft_memmove(void *dst, const void *src, size_t len);

// Search c in memory block
// RETURN: ptr to first matching byte or NULL if not found
void		*ft_memchr(const void *s, int8_t c, size_t n);

// Set memory block to 0
void		ft_bzero(void *s, size_t n);

// Compare two memory blocks
// RETURN: 0 if equal otherwise the difference between byte s1 and s2
int32_t		ft_memcmp(const void *s1, const void *s2, size_t n);

/*
** Character classification and convertion functions
*/

// Check for uppercase letter
bool		ft_isupper(char c);

// Check for lowercase letter
bool		ft_islower(char c);

// Check for alphabetic character
bool		ft_isalpha(char c);

// Check for digit (0-9)
bool		ft_isdigit(char c);

// Check for hexadecimal digit (0-9, a-f, A-F)
bool		ft_isxdigit(char c);

// Check for alphanumeric character
bool		ft_isalnum(char c);

// Check for ascii character
bool		ft_isascii(char c);

// Check for whitespace character (space, \\t, \\n, \\v, \\f, \\r)
bool		ft_isspace(char c);

// Check for blank character (space, \\t)
bool		ft_isblank(char c);

// Check for printable character except space
bool		ft_isgraph(char c);

// Check for printable character
bool		ft_isprint(char c);

// Check for printable character except space and alphanumeric character
bool		ft_ispunct(char c);

// Return uppercase equivalent of c. Return c if c is not a lowercase letter
char		ft_toupper(char c);

// Return lowercase equivalent of c. Return c if c is not a uppercase letter
char		ft_tolower(char c);

/*
** Conversion functions
*/

// Ascii to integer
int32_t		ft_atoi(const char *str);

// Ascii to long integer
int64_t		ft_atol(const char *str);

// Convert n to ascii using decimal base
char		*ft_ltoa(int64_t n);

// Convert n to ascii using base
char		*ft_ltoa_base(int64_t n, const char *base);

// Convert n to ascii using decimal base
char		*ft_ultoa(uint64_t n);

// Convert n to ascii using base
char		*ft_ultoa_base(uint64_t n, const char *base);

// Count digits in n using radix
size_t		ft_numlen(int64_t n, int64_t radix);

// Count digits in n using radix
size_t		ft_unumlen(uint64_t n, uint64_t radix);

/*
** C-string functions
*/

// Length of s
size_t		ft_strlen(const char *s);

// Length of s with maxlen as max length
size_t		ft_strnlen(const char *s, size_t maxlen);

// Size in bytes of a unicode character
size_t		ft_wchar_size(wchar_t c);

// Size in bytes of a unicode string
size_t		ft_wstr_size(const wchar_t *s);

// Length of s
size_t		ft_wstrlen(const wchar_t *s);

// Length of s with maxlen as max length
size_t		ft_wstrnlen(const wchar_t *s, size_t maxlen);

// Copy up to dstsize - 1 characters from src to dst, NUL-terminate the result
// RETURN: total length of the string which was tried to create
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);

// Append at most dstsize - strlen(dst) - 1 bytes, NUL-terminate the result
// RETURN: total length of the string which was tried to create
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);

// Compare two strings
// RETURN: 0 if equal otherwise the difference between char s1 and s2
int32_t		ft_strcmp(const char *s1, const char *s2);

// Compare two strings, compare at most n characters
// RETURN: 0 if equal otherwise the difference between char s1 and s2
int32_t		ft_strncmp(const char *s1, const char *s2, size_t n);

// Search c in string
// RETURN: ptr to first matching char or NULL if not found
char		*ft_strchr(const char *s, char c);

// Search c in string
// RETURN: ptr to last matching char or NULL if not found
char		*ft_strrchr(const char *s, char c);

// Search for needle in first n characters of haystack
// RETURN: ptr to first character of needle in haystack or NULL if not found
char		*ft_strnstr(const char *haystack, const char *needle, size_t n);

// Duplicate string s
// RETURN: new copy of s or NULL if error occured
char		*ft_strdup(const char *s);

// Create substring of s from start of size len
// RETURN: new substring of s or NULL if error occured
char		*ft_substr(const char *s, size_t start, size_t len);

// Join string s1 with string s2
// RETURN: new joined string or NULL if error occured
char		*ft_strjoin(const char *s1, const char *s2);

// Trim characters in set at beginning and end of s1
// RETURN: new trimmed string or NULL if error occured
char		*ft_strtrim(const char *s, const char *set);

// Create new string using f applied on all characters of s
// RETURN: new mapped string or NULL if error occured
char		*ft_strmapi(const char *s, char (*f)(uint32_t, char));

// Split s using delimiter delim
// RETURN: NUL-terminated array of string or NULL if error occured
char		**ft_split(const char *s, char delim);

// Duplicate NUL-terminated array of string
// RETURN: new duplicated array or NULL if error occured
char		**ft_strarr_dup(char *const *arr);

// Extend NUL-terminated array of string with back_str. Free old arr
// RETURN: new extended array of string or NULL if error occured
char		**ft_strarr_extend(char **arr, char *back_str);

// Get pointer to last string of NUL-terminated array
// RETURN: pointer to last string or NULL if empty array
char		*ft_strarr_last(char **arr);

// Size of NUL-terminated array of string
size_t		ft_strarr_size(char *const *arr);

// Replace string at index with newstr from NUL-terminated array. Frees old
// string
void		ft_strarr_replace(char **arr, char *newstr, size_t index);

// Remove string at index from NUL-terminated array
void		ft_strarr_remove(char **arr, size_t index);

// Sort NUL-terminated array based on ASCII ordering
void		ft_strarr_sort(char **arr);

// Free NUL-terminated array of string
void		ft_strarr_free(char **arr);

// Apply f on every character of s
// RETURN: true if any result of f is true otherwise false
bool		ft_strany(const char *s, bool (*f)(char));

// Apply f on every character of s
// RETURN: true if every result of f is true otherwise false
bool		ft_strall(const char *s, bool (*f)(char));

// Apply f on every character of s
void		ft_striter(char *s, void (*f)(char));

// Apply f on every character of s
// RETURN: how many times f returned true
size_t		ft_strcount_if(const char *s, bool (*f)(char));

/*
** Output functions
*/

// Write c to file descriptor
void		ft_putchar_fd(char c, int fd);

// Write string to file descriptor
void		ft_putstr_fd(const char *s, int fd);

// Write unicode char to file descriptor
void		ft_putwchar_fd(wchar_t c, int fd);

// Write unicode string to file descriptor
void		ft_putwstr_fd(const wchar_t *s, int fd);

// Write string followed by newline to file descriptor
void		ft_putendl_fd(const char *s, int fd);

// Write signed number to file descriptor using decimal base
void		ft_putnbr_fd(int64_t n, int fd);

// Write signed number to file descriptor using base
void		ft_putnbr_base_fd(int64_t n, const char *base, int fd);

// Write unsigned number to file descriptor using base
void		ft_putunbr_base_fd(uint64_t n, const char *base, int fd);


int32_t     ft_foo(void);
/*
** Linked list functions
*/

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

// Create new list node
// RETURN: new node or NULL if error occured
t_list		*ft_lstnew(void *content);

// Last node of the list
t_list		*ft_lstlast(t_list *lst);

// Create new list by applying f on every node. Delete with del if malloc fails
// RETURN: new list or NULL if error occured
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// Advance ptr to next node
t_list		*ft_lstnext(t_list **lst);

// Pop first node of the list
// RETURN: content of first node
void		*ft_lstpop_front(t_list **lst);

// Add node to front of list
void		ft_lstadd_front(t_list **lst, t_list *node);

// Add node to back of list
void		ft_lstadd_back(t_list **lst, t_list *node);

// Delete node using del
void		ft_lstdelone(t_list *lst, void (*del)(void *));

// Delete every node in lst using del
void		ft_lstclear(t_list **lst, void (*del)(void *));

// Apply f on every node
void		ft_lstiter(t_list *lst, void (*f)(void *));

// Apply f on every node content of lst
// RETURN: true if any result of f is true otherwise false
bool		ft_lstany(t_list *lst, bool (*f)(void *));

// Apply f on every node content of lst
// RETURN: true if every result of f is true otherwise false
bool		ft_lstall(t_list *lst, bool (*f)(void *));

// Size of the list
size_t		ft_lstsize(t_list *lst);

// Apply f on every node of lst
// RETURN: how many times f returned true
size_t		ft_lstcount_if(t_list *lst, bool (*f)(void *));

/*
** Doubly linked list functions
*/

typedef struct s_dlist
{
	void			*content;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}	t_dlist;

// Create new list node
// RETURN: new node or NULL if error occured
t_dlist		*ft_dlstnew(void *content);

// First node of the list
t_dlist		*ft_dlstfirst(t_dlist *lst);

// Last node of the list
t_dlist		*ft_dlstlast(t_dlist *lst);

// Advance ptr to next node
t_dlist		*ft_dlstnext(t_dlist **lst);

// Rewind ptr to prev node
t_dlist		*ft_dlstprev(t_dlist **lst);

// Add node to front of list
void		ft_dlstadd_front(t_dlist **lst, t_dlist *node);

// Add node to back of list
void		ft_dlstadd_back(t_dlist **lst, t_dlist *node);

// Delete node using del
void		ft_dlstdelone(t_dlist *lst, void (*del)(void *));

// Delete every node in lst using del
void		ft_dlstclear(t_dlist **lst, void (*del)(void *));

// Size of the list
size_t		ft_dlstsize(t_dlist *lst);

/*
** File functions
*/

// Read a line from file descriptor into line
// RETURN: 0 if EOF is hit, 1 if a line was read and -1 if error occured
int32_t		ft_get_next_line(int fd, char **line);

// Read whole content of file to a string
// RETURN: file content or NULL if error occured
char		*ft_read_to_str(const char *file);

// Count lines in file
// RETURN: line count or -1 if error occured
ssize_t		ft_count_lines(const char *file);

// Size of file
// RETURN: size in bytes or -1 if error occured
ssize_t		ft_file_size(const char *file);

/*
** String functions
*/

// String similar to cpp std::string
typedef struct s_string
{
	char	*data;
	size_t	cap;
	size_t	len;
}	t_string;

// Create new string taking ownership of cstr. Also accepts NULL
// RETURN: dst
t_string	*ft_str_new(t_string *dst, char *cstr);

// Duplicate cstr into dst
// RETURN: dst or NULL if error occured
t_string	*ft_str_dup(t_string *dst, const char *cstr);

// Append c to string to str, realloc if not enough space
// RETURN: dst or NULL if error occured
t_string	*ft_str_push(t_string *dst, char c);

// Append src to dst, realloc if not enough space
// RETURN: dst or NULL if error occured
t_string	*ft_str_append(t_string *dst, const char *src);

// Copy src into dst
// RETURN: dst or NULL if error occured
t_string	*ft_str_copy(t_string *dst, const char *src);

// Create substring of s from start of size len in dst
// RETURN: new substring of s or NULL if error occured
t_string	*ft_str_sub(t_string *dst, const char *str, size_t index, size_t len);

// Trim characters in set at beginning and end of str and put it in dst
// RETURN: new trimmed string or NULL if error occured
t_string	*ft_str_trim(t_string *dst, const char *str, const char *set);

// Set string to empty string
void		ft_str_clear(t_string *str);

// Free the string
void		ft_str_free(t_string *str);

// Return raw cstring and take ownership
char		*ft_str_take(t_string *str);

/*
** Hash functions
*/

// Hash memory block
size_t		ft_hash(const void *b, size_t size);

// Combine hash seed with hash of byte
void		ft_hash_combine(size_t *seed, int8_t byte);

/*
** Hash map functions
*/

typedef void			*t_hmap;

// Create new hash map
// RETURN: new hash map or NULL if error occured
t_hmap		ft_hmap_new(size_t size, void (*del)(void *));

// Size of hash map
size_t		ft_hmap_size(t_hmap map);

// Insert key-value pair if key doesn't exist. Fails if key is already in hmap
// RETURN: true if inserted or false if failed
bool		ft_hmap_insert(t_hmap map, const char *key, void *value);

// Insert key-value pair if key doesn't exist. Delete value if insert fails
// RETURN: true if inserted or false if failed
bool		ft_hmap_insert_del(t_hmap map, const char *key, void *value);

// Remove key-value pair
// RETURN: true if exists and removed otherwise false
bool		ft_hmap_remove(t_hmap map, const char *key);

// Find value using key
// RETURN: ptr to value if found otherwise NULL
void		*ft_hmap_find(t_hmap map, const char *key);

// Free hash map
void		ft_hmap_free(t_hmap map);

/*
** Math functions
*/

typedef struct s_vec2
{
	double	x;
	double	y;
}	t_vec2;

typedef struct s_vec2i
{
	int32_t	x;
	int32_t	y;
}	t_vec2i;

// Add vectors a and b
t_vec2		ft_vec2_add(t_vec2 a, t_vec2 b);

// Subtract vectors a and b
t_vec2		ft_vec2_sub(t_vec2 a, t_vec2 b);

// Multiply vector a by b
t_vec2		ft_vec2_mul(t_vec2 a, double b);

// Unit vector at angle
t_vec2		ft_vec2_unit(double angle);

// Normalize vector
t_vec2		ft_vec2_normalize(t_vec2 v);

// Distance between a and b
double		ft_vec2_dist(t_vec2 a, t_vec2 b);

// Length of vector
double		ft_vec2_length(t_vec2 v);

// Convert degrees to radians
double		ft_deg_to_rad(double degrees);

// Convert radians to degrees
double		ft_rad_to_deg(double radians);

// Wrap angle
double		ft_wrap_angle(double angle);

// Absolute value
int64_t		ft_labs(int64_t v);

// Absolute value
int32_t		ft_abs(int32_t v);

// Clamp value between min and max
int64_t		ft_clamp(int64_t v, int64_t min, int64_t max);

// Clamp value between min and max
double		ft_clampd(double v, double min, double max);

/*
** Time functions
*/

typedef struct s_time
{
	struct timeval	tp;
}	t_time;

// Get timestamp
int			ft_gettime(t_time *t);

// Get time difference in sec
double		ft_timediff(t_time t1, t_time t2);

#endif
