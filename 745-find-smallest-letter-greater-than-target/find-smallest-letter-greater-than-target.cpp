class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char mini = 'z';
        bool check = false;
        for(auto& it : letters){
            if(it > target){
                mini = min(mini, it);
                check = true;
            }
        }
        if(check == false){
            mini = letters[0];
        }
        return mini;
    }
};