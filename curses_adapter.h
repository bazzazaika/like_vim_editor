#pragma once

#include "console.h"
#include <vector>
#include <curses.h>

#include "MyString.h"
#pragma comment(lib, "mystring_lib.lib")

class CursesAdapter : public Console {
private:
	std::vector<WINDOW*> windows_;
	WINDOW* active_window_;
public:
	CursesAdapter();
	virtual ~CursesAdapter() override;
	virtual void get_size(unsigned int* x, unsigned int* y) override;
	virtual unsigned int add_window(unsigned int sy, unsigned int sx,
		int h, int w, int color_pair) override;
	virtual void delete_window(unsigned int window_id) override;
	virtual void clear_window(unsigned int window_id) override;
	virtual void write_window(unsigned int window_id, const MyString& str, unsigned int y) override;
	virtual void refresh_window(unsigned int window_id) override;
	virtual void set_active_window(unsigned int window_id) override;
	virtual void set_cursor(unsigned int window_id, unsigned int y, unsigned int x) override;
	virtual int get_input() override;

	//virtual void init_cursor(unsigned int window_id, unsigned int y, unsigned int x) override;
};