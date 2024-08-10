#include <stdio.h>
const int max=10;
int s[10], x[10];
int d, flag=0;
void sumofsub(int m, int k, int r);

int main()
{
    int i, n, sum=0;
    printf("Enter maximum no\n");
    scanf("%d", &n);

    printf("Enter the set in increasing order\n");
    for(int i=1; i<=n; i++)
        scanf("%d", &s[i]);

    printf("Enter the maximum subset value:");
    scanf("%d", &d);

    for(i=1; i<=n; i++)
        sum += s[i];

    if(sum < d || s[1] > d)
    {
        printf("No subset possible\n");
        flag = 1;
    }
    sumofsub(0, 1, sum);
    if(flag == 0)
        printf("no subset possible\n");
    return 0;
}

void sumofsub(int m, int k, int r)
{
    x[k] = 1;
    if((m + s[k]) == d)
    {
        printf("{");
        for(int i = 1; i <= k; i++)
            if(x[i] == 1)
                printf(" %d ", s[i]);
        flag = 1;
        printf("}");
        printf("\n");
    }
    else 
    {
        if(m + s[k] + s[k+1] <= d)
            sumofsub(m + s[k], k+1, r - s[k]);
        if((m + r - s[k] >= d) && (m + s[k+1] <= d))//if, after excluding the current element s[k], the remaining elements can still potentially sum to d.
        {
            x[k] = 0;
            sumofsub(m, k+1, r - s[k]);
        }
    }
}
/*Let's say you have a set s[] = {0, 1, 3, 4, 5} and you are looking for subsets that sum up to d = 7.

Assume that during the recursive process, the program identifies that the subset {3, 4} sums to 7.

x[] might look like this during that state: {0, 0, 1, 1, 0}, where:
x[2] = 1 means s[2] = 3 is part of the subset.
x[3] = 1 means s[3] = 4 is part of the subset.*/