#include<iostream>
#include<vector>
using namespace std;
#define ll long long
//有更直接的数学结论可以用,但一般的方法也想学会啊...
//已经把之前自己写的全部推倒重来了,毕竟就自己写的那一坨,没多少参考价值.明明已经有了具体的思路了,也能人肉写出计算过程,但在程序化的时候总是写不出正确有条理的代码.是对语言不熟悉还是方法错了呢.
void generateSubsets(vector<int>& nums, int index, vector<int>& current, ll& total) {
    //主要的时间开销在生成子集和计算总和的过程中。
    if (index == nums.size()) {//直到最后一个之前不用管
        for (int num : current) {
            total += num;
        }
        return;
    }
    //每个层级包含两种状态
    current.push_back(nums[index]);
    generateSubsets(nums, index + 1, current, total);
    current.pop_back();
    generateSubsets(nums, index + 1, current, total);
}

void way1(vector<int>& numbers) {
    ll total = 0;
    vector<int> current;
    generateSubsets(numbers, 0, current, total);
    cout << total;
}
ll power(int i,int p){
    ll res=1;
    while(p){
        if (1&p%2){
            res*=i;
        }
        i*=i;
        p/=2;
    }
    return res;
}
void way2(vector<int>&nums){
   //根据选与不选,将子集用二进制数表示
   /*
   1->100
   12->110
   ...
   3->001
   目标为找出所有位数为len的二进制数,统计每一位上1的数量,将其与该位置的元素相乘即可
   事实上可以发现每个元素出现的次数都为2^(n-1) (对称规律).该说是凑巧,还是必然的呢,
   每个元素只有两种状态,用二进制数模拟似乎很自然.
   这也说明了数学方法的重要性
   */
    ll len=nums.size();
    ll sum=0;
    if (len==1){
        cout<<nums[0];
        return;
    }
    
    for (auto elem:nums){
        sum+=elem;
    }
    cout<<sum*power(2,len-1);//不用pow是我能做到的最后一件事了

}
int main() {
    int num;
    vector<int> numbers;
    while(scanf("%d ",&num)!=EOF){
        numbers.push_back(num);
    }
    way2(numbers);
    //result(numbers); // 输出24
    //cout<<power(3,4);
    return 0;
}
