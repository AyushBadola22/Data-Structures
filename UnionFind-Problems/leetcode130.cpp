/*
    Sorry there is no explaination right now, but please contact me i will provide it 
*/

typedef vector<int> vi; 
class Solution {
public:
    vi parent; 
    int find(int u ){
        if (parent[u] < 0)
            return u; 
        return parent[u] = find(parent[u]); 
    }

    void unionFind(int u , int v ){
        int pu = find(u); 
        int pv = find(v); 

        if(pu == pv) return ; 

        if(parent[pu] < parent[pv]){
            parent[pu] += parent[pv]; 
            parent[pv]  = pu; 
        }
        else {
            parent[pv] += parent[pu]; 
            parent[pu]  = pv;
        }
    }

    void solve(vector<vector<char>>& board) {
        int rows = board.size() , cols = board[0].size(); 
        this->parent.resize(rows * cols , -1 ); 
        this->parent.push_back(-rows * cols);  // dummy node , every node connected to it will never be surrounded

        for (int i = 0 ; i < rows ; i++ ){
            for (int j = 0 ; j < cols ; j++){
                if(board[i][j] == 'O'){
                    if(i == 0 || i == rows-1 || j == 0 || j == cols-1)
                        unionFind(i * cols + j , rows * cols); 
                    else{
                        if(board[i-1][j] == 'O')
                            unionFind( i * cols + j , (i-1) * cols + j ); 
                        if(board[i+1][j] == 'O')
                            unionFind( i * cols + j , (i+1) * cols + j ); 
                        if(board[i][j+1] == 'O')
                            unionFind( i * cols + j , i * cols + (j+1) ); 
                        if(board[i][j-1] == 'O')
                            unionFind( i * cols + j , i * cols + (j-1) ); 
                    }
                }
            }
        }

        for (int i = 0 ; i < rows; i++){
            for (int j = 0 ; j < cols; j++){
                if( board[i][j] == 'O' && find(i*cols + j ) != rows * cols  ){
                    board[i][j] = 'X'; 
                }
            }
        }
    }
};