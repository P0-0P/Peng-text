#include <iostream>
#define MAX 20
using namespace std;
//图的邻接矩阵存储表示
#define MVNum 100 //最大顶点数
typedef struct {
    char vexs[MVNum];
    int arcs[MVNum][MVNum];
    int vexnum, arcnum;
}AMGraph;

//采用邻接矩阵创建无向网
int LocateVex(AMGraph &G,char v){
    int temp;
    for(int i=0;i<G.vexnum;i++){
        if(v==G.vexs[i])
            temp= i;
    }
    return temp;
}
void CreateUDN(AMGraph &G){
    cout<<"输入顶点信息(总顶点数和总边数)"<<endl;
    cin >> G.vexnum >> G.arcnum;
    cout << "输入各个顶点数："<<endl;
    for (int i = 0;i < G.vexnum;i++) {
        cin>>G.vexs[i];
    }
    for (int i=0;i<G.vexnum;i++){
        for(int j=0;j<G.vexnum;j++)
            G.arcs[i][j]=0;
    }
    cout << "输入一条边上的顶点及权值"<<endl;
    
    for (int k = 0;k < G.arcnum;k++) {
        cout << "第"<<k+1<<"条边的数据：";
        char V1, V2;
        int W;
        cin >> V1 >> V2 >> W;
        int i=LocateVex(G,V1);
        int j=LocateVex(G,V2);
        G.arcs[i][j]=W;
        G.arcs[j][i]=G.arcs[i][j];
    }

}
//显示邻接矩阵
void show(AMGraph& G) {
    cout << "邻接矩阵为："<<endl;
    cout << " ";
    for (int i = 0;i < G.vexnum;i++)
        cout << " " << G.vexs[i];
    cout<<endl;
    for (int i=0;i<G.vexnum;i++){
        cout << G.vexs[i] << " ";
        for(int j=0;j<G.vexnum;j++)
            cout<<G.arcs[i][j]<<" ";
    cout<<endl;
    }
}
//深度优先遍历(无向网)
int visited[MAX]={0};
void DFS(AMGraph G, int v) {
    cout << G.vexs[v] << " ";
    visited[v] = 1;
    for (int k = 0;k < G.vexnum;k++) {
        if (visited[k] == 0 && G.arcs[v][k] != 0)
            DFS(G, k);
    }
}
//创建队列
typedef struct {
    int* base;
    int front;
    int rear;
}SqQueue;
//队列初始化
void InitQueue(SqQueue& Q) {
    Q.base = new int[MAX];
    Q.front = Q.rear = 0;
}
//入队出队
void EnQueue(SqQueue& Q, int e) {
    if ((Q.rear + 1) % MAX == Q.front)
        cout << "队满"<<endl;
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MAX;
}
void DnQueue(SqQueue& Q,int &u) {
    if (Q.front == Q.rear)
        cout << "队 空 "<<endl;
    u = Q.base[Q.front];
    Q.front = (Q.front + 1) % MAX;
}
//判断队列是否为空
bool QueueEmpty(SqQueue Q) {
    if (Q.front == Q.rear || (Q.rear + 1) % MAX == Q.front)
        return false;
    else
        return true;
}
//广度优先遍历(无向网)
void BFS(AMGraph G, int v) {
    SqQueue Q;
    InitQueue(Q);
    cout << G.vexs[v]<<" ";
    visited[v] = 1;
    EnQueue(Q, v);
    while (QueueEmpty(Q)) {
        int u;
        DnQueue(Q, u);
        for (int k = 0;k < G.vexnum;k++) {
            if (visited[k] == 0 && G.arcs[u][k] != 0) {
                cout << G.vexs[k]<<" ";
                visited[k] = 1;
                EnQueue(Q, k);
            }
        }
    }
}
int main()
{
    AMGraph G;
    CreateUDN(G);
    show(G);
    //cout << "深度优先遍历："<<endl;
    //DFS(G, 1);
    cout << "广度优先遍历："<<endl;
    BFS(G, 1);
}