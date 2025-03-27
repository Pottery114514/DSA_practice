#include<iostream>
#include<vector>
using namespace std;
#define ll long long
//有更直接的数学结论可以用,但一般的方法也想学会啊...
//已经把之前自己写的全部推倒重来了,毕竟就自己写的那一坨,没多少参考价值.明明已经有了具体的思路了,也能人肉写出计算过程,但在程序化的时候总是写不出正确有条理的代码.是对语言不熟悉还是方法错了呢.
void generateSubsets(vector<int>& nums, int index, vector<int>& current, ll& total) {
    if (index == nums.size()) {
        for (int num : current) {
            total += num;
        }
        return;
    }
    ////好像有点懂了,像树一样延申下去
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
