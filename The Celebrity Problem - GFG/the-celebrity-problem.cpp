//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        int left = 0, right = n-1;
        
        
        while(left < right){
            if(M[left][right] == 0){
                right--;
            } else if(M[right][left] == 0){
                left++;
            }else {
                left++;
                right--;
            }
        }
        
        bool flag = true;
        
        for(int j = 0; j < n; j++){
            if(M[left][j] == 1 || (j != left && M[j][left] == 0)){
                flag = false;
                break;
            }
        }
        
        return (flag) ? left : -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends