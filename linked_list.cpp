#include<stdlib.h>
#include<iostream>
using namespace std;


#define OK 1

#define ERROR 0

#define OVERFLOW -2

typedef int Status;
typedef int ElemType; 
typedef struct LNode

{
ElemType data;//结点的数据域
struct LNode *next;//结点的指针域
}LNode,*LinkList;//LinkList为指向结构体LNode的指针类型

void createL(LinkList &L,int n){
    L=new LNode;
    L->next=NULL;
    for (int i=0;i<n;i++){
        LinkList p=new LNode;
        cin>>p->data;
        p->next=L->next;L->next=p;
    }
}
void printMin(LinkList &L,int n){

    LinkList p = L->next;
    ElemType minVal = p->data;
    while (p != NULL) {
        if (p->data < minVal) {
            minVal = p->data;
        }
        p = p->next;
    }
    cout<<minVal<<'\n';
}
void freeList(LinkList &L) {
    LinkList p = L;
    while (p != NULL) {
        LinkList temp = p;
        p = p->next;
        delete temp;
    }
}
int main(){
    int n;
    LinkList L;
    cin>>n;
    createL(L,n);
    printMin(L,n);
    freeList(L);
    return 0;
}