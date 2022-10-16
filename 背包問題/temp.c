#include <iostream>
using namespace std;

#define N 100

int maxw = 0, maxp = 0, numbest = 0, bestset[N], tmp[N];
int n, bag, profit[N];
double weight[N];

bool promising(int ctr, int p, int w)
{
    int x, totalw, bound;

    if (w >= bag)
    {
        return false;
    }
    else
    {
        x = ctr + 1;
        bound = p;
        totalw = w;
        while (x <= n && totalw + weight[x] <= bag)
        {
            totalw = totalw + weight[x];
            bound = bound + profit[x];
            x++;
        }
        if (x <= n)
        {
            bound = bound + (bag - totalw) * (profit[x] / weight[x]);
        }
        return bound > maxp;
    }
}

void knapsack(int ctr, int p, int w)
{
    int a = 0, b = 0;
    if (w <= bag && p > maxp)
    {
        maxp = p;
        maxw = w;
        numbest = ctr;
        while (a < ctr)
        {
            if (tmp[a] == 1)
            {
                bestset[b] = tmp[a];
                b++;
            }
            a++;
        }
    }

    if (promising(ctr, p, w))
    {
        tmp[ctr + 1] = 1;
        knapsack(ctr + 1, p + profit[ctr + 1], w + weight[ctr + 1]);
        tmp[ctr + 1] = 0;
        knapsack(ctr + 1, p, w);
    }
}

int main()
{

    //輸入有多少物品
    cin >> n;
    //輸入背包大小
    cin >> bag;
    //輸入每個物品的 weight和profit
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
        cin >> profit[i];
    }

    double cp[N];
    for (int i = 0; i < n; i++)
    {
        cp[i] = profit[i] / weight[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (cp[j] > cp[i])
            {
                double tmp = cp[i], tmpw = weight[i];
                int tmpp = profit[i];

                cp[i] = cp[j];
                cp[j] = tmp;

                weight[i] = weight[j];
                weight[j] = tmpw;

                profit[i] = profit[j];
                profit[j] = tmpp;
            }
        }
    }

    knapsack(-1, 0, 0);
    cout << maxw << " " << maxp;
}