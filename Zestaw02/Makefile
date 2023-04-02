
NAME1 = Queue
NAME2 = Generator
NAME3 = Radix

EXEC1  = $(NAME1).x
EXEC2  = $(NAME2).x
EXEC3  = $(NAME3).x

OBJS1  = $(NAME1).o
OBJS2  = $(NAME2).o
OBJS3  = $(NAME3).o

CFLAGS = -Wall -Wextra -std=c11 -pedantic -O -fPIC
LFLAGS = -Wall -Wextra -std=c11 -pedantic -O

CO = g++
LD = $(CO)

%.o: %.c
	$(CO) $(CFLAGS) -c $<

.PHONY: all clean
all: $(EXEC1) $(EXEC2) $(EXEC3)

$(EXEC1): $(OBJS1)
	$(LD) -o $@ $(LFLAGS) $^
	
$(EXEC2): $(OBJS2)
	$(LD) -o $@ $(LFLAGS) $^
	
$(EXEC3): $(OBJS3)
	$(LD) -o $@ $(LFLAGS) $^

clean:
	rm -f *.o  *~ *.a *.so *.x core core* a.out *.exe 

	