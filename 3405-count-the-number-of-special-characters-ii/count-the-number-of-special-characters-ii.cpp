class Solution {
public:
    int numberOfSpecialChars(string word) {
        int cnt = 0;
        int n = word.size();
        unordered_map<char,int> mpp;
        for(int i = 0; i < n; i++){
            char c = word[i];
            if(c >= 'a' && c <= 'z'){
                mpp[word[i]] = i;
            }
            else if(mpp.find(c) == mpp.end()){
                mpp[word[i]] = i;
            }
        }

        for(auto& itt : mpp){
            char it = itt.first;
            if(it >= 'a' && it <= 'z'){
                if(mpp.find(toupper(it)) != mpp.end() && mpp[it] < mpp[toupper(it)]) cnt++;
            }
        }
        return cnt;
    }
};