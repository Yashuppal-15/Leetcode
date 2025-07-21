class Solution {
public:
    char findTheDifference(string s, string t) {
        int m=s.size();
        int n=t.size();
        if(m<n){
            for(int i=0;i<n;i++){
                char c=t[i];
                size_t x=s.find(c);
//size_t unsigned integer type h int small string ki liya use ho ye bohot large string ki liya use ho .size_t ki jgh int likh skte h lekin overflow hoajayega
                if(x!=string::npos)
//string::npos its like bool (t or f) 
//exactly like bool found=fase; if (found == true)
//acts like: if (found == true)
//It works like a boolean condition:
//True if character is found
//False if character is not found
                s.erase(x,1);
                else return c;// If not found, this is the extra character in t
            }

        }
        return ' ';
}
};