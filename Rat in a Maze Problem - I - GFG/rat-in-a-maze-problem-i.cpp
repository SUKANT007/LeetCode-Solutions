//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> findPath(vector<vector<int>> &matrix, int n) {
        if(matrix[0][0] == 0 || matrix[n-1][n-1] == 0){
            return {};
        }
        
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        string curPath;
        vector<string> ans;
        
        solve(0,0,n,curPath,vis,matrix,ans);
        
        return ans;
    
    }
    
    void solve(int i, int j, int n, string &curPath, vector<vector<bool>>& vis, vector<vector<int>> &matrix, vector<string> &ans){
        
        if(i == n-1 && j == n-1){
            ans.push_back(curPath);
            
            return;
        }
        
        if(i < 0 || j < 0 || i >= n || j >= n || matrix[i][j] == 0 || vis[i][j]){
            return;
        }
        
        vis[i][j] = true;
        
        curPath.push_back('R');
        solve(i,j+1,n,curPath,vis,matrix,ans);
        curPath.pop_back();
        
        curPath.push_back('D');
        solve(i+1,j,n,curPath,vis,matrix,ans);
        curPath.pop_back();
        
        curPath.push_back('L');
        solve(i,j-1,n,curPath,vis,matrix,ans);
        curPath.pop_back();
        
        curPath.push_back('U');
        solve(i-1,j,n,curPath,vis,matrix,ans);
        curPath.pop_back();
        
        vis[i][j] = false;
        
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends