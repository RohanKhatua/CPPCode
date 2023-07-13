#include <bits/stdc++.h>
using namespace std;

int n;
int n_copy;

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

vector<Job> job_copy;

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

int findShortestJob(vector<Job> &jobs, int currentTime){
 
    int shortestJobIndex = -1;
    int shortestJobTime = INT_MAX;
    for (int i=0;i<n;i++){
        if (jobs[i].arrivalTime<=currentTime && jobs[i].burstTime<shortestJobTime){
            shortestJobIndex = i;
            shortestJobTime = jobs[i].burstTime;
        }
    }
    return shortestJobIndex;
}

void removeFinishedJobs(vector<Job> &jobs){

    for (int i=0;i<n;i++){
        if (jobs[i].burstTime==0){
            jobs.erase(jobs.begin()+i);
            i--;
            n--;
        }
    }
}

void arrangeSJF(vector<Job> &jobs){
    //Jobs are arranged as a list of when the job starts and stops being processed by the CPU
    int currentTime = jobs[0].arrivalTime;


    int totalTime = 0;
    for (auto job : jobs) {
        totalTime+=job.burstTime;
    }

    //maps a unit of time to a job
    map<int,int> timeJobMap;

    vector<pair<int, int>> jobTimes(n);

    int noJobDuration = 0;


    while (currentTime<=totalTime+noJobDuration && !jobs.empty()){
        removeFinishedJobs(jobs);
        int currentJobIndex = findShortestJob(jobs, currentTime);
        if (currentJobIndex!=-1) {
            timeJobMap[currentTime] = jobs[currentJobIndex].id;
            jobs[currentJobIndex].burstTime--;
        }
        else {
            noJobDuration++;
        }
        currentTime++;
    }

    vector<int> start_times(n_copy);
    vector<int> end_times(n_copy);

    for (int i=0;i<n_copy;i++){
        start_times[i]=INT_MAX;
        end_times[i]=INT_MIN;
    }

    
    //storing start and end times
    for (auto timeJobPair : timeJobMap){
        int jobIndex = timeJobPair.second-1;
        if (timeJobPair.first<start_times[jobIndex]){
            start_times[jobIndex] = timeJobPair.first;
        }
        if (timeJobPair.first>end_times[jobIndex]){
            end_times[jobIndex] = timeJobPair.first;
        }
    }    



    vector<int> waiting_times(n_copy);
    vector<int> turnaround_times(n_copy);

    for (int k=0;k<n_copy;k++){
        int waitingTime = start_times[k] - job_copy[k].arrivalTime;
        waiting_times[k] = waitingTime;
        int turnaroundTime = end_times[k] - job_copy[k].arrivalTime;
        turnaround_times[k] = turnaroundTime;

    }

    cout<<"Job ID\tStart Time\tEnd Time\tWaiting Time\tTurnaround Time\n";
    for (int i=0;i<n_copy;i++){
        cout<<job_copy[i].id<<"\t"<<start_times[i]<<"\t\t"<<end_times[i]<<"\t\t"<<waiting_times[i]<<"\t\t"<<turnaround_times[i]<<"\n";
    }

    cout<<"Average Waiting Time: "<<(float)accumulate(waiting_times.begin(), waiting_times.end(),0)/n_copy<<"\n";
    cout<<"Average Turnaround Time: "<<(float)accumulate(turnaround_times.begin(),turnaround_times.end(),0)/n_copy<<"\n";
}

int main(){
    cout<<"Enter number of jobs: ";
    
    cin>>n;
    n_copy = n;

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

    copy(jobs.begin(), jobs.end(), back_inserter(job_copy));
    //Jobs are first arranged in order when they arrive
    arrangeByArrivalTime(jobs);

    cout<<"Arranged by Arrival Time : "<<endl;
    displayJobs(jobs);

    arrangeSJF(jobs);

    return 0;
}

