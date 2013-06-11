CC           = gcc
FLAGS        = # -std=gnu99 -Iinclude
CFLAGS       = -fPIC -g #-pedantic -Wall -Wextra -ggdb3
LDFLAGS      = -shared
DEBUGFLAGS   = -O0 -D _DEBUG
RELEASEFLAGS = -O2 -D NDEBUG -combine -fwhole-program

LINKED_LIST  = linked_list
SHARED_LIB   = linked_list.so
STATIC_LIB   = linked_list.a
SOURCES      = linked_list.c linked_list_test.c
HEADERS      = linked_list.h
OBJECTS      = $(SOURCES:.c=.o)

all: $(SHARED_LIB) $(STATIC_LIB) $(LINKED_LIST)

$(SHARED_LIB): $(OBJECTS)
	$(CC) $(FLAGS) $(CFLAGS) $(DEBUGFLAGS) -o $(SHARED_LIB) $(OBJECTS)

$(STATIC_LIB): $(OBJECTS)
	ar -cvq $(STATIC_LIB) $(OBJECTS)

$(LINKED_LIST):  $(OBJECTS) $(STATIC_LIB)
	$(CC) -o $(LINKED_LIST) $(OBJECTS) $(STATIC_LIB)

clean:
	$(RM) $(OBJECTS)
	$(RM) $(SHARED_LIB)
	$(RM) $(STATIC_LIB)
	$(RM) $(LINKED_LIST)
