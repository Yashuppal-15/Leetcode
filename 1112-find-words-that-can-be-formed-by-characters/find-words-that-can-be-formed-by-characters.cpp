class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        map<char,int> freq;
        for(auto&i:chars){
            freq[i]++;
        }
        int sum=0;
        for(auto&i:words){
            auto k=freq;
            bool valid=true;
            for(int j=0;j<i.size();j++){
                if(k.find(i[j])!=k.end() && k[i[j]]>0){
                    k[i[j]]--;
                }else{
                    valid=false;
                    break;
                }
            }
            if(valid){
                sum=sum+i.size();
            }
        }
        return sum;
        
    }
};