// class Solution {
// public:
//     bool checkStrings(string s1, string s2) {
//         int n = s1.size();
//         unordered_map<char,int> odd1, even1;

//         for(int i = 0; i < n; i++){
//             if(i%2==0)
//                 even1[s1[i]]++;
//             else 
//                 odd1[s1[i]]++;
//         }
            

//         unordered_map<char,int> odd2, even2;

//         for(int i = 0; i < n; i++){
//             if(i%2==0)
//                 even2[s2[i]]++;
//             else 
//                 odd2[s2[i]]++;
//         }
//         return (odd1==odd2 && even1 == even2);
//     }
// };


// Approach 2

class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.size();
        
        int even[26] = {0};
        int odd[26] = {0};

        for(int i = 0; i < n; i++){
            if(i % 2 == 0){
                even[s1[i] - 'a']++;
                even[s2[i] - 'a']--;
            }
            else{
                odd[s1[i] - 'a']++;
                odd[s2[i] - 'a']--;
            }
        }

        for(int i = 0; i < 26; i++){
            if(even[i] != 0 || odd[i] != 0) return false;
        }
        return true;
    }
};