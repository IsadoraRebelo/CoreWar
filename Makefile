# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lsmienk <lsmienk@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2020/02/10 13:18:55 by lsmienk        #+#    #+#                 #
#    Updated: 2020/02/24 13:26:56 by lsmienk       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME1 = asm
NAME2 = corewar_vm

SRC1 = asm check_first_arg check_if_label check_params check_second_arg \
	check_third_arg comment_functions cor_generator read_list free \
	error_management get_labels get_params set_direct set_instructions \
	set_op translate_params write_params name_functions get_current \
	free_double_arr dup_param ft_puthexa_fd
SRC2 = add aff and battle check_argument_validity fork get_argument_types \
	get_argument get_arguments_number get_wait_cycles initialise_cursors \
	initialise_players introduction is_registry ld ldi lfork live lld lldi \
	main or parse_players st sti sub xor zjmp visu visu2 visu3 do_operation \
	kill_cursor
	 
SRCF1 = $(SRC1:%=asembler/%.c)
SRCF2 = $(SRC2:%=virtual_machine/src/%.c)
OBJ1 = $(SRC1:%=%.o)
OBJ2 = $(SRC2:%=%.o)
LIBFT = -I libft/includes -L libft -lft
FLAGS = -Wall -Werror -Wextra -g

MAKECOLOUR = \033[38;5;208m
CLEANCOLOUR = \033[38;5;229m
FCLEANCOLOUR = \033[38;5;214m
LIBCOLOUR = \033[38;5;220m
RESETCOLOUR = \033[0m

.PHONY: all clean fclean re

all: $(NAME1) $(NAME2)

$(NAME1): $(SRCF1)
	@echo "$(LIBCOLOUR)Compiling Libraries$(RESETCOLOUR)"
	@make -C libft/
	@echo "$(MAKECOLOUR)Compiling $(NAME1)$(RESETCOLOUR)"
	@clang -g $(FLAGS) -I libft/includes -c $(SRCF1)
	@clang $(FLAGS) -o $(NAME1) $(OBJ1) $(LIBFT)

$(NAME2): $(SRCF2)
	@echo "$(MAKECOLOUR)Compiling $(NAME2)$(RESETCOLOUR)"
	@clang -g $(FLAGS) -I libft/includes -c $(SRCF2)
	@clang $(FLAGS) -o $(NAME2) $(OBJ2) $(LIBFT) -lncurses

clean:
	@echo "$(CLEANCOLOUR)Cleaning Libraries$(RESETCOLOUR)"
	@make -C libft/ clean
	@rm -f $(OBJ1) $(OBJ2)

fclean: clean
	@echo "$(FCLEANCOLOUR)Removing Libraries and programs $(RESETCOLOUR)"
	@make -C libft/ fclean
	@rm -f $(NAME1) $(NAME2)

re: fclean all
