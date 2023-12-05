#pragma once

#include "iobserver.h"
#include <vector>
#include <iostream>

#include "MyString.h"
#pragma comment(lib, "mystring_lib.lib")


class Model {
private:
    unsigned char mode_; // 0 - Navigation mode; 1 - Command mode; 2 - Find mode; 3 - Write mode
    std::vector<MyString> content_;
    MyString command_;
    std::pair<int, int> cursor_position_; // y, x - only for content window
    // Observer
    std::vector<IObserver*> observers_;
    void notify();
public:
    Model();
    unsigned char get_mode() const;
    const std::vector<MyString>& get_content() const;
    const MyString& get_command() const;
    // Cursor
    const std::pair<int, int>& get_cursor() const;
    void cursor_move_up();
    void cursor_move_down();
    void cursor_move_left();
    void cursor_move_right();
    // Another logic
    void do_something();
    // Observer
    void attach(IObserver* observer);
    void detach(IObserver* observer);

    //text

};