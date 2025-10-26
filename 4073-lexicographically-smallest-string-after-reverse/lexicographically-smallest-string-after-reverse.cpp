class Solution {
public:
    string lexSmallest(string s) {
        char mini = 'z';
        char maxi = 'a';
        int indmini = -1;
        int indmaxi = -1;
        for(int i = 0; i < s.size(); i++){
            if(s[i] <= mini){
                mini = s[i];
                indmini = i;
            }
            if(s[i] > maxi){
                maxi = s[i];
                indmaxi = i;
            }
        }
        
        //cout<<indmini<<" "<<indmaxi<<endl;
        string ans = s;
        //reverse(str.begin(), str.begin()+indmini+1);
        string str2,str;
        //reverse(str2.begin()+indmaxi, str2.end());
        //cout<<str<<" "<<str2;
        for(int i = 1; i <= s.size(); i++){
            str = s;
            reverse(str.begin(), str.begin()+i);
            if(str < ans) ans = str;
            str2 =s ;
            reverse(str2.end()-i, str2.end());
            if(str2<ans) ans = str2;
        }
        return ans;
    }
};