class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int n = s.size();
        for(int i = 0 ; i < s.size() ; i++){
            string temp;
            while(s[i]==' ' && i < n){
                i++;
            }
            while(s[i] != ' ' && i < n){
                temp += s[i];
                i++;
            }
            if(temp.size()>0){
                if(ans.empty()) ans = temp;
                else ans = temp + " " + ans;
            }
        }
        return ans;    
    }
};