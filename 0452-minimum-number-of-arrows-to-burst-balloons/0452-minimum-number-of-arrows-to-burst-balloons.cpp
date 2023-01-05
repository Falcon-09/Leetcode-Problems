class Solution {
public:

    static bool cmp(vector<int> &a,vector<int> &b){
        if(a[1]<b[1]) return true;
        else if(a[1]==b[1]) return a[0]<b[0];
        return false;
    }

    int findMinArrowShots(vector<vector<int>>& p) {
        int n = p.size();

        sort(p.begin(),p.end(),cmp);

        int arrows = 1,j = p[0][1];

        for(int i=1;i<n;i++){
            int s = p[i][0];
            int e = p[i][1];

            if(j>=s) continue;

            j = e;

            arrows++;
        }

        return arrows;
    }
};