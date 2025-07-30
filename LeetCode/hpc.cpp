#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Define direction vectors for each type of connectivity
const vector<vector<pair<int, int>>> connectivityOptions = {
    {},
    // Option 1: Left and Right
    {{0, -1}, {0, 1}},
    // Option 2: Up and Down
    {{-1, 0}, {1, 0}},
    // Option 3: 4 Diagonal directions
    {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}},
    // Option 4: Up, Down, Left, Right
    {{0, -1}, {0, 1}, {-1, 0}, {1, 0}},
    // Option 5: All 8 directions
    {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}}
};

// Recursive DFS to mark connected cells
void exploreRegion(int row, int col, vector<vector<int>>& matrix, vector<vector<bool>>& seen, const vector<pair<int, int>>& directions) {
    int rows = matrix.size(), cols = matrix[0].size();
    seen[row][col] = true;

    for (auto move : directions) {
        int newRow = row + move.first;
        int newCol = col + move.second;
        if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols &&
            !seen[newRow][newCol] && matrix[newRow][newCol] == 1) {
            exploreRegion(newRow, newCol, matrix, seen, directions);
        }
    }
}

int main() {
    int option, height, width;
    cin >> option >> height >> width;

    if (option < 1 || option > 5) {
        cerr << "Error: Connectivity option must be between 1 and 5." << endl;
        return 1;
    }

    vector<vector<int>> binaryImage(height, vector<int>(width));
    for (int i = 0; i < height; ++i) {
        string line;
        cin >> line;
        for (int j = 0; j < width; ++j) {
            binaryImage[i][j] = line[j] - '0';
        }
    }

    vector<vector<bool>> visited(height, vector<bool>(width, false));
    int regionCount = 0;

    for (int r = 0; r < height; ++r) {
        for (int c = 0; c < width; ++c) {
            if (binaryImage[r][c] == 1 && !visited[r][c]) {
                regionCount++;
                exploreRegion(r, c, binaryImage, visited, connectivityOptions[option]);
            }
        }
    }

    cout << regionCount << endl;
    return 0;
}