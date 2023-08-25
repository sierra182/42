CC = /usr/bin/gcc-9
CFLAGS = -fdiagnostics-color=always -g
LDFLAGS = 
OUTPUT = ft_ten_queens_puzzle
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