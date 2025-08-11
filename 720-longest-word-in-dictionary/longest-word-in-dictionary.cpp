struct Trienode{
    Trienode *children[26];
    bool endofword = false;
};
class Trie{
private: Trienode *root;
public:
    Trie(){
        root = new Trienode();
    }
    void insert(string word){
        Trienode *current = root;
        for(int i=0;i<word.size();i++){
            int index = word[i] - 'a';
            if(current->children[index]==NULL){
                current->children[index] = new Trienode();
            }
            current = current->children[index];
        }
        current->endofword = true;
    }

    bool allPrefixExists(string word){
        Trienode *current = root;
        for(int i=0;i<word.size();i++){
            int index = word[i] - 'a';
            if(current->children[index]!=NULL){
                current = current->children[index];
                if(current->endofword==false) return false;
            }
            else return false;
        }
        return true;
    }
};
class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie t;
        for(auto &ch: words){
            t.insert(ch);
        }
        string longest_word = "";

        for(auto &ch: words){
            if(t.allPrefixExists(ch)){
                if(ch.size()>longest_word.size()){
                    longest_word = ch;
                }
                else if(ch.size()==longest_word.size() && ch<longest_word){
                    longest_word = ch;
                }
            }
        }
        return longest_word == "" ? "" : longest_word; 
    }
};