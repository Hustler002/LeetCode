class Solution {
public:

bool checkz(int n ){
    
    while(n>0){
        int x = n%10;
        n = n/10;
        if(x==0) return false;
    }

    return true;
}
    vector<int> getNoZeroIntegers(int n) {
        
       int x =1;
       int y = n-1;
 while(x<=y){
    if(checkz(x) && checkz(y)){
   return {x,y};
  
    }
     x++;
   y--;
 }
 return {1,1};
    }
};