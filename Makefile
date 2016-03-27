EXEC = threadpool

all: $(EXEC)

CC ?= gcc
CFLAGS = \
	-std=c99 -Wall -O0 -g
LDFLAGS = \
	-lpthread

$(EXEC): threadpool.c main.c
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	$(RM) $(EXEC)
