#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Process
{
    int processId;
    int arrivalTime;
    int burstTime;
    int waitingTime;
    int turnaroundTime;
};

void calculateTimes(vector<Process> &processes)
{
    processes[0].waitingTime = 0;
    processes[0].turnaroundTime = processes[0].burstTime;

    for (size_t i = 1; i < processes.size(); ++i)
    {
        processes[i].waitingTime = processes[i - 1].waitingTime + processes[i - 1].burstTime;
        processes[i].turnaroundTime = processes[i].waitingTime + processes[i].burstTime;
    }
}

void displayResults(const vector<Process> &processes)
{
    cout << "\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (const Process &process : processes)
    {
        cout << process.processId << "\t\t" << process.arrivalTime << "\t\t"
             << process.burstTime << "\t\t" << process.waitingTime << "\t\t"
             << process.turnaroundTime << endl;
    }
}

int main()
{
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> processes(n);

    cout << "Enter arrival time and burst time for each process:\n";
    for (int i = 0; i < n; ++i)
    {
        processes[i].processId = i + 1;
        cout << "Process " << i + 1 << " - Arrival Time: ";
        cin >> processes[i].arrivalTime;
        cout << "Process " << i + 1 << " - Burst Time: ";
        cin >> processes[i].burstTime;
    }

    // Sort processes based on arrival time
    sort(processes.begin(), processes.end(), [](const Process &a, const Process &b)
         { return a.arrivalTime < b.arrivalTime; });

    calculateTimes(processes);
    displayResults(processes);

    return 0;
}
