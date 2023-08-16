CC = /usr/bin/gcc-9
CFLAGS = -fdiagnostics-color=always -g
LDFLAGS = 
OUTPUT = search_bin
SOURCES =  $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)

.PHONY: all clean

all: $(OUTPUT)

%o: %c
	$(CC) $(CFLAGS) -c $< -o $@

$(OUTPUT) : $(OBJECTS)
	$(CC) $^ $(LDFLAGS) -o $@

clean:
	rm -f $(OUTPUT) $(OBJECTS)