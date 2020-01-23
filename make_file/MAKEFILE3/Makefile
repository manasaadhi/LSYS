
SRCS=*.c
OBJS=$(SRCS:%.o=%.c)




all:main
	@echo "completed..."


%.o:%.c
	gcc $(OBJS) -o $@
clean:
	rm -rf *.o

