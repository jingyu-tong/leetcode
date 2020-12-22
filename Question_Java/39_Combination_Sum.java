class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> ans = new ArrayList<>();
        dfs(candidates, 0, target, new ArrayList<>(), ans);
        return ans;
    }

    private void dfs(int[] candidates, int loc, int target, List<Integer> curAns, List<List<Integer>> ans) {
        if (target == 0) {
            ans.add(new ArrayList<Integer>(curAns));
            return;
        }
        if (target < 0)
            return;

        for (int i = loc; i < candidates.length; ++i) {
            curAns.add(candidates[i]);
            dfs(candidates, i, target - candidates[i], curAns, ans);
            curAns.remove(curAns.size() - 1);
        }
    }
}