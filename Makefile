TARGET=main

SOURCES=$(wildcard *.c)
OBJS=$(SOURCES:.c=.o)

CC=g++
LDFLAGS=-g #for using the gdb
INC_FLAGS=-I../include
CFLAGS= -c -pedantic -Wall -Werror -Wconversion -ansi -g $(INC_FLAGS)# -g flag for using gdb
CXXFLAGS=$(CFLAGS)

.PHONY: clean run gdb

$(TARGET): $(OBJS)
# all .cpp files in this directory are my sources



.depends:
	$(CC) -MM -I$(INC_DIR) $(SOURCES) > .depends

include .depends

clean:
	rm -f $(OBJS) $(TARGET) .depends
leak:
	valgrind --leak-check=full ./$(TARGET)

run: $(TARGET)
	./$(TARGET)

# Do not forget to add '-g' to CFLAGS
gdb: $(TARGET)
	gdb -q ./$(TARGET)






