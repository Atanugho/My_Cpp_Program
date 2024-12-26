#include <iostream>
#include <vector>
using namespace std;

// Build the Segment Tree
void buildTree(int i, int l, int r, vector<int>& segtree, vector<int>& nums) {
    if (l == r) {
        segtree[i] = nums[l];
        return;
    }

    int mid = (l + r) / 2;

    buildTree(2 * i + 1, l, mid, segtree, nums);
    buildTree(2 * i + 2, mid + 1, r, segtree, nums);

    segtree[i] = segtree[2 * i + 1] + segtree[2 * i + 2];
}

// Query the sum in the range [start, end]
int querySum(int start, int end, int i, int l, int r, vector<int>& segtree) {
    if (end < l || start > r) {
        return 0; 
    }

    if (start <= l && r <= end) {
        return segtree[i]; 
    }

    // Partial overlap
    int mid = l + (r - l) / 2;
    int leftSum = querySum(start, end, 2 * i + 1, l, mid, segtree);
    int rightSum = querySum(start, end, 2 * i + 2, mid + 1, r, segtree);

    return leftSum + rightSum;
}

int main() {
    cout << "Enter the size of the array: ";
    int n;
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> segtree(4 * n);

    cout << "Enter the number of queries: ";
    int q;
    cin >> q;
    vector<pair<int, int>> queries(q);

    cout << "Enter the queries (start and end indices): " << endl;
    for (int i = 0; i < q; i++) {
        cin >> queries[i].first >> queries[i].second;
    }

    buildTree(0, 0, n - 1, segtree, nums);

    vector<int> result;

    for (int i = 0; i < q; i++) {
        int start = queries[i].first - 1; // as index is 1 based 
        int end = queries[i].second - 1; // as index is 1 based

        result.push_back(querySum(start, end, 0, 0, n - 1, segtree));
    }

    cout << "Query results: ";
    for (int res : result) {
        cout << res << " ";
    }
    cout << endl;

    return 0;
}
