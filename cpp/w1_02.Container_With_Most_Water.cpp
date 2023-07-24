#include <iostream>
#include <vector>
using namespace std;

/*
Question link: https://leetcode.com/problems/container-with-most-water/description/

You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int left = 0;
        int right = height.size() - 1;

        while (left < right){
            int minHeight = (height[left] < height[right]) ? height[left] : height[right];
            int currArea = (right - left) * minHeight;
            maxArea = (currArea > maxArea) ? currArea : maxArea;

            if (height[left] < height[right])   left++;
            else    right--;
        }
        return maxArea;
    }
};

int main()
{
    Solution s;
    vector<int> height {1,8,6,2,5,4,8,3,7};
    int answer = s.maxArea(height);
    std::cout << "The answer is : " << answer << std::endl;
    return 0;   
};
