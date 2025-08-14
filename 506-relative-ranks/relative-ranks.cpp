class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        unordered_map<int,int> m;
        vector<int> res=score;
        sort(res.begin(),res.end(),greater<int>());
        for(int j=0;j<res.size();j++)
        {
            m[res[j]]=j+1;
        }
        vector<string> s;
        for(int i=0;i<score.size();i++)
        {
            if(m[score[i]] == 1)
            {
                s.push_back("Gold Medal");
            }
            else if(m[score[i]] == 2)
            {
                s.push_back("Silver Medal");
            }
            else if(m[score[i]] == 3)
            {
                s.push_back("Bronze Medal");
            }
            else
            {
                s.push_back(to_string(m[score[i]]));
            }
        }
        return s;
    }
};