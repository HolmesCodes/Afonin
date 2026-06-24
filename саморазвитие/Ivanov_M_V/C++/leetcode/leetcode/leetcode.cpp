#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	vector<int> nums1 = { 1,3 };
	vector<int> nums2 = { 2 };
    int sum = 0;
    int count = 0;
    if (nums1.size() == nums2.size()) {
        for (int i = 0;i < nums1.size();i++) {
            sum += nums1[i];
            count++;
        }
        for (int i = 0;i < nums2.size();i++) {
            sum += nums2[i];
            count++;
        }
        return (double)sum / count;
    }
    else {
        vector<int> nums3;
        for (auto i : nums1) {
            nums3.push_back(i);
        }
        for (auto i : nums2) {
            nums3.push_back(i);
        }
        sort(begin(nums3), end(nums3));
        int index = 0;
        index += nums3.size() / 2 + 1;
        return nums3[index];
    }
    
    
    
}