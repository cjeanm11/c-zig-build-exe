OBJ			=	obj
SRC			=	src
NAME		=	libft.a
CC			=	clang
AR			=	ar rcs
CFLAGS		=	-Wall -Werror -Wextra -Wpedantic -Wfloat-conversion -Wsign-conversion -c -I.
RM			=	rm -rf

CHAR_SRC	=	ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_islower.c\
				ft_isprint.c ft_isspace.c ft_isupper.c ft_tolower.c ft_toupper.c\
				ft_isblank.c ft_isgraph.c ft_isxdigit.c ft_ispunct.c
CONV_SRC	=	ft_atoi.c ft_atol.c ft_ltoa_base.c ft_ltoa.c ft_numlen.c ft_unumlen.c\
				ft_ultoa_base.c ft_ultoa.c
FILE_SRC	=	ft_count_lines.c ft_get_next_line.c ft_read_to_str.c ft_file_size.c
LIST_SRC	=	ft_lstadd_back.c ft_lstadd_front.c ft_lstany.c ft_lstclear.c\
				ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c\
				ft_lstpop_front.c ft_lstsize.c ft_lstnext.c ft_lstall.c ft_lstcount_if.c
DLIST_SRC	=	ft_dlstadd_back.c ft_dlstadd_front.c ft_dlstclear.c	ft_dlstdelone.c\
				ft_dlstlast.c ft_dlstnew.c ft_dlstfirst.c ft_dlstsize.c ft_dlstnext.c\
				ft_dlstprev.c
MEM_SRC		=	ft_bzero.c ft_calloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c\
				ft_memmove.c ft_memset.c ft_realloc.c ft_xcalloc.c ft_xmalloc.c
PUT_SRC		=	ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_base_fd.c ft_putnbr_fd.c\
				ft_putstr_fd.c ft_putwchar_fd.c ft_putwstr_fd.c ft_putunbr_base_fd.c
CSTR_SRC	=	ft_strarr_dup.c ft_strarr_free.c ft_split.c ft_strany.c ft_strcount_if.c ft_striter.c\
				ft_strarr_extend.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strall.c\
				ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnlen.c ft_strarr_replace.c\
				ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_wchar_size.c ft_strcmp.c\
				ft_wstr_size.c ft_wstrlen.c ft_wstrnlen.c ft_strarr_size.c ft_strarr_remove.c\
				ft_strarr_sort.c ft_strarr_last.c
STR_SRC		=	ft_str_push.c ft_str_append.c ft_str_clear.c ft_str_copy.c ft_str_dup.c ft_str_free.c\
				ft_str_new.c ft_str_sub.c ft_str_trim.c ft_str_take.c
HASH_SRC	=	ft_hash.c ft_hash_combine.c ft_hmap_new.c ft_hmap_free.c ft_hmap_insert.c\
				ft_hmap_find.c ft_hmap_size.c get_hmap_buckets.c ft_hmap_remove.c delete_pair.c\
				get_hmap_index.c create_pair.c ft_hmap_insert_del.c
MATH_SRC	=	ft_vec2_add.c ft_vec2_sub.c ft_vec2_mul.c ft_deg_to_rad.c ft_rad_to_deg.c ft_vec2_length.c\
				ft_vec2_unit.c ft_wrap_angle.c ft_vec2_normalize.c ft_vec2_dist.c ft_abs.c ft_labs.c\
				ft_clamp.c ft_clampd.c
TIME_SRC	=	ft_gettime.c ft_timediff.c

SRCS		=	$(CHAR_SRC) $(CONV_SRC) $(FILE_SRC) $(LIST_SRC) $(DLIST_SRC)\
				$(MEM_SRC) $(PUT_SRC) $(CSTR_SRC) $(STR_SRC) $(HASH_SRC)\
				$(MATH_SRC) $(TIME_SRC)

OBJS		=	$(SRCS:%=$(OBJ)/%.o)

VPATH		=	$(SRC)/ft_char $(SRC)/ft_convert $(SRC)/ft_cstr $(SRC)/ft_dlist\
				$(SRC)/ft_file $(SRC)/ft_hash $(SRC)/ft_list $(SRC)/ft_math\
				$(SRC)/ft_memory $(SRC)/ft_put $(SRC)/ft_string $(SRC)/ft_time

$(OBJ)/%.c.o:	%.c
				@$(CC) $(CFLAGS) $< -o $@
				@echo Compiling $<...

all:			CFLAGS += -O3 -DNDEBUG
all:			$(NAME)

$(NAME):		$(OBJ) $(OBJS)
				@$(AR) $(NAME) $(OBJS)
				@echo $(NAME) created.

$(OBJ):
				@mkdir -p $(OBJ)

debug:			CFLAGS += -g
debug:			$(NAME)

clean:
				@$(RM) $(OBJS)
				@echo Cleaned object files.

fclean:			clean
				@$(RM) $(NAME)
				@echo Cleaned binary.

re:				fclean all

.PHONY:		all clean fclean re debug
