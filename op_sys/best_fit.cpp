#include <iostream>
#include <vector>

using namespace std;

struct Segment {
    int id;
    int size;
    bool allocated;

    Segment(int _id, int _size) : id(_id), size(_size), allocated(false) {}
};

vector<Segment> segments;
vector<int> memory;

// Function to initialize the memory and segments
void initializeMemory(int memorySize) {
    memory.resize(memorySize, -1);

    segments.clear();
    segments.push_back(Segment(0, memorySize));
}

// Function to allocate memory using best fit algorithm for paging
void allocateMemoryPaging(int processId, int processSize) {
    int bestFitIdx = -1;
    int minFragmentation = memory.size();

    for (int i = 0; i < segments.size(); ++i) {
        if (!segments[i].allocated && segments[i].size >= processSize) {
            int fragmentation = segments[i].size - processSize;

            if (fragmentation < minFragmentation) {
                minFragmentation = fragmentation;
                bestFitIdx = i;
            }
        }
    }

    if (bestFitIdx != -1) {
        // Allocate memory
        memory[bestFitIdx] = processId;
        segments[bestFitIdx].allocated = true;
        cout << "Process " << processId << " allocated in segment " << bestFitIdx << endl;
    } else {
        cout << "Insufficient memory to allocate process " << processId << endl;
    }
}

// Function to display memory allocation status
void displayMemoryStatus() {
    cout << "Memory Status:" << endl;
    for (int i = 0; i < segments.size(); ++i) {
        if (segments[i].allocated) {
            cout << "Segment " << i << " : Process " << memory[i] << endl;
        } else {
            cout << "Segment " << i << " : Free" << endl;
        }
    }
    cout << endl;
}

int main() {
    int memorySize, numSegments, numProcesses;

    cout << "Enter memory size: ";
    cin >> memorySize;

    initializeMemory(memorySize);

    cout << "Enter the number of segments: ";
    cin >> numSegments;

    cout << "Enter the sizes of segments: " << endl;
    for (int i = 0; i < numSegments; ++i) {
        int segmentSize;
        cin >> segmentSize;
        segments.push_back(Segment(i + 1, segmentSize));
    }

    cout << "Enter the number of processes: ";
    cin >> numProcesses;

    cout << "Enter the sizes of processes: " << endl;
    for (int i = 0; i < numProcesses; ++i) {
        int processSize;
        cin >> processSize;

        allocateMemoryPaging(i + 1, processSize);
        displayMemoryStatus();
    }

    return 0;
}
