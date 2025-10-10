class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //step 1: //ans[i] = number of days you need to wait after day i for a warmer temperature.
        //Initialize all to 0 (default if no warmer day exists).
        vector<int> ans(temperatures.size(), 0);
        stack<int> st;               //stores indexes of unresolved days (waiting for a warmer temperature).
        
        //Step 2: Traverse each temperature
        for(int i=0; i < temperatures.size(); ++i){
            //Step 3: While current temp is warmer than the last stored day
            while(!st.empty() && temperatures[i] > temperatures[st.top()]){
                //Step 4: Compute the waiting days
                ans[st.top()] = i-st.top();
                //Step 5: Remove that day because it now has an answer.
                st.pop();
            }
            //Step 6: Push the current day’s index
            st.push(i);
        }
        return ans;
    }
};