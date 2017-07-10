CH_NAME = checker
PS_NAME = push_swap
VPATH = ./checker_f/src:./push_swap_f/src
LIB = libft.a
LIB_PATH = ./libft
PRINTF = printf.a
PRINTF_PATH = ./printf
PS_SRC = ps_sort_small_a.c ps_sort_small_b.c ps_push_pack.c ps_apl_cmds.c ps_apl_cmds2.c ps_bskt.c \
ps_check_argv_flags.c ps_check_digits.c ps_error.c \
ps_get_input_fd.c ps_get_stack.c ps_gnl.c ps_gnl2.c ps_main.c ps_med_lst.c ps_ordr_lst.c ps_push_smart_back.c \
ps_read_argv.c ps_sort_main.c ps_sort_stack.c ps_stack.c ps_stack2.c ps_str.c ps_tab.c
CH_SRC = ch_apl_cmds.c ch_apl_cmds2.c ch_bskt.c ch_check_argv_flags1.c ch_check_argv_flags2.c ch_check_cmds.c \
ch_check_digits.c ch_error.c ch_get_cmds.c ch_get_input_fd.c ch_get_stack.c ch_gnl.c ch_main.c \
ch_read_argv.c ch_result.c ch_sort_stack.c ch_stack.c ch_stack2.c ch_str.c ch_tab.c 
PS_OBJ = $(subst .c,.o,$(PS_SRC))
CH_OBJ = $(subst .c,.o,$(CH_SRC))

.PHONY: all clean fclean re

all: $(PS_NAME) $(CH_NAME)

$(PS_NAME): $(LIB) $(PRINTF) $(PS_OBJ)
	gcc -Wall -Wexra -Werror -o $(PS_NAME) $(PS_OBJ) $(PRINTF) $(LIB)

$(CH_NAME): $(LIB) $(PRINTF) $(CH_OBJ)
	gcc -Wall -Wexra -Werror -o $(CH_NAME) $(CH_OBJ) $(PRINTF) $(LIB)

$(PS_OBJ): $(PS_SRC)
	gcc -Wall -Wextra -Werror -c $^

$(CH_OBJ): $(CH_SRC)
	gcc -Wall -Wextra -Werror -c $^

$(LIB) :
	@make -C $(LIB_PATH)
	@make clean -C $(LIB_PATH)
	mv $(LIB_PATH)/$(LIB) ./

$(PRINTF) :
	@make -C $(PRINTF_PATH)
	@make clean -C $(PRINTF_PATH)
	mv $(PRINTF_PATH)/$(PRINTF) ./

clean:
	/bin/rm -f $(PS_OBJ) $(CH_OBJ)
	/bin/rm -f $(LIB)
	/bin/rm -f $(PRINTF)

fclean: clean
	/bin/rm -f $(PS_NAME) $(CH_NAME)

re: fclean all
