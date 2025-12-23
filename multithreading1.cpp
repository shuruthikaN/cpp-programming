#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
using namespace std;

mutex coutMutex; // Protects console output

void task(int id)
{
    // Lock console to avoid interleaved output
    lock_guard<mutex> lock(coutMutex);
    cout << "Thread running: " << id << endl;
}

int main()
{
    const int numThreads = 2;
    vector<thread> threads;

    for (int i = 1; i <= numThreads; ++i)
        threads.emplace_back(task, i);

    // Join all threads
    for (auto &t : threads)
        t.join();

    return 0;
}

