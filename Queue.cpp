#include <iostream>
#define MAXSIZE 100
using namespace std;

//定义队列
typedef struct {
    int* base;
    int front;
    int rear;
}SqQueue;

//队列初始化
void InitQueue(SqQueue& Q) {
    Q.base = new int[MAXSIZE];
    Q.front = Q.rear = 0;
}

//入队函数
void EnQueue(SqQueue& Q, int e) {
    if ((Q.rear + 1) % MAXSIZE == Q.front)
        cout << "队 满"<<endl;
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear + 1 % MAXSIZE);
}

//出队函数
int DnQueue(SqQueue& Q) {
    int e;
    if (Q.rear == Q.front)
        cout << "队 空"<<endl;
    e = Q.base[Q.front];
    Q.front = (Q.front + 1 % MAXSIZE);
    return e;
}

int main() {
    SqQueue Q;
    InitQueue(Q);
    EnQueue(Q, 0);  //入队0,1,0
    EnQueue(Q, 1);
    EnQueue(Q, 0);
    int a;
    cout << "请输入打印的行数：";
    cin >> a;
    for (int i = 0;i < a;i++)
        cout << " ";
    while (a) {
        int e = DnQueue(Q);
        e = e + Q.base[Q.front];
        cout << e << " ";
        EnQueue(Q, e);
        if (Q.base[Q.front] == 0) {
            cout << endl;
            EnQueue(Q, 0);
            a--;
            for (int i = 0;i < a;i++)
                cout << " ";
        }
    }    
    return 0;
}


