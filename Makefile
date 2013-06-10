APP     = linked_list

SRCS    = linked_list.c linked_list_test.c
OBJS    = $(SRCS:.c=.o)

CFLAGS  = -Wall -pedantic -g
LDFLAGS =

$(APP): $(OBJS)
	$(CC) $^ $(LDFLAGS) -o $@

.c.o:
	$(CC) $(CFLAGS) -c $<

clean:
	$(RM) $(OBJS)
	$(RM) $(APP)