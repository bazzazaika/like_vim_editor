#pragma once

class IObserver {
public:
    virtual void update() = 0;
    virtual void change_window() = 0;
    virtual void get_size(unsigned int* x, unsigned int* y) = 0;
};