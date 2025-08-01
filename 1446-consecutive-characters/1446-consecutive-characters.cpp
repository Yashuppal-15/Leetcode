class Solution {
public:
    int maxPower(string s) {
        int ans = 1, count = 1, n = s.length();

        for(int i = 1; i < n; i++){
            if(s[i] == s[i - 1]) 
                count++;
            else{
                ans = max(ans , count);
                count = 1;
            }
        }

        return max(ans , count);
    }
};