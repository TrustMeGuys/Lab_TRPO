OBJ_CATALOG=build/src
OBJ_CATALOG_TEST=build/test

CC=gcc
CFLAGS=-c -Wall -Werror
LDFLAGS=-Wall -Werror
SOURCES=main.c calculating_circles.c input_circles.c intersection_circles.c
SOURCES= main_test.c input_circles.c test_input_circles.c
VPATH=src test

.PHONY: all clean

OBJECTS=$(addprefix $(OBJ_CATALOG)/, $(SOURCES:.c=.o))
OBJECTS_TEST=$(addprefix $(OBJ_CATALOG_TEST)/, $(SOURCES_TEST:.c=.o))
EXECUTABLE=geometry

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) $(OBJECTS_TEST)
	$(CC) $(LDFLAGS) $(OBJECTS) -lm -o bin/main.exe
	$(CC) $(LDFLAGS) $(OBJECTS) -o bin/main_test.exe
	./bin/main_test.exe

$(OBJ_CATALOG)/%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

$(OBJ_CATALOG_TEST)/%.o: %.c
	$(CC) -I thirdparty -I src $(CFLAGS) $< -o $@
clean:
	rm -rf $(OBJ_CATALOG)/*.o $(OBJ_CATALOG_TEST)/*.o bin/*.exe
