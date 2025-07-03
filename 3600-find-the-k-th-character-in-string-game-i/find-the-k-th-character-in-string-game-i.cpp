class Solution {
public:
    char kthCharacter(int k) {
        long cnt = 0;
        int curr = k;
        while(curr > 1){
            long i = 1;
            while(i*2<curr) {
                i*=2;
            }
            curr-=i;;
            cnt++;
        }
        return 'a'+cnt%26;
    }
};