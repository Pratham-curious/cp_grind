class Robot {
private : 
 int width = 0,height = 0;
 int idx = 0,path = 0;
 vector<int> cord;
 vector<string> dir = {"North","West","South","East"};
public:
    Robot(int width, int height) {
        this->width = width;
        this->height = height;
        this->idx = 3;
        this->path = 2*(height+width-2);
        cord = {0,0};
        // north = 0,west = 1,south = 2,east = 3;
    }
    
    void step(int num) {
        int x = cord[0],y = cord[1];
        num%=path;
        if(num == 0){
            if((x == 0 && y ==0) || (x == width-1 && y == 0)){
                if(x == 0 && idx == 3) idx = 2;
                if(x == width-1 && idx == 0) idx = 3;
            }
            else if((x == 0 && y ==height-1) || (x == width-1 && y == height-1)){
                if(x == 0 && idx == 2) idx = idx = 1;
                if(x == width-1 && idx == 1) idx = 0;
            }
        }

        for(int i=0;i<num;i++){
            int mul = 1;
            if(idx == 1 || idx == 2) mul = -1;
            if(idx == 0 || idx == 2){
                if(y + mul >= height || y + mul < 0){
                    idx = (idx+1)%4;
                    i--;
                }
                else y+=mul;
            }
            else{
                if(x + mul >= width || x + mul < 0){
                    idx = (idx+1)%4;
                    i--;
                }
                else x+=mul;
            }
        }
       // cout<<x<<" "<<y<<endl;
        cord = {x,y};
    }
    
    vector<int> getPos() {
        return cord;
    }
    
    string getDir() {
        return dir[idx];
        
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */