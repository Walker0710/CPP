#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <map>

using namespace std;

void solve(double poured, int row, int col, int query_row, vector<vector<double>> &record)
{

    if (row >= query_row)
        return;

    if (col > row)
    {
        row++;
        col = 0;
        solve(record[row][col], row, col, query_row, record);
    }

    double howMuch = 0.0;

    if (poured >= 1)
    {
        howMuch = (double)(poured - 1) / 2;
    }

    record[row + 1][col] = record[row + 1][col] + howMuch;
    record[row + 1][col + 1] = record[row + 1][col + 1] + howMuch;

    solve(record[row][col + 1], row, col + 1, query_row, record);
}

double champagneTower(int poured, int query_row, int query_glass)
{
    vector<vector<double>> record(query_row + 2, vector<double>(query_row + 2, 0));
    solve(poured, 0, 0, query_row, record);
    return min(1.0, record[query_row][query_glass]);
}

// 2nd
void solve(double poured, int row, int col, int query_row, vector<vector<double>> &record)
{
    if (row > query_row)
        return;

    record[row][col] += poured;

    double excess = max(0.0, record[row][col] - 1.0);
    if (excess > 0)
    {
        solve(excess / 2, row + 1, col, query_row, record);
        solve(excess / 2, row + 1, col + 1, query_row, record);
    }
}

double champagneTower(int poured, int query_row, int query_glass)
{
    vector<vector<double>> record(query_row + 1, vector<double>(query_row + 1, 0));
    solve(poured, 0, 0, query_row, record);
    return min(1.0, record[query_row][query_glass]);
}

// dp 1st
void solve(double poured, int row, int col, int query_row, vector<vector<double>> &record)
{
    if (row >= query_row)
    return;

    if (col > row)
    {
        row++;
        col = 0;
        solve(record[row][col], row, col, query_row, record);
    }

    double howMuch = 0.0;

    if (poured >= 1)
    {
        howMuch = (double)(poured - 1) / 2;
    }

    record[row + 1][col] = record[row + 1][col] + howMuch;
    record[row + 1][col + 1] = record[row + 1][col + 1] + howMuch;

    solve(record[row][col + 1], row, col + 1, query_row, record);
}


//dp
double champagneTower(int poured, int query_row, int query_glass)
{
    vector<vector<double>> record(query_row + 2, vector<double>(query_row + 2, 0));
    record[0][0] = poured;

    for (int row = 0; row < query_row; row++)
    {
        for (int col = 0; col < query_row; col++)
        {
            double howMuch = 0.0;

            if (record[row][col] >= 1)
            {
                howMuch = (double)(record[row][col] - 1) / 2;
            }

            record[row + 1][col] = record[row + 1][col] + howMuch;
            record[row + 1][col + 1] = record[row + 1][col + 1] + howMuch;
        }
    }
    return min(1.0, record[query_row][query_glass]); 
}
