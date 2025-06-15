class Solution {
public:
    int minDistance(string word1, string word2) {
         vector<int>prev(word2.size()+1,0);
         vector<int>curr(word2.size()+1,0);

         int n=word2.size();
         for(int i=0; i<=n; i++){
             prev[i]=n-i;
         }

         for(int i=word1.size()-1; i>=0; i--){
            curr[n]=word1.size()-i;
            for(int j=n-1; j>=0; j--){
                if(word1[i]==word2[j]){
                    curr[j]=prev[j+1];
                }else{
                    curr[j]=1+min(prev[j],min(prev[j+1],curr[j+1]));
                }
            }
            prev=curr;
         }

         return prev[0];
    }
};