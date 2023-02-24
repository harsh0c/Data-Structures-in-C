#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st; // indices
        int n=nums.size();
        vector<int> ngetr(n);
        // ngetr[n-1]=-1;
        // st.push(n-1);
        int j=1;
        while(j<3){
            for(int i=n-1;i>=0;i--){
                while(st.size()>0 && nums[i]>=nums[st.top()]){
                    st.pop();
                }
                if(st.size()==0){
                    ngetr[i]=-1;
                }
                else{
                    ngetr[i]=nums[st.top()];
                }
                st.push(i);
            }
            j++;
        }
        return ngetr;
    }
};

int main(){
    Solution s1;
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<int> ans=s1.nextGreaterElements(nums);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}