class Solution {
private:
    vector<int> choose = {0,1,6,8,9};

    // int dp[30][30][2];

    int dfs(vector<int>& digit, int pos, bool lead, bool limit, vector<int> & have) {
        if(pos == -1) {
            if(have.size() == 0) return 0;
            if( (int)have.size() % 2 == 1 && ( have[(int)have.size() / 2] == 6 || have[(int)have.size() / 2] == 9) ) return 1;
            bool suc = true;
            for(int i = 0, len = have.size(); i < len / 2; ++i) {
                if( (have[i] == 6 && have[len - 1 - i] != 9) || (have[i] == 9 && have[len - 1 - i] != 6) ) {
                    return 1;
                }
                if(have[i] != 6 && have[i] != 9 && have[i] != have[len - 1- i]) {
                    return 1;
                }
            }
            return 0;
        }

        int up= limit? digit[pos] : 9;

        int ans = 0;
        // for(auto i : choose) {
        for(int i = 0; i <= up; ++i) {
            // if(i > up) break;
            if(i == 0 || i == 1 || i == 6 || i == 8 || i == 9) {
                bool newLead = lead && i==0;
                if(newLead == false) {
                    have.push_back(i);
                }
                ans += dfs(digit, pos-1, newLead, limit && i==digit[pos], have);
                if(newLead == false) {
                    have.pop_back();
                }
            }
        }
        return ans;
    }

public:
    int confusingNumberII(int N) {
        // memset(dp, -1, sizeof(dp));

        vector<int> digit;
        int x = N;
        while(x) {
            digit.push_back(x % 10);
            x /= 10;
        }
        vector<int> have;

        return dfs(digit, digit.size() - 1, true, true, have);
    }
};

/*
本题我们会将数字旋转 180° 来生成一个新的数字。

比如 0、1、6、8、9 旋转 180° 以后，我们得到的新数字分别为 0、1、9、8、6。

2、3、4、5、7 旋转 180° 后，是 无法 得到任何数字的。

易混淆数（Confusing Number）指的是一个数字在整体旋转 180° 以后，能够得到一个和原来 不同 的数，且新数字的每一位都应该是有效的。（请注意，旋转后得到的新数字可能大于原数字）

给出正整数 N，请你返回 1 到 N 之间易混淆数字的数量。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/confusing-number-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

