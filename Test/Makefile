

d = 1024

all:
	@if [ "$(d)" != "1024" ]; then \
		@cc -D BUFFER_SIZE=$(d) test.c ../Project/*.c -L../Project; \
	else \
	 	@cc test.c ../Project/*.c -L../Project; \
	fi
	@echo "---------------------Output---------------------"
	@./a.out; rm -f a.out
