#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// Class to represent a Job
class Job {
public:
    int id;
    int burstTime;
    int arrivalTime;
    int priority;

    // Constructor
    Job(int jobId, int burst, int arrival, int pri) : id(jobId), burstTime(burst), arrivalTime(arrival), priority(pri) {}
};

// Structure to compare Jobs based on their priority
struct CompareJob {
    bool operator()(const Job& job1, const Job& job2) {
        return job1.priority > job2.priority;
    }
};

// Function to calculate waiting time, turnaround time, starting time, and ending time for each Job
void calculateTimes(const vector<Job>& jobs, vector<int>& waitingTimes, vector<int>& turnaroundTimes, vector<int>& startingTimes, vector<int>& endingTimes) {
    int n = jobs.size();
    vector<int> remainingTimes(n, 0);
    priority_queue<Job, vector<Job>, CompareJob> pq;

    for (int i = 0; i < n; i++) {
        remainingTimes[i] = jobs[i].burstTime;
    }

    int completedJobs = 0;
    int currentTime = 0;
    int prevJobId = -1;

    while (completedJobs < n) {
        for (int i = 0; i < n; i++) {
            if (jobs[i].arrivalTime <= currentTime && remainingTimes[i] > 0 && i != prevJobId) {
                pq.push(jobs[i]);
            }
        }

        if (!pq.empty()) {
            Job currentJob = pq.top();
            pq.pop();

            if (prevJobId != -1 && remainingTimes[prevJobId] > 0) {
                pq.push(jobs[prevJobId]);
            }

            if (startingTimes[currentJob.id - 1] == -1) {
                startingTimes[currentJob.id - 1] = currentTime;
            }

            remainingTimes[currentJob.id - 1]--;
            prevJobId = currentJob.id - 1;

            if (remainingTimes[prevJobId] == 0) {
                completedJobs++;
                int finishTime = currentTime + 1;
                int waitingTime = finishTime - jobs[prevJobId].burstTime - jobs[prevJobId].arrivalTime;
                int turnaroundTime = finishTime - jobs[prevJobId].arrivalTime;

                waitingTimes[prevJobId] = waitingTime;
                turnaroundTimes[prevJobId] = turnaroundTime;
                endingTimes[prevJobId] = finishTime;
                prevJobId = -1;
            }
        }

        currentTime++;
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
void displayJobSchedule(const vector<Job>& jobs, const vector<int>& startingTimes, const vector<int>& endingTimes, const vector<int>& waitingTimes, const vector<int>& turnaroundTimes) {
    int n = jobs.size();

    cout << "Job Schedule Table:\n";
    cout << "-----------------------------------------------------------\n";
    cout << "Job ID\tStarting Time\tEnding Time\tWaiting Time\tTurnaround Time\n";
    cout << "-----------------------------------------------------------\n";
    for (int i = 0; i < n; i++) {
        cout << jobs[i].id << "\t" << startingTimes[i] << "\t\t" << endingTimes[i] << "\t\t" << waitingTimes[i] << "\t\t" << turnaroundTimes[i] << endl;
    }
    cout << "-----------------------------------------------------------\n";
}

int main() {
    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;

    vector<Job> jobs;
    vector<int> waitingTimes(n);
    vector<int> turnaroundTimes(n);
    vector<int> startingTimes(n, -1);
    vector<int> endingTimes(n, -1);

    cout << "Enter the burst time, arrival time, and priority for each job:\n";
    for (int i = 0; i < n; i++) {
        int burst, arrival, priority;
        cout << "Job " << i + 1 << ":\n";
        cout << "Burst Time: ";
        cin >> burst;
        cout << "Arrival Time: ";
        cin >> arrival;
        cout << "Priority: ";
        cin >> priority;
        jobs.push_back(Job(i + 1, burst, arrival, priority));
    }

    // Sort jobs based on their arrival time
    sort(jobs.begin(), jobs.end(), [](const Job& job1, const Job& job2) {
        return job1.arrivalTime < job2.arrivalTime;
    });

    // Calculate waiting time, turnaround time, starting time, and ending time for each job
    calculateTimes(jobs, waitingTimes, turnaroundTimes, startingTimes, endingTimes);

    // Calculate average waiting time and average turnaround time
    calculateAverageTimes(waitingTimes, turnaroundTimes);

    // Display the job schedule table
    displayJobSchedule(jobs, startingTimes, endingTimes, waitingTimes, turnaroundTimes);

    return 0;
}
