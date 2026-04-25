#include <bits/stdc++.h>
using namespace std;

bool canPlace(vector<long long> &pos, int k, long long d, long long per)
{
    int n = pos.size();

    vector<long long> ext(2 * n);
    for (int i = 0; i < n; i++)
    {
        ext[i] = pos[i];
        ext[i + n] = pos[i] + per;
    }

    for (int start = 0; start < n; start++)
    {
        int count = 1;
        long long first = ext[start];
        long long curr = ext[start];
        int idx = start;

        while (count < k)
        {
            long long target = curr + d;

            auto it = lower_bound(ext.begin() + idx + 1,
                                  ext.begin() + start + n, target);

            if (it == ext.begin() + start + n)
                break;

            curr = *it;
            idx = it - ext.begin();
            count++;
        }

        if (count == k && first + per - curr >= d)
            return true;
    }

    return false;
}

int main()
{
    int side;
    cout << "Enter the side length of the square: ";
    cin >> side;

    int n;
    cout << "Enter the number of points: ";
    cin >> n;

    vector<vector<int>> points(n, vector<int>(2));
    cout << "Enter the coordinates of the points: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> points[i][0] >> points[i][1];
    }

    int k;
    cout << "Enter the number of points to place: ";
    cin >> k;

    vector<long long> pos;

    for (auto &p : points)
    {
        int x = p[0], y = p[1];

        if (y == 0)
            pos.push_back(x);
        else if (x == side)
            pos.push_back(side + y);
        else if (y == side)
            pos.push_back(3LL * side - x);
        else
            pos.push_back(4LL * side - y);
    }

    sort(pos.begin(), pos.end());

    long long per = 4LL * side;
    long long low = 0, high = per, ans = 0;

    while (low <= high)
    {
        long long mid = (low + high) / 2;

        if (canPlace(pos, k, mid, per))
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    cout << ans << endl;
}