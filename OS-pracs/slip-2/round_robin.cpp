#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Process
{
    int processId;
    int burstTime;
    int remainingBurstTime;
};

void roundRobinScheduling(vector<Process> &processes, int timeQuantum)
{
    queue<Process> processQueue;

    for (auto &process : processes)
    {
        process.remainingBurstTime = process.burstTime;
        processQueue.push(process);
    }

    int currentTime = 0;

    while (!processQueue.empty())
    {
        Process currentProcess = processQueue.front();
        processQueue.pop();

        int executionTime = min(timeQuantum, currentProcess.remainingBurstTime);

        currentTime += executionTime;
        currentProcess.remainingBurstTime -= executionTime;

        cout << "Process " << currentProcess.processId << " executed for " << executionTime << " units of time." << endl;

        if (currentProcess.remainingBurstTime > 0)
        {
            processQueue.push(currentProcess);
        }
    }
}

int main()
{
    int n, timeQuantum;

    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> processes(n);

    cout << "Enter burst time for each process:\n";
    for (int i = 0; i < n; ++i)
    {
        processes[i].processId = i + 1;
        cout << "Process " << i + 1 << ": ";
        cin >> processes[i].burstTime;
    }

    cout << "Enter the time quantum: ";
    cin >> timeQuantum;

    roundRobinScheduling(processes, timeQuantum);

    return 0;
}
