// approach1: O(height*diameter) = O(n^2)
int height(Node* root) {
	if(!root)
	    return 0;
	return 1 + max(height(root->left), height(root->left));
}
int diameterOfBT(Node *root) {
    if(!root)
        return 0;
        
    int ld = diameterOfBT(root->left);    
    int rd = diameterOfBT(root->right);
    int lh = height(root->left);
    int rh = height(root->right);
    
    return max(lh+rh+1, max(ld, rd));
}
// approach2: creating pair class for height
pair<int, int> diameterOfBT_optimal(Node *root) {
    pair<int, int> p;
    if(!root) {
        p.first = 0; //height
        p.second = 0; //diameter
        return p;
    }
    
    pair<int, int> leftTree = diameterOfBT_optimal(root->left);
    pair<int, int> rightTree = diameterOfBT_optimal(root->right);
    
    int lh = leftTree.first, ld = leftTree.second;
    int rh = rightTree.first, rd = rightTree.second;
    
    p.first = max(lh, rh) + 1;  //heiht of root
    p.second = max({ld, rd, lh + rh + 1}); //diameter of root
    return p;
}


  public:
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        return diameterOfBT(root);
        // return diameterOfBT_optimal(root).second;
    }
};
