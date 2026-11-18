#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
    FILE* in = fopen("input.txt", "rt");
    if (!in) return 1;
    FILE* out = fopen("output.txt", "wt");
    if (!out) {
        fclose(in);
        return 1;
    }

    char field[100][101];
    int row = 0;
    int col = 0;

    while (fgets(field[row], 101, in) && row < 100) {
        int len = strlen(field[row]);
        if (len > 0 && field[row][len - 1] == '\n') {
            field[row][len - 1] = '\0';
            len--;
        }
        if (row == 0) col = len;

        row++;
    }

    fclose(in);
    int total_prizes = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (field[i][j] == '*') {
                total_prizes++;
            }
        }
    }

    int x = 1, y = 1;
    int dx = 1, dy = 0;
    int eaten_prizes = 0;
    char visited[100][100][4] = { 0 };
    int game_over = 0;

    while (!game_over) {
        int dir_index;
        if (dx == 1 && dy == 0) dir_index = 0;
        else if (dx == 0 && dy == 1) dir_index = 1;
        else if (dx == -1 && dy == 0) dir_index = 2;
        else dir_index = 3;

        if (visited[y][x][dir_index]) {
            fprintf(out, "no");
            game_over = 1;
            break;
        }

        visited[y][x][dir_index] = 1;
        if (field[y][x] == '*') {
            eaten_prizes++;
            field[y][x] = ' ';
        }

        else if (field[y][x] == '/') {
            int temp = dx;
            dx = -dy;
            dy = -temp;
        }

        else if (field[y][x] == '\\') {
            int temp = dx;
            dx = dy;
            dy = temp;
        }

        else if (field[y][x] == '#') {
            dx = -dx;
            dy = -dy;
            x -= dx;
            y -= dy;
        }

        x += dx;
        y += dy;

        if (y == row - 2 && x == col - 2) {
            fprintf(out, "yes\n");
            if (eaten_prizes == total_prizes) {
                fprintf(out, "yes");
            }
            else {
                fprintf(out, "no");
            }
            game_over = 1;
            break;
        }
    }
    fclose(out);
    return 0;
}