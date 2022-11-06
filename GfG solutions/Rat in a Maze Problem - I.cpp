
class Solution{
    //time: O(4^(n*n)) -->on each cell we try 4 possibilites
   //space: O(n*n)
    string dir = "DLRU";
    int dxdy[4][2] = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
    
    bool isValid(int x, int y,int n){
        if((x < n && x >= 0) && (y < n && y >= 0))
          return true;
         return false;
    }
    
    void findPathHelper(vector<vector<int>>&m, int n, int **visited, vector<string> &paths, string path, int x, int y){
        if(x == n-1 && y == n-1){
            paths.push_back(path);
            return;
        }
        
        visited[x][y] = 1;
        for(int i=0; i<4; i++){
            int dx = x + dxdy[i][0];
            int dy = y + dxdy[i][1];
            char direction = dir[i];
            if(isValid(dx, dy, n) && m[dx][dy] && !visited[dx][dy]){
                path.push_back(direction);
                findPathHelper(m, n, visited, paths, path, dx, dy);
                path.pop_back();
            }
        }
        visited[x][y] = 0;
    }
    
    
    
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> paths;
        string path = "";
        if(n == 0 || n == 1 || m[0][0] == 0 || m[n-1][n-1] == 0)
        return paths;
        
        int **visited = new int*[n];
        for(int i=0; i<n; i++){
            visited[i] = new int[n]();
        }
        
        findPathHelper(m, n, visited, paths, path, 0, 0);
        return paths;
    }
};

 
