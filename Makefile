All:
	gcc -o run Spring_mass/spring.c main.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
clean: 
	rm -f run