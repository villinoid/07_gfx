
OBJECTS= main.o draw.o display.o matrix.o parser.o gmath.o stack.o
CFLAGS= -Wall
LDFLAGS= -lm
CC= gcc

run: all
	./main script

all: $(OBJECTS)
	$(CC) -g -o main $(OBJECTS) $(LDFLAGS)

main.o: main.c display.h draw.h ml6.h matrix.h parser.h
	$(CC) -c main.c

draw.o: draw.c draw.h display.h ml6.h matrix.h gmath.h
	$(CC) $(CFLAGS) -c draw.c

display.o: display.c display.h ml6.h matrix.h stb_image_write.h
	$(CC) $(CFLAGS) -c display.c

matrix.o: matrix.c matrix.h
	$(CC) $(CFLAGS) -c matrix.c

parser.o: parser.c parser.h matrix.h draw.h display.h ml6.h stack.h
	$(CC) $(CFLAGS) -c parser.c

gmath.o: gmath.c gmath.h ml6.h
	$(CC) $(CFLAGS) -c gmath.c

stack.o: stack.c stack.h matrix.h
	$(CC) $(CFLAGS) -c stack.c

clean:
	rm *.o *~