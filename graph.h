#ifndef _GRAPH_H_
#define _GRAPH_H_

#define MAXV 1000000

typedef int data_type;
typedef int id_type;
typedef int info_type;
typedef int num_type;
typedef int weight_type;


typedef struct anode
{
    id_type no;
    weight_type weight;
    struct anode *nextarc;
}Anode;

typedef struct vnode
{
    info_type info;
    num_type num;
    Anode *firstarc;
}Vnode;

typedef struct 
{
    Vnode adj[MAXV];
    num_type n, m;
}adjGraph;
typedef adjGraph* AdjGraph;

AdjGraph createAdj(char *name);

#endif
