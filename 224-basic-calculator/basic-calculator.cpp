class Solution {
public:
    int bracketCal(string s,int &i){
        int ans=0;
        int n=s.size();
        int f=1;
        while(s[i]!=')'){
            if(s[i]==' ') i++;
            if(s[i]>='0' and s[i]<='9'){
                string temp="";
                while(i<n and s[i]>='0' and s[i]<='9'){
                    if(s[i]==' ') i++;
                    temp+=s[i];
                    i++;
                }
                ans+=stoi(temp)*f;
            }else if(s[i]=='+'){
                f=1;
                i++;
            }else if(s[i]=='-'){
                f=-1;
                i++;
            }else if(s[i]=='('){
                i++;
                ans+=bracketCal(s,i)*f;
                i++;
            }
        }
        return ans;
    }
    int calculate(string s) {
        int n=s.size();
        int ans=0;
        int i=0;
        int f=1;
        while(i<n){
            if(s[i]==' ') i++;
            if(s[i]>='0' and s[i]<='9'){
                string temp="";
                while(i<n and s[i]>='0' and s[i]<='9'){
                    if(s[i]==' ') i++;
                    temp+=s[i];
                    i++;
                }
                ans+=stoi(temp)*f;
            }else if(s[i]=='+'){
                f=1;
                i++;
            }else if(s[i]=='-'){
                f=-1;
                i++;
            }else if(s[i]=='('){
                i++;
                ans+=bracketCal(s,i)*f;
                i++;
            }
        }
        return ans;
    }
};