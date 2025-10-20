class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        for(auto& str: operations){
            if(str[0] == 'X'){
                if(str[1] == '+') x++;
                else x--;
            }
            else if(str[0] == '+') x++;
            else x--;
        }
        return x;
    }
};