#include "curses_adapter.h"


CursesAdapter::CursesAdapter() {
    initscr(); // initialization of screen
    cbreak();  // don't use buffer for getch
    //raw(); 
    //nonl();
    noecho();
    // Colors
    start_color();
    use_default_colors();
    init_pair(1, COLOR_BLACK, COLOR_WHITE);
    init_pair(2, COLOR_CYAN, COLOR_BLACK);
    // Show
    refresh();
}

CursesAdapter::~CursesAdapter() {
    for (unsigned int i = 0; i < this->windows_.size(); i++) {
        delwin(this->windows_[i]);
    }
    endwin();
}

void CursesAdapter::get_size(unsigned int* x, unsigned int* y) {
    *x = getmaxx(stdscr);
    *y = getmaxy(stdscr);
}

void CursesAdapter::set_cursor(unsigned int window_id, unsigned int y, unsigned int x) {
    this->active_window_ = this->windows_[window_id];
    wmove(this->active_window_, y, x);
}

int CursesAdapter::get_input() {
    return wgetch(this->active_window_);
}

unsigned int CursesAdapter::add_window(unsigned int sy, unsigned int sx,
    int h, int w, int color_pair) {
    WINDOW* new_window = newwin(h, w, sy, sx);
    if (color_pair > 0)
        wbkgd(new_window, COLOR_PAIR(color_pair));
    keypad(new_window, TRUE);
    wrefresh(new_window);
    this->windows_.push_back(new_window);
    return this->windows_.size() - 1;
}

void CursesAdapter::delete_window(unsigned int window_id) {
    WINDOW* cur_window = this->windows_[window_id];
    this->windows_.erase(this->windows_.begin() + window_id);
    delwin(cur_window);
    refresh();
}

void CursesAdapter::write_window(unsigned int window_id, const MyString& str) {
    WINDOW* cur_window = this->windows_[window_id];
    mvwprintw(cur_window, 0, 0, str.c_str());
}

void CursesAdapter::clear_window(unsigned int window_id) {
    wclear(this->windows_[window_id]);
}

void CursesAdapter::refresh_window(unsigned int window_id) {
    wrefresh(this->windows_[window_id]);
}

void CursesAdapter::set_active_window(unsigned int window_id) {
    this->active_window_ = this->windows_[window_id];
}