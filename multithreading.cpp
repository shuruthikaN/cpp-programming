#include <iostream>
#include <thread>
using namespace std;

void task(int id)
{
    cout << "Thread running: " << id << endl;
}

int main()
{
    thread t1(task, 1);
    thread t2(task, 2);

    t1.join();
    t2.join();

    return 0;
}

