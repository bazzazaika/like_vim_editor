#include "view.h"
#include "3.h"

View::View(Model* model, Console* console) {
    this->console_ = console;
    this->console_->get_size(&this->screen_size_x_, &this->screen_size_y_);
    this->content_window_id_ = console->add_window(0, 0, this->screen_size_y_ - 1, this->screen_size_x_, 0);
    this->command_window_id_ = console->add_window(this->screen_size_y_ - 1, 0, 1, this->screen_size_x_, 1);
    this->console_->set_active_window(this->command_window_id_);
    this->console_->set_cursor(this->command_window_id_, this->screen_size_y_ - 1, 0);
    console_->refresh_window(this->command_window_id_);
    //console_->refresh_window(content_window_id_);
    this->model_ = model;
    this->model_->attach(this);
}

void View::update() {
    unsigned char mode = this->model_->get_mode();
    if (mode == INSERT_COMMAND_MODE) {//command mode
        std::pair<int, int> cursor_position = this->model_->get_cursor();
        
        console_->write_window(command_window_id_, model_->get_command(), cursor_position.first);
        console_->refresh_window(command_window_id_);

        console_->set_cursor(this->command_window_id_, cursor_position.first, cursor_position.second);
        console_->refresh_window(this->command_window_id_);
        
        
    }
    else if (mode == MOVE_COMMAND_MODE) {
        // Depend on command size
        std::pair<int, int> cursor_position = this->model_->get_cursor();
        console_->set_cursor(this->command_window_id_, cursor_position.first, cursor_position.second);
        console_->refresh_window(this->command_window_id_);
    }
    else if (mode == MOVE_CONTENT_MODE) {
        // Depend on command size
        std::pair<int, int> cursor_position = this->model_->get_cursor();
        console_->set_cursor(this->content_window_id_, cursor_position.first, cursor_position.second);
        console_->refresh_window(this->content_window_id_);
    }
    else if (mode == INSERT_CONTENT_MODE) {
        std::pair<int, int> cursor_position = this->model_->get_cursor();
        
        console_->write_window(content_window_id_, model_->get_content(), cursor_position.first);
        console_->refresh_window(content_window_id_);

        console_->set_cursor(this->content_window_id_, cursor_position.first, cursor_position.second);
        console_->refresh_window(this->content_window_id_);
        
    }
    /*console_->clear_window(command_window_id_);
    console_->write_window(command_window_id_, model_->get_command());
    console_->refresh_window(command_window_id_);*/
}


void View::change_window() {
    unsigned char mode = this->model_->get_mode();
    if ((mode & (MOVE_COMMAND_MODE | INSERT_COMMAND_MODE)) == mode) {
        this->model_->save_and_change_pos_command();
        this->console_->set_active_window(this->content_window_id_);
        console_->refresh_window(this->content_window_id_);
        this->model_->set_mode(INSERT_CONTENT_MODE);
    }
    else if ((mode & (MOVE_CONTENT_MODE | INSERT_CONTENT_MODE))==mode) {
        this->model_->save_and_change_pos_content();
        this->console_->set_active_window(this->command_window_id_);
        this->console_->refresh_window(this->command_window_id_);
        this->model_->set_mode(INSERT_COMMAND_MODE);
    }
    
}


void View::get_size(unsigned int* x, unsigned int* y) {
    *x = this->screen_size_x_;
    *y = this->screen_size_y_;
}