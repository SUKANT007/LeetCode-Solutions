//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++


class data {
    public:
    
    int value;
    int apos;
    int vpos;
    
    data(int v, int ap, int vp){
        value = v;
        apos = ap;
        vpos = vp;
    }
};

struct cmp {
    bool operator()(data &d1, data &d2){
        return d1.value > d2.value;
    }
};

class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        priority_queue<data,vector<data>,cmp> minHeap;
        
        for(int i = 0; i < K; i++){
            data d(arr[i][0],i,0);
            minHeap.push(d);
        }
        
        vector<int> res;
        
        while(!minHeap.empty()){
            data cur = minHeap.top();
            minHeap.pop();
            
            res.push_back(cur.value);
            
            if(cur.vpos+1 < arr[cur.apos].size()){
                data d(arr[cur.apos][cur.vpos+1],cur.apos,cur.vpos+1);
                minHeap.push(d);
            }
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends