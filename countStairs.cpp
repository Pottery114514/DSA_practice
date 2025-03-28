#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 大数加法（字符串形式）
string addBigNumbers(const string &a, const string &b) {
    string res;
    int carry = 0;
    int i = a.size() - 1, j = b.size() - 1;
    
    while (i >= 0 || j >= 0 || carry) {
        int numA = (i >= 0) ? (a[i--] - '0') : 0;
        int numB = (j >= 0) ? (b[j--] - '0') : 0;
        int sum = numA + numB + carry;
        carry = sum / 10;
        res.push_back(sum % 10 + '0');
    }
    
    reverse(res.begin(), res.end());
    return res;
}
//矩阵快速幂
