class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    int n = nums.size();
    int count =0;
    vector<int>result;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if( i!=j && nums[i]>nums[j]){
                count++;
            }    
           
        }
       result.push_back(count);
       count = 0;
    }
    return result;
    }
};