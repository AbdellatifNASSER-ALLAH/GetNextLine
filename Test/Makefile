

d =

CFLAGS = -Wall -Wextra -Werror
ifneq ($(d),)
    CFLAGS += -D BUFFER_SIZE=$(d)
endif

all:
	@echo;
	cc $(CFLAGS) test.c ../Project/*.c -L../Project;
	@echo "\n---------------------Output---------------------";
	@./a.out; rm -f a.out
