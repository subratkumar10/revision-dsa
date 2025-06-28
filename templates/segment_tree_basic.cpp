class SegmentTree {
     vector<int>tree;
     int n;

    public:
    SegmentTree(vector<int>&nums){
           n = nums.size();
       tree.resize(n*4,0);
     

        create_seg(0,n-1,1,nums);
    }

//O(n) time complexity
    void create_seg(int l,int r,int st,vector<int>&nums){


        if(l==r){
            tree[st]=  nums[l];
            return;
        }

        int mid = l+(r-l)/2;

        create_seg(l,mid,st*2,nums);

        create_seg(mid+1,r,st*2+1,nums);

        tree[st] = tree[st*2]+tree[st*2+1];
    }

//O(log(n)) time complexity
      void update(int l, int r, int id,int st,int val){

        if(id<l || id>r)
        return;
        if(l==r){
            tree[st] = val;
            return;
        }

        int mid = l+(r-l)/2;

        update(l,mid,id,st*2,val);

        update(mid+1,r,id,st*2+1,val);

        tree[st] = tree[st*2]+tree[st*2+1];
    }

    //O(log(n)) time complexity
      int query(int l,int r,int ql,int qr,int st){


        if(qr<l || ql>r){
        return 0;
        }

        if(l>=ql && r<=qr){
            return tree[st];
        }
          int mid = l+(r-l)/2;

        int leftv = query(l,mid,ql,qr,st*2);

        int rightv = query(mid+1,r,ql,qr,st*2+1);

        return leftv+rightv;


    }


};
