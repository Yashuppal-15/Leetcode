class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;
        for(int i=0; i<s.length();i++){
            char brackets = s[i];

            //If it’s an opening bracket → push it onto the stack.
            if(brackets == '(' || brackets == '{' || brackets =='['){
                st.push(brackets);
            }
            //If it’s a closing bracket -> If stack is not empty → check top of stack:
            else{                          //If it matches → pop it.
                if(!st.empty()){
                    if(brackets == ')' && st.top() == '('){
                        st.pop();
                    }
                    else if(brackets == '}' && st.top() == '{'){
                        st.pop();
                    }
                    else if(brackets == ']' && st.top() == '['){
                        st.pop();
                    }
                    //If it doesn’t match → return false immediately.
                    else{
                        return false;
                    }
                }
                //If it’s a closing bracket: If stack is empty → invalid (no opening bracket to match).
                else{
                    return false;
                }
            }
        }
        //If stack still has something → invalid (some opening brackets never got closed).
        if(!st.empty()){
            return false;
        }
        //If stack is empty → valid string.
        else{
            return true;
        }        
    }
};