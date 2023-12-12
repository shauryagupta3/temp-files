#include <iostream>
#include <climits>
#include <cstring>

using namespace std;

void worstFit(int blockSize[], int m, int processSize[], int n)
{
    int allocation[n];
    memset(allocation, -1, sizeof(allocation));

    for (int i = 0; i < n; i++)
    {
        int worstIdx = -1;
        for (int j = 0; j < m; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                if (worstIdx == -1 || blockSize[j] > blockSize[worstIdx])
                {
                    worstIdx = j;
                }
            }
        }

        if (worstIdx != -1)
        {
            allocation[i] = worstIdx;
            blockSize[worstIdx] -= processSize[i];
        }
    }

    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < n; i++)
    {
        cout << " " << i + 1 << "\t\t"
             << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
}

int main()
{
    int m, n;

    cout << "Enter the number of memory blocks: ";
    cin >> m;

    int blockSize[m];
    cout << "Enter sizes of memory blocks:\n";
    for (int i = 0; i < m; ++i)
    {
        cout << "Block " << i + 1 << ": ";
        cin >> blockSize[i];
    }

    cout << "Enter the number of processes: ";
    cin >> n;

    int processSize[n];
    cout << "Enter sizes of processes:\n";
    for (int i = 0; i < n; ++i)
    {
        cout << "Process " << i + 1 << ": ";
        cin >> processSize[i];
    }

    worstFit(blockSize, m, processSize, n);

    return 0;
}
