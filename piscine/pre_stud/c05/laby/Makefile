CC = /usr/bin/gcc-9
CFLAGS = -Wall -Wextra -Werror
LDFLAGS =
OUTPUT = laby
SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)

.PHONY: all clean

all: $(OUTPUT)

$(OUTPUT): $(OBJECTS)
	$(CC) $^ $(LDFLAGS) -o $@

%o: %c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -f $(OBJECTS) $(OUTPUT)
