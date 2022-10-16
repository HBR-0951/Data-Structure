#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int level;
    int profit;
    int weight;
} node;

typedef struct queue_of_node
{
    node index;
    struct queue_of_node *next;

} queue_of_node;

// Global
int n, *w, *p, W, maxprofit, queue_index = 0, maxweight;

queue_of_node *Head = NULL; //跑 queue
queue_of_node *Tail = NULL;

void enqueue(node v);
void sort();
void knapsack();
node dequeue();
float bound(node u);
int isEmpty();

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
    sort(); // fractional 排序
    knapsack();
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

void enqueue(node v)
{

    queue_of_node *new_node;
    new_node = malloc(sizeof(queue_of_node));

    new_node->index = v;
    new_node->next = NULL;

    if (Head == NULL)
    {
        Head = new_node;
    }
    else
    {
        Tail->next = new_node;
    }
    Tail = new_node;
}

node dequeue()
{
    queue_of_node *ptr = Head;
    node temp = Head->index;
    Head = Head->next;
    free(ptr);
    return temp;
}

int isEmpty()
{
    if (Head == NULL)
        return 1;
    else
        return 0;
}

void knapsack()
{
    node u, v;

    v.level = 0;
    v.profit = 0;
    v.weight = 0;

    maxprofit = 0;
    maxweight = 0;
    enqueue(v);

    while (!isEmpty())
    {
        v = dequeue();

        u.level = v.level + 1;
        u.weight = v.weight + w[u.level];
        u.profit = v.profit + p[u.level];

        if (u.weight <= W && u.profit > maxprofit)
        {
            maxprofit = u.profit;
            maxweight = u.weight;
        }

        if (bound(u) > maxprofit)
        {
            enqueue(u);
        }
        u.weight = v.weight;
        u.profit = v.profit;
        if (bound(u) > maxprofit)
        {
            enqueue(u);
        }
    }
}

float bound(node u)
{
    int j, k;
    int totweight;
    float result;

    if (u.weight >= W)
    {
        return 0;
    }
    else
    {
        result = u.profit;
        j = u.level + 1;
        totweight = u.weight;
        while (j <= n && totweight + w[j] <= W)
        {
            totweight += w[j];
            result += p[j];
            j++;
        }
        k = j;
        if (k <= n)
        {
            result += (W - totweight) * (float)p[k] / w[k];
        }
        return result;
    }
}