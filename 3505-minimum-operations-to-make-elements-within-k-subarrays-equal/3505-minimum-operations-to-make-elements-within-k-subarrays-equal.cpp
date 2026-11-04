#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = (int)nums.size();

        // Maintain the lower and upper halves of the current window.
        // lower contains ceil(x / 2) elements; its largest element is a median.
        multiset<long long> lower, upper;
        long long sumLower = 0, sumUpper = 0;

        auto rebalance = [&]() {
            int target = (x + 1) / 2;

            while ((int)lower.size() > target) {
                auto it = prev(lower.end());
                long long v = *it;
                lower.erase(it);
                sumLower -= v;
                upper.insert(v);
                sumUpper += v;
            }

            while ((int)lower.size() < target && !upper.empty()) {
                auto it = upper.begin();
                long long v = *it;
                upper.erase(it);
                sumUpper -= v;
                lower.insert(v);
                sumLower += v;
            }

            // Ensure every value in lower is <= every value in upper.
            if (!lower.empty() && !upper.empty() &&
                *prev(lower.end()) > *upper.begin()) {
                long long a = *prev(lower.end());
                long long b = *upper.begin();

                lower.erase(prev(lower.end()));
                upper.erase(upper.begin());

                lower.insert(b);
                upper.insert(a);

                sumLower += b - a;
                sumUpper += a - b;
            }
        };

        auto add = [&](long long v) {
            if (lower.empty() || v <= *prev(lower.end())) {
                lower.insert(v);
                sumLower += v;
            } else {
                upper.insert(v);
                sumUpper += v;
            }
            rebalance();
        };

        auto remove = [&](long long v) {
            auto it = lower.find(v);
            if (it != lower.end()) {
                lower.erase(it);
                sumLower -= v;
            } else {
                it = upper.find(v);
                upper.erase(it);
                sumUpper -= v;
            }
            rebalance();
        };

        vector<long long> cost(n - x + 1);

        for (int i = 0; i < n; ++i) {
            add(nums[i]);

            if (i >= x) {
                remove(nums[i - x]);
            }

            if (i >= x - 1) {
                long long median = *prev(lower.end());
                cost[i - x + 1] =
                    median * (long long)lower.size() - sumLower +
                    sumUpper - median * (long long)upper.size();
            }
        }

        // dpPrev[i] = minimum cost to choose j-1 non-overlapping
        // windows from the first i elements.
        const long long INF = LLONG_MAX / 4;
        vector<long long> dpPrev(n + 1, 0), dpCur(n + 1, INF);

        for (int j = 1; j <= k; ++j) {
            fill(dpCur.begin(), dpCur.end(), INF);

            for (int i = 1; i <= n; ++i) {
                // Do not use an operation window ending at i.
                dpCur[i] = dpCur[i - 1];

                // Or choose the window [i - x, i - 1].
                if (i >= x && dpPrev[i - x] != INF) {
                    dpCur[i] = min(
                        dpCur[i],
                        dpPrev[i - x] + cost[i - x]
                    );
                }
            }

            dpPrev.swap(dpCur);
        }

        return dpPrev[n];
    }
};
