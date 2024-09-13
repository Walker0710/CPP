#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart)
{
    vector<vector<int>> ans;
    ans.push_back({rStart, cStart});
    int rowp = rStart;
    int colp = cStart;

    for(int i = 1; i<1000; i++) {

        if(i%2 == 1) {

            for(int j = 1; j<=i; j++) {

                colp = colp + 1;
                if(colp >= 0 && colp < cols && rowp >= 0 && rowp < rows)
                ans.push_back({rowp, colp});
            }

            for(int j = 1; j<=i; j++) {

                rowp = rowp + 1;
                if(colp >= 0 && colp < cols && rowp >= 0 && rowp < rows)
                ans.push_back({rowp, colp});
            }
        }

        else {

            for(int j = 1; j<=i; j++) {

                colp = colp - 1;
                if(colp >= 0 && colp < cols && rowp >= 0 && rowp < rows)
                ans.push_back({rowp, colp});
            }

            for(int j = 1; j<=i; j++) {

                rowp = rowp - 1;
                if(colp >= 0 && colp < cols && rowp >= 0 && rowp < rows)
                ans.push_back({rowp, colp});
            }
        }
    }

    return ans;
}

//2nd approch
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        vector<vector<int>> result;
        int total = 0;

        int rowStart = rStart;
        int rowEnd = rStart;

        int colStart = cStart;
        int colEnd = cStart;

        while(true){
            for(int i=colStart; i<=colEnd; i++){
                if(i >= 0 && i < cols && rowStart >= 0){
                    result.push_back({rowStart, i});
                    total++;
                }
            }
            colEnd++;
            if(total == (rows * cols))
                break;
            for(int i=rowStart; i<=rowEnd; i++){
                if(i >= 0 && i < rows && colEnd < cols){
                    result.push_back({i, colEnd});
                    total++;
                }
            }
            rowEnd++;
            if(total == (rows * cols))
                break;
            for(int i=colEnd; i>=colStart; i--){
                if(i >= 0 && i < cols && rowEnd < rows){
                    result.push_back({rowEnd, i});
                    total++;
                }
            }
            colStart--;
            if(total == (rows * cols))
                break;
            for(int i=rowEnd; i>=rowStart; i--){
                if(i >= 0 && i < rows && colStart >= 0){
                    result.push_back({i, colStart});
                    total++;
                }
            }
            rowStart--;
            if(total == (rows * cols))
                break;
        }
        return result;
    }