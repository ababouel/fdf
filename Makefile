# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ababouel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/16 20:53:00 by ababouel          #+#    #+#              #
#    Updated: 2022/02/20 18:06:38 by ababouel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = src/draw.c \
	   src/keytools.c \
	   src/main.c \
	   src/parsemap.c \
	   src/retools.c \
	   src/tools.c \
	   src/utils/ft_atoi.c \
	   src/utils/ft_strdup.c \
	   src/utils/ft_freemem.c \
	   src/utils/get_next_line.c \
	   src/utils/ft_split.c \
	   src/utils/get_next_line_utils.c \
	   src/utils/ft_strchr.c

SRCS_BONUS = src_bonus/draw_bonus.c \
	   src_bonus/keytools_bonus.c \
	   src_bonus/main_bonus.c \
	   src_bonus/parsemap_bonus.c \
	   src_bonus/retools_bonus.c \
	   src_bonus/tools_bonus.c \
	   src_bonus/utils/ft_atoi_bonus.c \
	   src_bonus/utils/ft_strdup_bonus.c \
	   src_bonus/utils/ft_freemem_bonus.c \
	   src_bonus/utils/get_next_line_bonus.c \
	   src_bonus/utils/ft_split_bonus.c \
	   src_bonus/utils/get_next_line_utils_bonus.c \
	   src_bonus/utils/ft_strchr_bonus.c \
	   src_bonus/menu_bonus.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
FLAGS = -Wall -Werror -Wextra
NAME = fdf
FDF = src/utils/fdf.h
FDF_BONUS = src_bonus/utils/fdf_bonus.h

all: $(NAME)

$(NAME) : $(OBJS)
	cc $(FLAGS) $(OBJS) -o $@ -lmlx -framework OpenGL -framework AppKit

%.o: %.c $(FDF)
	cc $(FLAGS) -c $< -o $@

bonus: $(OBJS_BONUS)
	cc $(FLAGS)  $(OBJS_BONUS) -o $(NAME) -lmlx -framework OpenGL -framework AppKit

%.o: %.c $(FDF_BONUS)
	cc $(FLAGS) -c $< -o $@

clean: 
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME) clean

.PHONY = re fclean clean all bonus
