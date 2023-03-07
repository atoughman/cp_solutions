// problem link
// https://leetcode.com/problems/regions-cut-by-slashes/description/

let n;

let inside = (row, col) => {
    return row >= 0 && col >= 0 && row < n && col < n;
}

let dfs = (row, col, type, vis, grid) => {
    if(!inside(row,col) || vis[row][col][type]) return;

    vis[row][col][type] = true;

    // cross cell
    switch(type) {
        case 0: // top
            dfs(row - 1, col, 2, vis, grid)
            break;
        case 1: // left
            dfs(row, col - 1, 3, vis, grid)
            break;
        case 2: // bottom
            dfs(row + 1, col, 0, vis, grid)
            break;
        case 3: // right
            dfs(row, col + 1, 1, vis, grid)
            break;
    }
    
    // same cell
    if(grid[row][col] !== "/") {
        dfs(row, col, (type ^ 3), vis, grid)
    }
    if(grid[row][col] !== "\\") {
        dfs(row,col, (type ^ 1), vis, grid)
    }
}

var regionsBySlashes = function(grid) {
    n = grid.length
    let regions = 0;

    const vis = new Array(n).fill(false).map(() => {
        return new Array(n).fill(false).map(() => {
            return new Array(4).fill(false)
        })
    })

    for(let i=0; i<n; i++) {
        for(let j=0; j<n; j++) {
            for(let k=0; k<4; k++) {
                if(vis[i][j][k] === true) continue;
                dfs(i, j, k, vis, grid)
                regions += 1;
            }
        }
    }

    return regions;
};