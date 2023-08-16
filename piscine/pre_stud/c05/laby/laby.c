#include <stdio.h>
#include <stdbool.h>
#define N 4

bool isValid(int maze[N][N], int x, int y) {
    if (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1) return true;
    return false;
}

bool solveMazeUtil(int maze[N][N], int x, int y, int solution[N][N]) {
    if (x == N - 1 && y == N - 1 && maze[x][y] == 1) {
        solution[x][y] = 1;
        return true;
    }

    if (isValid(maze, x, y)) {
        solution[x][y] = 1;
        
        if (solveMazeUtil(maze, x + 1, y, solution)) return true; // Move right
        if (solveMazeUtil(maze, x, y + 1, solution)) return true; // Move down

        solution[x][y] = 0; // Backtrack if the branch is unsuccessful
        return false;
    }
    return false;
}

bool solveMaze(int maze[N][N]) {
    int solution[N][N] = { {0, 0, 0, 0},
                           {0, 0, 0, 0},
                           {0, 0, 0, 0},
                           {0, 0, 0, 0} };

    if (!solveMazeUtil(maze, 0, 0, solution)) {
        printf("No solution\n");
        return false;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) printf(" %d ", solution[i][j]);
        printf("\n");
    }
    return true;
}

int main() {
    int maze[N][N] = { {1, 0, 0, 0},
                       {1, 1, 0, 1},
                       {0, 1, 0, 0},
                       {1, 1, 1, 1} };

    solveMaze(maze);
    return 0;
}


