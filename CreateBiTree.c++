#include<iostream>
using namespace std;
//定义二叉树BiTree
typedef struct BiTNode{
    BiTNode* Lchild;
    BiTNode* Rchild;
    char data;
}*BiTree,BiTNode;
//以先序顺序创建二叉树
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
//中序顺序遍历二叉树
void InOrderTraverse(BiTree T) {
    if (T) {
        InOrderTraverse(T->Lchild);
        cout << T->data;
        InOrderTraverse(T->Rchild);
    }
}
//二叉树的深度
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
//二叉树的节点个数
int NodeCount(BiTree T) {
    if (T == NULL)
        return 0;
    else
        return NodeCount(T->Lchild) + NodeCount(T->Rchild) + 1;
}
int main() {
    BiTree T;
    cout << "输入先序顺序："<<endl;
    CreateBiTree(T);
    cout << "二叉树的中序序列为："<<endl;
    InOrderTraverse(T);
    cout << endl;
    cout << "二叉树的深度为："<<Depth(T)<<endl;
    cout << "二叉树的节点个数为："<<NodeCount(T)<<endl;
    
}