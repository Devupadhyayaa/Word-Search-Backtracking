#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define tc ll t; cin>>t;while(t--)
#define loop(variable,n) for(int variable=0;variable<n;variable++)
void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
bool wordmke(vector<vector<char>>&board,int idx,string word,int row ,int col){
    if(idx==word.size())return true;
    if(idx==0){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    board[i][j]='.';
                    if(wordmke(board,idx+1,word,i+1,j)==true){
                        return true;
                    }
                    if(wordmke(board,idx+1,word,i-1,j)==true){
                        return true;
                    }
                    if(wordmke(board,idx+1,word,i,j+1)==true){
                        return true;
                    }
                    if(wordmke(board,idx+1,word,i,j-1)==true){
                        return true;
                    }
                    board[i][j]=word[0];
                }
            }
        }
    }
    else{
        if(row<0||col<0||row>board.size()-1||col>board[0].size()-1)return false;
        if(board[row][col]==word[idx]){
            board[row][col]='.';
            if(wordmke(board,idx+1,word,row+1,col)==true){
                return true;
            }
            if(wordmke(board,idx+1,word,row-1,col)==true){
                return true;
            }
            if(wordmke(board,idx+1,word,row,col+1)==true){
                return true;
            }
            if(wordmke(board,idx+1,word,row,col-1)==true){
                return true;
            }
            board[row][col]=word[idx];
        }
        else return false;
    }
    return false;
}
bool exist(vector<vector<char>>& board, string word) {
     if(wordmke(board,0,word,0,0))return true;
     return false;
}
int main(){
    fastIO();
    int n,m;cin>>n>>m;
    string str;cin>>str;
    vector<vector<char>>v(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
    if(exist(v,str))cout<<"YES";
    else cout<<"No"<<endl;
return 0;
}
/*
1. Wrong Ans?
Did u read the Statement properly?
Did u miss any constraints?
Did u miss any corner case?
Are u sure about your Solution?
2. No Idea?
Try Greedy..
Try DP...
First Try Recursive DP..
Then Try Iterative DP..
If memory exceeds, then try to reduce it..
If not possible then, try to solve it using following way..
Try to solve it using Permutation ans Combination..
Try to find Sequence..
Try to Solve it using Algebra..
*/