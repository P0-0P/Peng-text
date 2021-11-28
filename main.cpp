#include <iostream>
#define MAX 20
using namespace std;
//ͼ���ڽӾ���洢��ʾ
#define MVNum 100 //��󶥵���
typedef struct {
    char vexs[MVNum];
    int arcs[MVNum][MVNum];
    int vexnum, arcnum;
}AMGraph;

//�����ڽӾ��󴴽�������
int LocateVex(AMGraph &G,char v){
    int temp;
    for(int i=0;i<G.vexnum;i++){
        if(v==G.vexs[i])
            temp= i;
    }
    return temp;
}
void CreateUDN(AMGraph &G){
    cout<<"���붥����Ϣ(�ܶ��������ܱ���)"<<endl;
    cin >> G.vexnum >> G.arcnum;
    cout << "���������������"<<endl;
    for (int i = 0;i < G.vexnum;i++) {
        cin>>G.vexs[i];
    }
    for (int i=0;i<G.vexnum;i++){
        for(int j=0;j<G.vexnum;j++)
            G.arcs[i][j]=0;
    }
    cout << "����һ�����ϵĶ��㼰Ȩֵ"<<endl;
    
    for (int k = 0;k < G.arcnum;k++) {
        cout << "��"<<k+1<<"���ߵ����ݣ�";
        char V1, V2;
        int W;
        cin >> V1 >> V2 >> W;
        int i=LocateVex(G,V1);
        int j=LocateVex(G,V2);
        G.arcs[i][j]=W;
        G.arcs[j][i]=G.arcs[i][j];
    }

}
//��ʾ�ڽӾ���
void show(AMGraph& G) {
    cout << "�ڽӾ���Ϊ��"<<endl;
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
//������ȱ���(������)
int visited[MAX]={0};
void DFS(AMGraph G, int v) {
    cout << G.vexs[v] << " ";
    visited[v] = 1;
    for (int k = 0;k < G.vexnum;k++) {
        if (visited[k] == 0 && G.arcs[v][k] != 0)
            DFS(G, k);
    }
}
//��������
typedef struct {
    int* base;
    int front;
    int rear;
}SqQueue;
//���г�ʼ��
void InitQueue(SqQueue& Q) {
    Q.base = new int[MAX];
    Q.front = Q.rear = 0;
}
//��ӳ���
void EnQueue(SqQueue& Q, int e) {
    if ((Q.rear + 1) % MAX == Q.front)
        cout << "����"<<endl;
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MAX;
}
void DnQueue(SqQueue& Q,int &u) {
    if (Q.front == Q.rear)
        cout << "�� �� "<<endl;
    u = Q.base[Q.front];
    Q.front = (Q.front + 1) % MAX;
}
//�ж϶����Ƿ�Ϊ��
bool QueueEmpty(SqQueue Q) {
    if (Q.front == Q.rear || (Q.rear + 1) % MAX == Q.front)
        return false;
    else
        return true;
}
//������ȱ���(������)
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
    //cout << "������ȱ�����"<<endl;
    //DFS(G, 1);
    cout << "������ȱ�����"<<endl;
    BFS(G, 1);
}