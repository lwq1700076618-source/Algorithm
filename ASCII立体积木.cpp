#include <bits/stdc++.h>
using namespace std;

int m, n;
int a[55][55];
char canvas[1000][1000];
int maxRow = 0, maxCol = 0;

// 积木模板
string block[6] = {
    "  +---+",
    " /   /|",
    "+---+ |",
    "|   | +",
    "|   |/",
    "+---+"
};

// 在 (row, col) 位置画一个积木
void drawBlock(int row, int col) {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            if (block[i][j] != ' ') {
                canvas[row + i][col + j] = block[i][j];
            }
        }
    }
    maxRow = max(maxRow, row + 6);
    maxCol = max(maxCol, col + 7);
}

int main() {
    cin >> m >> n;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    
    // 初始化
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            canvas[i][j] = '.';
        }
    }
    
    // 从后往前画
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < a[i][j]; k++) {
                // 关键：计算每个积木的位置
                // i: 行（前后），j: 列（左右），k: 高度
                // 行坐标：后面（i大）的行坐标小，因为显示在前面
                // 列坐标：左边（j小）的列坐标小
                int row = (m - 1 - i) * 2 + k * 3;
                int col = j * 4 + (m - 1 - i) * 2;
                drawBlock(row, col);
            }
        }
    }
    
    // 输出
    for (int i = maxRow - 1; i >= 0; i--) {
        for (int j = 0; j < maxCol; j++) {
            cout << canvas[i][j];
        }
        cout << endl;
    }
    
    return 0;
}
