class Solution {
public:
    int findFinalValue(vector<int>& nums, int original)
    {
        //time complexity: O(n*logM)
        //space complexity: O(1)

        int i;
        //variable to track the availability of 'original' value
        bool found=true;

        //keep checking until the 'original' value is found
        while(found)
        {
            //set 'found' to 'false'
            found=false;
            for(i=0;i<nums.size();i++)
            {
                //if 'original' is found in given array
                if(nums[i]==original)
                {
                    //double 'original' value
                    original=original*2;
                    //set 'found' value to 'true'
                    found=true;
                    //break the loop to avoid further checking in the array
                    break;
                }
            }
        }
        //returning 'original' value
        return original; 
    }
};