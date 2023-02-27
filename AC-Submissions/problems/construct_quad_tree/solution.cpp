/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    struct ROI {
        int top;
        int bottom;
        int left;
        int right;
    };
    
    int isLeaf(const vector<vector<int>>& grid, const ROI& roi) {
        const int val = grid[roi.top][roi.left];
        for (int r=roi.top; r<=roi.bottom; ++r) {
            for (int c=roi.left; c<=roi.right; ++c) {
                if (val != grid[r][c]) { return -1; }
            }
        }
        
        return val;
    }
    
    Node* construct_quad_tree(const vector<vector<int>>& grid, const ROI& roi) {
        int val = isLeaf(grid, roi);
        if (val != -1) {
            return new Node(val, true);
        }
        
        Node* node = new Node(0, false);
        int mid_col = (roi.left + roi.right)/2;
        int mid_row = (roi.top + roi.bottom)/2;
        
        const ROI top_left_roi{.top=roi.top, .bottom=mid_row, .left=roi.left, .right=mid_col };
        const ROI top_right_roi{.top=roi.top, .bottom=mid_row, .left=mid_col+1, .right=roi.right };
        const ROI bottom_left_roi{.top=mid_row+1, .bottom=roi.bottom, .left=roi.left, .right=mid_col };
        const ROI bottom_right_roi{.top=mid_row+1, .bottom=roi.bottom, .left=mid_col+1, .right=roi.right };
        
        node->topLeft = construct_quad_tree(grid, top_left_roi);
        node->topRight = construct_quad_tree(grid, top_right_roi);
        node->bottomLeft = construct_quad_tree(grid, bottom_left_roi);
        node->bottomRight = construct_quad_tree(grid, bottom_right_roi);
        
        return node;
    }
    
    Node* construct(vector<vector<int>>& grid) {
        if (grid.size() == 0) { return nullptr; }
        else if (grid.size() == 1) {
            return new Node(grid[0][0], true);
        }
        
        const ROI roi{.top=0, .bottom=static_cast<int>(grid.size())-1, .left=0, .right=static_cast<int>(grid[0].size())-1 };
        Node* node = construct_quad_tree(grid, roi);
        
        return node;
    }
};