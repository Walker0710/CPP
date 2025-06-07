#include <bits/stdc++.h>

using namespace std;

// << ,

double solve(double mid, vector<vector<int>> &squares)
{
    double abov = 0;
    double belo = 0;

    for (int i = 0; i < squares.size(); i++)
    {

        // above
        if (squares[i][1] >= mid)
        {
            abov = abov + squares[i][2] * squares[i][2];
        }

        // below
        else if (squares[i][1] + squares[i][2] <= mid)
        {
            belo = belo + squares[i][2] * squares[i][2];
        }

        else
        {
            double side = (double)squares[i][2];
            double total = side * side;

            double newY = mid - squares[i][1];

            belo = belo + newY * side;
            abov = abov + (total - newY * side);
        }
    }

    return abov - belo;
}

double separateSquares(vector<vector<int>> &squares)
{
    double lo = 0;
    double hi = 2 * 1e9;

    while (hi - lo > 1e-6)
    {
        double mid = (hi + lo) / 2.0;

        double diff = solve(mid, squares);

        if (diff > 0)
        {
            lo = mid;
        }
        else
        {
            hi = mid;
        }
    }

    return hi;
}





double helper(double line, vector<vector<int>> &squares)
{
    double aAbove = 0, aBelow = 0;
    int n = squares.size();
    for (int i = 0; i < n; i++)
    {
        int x = squares[i][0], y = squares[i][1];
        int l = squares[i][2];
        double total = (double)l * l;

        if (line <= y)
        {
            aAbove += total;
        }
        else if (line >= y + l)
        {
            aBelow += total;
        }
        else
        {
            double aboveHeight = (y + l) - line;
            double belowHeight = line - y;
            aAbove += l * aboveHeight;
            aBelow += l * belowHeight;
        }
    }
    return aAbove - aBelow;
}

double separateSquares(vector<vector<int>> &squares)
{
    double lo = 0, hi = 2 * 1e9;

    for (int i = 0; i < 60; i++)
    {
        double mid = (lo + hi) / 2.0;
        double diff = helper(mid, squares);

        if (diff > 0)
            lo = mid;
        else
            hi = mid;
    }

    return hi;
}