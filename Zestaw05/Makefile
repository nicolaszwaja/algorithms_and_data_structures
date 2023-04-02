
NAME1 = BubbleSort		
NAME2 = InsertionSort
NAME3 = SelectionSort

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
all: $(EXEC1) $(EXEC2)

$(EXEC1): $(OBJS1)
	$(LD) -o $@ $(LFLAGS) $^
	
$(EXEC2): $(OBJS2)
	$(LD) -o $@ $(LFLAGS) $^

$(EXEC3): $(OBJS3)
	$(LD) -o $@ $(LFLAGS) $^	

clean:
	rm -f *.o  *~ *.a *.so *.x core core* a.out *.exe 

	