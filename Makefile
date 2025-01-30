OBJ := $(patsubst %.c,%.o,$(wildcard *.c))

inverted_search: $(OBJ)	
	gcc -o $@ $^

%.o: %.c
	gcc -c $< -o $@

clean:
	rm -f *.o inverted_search