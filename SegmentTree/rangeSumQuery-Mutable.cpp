class NumArray {
public:
    int n;
    vector<int> segmentTree;

    void buildSegmentTree(vector<int>& nums,int i,int l,int r){

        if(l == r){
            segmentTree[i] = nums[l];
            return;
        }

        int mid = l + (r-l)/2;

        buildSegmentTree(nums,2*i+1,l,mid);
        buildSegmentTree(nums,2*i+2,mid+1,r);

        segmentTree[i] = segmentTree[2*i+1] + segmentTree[2*i+2];
    }

    void updateSegmentTree(int index,int val,int i,int l,int r){

        if(l == r){
            segmentTree[i] = val;
            return;
        }

        int mid = l + ( r- l) / 2;

        if(index <= mid){
           updateSegmentTree(index,val,2*i+1,l,mid); 
        }else{
            updateSegmentTree(index,val,2*i+2,mid+1,r);
        }

        segmentTree[i] = segmentTree[2*i+1] + segmentTree[2*i+2];
    }

    int querySegmentTree(int left,int right,int i,int l,int r){

        if(l > right || r < left){
            return 0;
        }

        if(l >= left && r <= right){
           return segmentTree[i];
        }

        int mid = l + (r-l)/2;

        return querySegmentTree(left,right,2*i+1,l,mid) + querySegmentTree(left,right,2*i+2,mid+1,r);
    }

    NumArray(vector<int>& nums) {
        n = nums.size();
        segmentTree.resize(4*n);
        buildSegmentTree(nums,0,0,n-1);
    }
    
    void update(int index, int val) {
        updateSegmentTree(index,val,0,0,n-1);
    }
    
    int sumRange(int left, int right) {
        return querySegmentTree(left,right,0,0,n-1);
    }
};

