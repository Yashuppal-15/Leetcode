class Solution {
public:
    string decodeString(string s) {
        stack<string> st;

        //Iterate through each character
        for(auto ch:s){
            //When we see ], it means we’ve reached the end of an encoded block, so now we must decode it.
            if(ch == ']'){
                string stringToRepeat = "";

                //Pop characters/substrings until we find the opening bracket "[".
                while(!st.empty() && st.top() != "["){
                    string top = st.top();
                    stringToRepeat += top;
                    st.pop();
                }
                //Discard the "[".
                st.pop();

                //Collect all digits from the stack.
                string numericTimes = "";
                while(!st.empty() && isdigit(st.top()[0])){
                    numericTimes += st.top();
                    st.pop();
                }
                //Reverse the digits (since they were popped in reverse order).
                reverse(numericTimes.begin(), numericTimes.end());
                int n = stoi(numericTimes);                 //Convert to integer n (number of times to repeat).


                //Build the decoded substring
                string currentdecode = "";
                while(n--){
                    currentdecode += stringToRepeat;
                }
                //Push the result back on the stack.
                st.push(currentdecode);
            }

            //If the current char is not ], just push it as a string (either digit, letter, or "[").
            else{
                string temp(1,ch);
                st.push(temp);
            }
        }
        
        //Collect everything left in the stack into ans
        string ans;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        //Reverse it because stack gave us reversed order.
        reverse(ans.begin(),ans.end());
        return ans;                                        //Return the decoded string.
    }
};