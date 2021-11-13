#include<iostream>
using namespace std;
//���������BiTree
typedef struct BiTNode{
    BiTNode* Lchild;
    BiTNode* Rchild;
    char data;
}*BiTree,BiTNode;
//������˳�򴴽�������
void CreateBiTree(BiTree &T) {
    char ch;
    cin >> ch;
    if (ch == '#')
        T = NULL;
    else {
        T = new BiTNode;
        T->data = ch;
        CreateBiTree(T->Lchild);
        CreateBiTree(T->Rchild);
    }
}
//����˳�����������
void InOrderTraverse(BiTree T) {
    if (T) {
        InOrderTraverse(T->Lchild);
        cout << T->data;
        InOrderTraverse(T->Rchild);
    }
}
//�����������
int Depth(BiTree T) {
    if (T == NULL)
        return 0;
    else {
        int m = Depth(T->Lchild);
        int n = Depth(T->Rchild);
        if (m > n)
            return (m + 1);
        else
            return (n + 1);
    }
}
//�������Ľڵ����
int NodeCount(BiTree T) {
    if (T == NULL)
        return 0;
    else
        return NodeCount(T->Lchild) + NodeCount(T->Rchild) + 1;
}
int main() {
    BiTree T;
    cout << "��������˳��"<<endl;
    CreateBiTree(T);
    cout << "����������������Ϊ��"<<endl;
    InOrderTraverse(T);
    cout << endl;
    cout << "�����������Ϊ��"<<Depth(T)<<endl;
    cout << "�������Ľڵ����Ϊ��"<<NodeCount(T)<<endl;
    
}