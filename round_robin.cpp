#include <bits/stdc++.h>
using namespace std;

// Class to represent a Job
class Job {
public:
    int id;
    int burstTime;
    int arrivalTime;
    int remainingTime;

    // Constructor
    Job(int jobId, int burst, int arrival) : id(jobId), burstTime(burst), arrivalTime(arrival), remainingTime(burst) {}
};

// Function to calculate waiting time and turnaround time for each Job
void calculateTimes(const vector<Job>& jobs, int quantum, vector<int>& waitingTimes, vector<int>& turnaroundTimes) {
    int n = jobs.size();
    vector<int> remainingTimes(n, 0);
    queue<Job> readyQueue;
    int currentTime = 0;
    int completedJobs = 0;

    for (int i = 0; i < n; i++) {
        remainingTimes[i] = jobs[i].burstTime;
    }

    while (completedJobs < n) {
        for (int i = 0; i < n; i++) {
            if (jobs[i].arrivalTime <= currentTime && remainingTimes[i] > 0) {
                int executionTime = min(quantum, remainingTimes[i]);
                remainingTimes[i] -= executionTime;
                currentTime += executionTime;

                if (remainingTimes[i] == 0) {
                    completedJobs++;
                    int waitingTime = currentTime - jobs[i].burstTime - jobs[i].arrivalTime;
                    int turnaroundTime = currentTime - jobs[i].arrivalTime;
                    waitingTimes[i] = waitingTime;
                    turnaroundTimes[i] = turnaroundTime;
                } else {
                    readyQueue.push(jobs[i]);
                }
            }
        }

        if (!readyQueue.empty()) {
            Job currentJob = readyQueue.front();
            readyQueue.pop();
            readyQueue.push(currentJob);
            currentTime++;
        } else {
            int minArrivalTime = INT_MAX;
            for (int i = 0; i < n; i++) {
                if (remainingTimes[i] > 0 && jobs[i].arrivalTime < minArrivalTime) {
                    minArrivalTime = jobs[i].arrivalTime;
                }
            }
            currentTime = minArrivalTime;
        }
    }
}

// Function to calculate average waiting time and average turnaround time
void calculateAverageTimes(const vector<int>& waitingTimes, const vector<int>& turnaroundTimes) {
    int n = waitingTimes.size();
    int totalWaitingTime = 0;
    int totalTurnaroundTime = 0;

    for (int i = 0; i < n; i++) {
        totalWaitingTime += waitingTimes[i];
        totalTurnaroundTime += turnaroundTimes[i];
    }

    double averageWaitingTime = static_cast<double>(totalWaitingTime) / n;
    double averageTurnaroundTime = static_cast<double>(totalTurnaroundTime) / n;

    cout << "Average Waiting Time: " << averageWaitingTime << endl;
    cout << "Average Turnaround Time: " << averageTurnaroundTime << endl;
}

// Function to display the job schedule table
void displayJobSchedule(const vector<Job>& jobs, const vector<int>& waitingTimes, const vector<int>& turnaroundTimes) {
    int n = jobs.size();

    cout << "Job Schedule Table:\n";
    cout << "----------------------------------------------------\n";
    cout << "Job ID\tBurst Time\tWaiting Time\tTurnaround Time\n";
    cout << "----------------------------------------------------\n";
    for (int i = 0; i < n; i++) {
        cout << jobs[i].id << "\t" << jobs[i].burstTime << "\t\t" << waitingTimes[i] << "\t\t" << turnaroundTimes[i] << endl;
    }
    cout << "----------------------------------------------------\n";
}

int main() {
    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;

    vector<Job> jobs;
    vector<int> waitingTimes(n);
    vector<int> turnaroundTimes(n);

    cout << "Enter the burst time and arrival time for each job:\n";
    for (int i = 0; i < n; i++) {
        int burst, arrival;
        cout << "Job " << i + 1 << " burst time: ";
        cin >> burst;
        cout << "Job " << i + 1 << " arrival time: ";
        cin >> arrival;
        jobs.push_back(Job(i + 1, burst, arrival));
    }

    int quantum;
    cout << "Enter the time quantum: ";
    cin >> quantum;

    // Calculate waiting time and turnaround time for each job
    calculateTimes(jobs, quantum, waitingTimes, turnaroundTimes);

    // Calculate average waiting time and average turnaround time
    calculateAverageTimes(waitingTimes, turnaroundTimes);

    // Display the job schedule table
    displayJobSchedule(jobs, waitingTimes, turnaroundTimes);

    return 0;
}