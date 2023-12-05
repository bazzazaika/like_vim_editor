#pragma once
#include "iobserver.h"
#include "console.h"
#include "model.h"


class View : public IObserver {
public:
    View(Model* model, Console* console);
    ~View() {};
    virtual void update() override;
private:
    unsigned int screen_size_x_, screen_size_y_;
    unsigned int header_window_id_;
    unsigned int content_window_id_;
    unsigned int command_window_id_;
    Console* console_;
    Model* model_;
};