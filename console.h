#pragma once
//#include <curses.h>
//#include "mystring.h"


#include <iostream>
#include "MyString.h"
#pragma comment(lib, "mystring_lib.lib")	

class Console {
public:
    virtual ~Console() {};
    virtual void get_size(unsigned int* x, unsigned int* y) = 0;
    virtual unsigned int add_window(unsigned int sy, unsigned int sx,
        int h, int w, int color_pair) = 0;
    virtual void delete_window(unsigned int window_id) = 0;
    virtual void clear_window(unsigned int window_id) = 0;
    virtual void write_window(unsigned int window_id, const MyString& str, unsigned int y) = 0;
    virtual void refresh_window(unsigned int window_id) = 0;
    virtual void set_active_window(unsigned int window_id) = 0;
    virtual void set_cursor(unsigned int window_id, unsigned int y, unsigned int x) = 0;
    //virtual void init_cursor(unsigned int window_id, unsigned int y, unsigned int x) = 0;
    virtual int get_input() = 0;
};