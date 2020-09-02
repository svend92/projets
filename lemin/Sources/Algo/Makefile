# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anain <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/25 15:14:06 by anain             #+#    #+#              #
#    Updated: 2019/06/25 15:14:08 by anain            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


DIRLIB_LIB = ../../Lib
DIRSRC = ./
DIROBJ = ../../Objets
DIRINCS = -I ../../libft \
		  -I ../Utilities \

INC = algo.h
# Nom de la librairie
NAME = $(DIRLIB_LIB)/algo.a

# Nom des fichiers sources C
FICSRCC = $(DIRSRC)/bfs.c $(DIRSRC)/algo_list_manip.c $(DIRSRC)/edmonds_karp.c $(DIRSRC)/final_paths.c $(DIRSRC)/special_cases.c
# Nom des fichiers objets correspondant aux fichiers sources
FICOBJC = $(FICSRCC:$(DIRSRC)/%.c=$(DIROBJ)/%.o)

# Options
OPTIONSC = -Wall -Wextra -Werror

# Creation de la librairie
all : $(NAME)

$(NAME): $(FICOBJC)
	@echo "\033[38;5;15mCréation de la lib algo.a [OK\033[38;5;40m✓\033[38;5;15m]"
	@ar -cr $@ $(FICOBJC)

# Compilation des fichiers sources C
$(FICOBJC): $(FICSRCC) $(INC)
	$(CC) $(OPTIONSC) $(DIRINCS) -c $(DIRSRC)/$(@F:.o=.c) -o $@

clean:
	@rm -f $(FICOBJC)

fclean: clean
	@rm -f $(NAME)

re : fclean all