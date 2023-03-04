class Solution {
public:
    double findMedianSortedArrays(vector<int>& v1, vector<int>& v2) {
        
        
    std::vector<int> dst;
    std::merge(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(dst));
        
    int n = dst.size();
        
    return n%2? dst[n/2] : (dst[n/2-1]+dst[n/2])/2.0;
    }
};