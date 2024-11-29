d =
f = test.txt
CFLAGS = -g -Wall -Wextra -Werror
ifneq ($(d),)
    CFLAGS += -D BUFFER_SIZE=$(d)
endif
SRCS = ../Project/get_next_line.c ../Project/get_next_line_utils.c 
SRCSB = ../Project/get_next_line_bonus.c ../Project/get_next_line_utils_bonus.c 
FILES = $(filter-out $(wildcard giant*.txt), $(wildcard *.txt))

# ANSI color codes
RESET  = \033[0m
RED    = \033[31m
GREEN  = \033[32m
YELLOW = \033[33m
BLUE   = \033[34m
CYAN   = \033[36m
BOLD   = \033[1m

all:
	@echo;
	cc $(CFLAGS) test.c $(SRCS) -I../Project;
	@echo "$(BOLD)$(GREEN)\nProcessing $(f)...$(RESET)";
	@./a.out $(f)

files: all
	@for file in $(FILES); do\
		echo "$(BOLD)$(GREEN)Processing $$file...$(RESET)"; \
		./a.out $$file ; \
	done;

bonus:
	cc $(CFLAGS) bonus.c $(SRCSB) -I../Project;
	@echo "\n---------------Bonus-----------";
	@./a.out

clean:
	rm -rf a.out*
