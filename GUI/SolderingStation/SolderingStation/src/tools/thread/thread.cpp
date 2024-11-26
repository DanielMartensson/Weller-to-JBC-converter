#include "thread.h"
#include <boost/thread.hpp>
#include <atomic>

static std::atomic<bool> run(false);
static std::atomic<THREAD_DATA*> threadData_;

void runThread() {
    while (run) {

    }
}

bool startThread() {
    run = true;
    boost::thread t(runThread);
    t.join();
    return true;
}

bool stopThread() {
    run = false;
    boost::this_thread::sleep_for(boost::chrono::seconds(1)); // Just a delay of 1 second so the thread will finish
    return true;
}

void setData(THREAD_DATA* threadData) {
    threadData_ = threadData_;
}

THREAD_DATA* getData() {
    return threadData_;
}