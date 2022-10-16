#include <stdio.h>
#include <stdlib.h>

// Global
int n, *w, *p, W, maxprofit, maxweight = 0, numbest, totalWeight = 0, totalProfit = 0;
// char *include, *bestset;

void sort();
void knapsack(int i, int profit, int weight);
int promising(int i, int weight, int profit);

int main(void)
{
    scanf("%d", &n);
    scanf("%d", &W);

    w = malloc((n + 1) * sizeof(int));
    p = malloc((n + 1) * sizeof(int));
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &w[i]);
        scanf("%d", &p[i]);
    }
    sort();
    // include = malloc((n + 1) * sizeof(char));
    // bestset = malloc((n + 1) * sizeof(char));
    numbest = 0;
    maxprofit = 0;
    knapsack(0, 0, 0);
    printf("%d %d", maxweight, maxprofit);
}

void sort()
{
    double fractional[n + 1];
    for (int i = 1; i <= n; i++)
    {
        fractional[i] = (double)p[i] / w[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (fractional[j] > fractional[i])
            {
                double ftemp = fractional[i];
                fractional[i] = fractional[j];
                fractional[j] = ftemp;

                int wtemp = w[i];
                w[i] = w[j];
                w[j] = wtemp;

                int ptemp = p[i];
                p[i] = p[j];
                p[j] = ptemp;
            }
        }
    }
}

void knapsack(int i, int profit, int weight)
{

    if (weight <= W && profit > maxprofit)
    {

        maxprofit = profit;
        maxweight = weight;
        numbest = i;

        // bestset = include;
        // for (int j = 1; j <= i; j++)
        // {
        //     bestset[i] = include[i];
        // }
    }
    if (promising(i, weight, profit))
    {

        // include[i + 1] = 'y';

        knapsack(i + 1, profit + p[i + 1], weight + w[i + 1]);
        // include[i + 1] = 'n';

        knapsack(i + 1, profit, weight);
    }
}

int promising(int i, int weight, int profit)
{
    int j, k;
    int totweight;
    float bound;

    if (weight >= W)
        return 0;
    else
    {
        j = i + 1;
        bound = profit;
        totweight = weight;
        while (j <= n && totweight + w[j] <= W)
        {
            totweight = totweight + w[j];
            bound = bound + p[j];
            j++;
        }

        k = j;
        if (k <= n)
        {
            bound = bound + (W - totweight) * ((float)p[k] / w[k]);
        }
        if (bound > maxprofit)
        {
            return 1;
        }
        return 0;
    }
}