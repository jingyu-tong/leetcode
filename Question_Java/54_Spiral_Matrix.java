class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> ans = new ArrayList<>();
        int ys = 0;
        int ye = matrix.length - 1;
        int xs = 0;
        int xe = matrix[0].length - 1;
        while (ye >= ys && xe >= xs) {
            for (int i = xs; i <= xe; ++i) {
                ans.add(matrix[ys][i]);
            }
            ++ys;
            for (int i = ys; xs <= xe && i <= ye; ++i) {
                ans.add(matrix[i][xe]);
            }
            --xe;
            for (int i = xe; ys <= ye && i >= xs; --i) {
                ans.add(matrix[ye][i]);
            }
            --ye;
            for (int i = ye; xs <= xe && i >= ys; --i) {
                ans.add(matrix[i][xs]);
            }
            ++xs;
        }
        return ans;
    }
}