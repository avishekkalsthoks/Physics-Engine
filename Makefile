All:
	gcc -o run main.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
clean: 
	rm -f run