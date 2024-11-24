

d =
f =

CFLAGS = -g -Wall -Wextra -Werror
ifneq ($(d),)
    CFLAGS += -D BUFFER_SIZE=$(d)
endif

all:
	@echo;
	cc $(CFLAGS) test.c ../Project/*.c -I../Project;
	@echo "\n---------------------Output---------------------";
	@./a.out $(f)

bonus:
	cc $(CFLAGS) bonus.c ../Project/*bonus.c -I../Project;
	@echo "\n---------------Bonus-----------";
	@./a.out

clean:
	rm -rf a.out*
