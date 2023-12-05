#include "view.h"

View::View(Model* model, Console* console) {
    this->console_ = console;
    this->console_->get_size(&this->screen_size_x_, &this->screen_size_y_);
    this->content_window_id_ = console->add_window(0, 0, this->screen_size_y_ - 1, this->screen_size_x_, 0);
    this->command_window_id_ = console->add_window(this->screen_size_y_ - 1, 0, 1, this->screen_size_x_, 1);
    this->console_->set_active_window(this->content_window_id_);
    this->model_ = model;
    this->model_->attach(this);
}

void View::update() {
    unsigned char mode = this->model_->get_mode();
    if (mode == 0) {
        std::pair<int, int> cursor_position = this->model_->get_cursor();
        console_->set_cursor(this->content_window_id_, cursor_position.first, cursor_position.second);
        console_->refresh_window(this->content_window_id_);
        console_->write_window(command_window_id_, model_->get_command());
        console_->refresh_window(command_window_id_);
    }
    else if (mode == 1) {
        // Depend on command size
    }


    /*console_->clear_window(command_window_id_);
    console_->write_window(command_window_id_, model_->get_command());
    console_->refresh_window(command_window_id_);*/
}