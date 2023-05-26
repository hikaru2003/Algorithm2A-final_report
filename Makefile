NAME = sort

SRCS	=	$(shell echo *.c)

OBJDIR = obj/

OBJS = $(SRCS:%.c=$(OBJDIR)%.o)
CC = cc

all: $(OBJDIR) $(NAME)

$(OBJDIR):
	mkdir -p obj

$(OBJDIR)%.o: %.c
		$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all