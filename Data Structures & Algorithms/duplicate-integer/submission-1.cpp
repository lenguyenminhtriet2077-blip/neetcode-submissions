
class Solution {

private:
    unordered_set<int> seen;
public:
    bool hasDuplicate(vector<int>& nums) {
        for (auto num : nums){
            if (seen.count(num))
                return true;
            else
            {
                seen.insert(num);
                continue;
            }
        }
        return false;
    }
};