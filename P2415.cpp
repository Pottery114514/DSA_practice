#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<sstream>
using namespace std;
#define ll long long
/*
对于{1,2,3}
1+(1+2)+(1+2+3)
 +(1+3)
2+(2+3)
3
*/
ll sub(int i,vector<int>& numbers,ll sum,int k){
    int len=numbers.size();
    int j=len;
    ll curr=0;
    if (k==len) return sum;
    while (j<len){
        curr+=numbers[j];
        sum+=curr;
        j++;
    }
    return sub(i,numbers,sum,k++);
}
void result(vector<int>& numbers){
    ll res, sum;
    for (int i=0;i<numbers.size();i++){
        res+=sub(i,numbers,sum,0);
    }
    cout<<res;
}
int main(){
    int num;
    ll ans=0;
    vector<int> numbers;
    while (scanf("%d ",&num)!=EOF){
        numbers.push_back(num);
    }
    result(numbers);
    return 0;
}
