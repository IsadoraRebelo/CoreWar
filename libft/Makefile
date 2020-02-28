# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lsmienk <lsmienk@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2019/03/21 16:55:01 by lsmienk        #+#    #+#                 #
#    Updated: 2020/02/17 13:09:49 by lsmienk       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
RAWFILES =  ft_abs ft_atoi ft_bzero ft_itoa ft_isalnum ft_isalpha ft_isascii \
			ft_isdigit ft_isprint  ft_intlen ft_memcpy ft_memalloc ft_memdel \
			ft_memset ft_putchar ft_putchar_fd ft_putendl ft_putendl_fd  \
			ft_putnbr ft_putnbr_fd ft_putstr ft_putstr_fd ft_strcmp ft_strdel\
			ft_strdup ft_strlen ft_strchr ft_strrchr ft_strclr ft_strncmp \
			ft_strnew  ft_strcat ft_strncat ft_strlcat ft_strcpy ft_strend \
			ft_strstr ft_strnstr ft_strrev ft_striter ft_striteri ft_strmap\
			ft_strmapi ft_strequ ft_strnequ  ft_strsub ft_tolower ft_toupper \
			ft_strncpy ft_strjoin ft_strtrim ft_memmove ft_memccpy ft_memchr \
			ft_memcmp ft_wordcount ft_strsplit ft_strnlen ft_lstnew \
			ft_lstdelone ft_lstdel ft_lstadd ft_lstiter ft_lstmap ft_atoi_base \
			ft_closeprogram ft_itoa_base ft_itoa_base_up ft_get_next_line \
			ft_countwords ft_isprime ft_whitespace ft_writeincolours

FT_PRINTF = ft_printf str_part set_character set_number set_unumber set_string\
			set_octal set_float flags width print_width set_hex set_hex_up \
			set_pointer set_percent ret_putchar ret_putstr ret_putnbr \
			ret_putnbr_u set_prec set_floatl check_next check_nextl round_up \
			check_round check_roundl float_width float_behavior \
			float_exceptions float_sign prec_sign

SRC = $(RAWFILES:%=%.c)
OBJ = $(RAWFILES:%=%.o)
PSRC = $(FT_PRINTF:%=ft_printf/srcs/%.c)
POBJ = $(FT_PRINTF:%=%.o)
FLAG = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME):
	@gcc  $(FLAG) -c $(SRC) $(PSRC)
	@ar -rc $(NAME) $(OBJ) $(POBJ)

clean:
	@/bin/rm -f $(OBJ) $(POBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
