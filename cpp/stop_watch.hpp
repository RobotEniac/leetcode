#ifndef STOP_WATCH_HPP
#define STOP_WATCH_HPP
#pragma once

#include <iostream>
#include <chrono>

class StopWatch {
    using Clock = std::chrono::system_clock;
    using TimePoint = std::chrono::system_clock::time_point;
public:
    StopWatch() : s_(Clock::now()), last_(Clock::now()) {}

    ~StopWatch() {
        Elapse();
    }

    void Pause() {
        Elapse();
    }

private:
    void Elapse() {
        TimePoint ct = Clock::now();
        Clock::duration fs = ct - s_;
        uint64_t dfs = std::chrono::duration_cast<std::chrono::microseconds>(fs).count();
        Clock::duration fl = ct - last_;
        uint64_t dfl = std::chrono::duration_cast<std::chrono::microseconds>(fl).count();
        std::cout << "from start: " << dfs << ", from last: " << dfl << std::endl;
        last_ = ct;
    }

private:
    TimePoint s_;
    TimePoint last_;
};
#endif
