///Copied.
using element = pair<int,int>;  //an element is (row and then value)

using cache = map<int, vector<element>>;   //map to group the nodes by their column index`

using stackElement = pair<pair<int,TreeNode*>, element>;   //element for the stack search (<col, Node*>,<row, value>)


ostream & operator<<(ostream & out, const element & P)
{
  out << "( " << P.first << ", " << P.second << ")";
  return out;
}

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {

    // The resulting vector
     vector<vector<int>> results;
    if(!root)
      return results;
    

    //cache to group the elements
    cache C;

    //initaing the stack
    stack<stackElement> frontier;
    frontier.push(make_pair( make_pair(0, root)  , make_pair(0, root->val)));


    while(frontier.size())
    {
      //extacting the current stack element
      auto current = frontier.top();   frontier.pop();

      //getting the column index
      int col = current.first.first;
      TreeNode *node = current.first.second;

      //adding the element to the results
      C[col].push_back(current.second);

      //expanding left and right
      if(node->left)
          frontier.push( make_pair(make_pair(col-1, node->left),
                                   make_pair(current.second.first+1, node->left->val)));
      if(node->right)
          frontier.push( make_pair(make_pair(col+1, node->right),
                                   make_pair(current.second.first+1, node->right->val)));
    }

    for(auto P : C)
      {
        results.push_back(vector<int>());
        sort(P.second.begin(), P.second.end());
         /* cout << P.first << " : " ; */
        for(auto v : P.second)
            results.back().push_back(v.second);
        cout << endl;
      }

    return results;
    }
};