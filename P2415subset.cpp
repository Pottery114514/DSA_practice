#include<iostream>
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
