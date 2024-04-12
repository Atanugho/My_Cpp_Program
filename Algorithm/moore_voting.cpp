#include <iostream>
#include <vector>

using namespace std;

int findMajorityElement(vector<int>& nums) {
    int candidate = 0;
    int count = 0;

    for (int num : nums) {
        if (count == 0) {
            candidate = num;
            count = 1;
        } else if (num == candidate) {
            count++;
        } else {
            count--;
        }
    }

    // At this point, candidate holds a potential majority element.
    // Verify if it's the majority element.
    count = 0;
    for (int num : nums) {
        if (num == candidate) {
            count++;
        }
    }

    if (count > nums.size() / 2) {
        return candidate;
    } else {
        return -1; // No majority element found
    }
}

int main() {
    vector<int> nums = {3, 3, 4, 2, 4, 4, 2, 4, 4};
    int majorityElement = findMajorityElement(nums);
    if (majorityElement != -1) {
        cout << "Majority element: " << majorityElement << endl;
    } else {
        cout << "No majority element found" << endl;
    }
    return 0;
}
