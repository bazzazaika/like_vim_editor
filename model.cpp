#include "model.h"


Model::Model() {
    this->command_ = "";
    this->mode_ = 0;
    this->cursor_position_ = { 0,0 };
}

unsigned char Model::get_mode() const {
    return this->mode_;
}

const std::vector<MyString>& Model::get_content() const {
    return this->content_;
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

void Model::do_something() {
    this->command_ = "Finish";
    notify();
}

// ==========================================================================
// =============================== Observer =================================
// ========================================================================== 

void Model::attach(IObserver* observer) {
    this->observers_.push_back(observer);
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