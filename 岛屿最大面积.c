给定一个包含了一些 0 和 1 的非空二维数组 grid 。
一个 岛屿 是由一些相邻的 1 (代表土地) 构成的组合，这里的「相邻」要求两个 1 必须在水平或者竖直方向上相邻。你可以假设 grid 的四个边缘都被 0（代表水）包围着。
找到给定的二维数组中最大的岛屿面积。(如果没有岛屿，则返回面积为 0 。)
示例 1:

[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]

对于上面这个给定矩阵应返回 6。注意答案不应该是 11 ，因为岛屿只能包含水平或垂直的四个方向的 1 。

示例 2:

[[0,0,0,0,0,0,0,0]]

对于上面这个给定的矩阵, 返回 0。

注意: 给定的矩阵grid 的长度和宽度都不超过 50。

void dfs(int x,int y,int **grid,int *num,int maxX,int maxY){
    if(x < 0 || x >= maxX || y < 0 || y >= maxY || !grid[x][y])
        return;
    (*num)++;
    grid[x][y] = 0;
    dfs(x+1,y,grid,num,maxX,maxY);
    dfs(x-1,y,grid,num,maxX,maxY);
    dfs(x,y+1,grid,num,maxX,maxY);
    dfs(x,y-1,grid,num,maxX,maxY);
}

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
    if(!grid || !gridColSize) return 0;
    int maxX = gridSize,maxY = gridColSize[0];
    int num,result = 0;
    int i,j;
    for(i = 0;i < maxX;i++){
        for(j = 0;j < maxY;j++){
            if(grid[i][j]){
                num = 0;
                dfs(i,j,grid,&num,maxX,maxY);
                if(num > result)
                    result = num;
            }
        }
    }
    return result;
}
