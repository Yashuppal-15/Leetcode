class Solution {
public:
    int minAddToMakeValid(string s) {

        stack<char> st;
        int ans=0;                      //ans will count how many parentheses we need to add.

        for(auto ch:s){                 //Go through every character in the string.
            
            //If we see '(', we push it to stack (unmatched).
            //At the same time, we increase ans (because this '(' needs a matching ')').
            if(ch=='('){
                ++ans;
                st.push(ch);
            }
            
            //If we see ')':
            //If there’s an unmatched '(' in stack, pop it (they cancel out). 
                       //Also decrease ans (because that '(' got matched).
            //If there’s no '(' in stack, this ')' is extra → so we increment ans 
                       //(we’ll need an extra '(' later to balance it).
            else{
                if(!st.empty()){
                    st.pop();
                    --ans;
                }
                else
                ans++;
            }
        }
        return ans;                //At the end, ans is the minimum number of parentheses we must add.
    }
};