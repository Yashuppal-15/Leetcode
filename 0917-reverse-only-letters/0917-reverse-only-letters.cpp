class Solution {
public:
    bool isal(char ch){
        if(ch<='z' && ch>='a' || ch<='Z' && ch>='A')
        return 1;
        return 0;
    }
    string reverseOnlyLetters(string s) {
        int i = 0, j = s.size()-1;
        while(i<j){
            if(isal(s[i]) && isal(s[j]))
            swap(s[i++],s[j--]);
            
            if(!isal(s[i]))
            i++;
            if(!isal(s[j]))
            j--;
        }
        return s;
    }
};