#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<sstream>
using namespace std;
#define ll long long
/*#include<iostream>
#include<vector>
using namespace std;
#define ll long long

void generateSubsets(vector<int>& nums, int index, vector<int>& current, ll& total) {
    if (index == nums.size()) {
        for (int num : current) {
            total += num;
        }
        return;
    }
    
    // 包含当前元素
    current.push_back(nums[index]);
    generateSubsets(nums, index + 1, current, total);
    current.pop_back();
    
    // 不包含当前元素
    generateSubsets(nums, index + 1, current, total);
}

void result(vector<int>& numbers) {
    ll total = 0;
    vector<int> current;
    generateSubsets(numbers, 0, current, total);
    cout << total;
}

int main() {
    vector<int> numbers;
    for (int i = 1; i < 4; i++) {
        numbers.push_back(i);
    }
    result(numbers); // 输出24
    return 0;
}
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
