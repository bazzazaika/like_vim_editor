#include "model.h"


Model::Model() {
    this->command_ = "";
    this->content_.push_back("");
    this->mode_ = 0;
    this->cursor_position_ = { 0,0 };
    this->cursor_position_content_ = { 0,0 };
    this->cursor_position_command_ = { 0,0 };
    this->cur_index_content_ = 0;
    this->upper_index_ = 0;
    this->lower_index_ = 0;
}

unsigned char Model::get_mode() const {
    return this->mode_;
}

const MyString& Model::get_content() const {
    return this->content_[cur_index_content_];
}

const MyString& Model::get_command() const {
    return this->command_;
}

const std::pair<int, int>& Model::get_cursor() const {
    return this->cursor_position_;
}

void Model::cursor_move_up() {
    this->cursor_position_.first--;
    this->notify();
}

void Model::cursor_move_down() {
    this->cursor_position_.first++;
    this->notify();
}
void Model::cursor_move_left() {
    this->cursor_position_.second--;
    this->notify();
}
void Model::cursor_move_right() {
    this->cursor_position_.second++;
    this->notify();
}

void Model::cursor_move_next_line() {
    cursor_position_.first++;
    cursor_position_.second = 0;
    this->notify();
}



void Model::do_something() {
    this->command_ = "Finish";
    notify();
}

// ==========================================================================
// =============================== Observer =================================
// ========================================================================== 

void Model::attach(IObserver* observer) {
    this->observers_.push_back(observer);
    observer->get_size(&max_x_, &max_y_);
    observer->update();
}

void Model::detach(IObserver* observer) {
    std::vector<IObserver*>::const_iterator i;
    i = find(this->observers_.begin(), this->observers_.end(), observer);
    this->observers_.erase(i);
}

void Model::notify()
{
    for (int i = 0; i < observers_.size(); i++)
        observers_[i]->update();

}



// ==========================================================================
// =============================== Text =================================
// ========================================================================== 

void Model::insert_to_content(char c) {

    if (this->content_[cur_index_content_].size() >= max_x_) {
        cur_index_content_++;
        this->content_.push_back("");
        this->cursor_move_next_line();
    }
    this->content_[cur_index_content_].insert(this->cursor_position_.second, 1, c);
    //this->command_.append(1, c);
    this->cursor_move_right();
}



// ==========================================================================
// =============================== command =================================
// ========================================================================== 

void Model::insert_to_command(char c) {
    this->command_.insert(this->cursor_position_.second,1,c);
    //this->command_.append(1, c);
    this->cursor_move_right();
}

// ==========================================================================
// =============================== mode =================================
// ========================================================================== 

void Model::set_mode(unsigned char mode) {
    this->mode_ = mode;
}

void Model::change_window() {
    for (int i = 0; i < observers_.size(); i++)
        observers_[i]->change_window();

}


void Model::save_and_change_pos_command() {
    this->cursor_position_command_ = this->cursor_position_;
    this->cursor_position_ = this->cursor_position_content_;
}

void Model::save_and_change_pos_content() {
    this->cursor_position_content_ = this->cursor_position_;
    this->cursor_position_ = this->cursor_position_command_;
}