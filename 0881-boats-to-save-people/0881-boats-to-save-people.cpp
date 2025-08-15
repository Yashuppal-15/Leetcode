class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n=people.size();
        int l=0;
        int h=n-1;
        sort(people.begin(),people.end());
        int count=0;
        int mini=INT_MAX;
        for(int i=0; i<n; i++){
            mini=min(mini,people[i]);
        }
        if(mini>=limit){
              return n;
        }
        while(l<=h){
            int m=people[l]+people[h];
            if(l==h)m=people[l];
            if(m>limit){
              count++;
              h--;
            }else {
                h--;
                l++;
                count++;
            }
           
        }
        return count;
    }
};