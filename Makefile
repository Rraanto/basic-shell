CC=clang
FLAGS=-g -lreadline

all=shell

shell:shell.c 
	$(CC) $(FLAGS) $^ -o $@

clean:
	rm $(all)
