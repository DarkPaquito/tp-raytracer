CC = g++
CFLAGS = -Wall -Werror -Wextra -std=c++20 -pedantic
VPATH = src

BIN = raytracer
OBJS = raytracer.o type.o image.o

all: $(BIN)

$(BIN): $(OBJS)

clean:
	$(RM) $(BIN) $(OBJS)

.PHONY: all clean
