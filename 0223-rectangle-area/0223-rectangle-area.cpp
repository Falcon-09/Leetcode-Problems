class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        long long A1 = (ax2-ax1)*(ay2-ay1);
        long long A2 = (bx2-bx1)*(by2-by1);
        long long A3 = max(0,min(ax2,bx2)-max(ax1,bx1))*max(0,min(ay2,by2)-max(ay1,by1));
        
        return A1+A2-A3;
    }
};