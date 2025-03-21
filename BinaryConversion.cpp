//an example of how to 进制转换
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

void vectorVer(int n){
    vector<int> res;
    while (n>0){
        res.push_back(n%2);
        n>>=1;
    }
    for (int i=res.size()-1;i>=0;i--){
        cout<<res[i];
    }
}
void stackVer(int n){//最拟态
    stack<int> res;
    while (n>0){
        res.push(n%2);
        n>>=1;
    }
    while (!res.empty()){
        cout<<res.top();
        res.pop();
    }
    
}
int main(){
    int n;
    cin>>n;
    stackVer(n);
    return 0;
}
