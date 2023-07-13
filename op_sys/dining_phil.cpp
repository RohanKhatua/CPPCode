#include <iostream>
#include <mutex>
#include <condition_variable>
#include <thread>

const int numPhilosophers = 5;  // Number of philosophers

enum class State { THINKING, HUNGRY, EATING };

class DiningPhilosophers {
private:
    std::mutex mtx;
    std::condition_variable cv;
    State state[numPhilosophers];
    bool dependencies[numPhilosophers][numPhilosophers];

public:
    DiningPhilosophers() {
        for (int i = 0; i < numPhilosophers; i++) {
            state[i] = State::THINKING;
            for (int j = 0; j < numPhilosophers; j++) {
                dependencies[i][j] = false;
            }
        }
    }

    void setDependency(int philosopherId, int forkId) {
        dependencies[philosopherId][forkId] = true;
    }

    void test(int philosopherId) {
        // Check if all dependencies are satisfied for the philosopher
        bool canEat = true;
        for (int i = 0; i < numPhilosophers; i++) {
            if (dependencies[philosopherId][i] && state[i] != State::EATING) {
                canEat = false;
                break;
            }
        }

        if (state[philosopherId] == State::HUNGRY && canEat) {
            state[philosopherId] = State::EATING;
            cv.notify_all();
        }
    }

    void pickupForks(int philosopherId) {
        std::unique_lock<std::mutex> lock(mtx);
        state[philosopherId] = State::HUNGRY;
        std::cout << "Philosopher " << philosopherId << " is hungry." << std::endl;
        printWaitForGraph();  // Print the wait-for graph
        test(philosopherId);
        if (state[philosopherId] != State::EATING) {
            cv.wait(lock);
        }
    }

    void returnForks(int philosopherId) {
        std::unique_lock<std::mutex> lock(mtx);
        state[philosopherId] = State::THINKING;
        for (int i = 0; i < numPhilosophers; i++) {
            test(i);
        }
    }

    void printWaitForGraph() {
        std::cout << "Wait-for Graph Matrix:" << std::endl;
        for (int i = 0; i < numPhilosophers; i++) {
            for (int j = 0; j < numPhilosophers; j++) {
                std::cout << dependencies[i][j] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
};

void philosopher(DiningPhilosophers& dp, int philosopherId) {
    for (int i = 0; i < 5; i++) {
        // Thinking
        std::cout << "Philosopher " << philosopherId << " is thinking." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        // Pick up forks
        dp.pickupForks(philosopherId);
        std::cout << "Philosopher " << philosopherId << " picks up forks and starts eating." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        // Return forks
        dp.returnForks(philosopherId);
        std::cout << "Philosopher " << philosopherId << " returns forks and finishes eating." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

int main() {
    DiningPhilosophers dp;

    // Set dependencies using wait-for graph matrix
    dp.setDependency(0, 0);
    dp.setDependency(0, 4);
    dp.setDependency(1, 1);
    dp.setDependency(1, 0);
    dp.setDependency(2, 2);
    dp.setDependency(2, 1);
    dp.setDependency(3, 3);
    dp.setDependency(3, 2);
    dp.setDependency(4, 4);
    dp.setDependency(4, 3);

    std::thread philosophers[numPhilosophers];
    for (int i = 0; i < numPhilosophers; i++) {
        philosophers[i] = std::thread(philosopher, std::ref(dp), i);
    }

    for (int i = 0; i < numPhilosophers; i++) {
        philosophers[i].join();
    }

    return 0;
}
