#include "graph.h"
#include "stats.h"
#include "priority_queue.h"
#include "config.h"

static void Dijkstra(AdjGraph g, int u , int* dis);
static int *int_new(int value);
static const int inf = 0x3f3f3f3f;

int numberOfEdges(char name[])
{
    AdjGraph g;
    num_type m;
    g = createAdj(name);
    m = g->m;
    //printf("%d", g->m);
    free(g);
    return m;
}

int numberOfVertices(char name[])
{
    AdjGraph g;
    num_type n;
    g = createAdj(name);
    //printf("%d", g->n);
    n = g->n;
    free(g);
    return n;
}

void deleteI(Vnode *v, id_type id)
{
    Anode *p, *pre;
    pre = v->firstarc;
    if (pre == NULL)
        return;
    if (pre->no == id) {
        v->firstarc = pre->nextarc;
        v->outDegree--;
        v->inDegree--;
        free(pre);
        return;
    }
    p = pre->nextarc;
    while (p != NULL) {
        if (p->no == id) {
            pre->nextarc = p->nextarc;
            v->outDegree--;
            v->inDegree--;
            free(p);
            return;
        }
        pre = p;
        p = p->nextarc;
    }
}

void deleteDupVer(AdjGraph g)
{
    for (int i = 0; i < MAXV; i++) {
        if (g->adj[i].outDegree > 0) {
            Anode *p = g->adj[i].firstarc;
            while (p != NULL) {
                deleteI(&g->adj[p->no], i);
                //printGraph(g);
                //printf("\n");
                p = p->nextarc;
            }
        }
    }
}

float freemanNetworkCentrality(char name[])
{
    double cd;
    AdjGraph g;
    g = createAdj(name);
    //freopen("out.txt", "w", stdout);
    //printGraph(g);
    long cd1 = (long)(g->n - 1) * (g->n - 2);
    //printf("%ld", cd1);
    long max = -1;
    long sum = 0;
    int num;
    int num2;
    deleteDupVer(g);
    for (int i = 0; i < MAXV; i++) {
        num = g->adj[i].outDegree;
        if (num > 0) {
            //printf("%d:%d\n", i, num);
            num2 = num + g->adj[i].inDegree;
            sum += 2 * num;
            if (num2 > max) {
                max = num2;
            }
        }
    }
    sum = g->n * max - sum;
    printf("分子：%ld 分母：%ld 最大度:%ld\n", sum, cd1, max);
    cd = (double)sum / cd1;
    //printf("\n");
    //printGraphList(g);
    //printf("%.15lf\n", cd);
    return (float)cd;
}

float closenessCentrality(char name[], int node)
{
    AdjGraph g;
    g = createAdj(name);
    int dis[MAXV];
    long sum = 0;
    long num = 0;
    double cc;
    Dijkstra(g, node, dis);
    for (int i  = 0; i < MAXV; i++) {
        if (dis[i] != inf) {
            num++;
            //printf("%d: %d\n", i, dis[i]);
            sum += dis[i];
        }
    }
    cc = (double)(num - 1) / sum;
    //printf("%.15lf\n", cc);
    return cc;
}

static int *int_new(int value)
{
    int *p = (int *)malloc(sizeof(int));
    *p = value;
    return p;
}

static void Dijkstra(AdjGraph g, int u , int* dis)
{
    if (g->adj[u].outDegree == -1) {
        printf("vertice doesn't exitst!!!");
        exit(1);
    }
    for (int i = 0; i < MAXV; i++) {
        dis[i] = inf;
    }
    PriorityQueue *pq = priority_queue_new(PRIORITY_MIN);
    dis[u] = 0;
    KeyValue *kv = key_value_new(dis[u], int_new(u));
    priority_queue_enqueue(pq, kv);
    
    while (!priority_queue_empty(pq)) {
        Anode *p;
        kv = priority_queue_dequeue(pq);
        u = *(int *)kv->_value;
        //dis[u] = kv->_key > dis[u] ? dis[u] : kv->_key;

        //printf("de: %d %d\n\n", u, dis[u]);

        p = g->adj[u].firstarc;
        while (p != NULL) {
            int v = p->no;
            if (dis[v] > dis[u] + p->weight) {

                //printf("cmp: %d %d\n\n", u, v);

                dis[v] = dis[u] + p->weight;
                kv = key_value_new(dis[v], int_new(v));

                //printf("en: %d %d\n\n", v, dis[v]);
                priority_queue_enqueue(pq, kv);
            }
            p = p->nextarc;
        }
    }
}

