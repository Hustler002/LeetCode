class Robot {
public:
    string dir="";
    int x,y;
    int mx, my;
    Robot(int width, int height) {
        dir = "East";
        x =0,y=0;
        mx = width - 1;
        my = height - 1;
    }
    
    void step(int num) {
        int perimeter = 2 * (mx + my);
        num %= perimeter;
        
        // ADDED: Edge case. If the robot completes a full loop and arrives 
        // back at the origin, it will be facing South, not East.
        if (num == 0 && x == 0 && y == 0) {
            dir = "South";
            return;
        }
        while(num--){
            if(dir == "North"){
                y++;
                if(y > my) {
                    dir = "West";
                    y--;
                    x--;
                }
            }
            else if(dir == "South"){
                y--;
                if(y < 0) {
                    dir = "East";
                    y++;
                    x++;
                }
            }
            else if(dir == "East"){
                x++;
                if(x > mx) {
                    dir = "North";
                    y++;
                    x--;
                }
            }
            else if(dir == "West"){
                x--;
                if(x < 0) {
                    dir = "South";
                    y--;
                    x++;
                }
            }
        }
    }
    
    vector<int> getPos() {
        return {x,y};
    }
    
    string getDir() {
        return dir;
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */