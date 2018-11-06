/*
 * Created by yuwancumian666 on 2018/10/30.
*/

#ifndef DATA_STRUCTURE_GRAPH_H
#define DATA_STRUCTURE_GRAPH_H


#define MAX_VERTEX_NUM 20
#define INFINITY 32768
#define ADJ_TYPE int
#define OTHER_INFO char

typedef enum {DG, DN, UDG, UDN} GraphKind;
typedef char VertexData;
typedef struct ArcNode {
    ADJ_TYPE adj;
    OTHER_INFO info;
} ArcNode;
typedef struct {
    VertexData vertex[MAX_VERTEX_NUM];
    ArcNode arcs[MAX_VERTEX_NUM];
    int vexnum, arcnum;
    GraphKind kind;
} AdjMatrix;


#endif //DATA_STRUCTURE_GRAPH_H
