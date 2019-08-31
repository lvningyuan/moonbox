
O(n)时间复杂度
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int j =0;
        int i=array.size()-1;
        while(i>=0 && j<array[0].size())
        {
            if(target==array[i][j])
                return true;
            else if(target<array[i][j])
               --i;
            else
                ++j;
        }
        return false ;
    }
};


方法二 “
简单 for循环
