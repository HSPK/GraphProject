#include "search.h"
#include "graph.h"
#include "config.h"
#include "util.h"
#include "priority_queue.h"

const char alg_table[][MAX_ALG_LEN] = {"DFS", "BFS", "Dijkstra"};
const int alg_num = sizeof(alg_table) / MAX_ALG_LEN;
const int inf = 0x3f3f3f3f;
static int matchAlg(char *c);

uint8 visited[MAXV] = {0, };

int *int_new(int value)
{
    int *p = (int *)malloc(sizeof(int));
    *p = value;
    return p;
}

int Dijkstra(AdjGraph g, int u, int w, int* path)
{
    int dis[MAXV];
    for (int i = 0; i < MAXV; i++) {
        dis[i] = inf;
    }
    PriorityQueue *pq = priority_queue_new(PRIORITY_MIN);
    dis[u] = 0;
    path[u] = u;
    //printGraph(g);
    KeyValue *kv = key_value_new(dis[u], int_new(u));
    priority_queue_enqueue(pq, kv);
    
    while (!priority_queue_empty(pq)) {
        Anode *p;
        kv = priority_queue_dequeue(pq);
        u = *(int *)kv->_value;
        dis[u] = kv->_key;
        //printf("de: %d %d\n", u, dis[u]);

        if (u == w) {
            //priority_queue_print(pq);
            return dis[u];
        }

        p = g->adj[u].firstarc;
        while (p != NULL) {
            int v = p->no;
            if (dis[v] > dis[u] + p->weight) {
                dis[v] = dis[u] + p->weight;
                path[v] = u;
                kv = key_value_new(dis[v], int_new(v));
                //printf("en: %d %d\n", v, dis[v]);
                priority_queue_enqueue(pq, kv);
            }
            p = p->nextarc;
        }
    }
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
    int cost;
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
            cost = Dijkstra(g, u, v, path);
            processPath(path, u, v);
            printf("\n%d", cost);
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
