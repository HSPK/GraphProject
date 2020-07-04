#include "search.h"
char* shortestPath(int u, int v, char algorithm[], char name[])
{
    AdjGraph g;
    g = createAdj(name);
	char *path;
	switch(matchCmd(algorithm[])) {
		case 15:
			path = DFS(u,v,g)
			break;
		case 16:
			break;
		case 17:
			break;
	}
	return path;


}
char*DFS(int u, int v, AdjGraph g)


