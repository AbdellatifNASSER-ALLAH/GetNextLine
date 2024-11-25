d =
f =
CFLAGS = -g -Wall -Wextra -Werror
ifneq ($(d),)
    CFLAGS += -D BUFFER_SIZE=$(d)
endif
SRCS = ../Project/get_next_line.c ../Project/get_next_line_utils.c 
SRCSB = ../Project/get_next_line_bonus.c ../Project/get_next_line_utils_bonus.c 

all:
	@echo;
	cc $(CFLAGS) test.c $(SRCS) -I../Project;
	@echo "\n---------------------Output---------------------";
	@./a.out $(f)

bonus:
	cc $(CFLAGS) bonus.c $(SRCSB) -I../Project;
	@echo "\n---------------Bonus-----------";
	@./a.out

clean:
	rm -rf a.out*
