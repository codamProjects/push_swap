
CC= gcc
CFLAGS= -Wall -Werror -Wextra
NAME= push_swap
BNAME= checker
RM= rm -f
HEADER= push_swap.h

SOURCES= push_swap.c \
		 write_free_error.c \
		 get_move.c \
		 short_sort.c \
		 large_sort.c \
		 push.c \
		 atoi_bzero.c \
		 check_tops.c \

BSOURCES= b_moves_s.c \
		  b_moves_p.c \
		  b_read_check.c \
		  checker.c \
		  b_strcmp.c \
		  atoi_bzero.c \
		  check_tops.c \
		  write_free_error.c \

OBJECTS= $(SOURCES:.c=.o)
	
BOBJECTS= $(BSOURCES:.c=.o)

all: $(NAME)

bonus: all $(BNAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS)

$(BNAME): $(BOBJECTS)
	$(CC) $(CFLAGS) -o $(BNAME) $(OBJECTS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $<

clean:
	$(RM) $(OBJECTS) $(BOBJECTS)

fclean: clean
	$(RM) $(NAME) $(BNAME)

re: fclean bonus
