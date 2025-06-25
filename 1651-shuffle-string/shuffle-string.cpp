class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int n=indices.size();
        string rs=s;
        for(int i=0;i<n;i++){
            rs[indices[i]]=s[i];
        }
        return rs;
    }
};