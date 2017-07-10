/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 17:29:25 by kbovt             #+#    #+#             */
/*   Updated: 2017/03/07 17:29:26 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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

typedef struct			s_ordr_lst
{
	int					pack;
	struct s_ordr_lst	*next;
}						t_ordr_lst;

typedef struct			s_stack
{
	int					*stack;
	int					size;
	int					first;
	int					sorted;
	t_ordr_lst			*ordr_lst;
}						t_stack;

typedef struct			s_ps_bskt
{
	char				s;
	char				*s_file;
	int					stack_i;
}						t_ps_bskt;

typedef struct			s_med_lst
{
	int					st_size;
	int					med;
	int					n_cmnds;
	t_gnl_list			*cmnds;
	t_gnl_list			*last_cmnd;
	struct s_med_lst	*next;
}						t_med_lst;

void					main_next(t_stack *st_a, t_stack *st_b);

/*
**med_lst.c
*/
t_med_lst				*make_all_med_lst(t_stack *stack_a);
t_med_lst				*new_one_med_lst(int median, t_stack *stack_a);
void					del_med_lst(t_med_lst **med_lst);
void					append_cmnd(char *cmnd, t_med_lst *med_lst);
t_med_lst				*min_med_lst(t_med_lst *med_lst);

/*
**sort_main.c
*/
void					sort_ps(t_stack *stack_a, t_stack *stack_b, \
						t_med_lst *med_lst);
void					push_pack_back(t_stack *stack_a, t_stack *stack_b, \
						t_med_lst *med_lst);
void					push_pack(t_stack *stack_a, t_stack *stack_b, \
						t_med_lst *med_lst);
int						get_median(int *tab, int size, int *pack_size, \
						t_med_lst *med_lst);
void					sort_small(t_stack *stack_a, t_stack *stack_b, \
						t_med_lst *med_lst);

void					sort_small_a(t_stack *stack_a, t_stack *stack_b, \
						t_med_lst *med_lst);
void					sort_small_a_3(t_stack *stack_a, t_stack *stack_b, \
						t_med_lst *med_lst);
void					sort_small_b(t_stack *stack_a, t_stack *stack_b, \
						t_med_lst *med_lst);
void					sort_small_b_3(t_stack *stack_a, t_stack *stack_b, \
						t_med_lst *med_lst);
void					sort_special(t_stack *stack_a, t_stack *stack_b, \
						t_med_lst *med_lst);

int						is_max(int num, int *tab, int len);

void					sort_small_a_3_ult(t_stack *stack_a, t_stack *stack_b, \
						t_med_lst *med_lst);

/*
**push_smart_back.c
*/
void					push_smart_back(t_stack *stack_a, t_stack *stack_b, \
						t_med_lst *med_lst);
void					push_smart_back_c1(t_stack *st_a, t_stack *st_b, \
						t_med_lst *m_lst);
void					push_smart_back_c2(t_stack *st_a, t_stack *st_b, \
						t_med_lst *m_lst);
void					push_smart_back_c3(t_stack *st_a, t_stack *st_b, \
						t_med_lst *m_lst);
int						push_smart_cond(t_stack *st_b);

/*
**ordr_lst.c
*/
void					add_front_ordr_lst(int new_pack, \
						t_ordr_lst **head_ordr_lst);
void					del_ordr_lst(t_ordr_lst **head_ordr_lst);
void					del_first_ordr_lst(t_ordr_lst **head_ordr_lst);
int						is_ordr_lst_one(t_ordr_lst *head_ordr_lst);
void					print_ordr_lst(t_ordr_lst *lst);

/*
**main_push_swap.c
*/
int						main(int argc, char **argv);

/*
**bskt.c
*/
t_ps_bskt				*new_ps_bskt(void);
t_ps_bskt				*del_ps_bskt(t_ps_bskt **bskt);
void					print_bskt(t_ps_bskt *bskt);

/*
**read_argv.c
*/
t_ps_bskt				*read_argv(int argc, char **argv, t_ps_bskt **bskt);
int						check_bskt(t_ps_bskt *bskt);
int						check_argv(int argc, char **argv, t_ps_bskt *bskt);

/*
**check_argv_flags.c
*/
int						check_one_flag(t_ps_bskt *bskt, int *i, \
						int argc, char **argv);
int						is_flag(char *argumet);
void					get_allowed_flags(char allowed_flags[5][3]);
int						check_s_flag(t_ps_bskt *bskt, int *i, \
						int argc, char **argv);

/*
**get_stack.c
*/
t_stack					*get_stack(int argc, char **argv, t_ps_bskt **bskt);
t_stack					*get_stack_file(t_ps_bskt **bskt);
t_stack					*get_stack_argv(int argc, char **argv, \
						t_ps_bskt **bskt);

/*
**get_input_fd.c
*/
t_gnl_list				*get_inpt_fd(int fd);

/*
**apply_commands.c
*/
void					apply_command(t_stack *stack_a, t_stack *stack_b, \
						char *command);
void					apl_apd_cmd(t_stack *st_a, t_stack *st_b, char *cmd, \
						t_med_lst *m_lst);

/*
**apply_commands2.c
*/
int						swap(t_stack *stack);
int						rotate(t_stack *stack);
int						r_rotate(t_stack *stack);
int						push(t_stack *from, t_stack *to);

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
**gnl.c
*/
char					*gnl_to_string(t_gnl_list *list);
char					*ft_strjoin2(char *s1, char *s2);
void					del_gnl_list(t_gnl_list **head);
t_gnl_list				*new_gnl_elem(char *line);
void					print_commands(t_gnl_list *list);

/*
**gnl.c
*/
int						count_gnl_lst(t_gnl_list *list);

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
int						is_dublic_stack(t_stack **stack);
int						check_dubls(t_stack **stack);

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
int						stack_is_sorted(t_stack *stack_a);

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
