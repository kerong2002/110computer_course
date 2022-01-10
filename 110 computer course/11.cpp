#include <cstdio>
#include <iostream>

using namespace std;
int N, i, j, disti, distj, k;
int main(int argc, char *argv[])
{
    while (cin >> N)
    {
        if(N<=0 or N>9)break;
        //for i in range(1,2*N):
        for (i = 1; i < 2 * N; i++)
        {
            //for j in range(1,2*N):
            for (j = 1; j < 2 * N; j++)
            {
                disti = 0;
                distj = 0;
                k = 0;
                if (i >= N)
                    disti = i - N;
                else
                    disti = N - i;
                if (j >= N)
                    distj = j - N;
                else
                    distj = N - j;
                if (disti >= distj)
                    k = disti;
                else
                    k = distj;
                printf("%d", k + 1);
            }
            cout << "\n";
        }
    }
}
