#include "search.h"
/*<<<<<<< HEAD
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

=======*/
#include "graph.h"
#include "config.h"
#include "util.h"
#include "priority_queue.h"

const char alg_table[][MAX_ALG_LEN] = {"DFS", "BFS", "Dijkstra"};
const int alg_num = sizeof(alg_table) / MAX_ALG_LEN;
static int matchAlg(char *c);

uint8 visited[MAXV] = {0, };

int Dijkstra(AdjGraph g, int u, int v, int path)
{
    KeyValue *kv = key_value_new(0, &u);
}

void BFS(AdjGraph g, int u, int v, int *path)
{

}

void DFS(AdjGraph g, int u, int v,int *path)
{
    Anode *p;
    visited[u] = 1;
    if (u == v) {
        return;
    }
    p = g->adj[u].firstarc;
    while (p != NULL) {
        if (visited[p->no] == 0) {
            path[p->no] = u;
            DFS(g, p->no, v,path);
        }
        p = p->nextarc;
    }
}

void processPath(int *path, int u, int v)
{
    if (path[v] == 0) {
        printf("path not exist!!!\n");
        return;
    }
    int i = v;
    while (i != path[i])
    {
        printf("%d <- ", i);
        i = path[i];
    }
    printf("%d", i);
}

char* shortestPath(int u, int v, char algorithm[], char name[])
{
    AdjGraph g;
    g = createAdj(name);
    id_type path[MAX_PATH_LEN];
    //char path[MAX_PATH_LEN] = {0, };
    if (g->adj[u].num == -1 || g->adj[v].num == -1) {
        printf("vertices not exist!!!\n");
        exit(1);
    } 
    path[u] = u;
    switch (matchAlg(algorithm))
    {
        case 0 :            //DFS
            DFS(g, u, v, path);
            //processPath(path, u, v);
            break;
        case 1 :            //BFS
            BFS(g, u, v, path);
            break;
        default:
            printf("unsupported alg: %s\n", algorithm);
            break;
    }
}

static int matchAlg(char *c)
{
    for (int i = 0; i < alg_num; i++) {
        if (strcmp(c, (char *)alg_table[i]) == 0) {
            return i;
        }
    }
    return -1;
}
//>>>>>>> way
