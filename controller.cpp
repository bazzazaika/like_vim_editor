#include "controller.h"
#include "curses.h"
#include "3.h"
//get input, do something которые мы делали в main теперь реализуем тут

Controller::Controller(Model* model, Console* console) {
    this->model_ = model;
    this->console_ = console;
}

void Controller::handler() {
    while (1)
    {
        int input = this->console_->get_input();
        unsigned char mode = this->model_->get_mode();

        if ((input & (KEY_LEFT | KEY_RIGHT)) == input) {
            if ((mode & (MOVE_COMMAND_MODE | INSERT_COMMAND_MODE)) == mode) {
                switch (input)
                {
                case KEY_LEFT:
                    this->model_->set_mode(MOVE_COMMAND_MODE);
                    this->model_->cursor_move_left();
                    break;

                case KEY_RIGHT:
                    this->model_->set_mode(MOVE_COMMAND_MODE);
                    this->model_->cursor_move_right();
                    break;

                default:
                    break;
                }
            }
            else if ((mode & (MOVE_CONTENT_MODE | INSERT_CONTENT_MODE)) == mode) {
                switch (input)
                {
                case KEY_UP:
                    this->model_->set_mode(MOVE_CONTENT_MODE);
                    this->model_->cursor_move_up();
                    break;

                case KEY_DOWN:
                    this->model_->set_mode(MOVE_CONTENT_MODE);
                    this->model_->cursor_move_down();
                    break;

                case KEY_LEFT:
                    this->model_->set_mode(MOVE_CONTENT_MODE);
                    this->model_->cursor_move_left();
                    break;

                case KEY_RIGHT:
                    this->model_->set_mode(MOVE_CONTENT_MODE);
                    this->model_->cursor_move_right();
                    break;

                default:
                    break;
                }
            }
        }
        else if ('!' <= input && input <= '~') {
            if ((mode & (MOVE_COMMAND_MODE | INSERT_COMMAND_MODE)) == mode) {
                this->model_->set_mode(INSERT_COMMAND_MODE);
                this->model_->insert_to_command((char)input);
            }
            else if ((mode & (MOVE_CONTENT_MODE | INSERT_CONTENT_MODE)) == mode) {
                this->model_->set_mode(INSERT_CONTENT_MODE);
                this->model_->insert_to_content((char)input);
            }   
            
        }
        else if (input == 27 /*ESC*/ ) {
            this->model_->change_window();
        }

        
        
        
    }
}