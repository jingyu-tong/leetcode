class Solution {
    public List<List<Integer>> permuteUnique(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> ans = new ArrayList<>();
        dfs(nums, new boolean[nums.length], new ArrayList<Integer>(), ans);
        return ans;
    }

    private void dfs(int[] nums, boolean[] used, List<Integer> curAns, List<List<Integer>> ans) {
        if (curAns.size() == nums.length) {
            ans.add(new ArrayList<Integer>(curAns));
            return;
        }
        for (int i = 0; i < nums.length; ++i) {
            if (used[i])
                continue;
            used[i] = true;
            curAns.add(nums[i]);
            dfs(nums, used, curAns, ans);
            curAns.remove(curAns.size() - 1);
            used[i] = false;
            while (i < nums.length - 1 && nums[i] == nums[i + 1])
                ++i;
        }
    }
}