OBJ_CATALOG=build

CC=gcc
CFLAGS=-c -Wall -Werror
LDFLAGS=-Wall -Werror
SOURCES=main.c calculating_circles.c input_circles.c intersection_circles.c
VPATH=src

.PHONY: all clean

OBJECTS=$(addprefix $(OBJ_CATALOG)/, $(SOURCES:.c=.o))
EXECUTABLE=geometry

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) $(OBJECTS_TEST)
	$(CC) $(LDFLAGS) $(OBJECTS) -lm -o bin/main.exe

$(OBJ_CATALOG)/%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJ_CATALOG)/*.o 
