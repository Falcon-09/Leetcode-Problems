class Solution {
public:
    
    double calculateSlope(vector<int>pt1, vector<int> pt2){
        return ((double)(pt2[1]-pt1[1]))/((double)(pt2[0]-pt1[0]));
    }
    
    int maxPoints(vector<vector<int>>& points) {
        int max_points = 1;
        for(int i=0;i<points.size()-1;i++){
            unordered_map<double,int> hash;
            int local_max = INT_MIN;
            for(int j=i+1;j<points.size();j++){
                if(points[i][0]==points[j][0]){
                    hash[INT_MAX]==0 ? hash[INT_MAX]=2 : hash[INT_MAX]++;
                }else{
                    double slope = calculateSlope(points[i],points[j]);
                    
                    hash[slope]==0 ? hash[slope]=2 : hash[slope]++;
                }
            }
            
            for(auto it:hash){
                local_max = max(local_max, it.second);
            }
            max_points = max(max_points, local_max);
        }
        
        return max_points;
    }
};