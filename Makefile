obj = main.o graph.o stats.o priority_queue.o search.o util.o
search-cli: $(obj)
	gcc -o search-cli $(obj)

main.o: main.c main.h
	gcc -c -g main.c 

graph.o: graph.c graph.h config.h
	gcc -c -g graph.c

stats.o: stats.c graph.h stats.h
	gcc -c -g stats.c

priority_queue.o: priority_queue.c priority_queue.h
	gcc -c -g priority_queue.c

search.o: search.c search.h
	gcc -c -g search.c

util.o: util.c util.h
	gcc -c -g util.c

.PHONY:clean
clean:
	-rm $(obj)
