# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    make-deferred-evaluation.mk                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npineau <npineau@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/06/10 17:36:01 by npineau           #+#    #+#              #
#    Updated: 2014/06/10 17:36:14 by npineau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = $(shell echo ’Ouch!’ \
	  1>&2 ; echo *.[cy])
OBJ = \
	  $(patsubst %.c,%.o,\
	  $(filter %.c,$(SRC))) \
	  $(patsubst %.y,%.o,\
	  $(filter %.y,$(SRC)))
test: $(OBJ)
	$(CC) -o $@ $(OBJ)
