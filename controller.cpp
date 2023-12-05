#include "controller.h"
#include "curses.h"

//get input, do something которые мы делали в main теперь реализуем тут

Controller::Controller(Model* model, Console* console) {
    this->model_ = model;
    this->console_ = console;
}

void Controller::handler() {
    while (1)
    {
        int input = this->console_->get_input();
        if (input & (KEY_UP | KEY_DOWN| KEY_LEFT| KEY_RIGHT)) {
            switch (input)
            {
            case KEY_UP:
                this->model_->cursor_move_up();
                break;

            case KEY_DOWN:
                this->model_->cursor_move_down();
                break;

            case KEY_LEFT:
                this->model_->cursor_move_left();
                break;

            case KEY_RIGHT:
                this->model_->cursor_move_right();
                break;

            default:
                break;
            }
        }
        else if ('!'<= input && input<='~') {

        }
        
    }
}