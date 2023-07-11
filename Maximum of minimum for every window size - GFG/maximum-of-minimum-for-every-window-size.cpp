//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    
    vector<int> findNearestSmallestInRight(int arr[], int n){
        stack<int> s;
        vector<int> nearestSmallestInRight(n);
        
        for(int i = n-1; i >= 0; i--){
            while(!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            
            if(!s.empty()){
                nearestSmallestInRight[i] = s.top();
            } else {
                nearestSmallestInRight[i] = n;
            }

            s.push(i);
        }
        
        return nearestSmallestInRight;
    }
    
    
    vector<int> findNearestSmallestInLeft(int arr[], int n){
        stack<int> s;
        vector<int> nearestSmallestInLeft(n);
        
        for(int i = 0; i < n; i++){
            while(!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            
            if(!s.empty()){
                nearestSmallestInLeft[i] = s.top();
            } else {
                nearestSmallestInLeft[i] = -1;
            }

            s.push(i);
        }
        
        return nearestSmallestInLeft;
    }
    //Function to find maximum of minimums of every window size.
    vector <int> maxOfMin(int arr[], int n)
    {
        vector<int> nearestSmallestInLeft = findNearestSmallestInLeft(arr,n);
        vector<int> nearestSmallestInRight = findNearestSmallestInRight(arr,n);
        
        vector<int> windows(n,INT_MIN);
        
        for(int i = 0; i < n; i++){
            int windowSize = nearestSmallestInRight[i] - nearestSmallestInLeft[i] - 1;
            windows[windowSize-1] = max(windows[windowSize-1],arr[i]);
        }

        int maxWindow = windows[n-1];
        
        // for(int i = 0; i < n; i++){
        //     cout << windows[i] <<" ";
        // }
        
        // cout << endl;

        for(int i = n-2; i >= 0; i--){
            maxWindow = max(maxWindow,windows[i]);
            windows[i] = maxWindow;
        }
        
        return windows;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        vector <int> res = ob.maxOfMin(a, n);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends