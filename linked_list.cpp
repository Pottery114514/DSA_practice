//an example of how to make an list
#include<iostream>
using namespace std;
//定义别名方便后期修改
typedef int Status;
typedef int ElemType; 

class List{
    struct Node{
        ElemType data;
        Node* next;
    };
    Node* head;//
    public:
        List(){

        }
        void createBySize(){//init list with length n

        }
        void createByCheck(){//store value untill get -1

        }
        ElemType findMin(){}
        void deleteElem(){}
};
