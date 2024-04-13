class Solution {
public:
vector<int> getleftmax(vector<int>& height, int& n){
    vector<int> leftmax(n);
    leftmax[0] = height[0];
    for(int i=1; i<n; i++){
        leftmax[i] = max(leftmax[i-1], height[i]);
    }
    return leftmax;
}
vector<int> getrightmax(vector<int>& height, int& n){
    vector<int> rmax(n);
    rmax[n-1] = height[n-1];
    for(int i=n-2; i>=0; i--){
        rmax[i] = max(rmax[i+1], height[i]);
    }
    return rmax;
}

    int trap(vector<int>& height) {
        int n= height.size();
         vector<int> getleft = getleftmax(height, n);
         vector<int> getright = getrightmax(height, n);

         int sum = 0;
         for(int i=0; i<n; i++){
            int h = min(getleft[i], getright[i])- height[i];
            sum += h;
         }
        return sum;
    }
};