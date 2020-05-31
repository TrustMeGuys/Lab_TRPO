.PHONY: all clean

OBJ_CATALOG=build_file


CC=gcc
CFLAGS= -c -Wall -Werror
SOURCES=main.c geometry.c
VPATH=source

OBJECTS=$(addprefix $(OBJ_CATALOG)/,$(SOURCES:.c=.o))
EXECUTABLE=main

all:$(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -lm -o bin/main.exe

$(OBJ_CATALOG)/%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJ_CATALOG)/*.o bin/*.exe
