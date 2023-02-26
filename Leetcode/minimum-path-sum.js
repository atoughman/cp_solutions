// problem link
// https://leetcode.com/problems/minimum-path-sum/description/

// -------------------- RECURSIVE
{
    let m,n;

    let inside = location => {
        const {i, j} = location;
        return i >= 0 && j >= 0 && i < n && j < m;
    }

    let solve = props => {
        const { current_loc, grid } = props;
        const {i, j} = current_loc;

        // base condition
        if(!inside(current_loc)) return Number.MAX_SAFE_INTEGER;

        let top_sum = solve({
            current_loc: {
                i: i-1, 
                j
            }, 
            grid
        })

        let left_sum = solve({
            current_loc: {
                i, 
                j: j-1
            }, 
            grid
        })

        return Math.min(left_sum, top_sum) + grid[i][j];
    }

    var minPathSum = function(grid) {
        n = grid.length;
        m = grid[0].length;

        return solve({
            current_loc: {
                i: n-1,
                j: m-1
            },
            grid
        });
    };
}

// -------------------- RECURSIVE+ MEMO
{
    let m,n;
    let dp = [[]];

    let inside = location => {
        const {i, j} = location;
        return i >= 0 && j >= 0 && i < n && j < m;
    }

    let solve = props => {
        const { current_loc, grid } = props;
        const {i, j} = current_loc;

        // base condition
        if(!inside(current_loc)) return Number.MAX_SAFE_INTEGER;

        // is it already solved ?
        if(dp[i][j] !== -1) return dp[i][j];

        let top_sum = solve({
            current_loc: {
                i: i-1, 
                j
            }, 
            grid
        })

        let left_sum = solve({
            current_loc: {
                i, 
                j: j-1
            }, 
            grid
        })

        return dp[i][j] = Math.min(left_sum, top_sum) + grid[i][j];
    }

    var minPathSum = function(grid) {
        n = grid.length;
        m = grid[0].length;

        dp = new Array(n).fill(-1).map(() => new Array(m).fill(-1));
        dp[0][0] = grid[0][0];

        return solve({
            current_loc: {
                i: n-1,
                j: m-1
            },
            grid
        });
    };
}

// -------------------- ITERATIVE+ 2-D MEMO
{
    const INF = Number.MAX_SAFE_INTEGER;

    var minPathSum = function(grid) {
        let n = grid.length;
        let m = grid[0].length;

        let dp = new Array(n).fill(-1).map(() => new Array(m).fill(-1));
        dp[0][0] = grid[0][0];

        for(let i=0; i<n; i++) {
            for(let j=0; j<m; j++) {
                if(i == 0 && j == 0) continue;
                let left_sum = j-1 >= 0 ? dp[i][j-1] : INF;
                let top_sum = i-1 >=0 ? dp[i-1][j] : INF;

                dp[i][j] = Math.min(left_sum, top_sum) + grid[i][j];
            }
        }

        return dp[n-1][m-1];
    };
}

// -------------------- ITERATIVE+ 1-D MEMO
{
    const INF = Number.MAX_SAFE_INTEGER;

    var minPathSum = function(grid) {
        let n = grid.length;
        let m = grid[0].length;

        let dp = new Array(n).fill(-1);

        for(let i=0; i<n; i++) {
            let new_dp = new Array(m).fill(-1);
            for(let j=0; j<m; j++) {
                if(i == 0 && j == 0) {
                    new_dp[j] = grid[0][0];
                    continue;
                }
                
                let left_sum = j-1 >= 0 ? new_dp[j-1] : INF;
                let top_sum = i-1 >=0 ? dp[j] : INF;

                new_dp[j] = Math.min(left_sum, top_sum) + grid[i][j];
            }
            [dp, new_dp] = [new_dp, dp];
        }

        return dp[m-1];
    };
}

// -------------------- ITERATIVE+ INPLACE ( NO EXTRA MEMO )
{
    var minPathSum = function(grid) {
        let n = grid.length;
        let m = grid[0].length;

        for(let i=1; i<n; i++) {
            grid[i][0] += grid[i-1][0];
        }

        for(let j=1; j<m; j++) {
            grid[0][j] += grid[0][j-1];
        }

        for(let i=1; i<n; i++) {
            for(let j=1; j<m; j++) {
                grid[i][j] += Math.min(grid[i-1][j], grid[i][j-1]);
            }
        }

        return grid[n-1][m-1];
    };
}