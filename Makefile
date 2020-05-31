.PHONY: all clean

OBJ_CATALOG=build


CC=gcc
CFLAGS= -c -Wall -Werror
SRC=main.c geometry.c
VPATH=src

OBJECTS=$(addprefix $(OBJ_CATALOG)/,$(SRC:.c=.o))
EXECUTABLE=main

all:$(SRC) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -lm -o bin/main.exe

$(OBJ_CATALOG)/%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJ_CATALOG)/*.o bin/*.exe
