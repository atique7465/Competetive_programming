class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        for(int i = 0; i < nums1.size(); i++){
            for(int j = 0; j < nums2.size(); j++){
                if(nums1[i] == nums2[j]) return nums1[i];
            }
        }
        int v1 = nums1[0], v2 = nums2[0];
        if(v1 < v2) return v1 * 10 + v2;
        else return v2 * 10 + v1;
    }
};