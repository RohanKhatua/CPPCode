#include <bits/stdc++.h>
using namespace std;

class Job {
    public:
        int id;
        int burstTime;
        int arrivalTime;        

        Job(int id, int burstTime, int arrivalTime){
            this->id = id;
            this->burstTime = burstTime;
            this->arrivalTime = arrivalTime;
        }
};

void displayJobs(const vector<Job>& jobs){
    cout<<"Job ID\tBurst Time\tArrival Time\n";
    for (auto & job : jobs){
        cout<<job.id<<"\t"<<job.burstTime<<"\t\t"<<job.arrivalTime<<"\n";
    }
}

void arrangeByArrivalTime(vector<Job> &jobs){
    //Jobs are arranged in ascending order of arrival time
    sort(jobs.begin(), jobs.end(), [](Job a, Job b){
        if (a.arrivalTime==b.arrivalTime){
            return a.id<b.id;
        }
        return a.arrivalTime < b.arrivalTime;
    });
}

void arrangeFCFS(vector<Job> &jobs){
    //Jobs are arranged as a list of when the job starts and stops being processed by the CPU
    int currentTime = jobs[0].arrivalTime;
    int n = jobs.size();

    int totalTime = 0;
    for (auto job : jobs) {
        totalTime+=job.burstTime;
    }

    vector<pair<int, int>> jobTimes(n);
    int i=0;
    while (currentTime<=totalTime && i<n){
        if (currentTime<jobs[i].arrivalTime) currentTime++;
        jobTimes[i] = make_pair(currentTime, currentTime+jobs[i].burstTime);
        currentTime+=jobs[i].burstTime;
        i++;
    }

    int totalWaitingTime = 0;
    int totalTurnaroundTime = 0;

    cout<<"Job ID\tStart Time\tEnd Time\tWaiting Time\tTurnaround Time\n";
    for (int k=0;k<n;k++){
        int waitingTime = jobTimes[k].first - jobs[k].arrivalTime;
        int turnaroundTime = jobTimes[k].second - jobs[k].arrivalTime;
        totalWaitingTime+=waitingTime;
        totalTurnaroundTime+=turnaroundTime;
        cout<<jobs[k].id<<"\t"<<jobTimes[k].first<<"\t\t"<<jobTimes[k].second<<"\t\t"<<waitingTime<<"\t\t"<<turnaroundTime<<"\n";
    }



    cout<<"Average Waiting Time = "<<float(totalWaitingTime)/n<<endl;
    cout<<"Average Turnaround Time = "<<float(totalTurnaroundTime)/n;
}

int main(){

    cout<<"Enter number of jobs: ";
    int n;
    cin>>n;

    vector<Job> jobs;

    for (int i=0;i<n;i++){
        cout<<"Enter burst time and arrival time for job "<<i+1<<": ";
        int id = i+1;
        int burstTime = 0;
        int arrivalTime = 0;
        cin>>burstTime>>arrivalTime;
        Job j = Job(id, burstTime, arrivalTime);
        jobs.push_back(j);
    }

    //Jobs are first arranged in order when they arrive
    arrangeByArrivalTime(jobs);

    cout<<"Arranged by Arrival Time : "<<endl;
    displayJobs(jobs);

    arrangeFCFS(jobs);

    return 0;
}

