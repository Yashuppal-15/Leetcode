class Solution {
public:
    int longestValidParentheses(string s) {

        //Stack will store indices (not characters).
        stack<int> st;
        //We push -1 initially as a base index to help compute lengths correctly.
        //Example: If the string starts with a valid substring "()" at indices [0,1], 
        //then 1 - (-1) = 2 (correct length).
        st.push(-1);
        int maxLen = 0;

        //Iterate through each character with its index i.
        for(int i=0; i<s.length(); i++){
            char ch = s[i];
            //If current char is '(', push its index onto the stack.
            if(ch == '('){
                st.push(i);
            }
            else{
                //If ')', we try to match it with the last '(' index in the stack → so we pop.
                st.pop();

                //If stack is empty after popping, push the current index of ')'.
                //Why? Because this marks the new base index for future valid substrings.
                //Example: In string ")()", when the first ')' is at index 0 → push 0 
                //so the next valid substring can start after it.
                if(st.empty()){
                    st.push(i);
                }
                else{
                    //If stack is not empty:
                    //The top element of stack is the index before the valid substring.
                    int len = i-st.top();
                    maxLen = max(len,maxLen);
                }
            }
        }
        return maxLen;
    }
};