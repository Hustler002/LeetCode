class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int cnt = 0;

        for(auto& st : patterns){
            if(word.find(st) != string::npos) cnt++;
        }
        return cnt;
    }
};