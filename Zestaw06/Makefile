
NAME1 = BinaryTree	

EXEC1  = $(NAME1).x

OBJS1  = $(NAME1).o

CFLAGS = -Wall -Wextra -std=c11 -pedantic -O -fPIC
LFLAGS = -Wall -Wextra -std=c11 -pedantic -O

CO = g++
LD = $(CO)

%.o: %.c
	$(CO) $(CFLAGS) -c $<

.PHONY: all clean
all: $(EXEC1)

$(EXEC1): $(OBJS1)
	$(LD) -o $@ $(LFLAGS) $^
	
clean:
	rm -f *.o  *~ *.a *.so *.x core core* a.out *.exe 

	