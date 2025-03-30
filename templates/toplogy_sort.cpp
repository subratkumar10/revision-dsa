

// course schedule II which is based on toplogical sort

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {


    //cardinality 
    vector<int>card(numCourses,0);

    int n = prerequisites.size();
    vector<vector<int>>adj(numCourses);
    for(int i=0;i<n;i++ ){

        adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        card[prerequisites[i][0]]++;
    }

    queue<int>q;
    for(int i =0;i<numCourses;i++){
        if(card[i]==0){
            q.push(i);
            // cout<<i<<endl;
        }
    }
    vector<int>ans;
    while(!q.empty()){

        int top = q.front();
        q.pop();
        ans.push_back(top);
        for(auto child: adj[top]){

            card[child]--;
            if(card[child]==0){
                q.push(child);
            }
        }
    }
    if(ans.size()!=numCourses)
    return {};
    return ans;



    
}