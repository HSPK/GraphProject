#include "search.h"
char* shortestPath(int u, int v, char algorithm[], char name[])
{
    AdjGraph g;
    g = createAdj(name);
	int p[5000000];
	char *path;
	switch(matchCmd(algorithm[])) {
		case 15:
		    DFS(u, v, g, 0);
			break;
		case 16:

			break;
		case 17:

			break;
	}
	return NULL;


}
int visited[1000000] = { 0 };
void DFS(int u, int v, AdjGraph g,int d,int path[]) 
{
	int w, i;
	Anode *p;
	path[d++] = u;
	visited[u] = 1;
	if (u == v && d > 0) {
		for (i = 0; i < d; i++)
	    	printf("%2d->", path[i]);
		printf("\n");
	    return;
	}
	p = g->adj[u].firstarc;
    while (p != NULL) {
		w = p->no;
		if (visited[w] == 0)
			DFS(w, v, g, d, path);
		p = p->nextarc;															
	}
}

