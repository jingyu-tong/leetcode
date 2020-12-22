class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        List<List<Integer>> ans = new ArrayList<>();
        dfs(candidates, 0, target, new ArrayList<Integer>(), ans);
        return ans;
    }

    private void dfs(int[] candidates, int loc, int target, List<Integer> combination, List<List<Integer>> ans) {
        if (target < 0)
            return;
        if (target == 0) {
            ans.add(new ArrayList<Integer>(combination));
            return;
        }

        for (int i = loc; i < candidates.length; ++i) {
            combination.add(candidates[i]);
            dfs(candidates, i + 1, target - candidates[i], combination, ans);
            combination.remove(combination.size() - 1);
            while (i + 1 < candidates.length && candidates[i + 1] == candidates[i])
                ++i;
        }
    }
}