#ifndef _MAIN_H_
#define _MAIN_H_

#include "config.h"
#include "graph.h"
#include "stats.h"
#include "search.h"
#define MAX_CMD_LEN 50   
const char readme[] = "you guess how to use this tool!!!\n";

const char cmd_table[][MAX_CMD_LEN] = {"-h", "--help", "-g", "--graph", 
                                //  0       1      2        3
                                "-s", "--stats", "-u", "-v",
                                //  4       5      6        7
                                "-j", "-sp" , "--shortestpath" ,
                                // 8      9           10
                                "edges", "vertices", "freeman", "closeness",
                                // 11      12          13          14
                                "DFS", "BFS", "Dijkstra"
                                // 15    16      17
                                };
const int cmd_num = sizeof(cmd_table) / MAX_CMD_LEN;


void process(int argc, char *argv[]);
int strcmp(char *p, char *q);
int matchCmd(char *c);
void init();
void processGraph(int argc, char *argv[]);
void graphPath(int argc, char *argv[]);
void graphStats(int argc, char *argv[]);
void printSuantou();

#endif
