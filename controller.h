#pragma once

#include "model.h"
#include "console.h"

class Controller {
private:
    Model* model_;
    Console* console_;

public:
    Controller(Model* model, Console* console);
    void handler();
};