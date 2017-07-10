/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 16:47:43 by kbovt             #+#    #+#             */
/*   Updated: 2017/03/07 16:47:44 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../../libft/includes/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../../libft/includes/get_next_line.h"
# include "../../printf/includes/ft_printf.h"

typedef struct			s_gnl_list
{
	char				*line;
	struct s_gnl_list	*next;
}						t_gnl_list;

typedef struct			s_stack
{
	int					*stack;
	int					size;
	int					first;
}						t_stack;

typedef struct			s_ch_bskt
{
	int					v;
	int					c;
	int					i;
	char				*i_file;
	char				s;
	char				*s_file;
	int					d;
	int					stack_i;
}						t_ch_bskt;

/*
**main_checker.c
*/
int						main(int argc, char **argv);

/*
**apply_commands.c
*/
void					apl_cmds(t_stack *st_a, t_stack *st_b, t_gnl_list \
						*cmds, t_ch_bskt *bskt);
void					apl_cmd(t_stack *st_a, t_stack *st_b, char *cmd);

/*
**apply_commands2.c
*/
int						swap(t_stack *stack);
int						rotate(t_stack *stack);
int						r_rotate(t_stack *stack);
int						push(t_stack *from, t_stack *to);

/*
**bskt.c
*/
t_ch_bskt				*new_ch_bskt(void);
t_ch_bskt				*del_ch_bskt(t_ch_bskt **bskt);
void					print_bskt(t_ch_bskt *bskt);

/*
**check_argv_flags1.c
*/
int						check_one_flag(t_ch_bskt *bskt, int *i, int argc, \
						char **argv);
int						is_flag(char *argumet);
void					get_allowed_flags(char allowed_flags[5][3]);

/*
**check_argv_flags2.c
*/
int						check_i_flag(t_ch_bskt *bskt, int *i, int argc, \
						char **argv);
int						check_s_flag(t_ch_bskt *bskt, int *i, int argc, \
						char **argv);
int						check_d_flag(t_ch_bskt *bskt);
int						check_v_flag(t_ch_bskt *bskt);
int						check_c_flag(t_ch_bskt *bskt);

/*
**check_commands.c
*/
int						check_cmds(t_gnl_list **inpt_commands);
void					get_allowed_cmds(char commands[12][4]);
int						compare_cmd(char *inpt_command, char *command);

/*
**check_digits.c
*/
int						check_digits(int stack_i, int argc, char **argv);
int						over_int(char *argv);
int						isspc(char c);
long int				ft_atoi_long(char *argv);

/*
**error.c
*/
long int				error_return0(char *print);

/*
**get_commands.c
*/
t_gnl_list				*get_cmds(t_ch_bskt **bskt, t_stack *st_a, \
						int *is_empt);
t_gnl_list				*get_cmds_file(t_ch_bskt **bskt);
t_gnl_list				*get_cmds_debug(t_ch_bskt **bskt, t_stack *stack_a);
t_gnl_list				*get_inpt_fd_debug(int fd, t_ch_bskt **bskt, \
						t_stack *st_a);
t_gnl_list				*get_cmds_stdin(int *is_empty);

/*
**get_input_fd.c
*/
t_gnl_list				*get_inpt_fd(int fd);

/*
**get_stack.c
*/
t_stack					*get_stack(int argc, char **argv, t_ch_bskt **bskt);
t_stack					*get_stack_file(t_ch_bskt **bskt);
t_stack					*get_stack_argv(int argc, char **argv, \
						t_ch_bskt **bskt);

/*
**gnl.c
*/
char					*gnl_to_string(t_gnl_list *list);
char					*ft_strjoin2(char *s1, char *s2);
void					del_gnl_list(t_gnl_list **head);
t_gnl_list				*new_gnl_elem(char *line);
void					print_cmds(t_gnl_list *list);

/*
**read_argv.c
*/
t_ch_bskt				*read_argv(int argc, char **argv, t_ch_bskt **bskt);
int						check_bskt(t_ch_bskt *bskt);
int						check_argv(int argc, char **argv, t_ch_bskt *bskt);

/*
**result.c
*/
void					print_result(int flag);
int						is_sorted(t_stack *stack);

/*
**sort_stack.c
*/
void					ft_swap(int *a, int *b);
void					sort_stack(int *stack, int first, int last);
int						is_dublic_stack(t_stack *stack);

/*
**stack.c
*/
t_stack					*new_stack(int size, int first);
t_stack					*new_stack_b(int size, int first);
t_stack					*del_stack(t_stack **stack);
t_stack					*copy_stack(t_stack *stack_origin);

/*
**stack2.c
*/
int						*stack_from_tab(char **tab, int size, int start_i);
void					print_stack(t_stack *stack);
void					print_stacks(t_stack *stack_a, t_stack *stack_b);

/*
**str.c
*/
char					*str_replace(char *str, char from, char to);

/*
**tab.c
*/
int						count_tabs(char **tab);
long int				del_tab(char ***tab);

#endif
