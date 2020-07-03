obj = main.o graph.o stats.o
search-cli: $(obj)
	gcc -o search-cli $(obj)

main.o: main.c main.h
	gcc -c -g main.c 

graph.o: graph.c graph.h config.h
	gcc -c -g graph.c

stats.o: stats.c graph.h stats.h
	gcc -c -g stats.c

.PHONY:clean
clean:
	-rm $(obj)
