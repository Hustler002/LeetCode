class Solution {
public:
    string sortVowels(string s) {
        string vow = "";
        for(auto& ch : s){
            if(ch=='A' || ch=='E' ||ch=='I' ||ch=='O' ||ch=='U' ||ch=='a' ||ch=='e' ||ch=='i' ||ch=='o' ||ch=='u'){
                vow.push_back(ch);
            }
        }
        sort(vow.begin(),vow.end());
        int j = 0;
        for(int i = 0; i < s.size(); i++){
            char ch = s[i];
            if(ch=='A' || ch=='E' ||ch=='I' ||ch=='O' ||ch=='U' ||ch=='a' ||ch=='e' ||ch=='i' ||ch=='o' ||ch=='u'){
                s[i] = vow[j];
                j++;
            }
        }
        return s;
    }
};