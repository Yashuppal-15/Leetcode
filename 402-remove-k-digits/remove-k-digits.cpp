class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        string ans;
        int fixedLen; // ans.size() should never be less than fixedLen
        for(int i = 0; i < n; ++i)
        {
            fixedLen = i-k < 0? 0 : i-k;
            while(ans.size() > fixedLen && ans.back() > num[i])
            {
                ans.pop_back();
            }
            ans.push_back(num[i]);
        }

        //trim extra added to end
        while(ans.size() > n-k) ans.pop_back();

        //trim leading zeros
        int start = 0;
        while(start < ans.size() && ans[start] == '0') ++start;
        ans.erase(ans.begin(), ans.begin()+start);


        return ans.size() == 0? "0" : ans;
    }
};