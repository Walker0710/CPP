#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define int long long
#define vec(v) vector<int> v

// << ,

// void solve()
// {
//   int n, m;
//   cin >> n >> m;
//   int p = n + m + 1;

//   vector<int> pro(p), test(p);

//   for (int i = 0; i < p; i++)
//   {
//     cin >> pro[i];
//   }

//   for (int i = 0; i < p; i++)
//   {
//     cin >> test[i];
//   }

//   int l = n; // rec of jobs
//   int r = m;

//   int a = -1; // checkpoint index
//   int b = -1;

//   vector<int> ans;

//   vector<int> dp(p + 1); // total skill till ith index
//   int check = -1;
//   int which = -1;

//   for (int i = 0; i < p; i++)
//   {

//     if (l > 0 & r > 0)
//     {

//       if (pro[i] > test[i])
//       {

//         dp[i + 1] = pro[i] + dp[i];
//         l--;
//       }

//       else
//       {
//         dp[i + 1] = test[i] + dp[i];
//         r--;
//       }
//     }

//     else
//     {

//       if (pro[i] > test[i] & a == -1)
//       {
//         a = i;
//       }

//       if (pro[i] < test[i] & b == -1)
//       {
//         b = i;
//       }

//       if (l > 0)
//       {

//         if(check == -1) {
//           check = i-1;
//           which = 0;
//         }

//         dp[i+1] = pro[i] + dp[i];

//       }

//       else
//       {

//         if(check == -1) {
//           check = i-1;
//           which = 1;
//         }

//         dp[i+1] = test[i] + dp[i];
//       }
//     }
//   }

//   if (a == -1)
//   {
//     a = p - 1;
//   }

//   if (b == -1)
//   {
//     b = p - 1;
//   }

//   int sum = 0;

//   for (int i = p - 1; i >= 0; i--)
//   {
//     if (i > check)
//     {
//       if (which == 0)
//       {
//         ans.push_back(dp[i + 1] + sum - pro[i]);
//         sum = sum + pro[i];
//       }

//       else
//       {
//         ans.push_back(dp[i + 1] + sum - test[i]);
//         sum = test[i] + sum;
//       }
//     }

//     else
//     {

//       if (pro[i] > test[i])
//       {

//         ans.push_back(dp[i + 1] + sum - pro[i] + pro[a] - (which == 0 ? pro[a] : test[a]));
//         sum = sum + pro[i];
//       }

//       else
//       {

//         ans.push_back(dp[i + 1] + sum - test[i] + test[a] - (which == 0 ? pro[b] : test[b]));
//         sum = sum + test[i];
//       }
//     }
//   }

//   reverse(all(ans));

//   for (auto a : ans)
//   {
//     cout << a << " ";
//   }

//   cout << endl;
// }

// yt copied
void solve()
{
  int n, m;
  cin >> n >> m;
  vector<int> a(n + m + 1), b(n + m + 1);
  int sz = n + m + 1;

  for (int i = 0; i < sz; i++)
  {
    cin >> a[i];
  }
  for (int i = 0; i < sz; i++)
  {
    cin >> b[i];
  }

  int x = n, y = m;
  int k = -1;
  bool swp = false;

  for (int i = 0; i < sz; i++)
  {
    if (a[i] > b[i])
      x--;
    else
      y--;
    if (y < 0)
      swp = true;
    if (x < 0 || y < 0)
    {
      k = i;
      break;
    }
  }
  if (swp)
  {
    swap(n, m);
    swap(a, b);
  }
  // now n will guranteed run out first
  int tot = 0;
  for (int i = 0; i < sz; i++)
  {
    if (i == k)
      continue;
    if (i < k)
    {
      tot += max(a[i], b[i]);
    }
    else
    {
      tot += b[i];
    }
  }
  for (int i = 0; i < sz; i++)
  {
    if (i == k)
    {
      cout << tot << " ";
    }
    else if (i < k && a[i] > b[i])
    {
      int c = tot;
      c += a[k];
      c -= a[i];
      cout << c << " ";
    }
    else if (i < k)
    {
      int c = tot;
      c += b[k];
      c -= b[i];
      cout << c << " ";
    }
    else
    {
      // i>k
      int c = tot;
      c += b[k];
      c -= b[i];
      cout << c << " ";
    }
  }
  cout << "\n";
  // cout << k << "\n";
}

signed main()
{
  int t;
  cin >> t;

  while (t--)
  {
    solve();
  }

  return 0;
}
