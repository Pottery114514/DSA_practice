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

void createLbySize(LinkList &L,int n){
    L=new LNode;
    L->next=NULL;
    for (int i=0;i<n;i++){
        LinkList p=new LNode;
        cin>>p->data;
        p->next=L->next;L->next=p;
    }
}
void createL(LinkList& L){
    L = new LNode;
    L->next = NULL;
    LinkList tail = L; // Pointer to the last node in the list
    ElemType value;

    while (true) {
        cin >> value;
        if (value == -1) {
            break; // Stop reading when -1 is entered
        }
        LinkList p = new LNode;
        p->data = value;
        p->next = NULL;
        tail->next = p; // Append the new node to the end
        tail = p; // Update the tail pointer
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
void deleteMax(LinkList& L){
    if (L->next == NULL) {
        return;
    }

    LinkList prevMax = NULL; // Previous node of the maximum node
    LinkList maxNode = L->next; // Node with the maximum value
    LinkList prev = L; // Previous node during traversal
    LinkList current = L->next; // Current node during traversal

    // Traverse the list to find the maximum node
    while (current != NULL) {
        if (current->data > maxNode->data) {
            maxNode = current;
            prevMax = prev;
        }
        prev = current;
        current = current->next;
    }

    // Delete the maximum node
    if (prevMax != NULL) {
        prevMax->next = maxNode->next; // Bypass the maximum node
        delete maxNode; // Free the memory of the maximum node
    } else {
        // If the maximum node is the first node
        L->next = maxNode->next;
        delete maxNode;
    }
}
void printL_rever(LinkList& L){

    if (L->next == NULL) {
        return; // Base case: end of list
    }
    printL_rever(L->next); // Recursively print the rest of the list
    cout << L->next->data << " "; // Print the current node's data
}
void printL(LinkList& L){
    LinkList p = L->next;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
int main(){
    //int n;
    LinkList L;
    
    //cin>>n;
    createL(L);
    //printL(L);
    //printMin(L,n);
    //deleteMax(L);
    printL_rever(L);
    freeList(L);
    return 0;
}
