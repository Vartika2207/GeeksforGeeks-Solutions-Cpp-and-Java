bool isPossible(bool graph[101][101], int n, int curr, int color[], int pickedColor){
        for(int i=0; i<n; i++){
            if(curr != i and graph[curr][i] and color[i] == pickedColor)
              return false;
        }
        return true;
    }
    
    bool gColoring(bool graph[101][101], int m, int n, int curr, int color[]){
        if(curr == n) //all nodes covered
          return true; 
          
        //try all color for curr node  
        for(int i=1; i<=m; i++){
            if(isPossible(graph, n, curr, color, i)){
               color[curr] = i;
               if(gColoring(graph, m, n, curr+1, color))
                 return true;
              color[curr] = 0; //back track  
           }  
        } 
        return false;
    }
    
    bool graphColoring_(bool graph[101][101], int m, int n){
        int color[n]={0};
         
        return gColoring(graph, m, n, 0, color);
    }
    
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        return graphColoring_(graph, m, n);
    }
