CC=clang
FLAGS=-g -lreadline

all=shell

%.o: %.c
	$(CC) -c -o $@ $<

utilities.o: utilities.c utilities.h 

processes.o: processes.c processes.h 

builtins.o: builtins.c builtins.h 

shell: shell.c utilities.o processes.o builtins.o
	$(CC) $(FLAGS) $^ -o $@

clean:
	rm -f *.o

clear: 
	rm -f $(all) 
