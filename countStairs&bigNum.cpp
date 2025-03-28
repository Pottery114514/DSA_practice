#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;
#define ll long long

string addNum(string a,string b){//高精度算法
    /*
    运算时转为整型,结果再转换为字符串
    */
    int i=a.size()-1,j=b.size()-1;
    string res;
    stack<int> res_int;
    int numA,numB,up=0;;
    while (i>=0||j>=0||up>0){//对up>0的判断处理最高位进位的情况
        numA= (i>=0) ? a[i]-'0' : 0;//统一处理位数不同的情况
        numB= (j>=0) ? b[j]-'0' : 0;//还有这种写法?
        int curr=numA+numB+up;
        res_int.push(curr%10);
        curr/10>0?up=1:up=0;
        i--;
        j--;
    }
    while (!res_int.empty()){
        res.push_back(res_int.top()+'0');
        res_int.pop();
    }
    //cout<<res;
    return res;
}
void wayDp(int n){//动态规划+高精度
    if (n==1) cout<<'1';//写成'='真的很麻烦...排错找半天
    if (n==2) cout<<'2';
    string pre2={'1'},pre1={'2'};
    string curr;
    for (int i=3;i<=n;i++){
        curr=addNum(pre1,pre2);
        pre2=pre1;
        pre1=curr;
    }
    cout<<curr;
}
int main(){
    int n;
    cin>>n;
    wayDp(n);
    return 0;
}
