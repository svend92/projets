# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anain <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/14 16:51:54 by anain             #+#    #+#              #
#    Updated: 2019/11/14 16:51:55 by anain            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

DIRSRC = Sources
DIRLIB = Lib
DIROBJ = Objets
DIRSRC_SRC =	$(DIRSRC)/Algo \
				$(DIRSRC)/Utilities \
				$(DIRSRC)/Parser \
				$(DIRSRC)/Display \
				libft

OPTIONSC :=	-Wall -Wextra -Werror

DIRINCS = -I $(DIRSRC)/Algo \
		-I $(DIRSRC)/Utilities \
		-I $(DIRSRC)/Parser \
		-I $(DIRSRC)/Display \
		-I libft \
# Librairies necessaires a l'executable

LIBS = $(DIRLIB)/algo.a $(DIRLIB)/utilities.a $(DIRLIB)/parser.a $(DIRLIB)/display.a libft/libft.a 

FICSRCC = $(DIRSRC)/main.c
FICOBJC = $(FICSRCC:$(DIRSRC)/%.c=$(DIROBJ)/%.o)

all : $(NAME)

$(NAME): $(LIBS) libs $(DIROBJ) $(FICOBJC)
	@echo
	@echo "\033[38;5;15mCréation de $@ [OK\033[38;5;40m✓\033[38;5;15m]"
	@$(CC) $(OPTIONSC) $(FICOBJC) $(LIBS) -o $@

libs :
	@make -s -C $(DIRSRC)/Algo
	@make -s -C $(DIRSRC)/Parser
	@make -s -C $(DIRSRC)/Utilities
	@make -s -C $(DIRSRC)/Display
	@make -s -C libft

$(LIBS):
	@mkdir $(DIRLIB) 2> /dev/null || true
	@mkdir $(DIROBJ) 2> /dev/null || true

# Compilation des fichiers sources C

$(DIROBJ)/%.o: $(DIRSRC)/%.c
	@$(CC) $(DIRINCS) -c $(DIRSRC)/$(@F:.o=.c) -o $@

clean: cleanlib
	@rm -f $(FICOBJC)
	@echo "\033[38;5;15mclean [OK\033[38;5;40m✓\033[38;5;15m]"

cleanlib :
	@for dir in $(DIRSRC_SRC) ; do \
        make -s clean -C  $$dir ; \
    done
fclean: clean fcleanlib
	@rm -f $(NAME)
	@rm -rf $(DIROBJ)
	@rm -rf $(DIRLIB)
	@echo "\033[38;5;15mfclean [OK\033[38;5;40m✓\033[38;5;15m]"

fcleanlib :
	@for dir in $(DIRSRC_SRC) ; do \
        make -s fclean -C  $$dir ; \
    done
re : fclean all
