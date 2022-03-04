CC = g++
EXECUTABLE = main
BUILDDIR = build
CFLAGS = -g -Wall -Werror -std=c17

VPATH = calculator calculator/math calculator/gui calculator/math/exceptions

all: $(EXECUTABLE)

run: all
	./$(EXECUTABLE)

$(EXECUTABLE): main.o wmath.o

clean:
	rm *.o  $(EXECUTABLE)
