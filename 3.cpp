#pragma once
#include "model.h"
#include "view.h"
#include "curses_adapter.h"
#include <iostream>
#include "controller.h"
#include "console.h"

int main() {
    Model model;
    CursesAdapter adapter;
    View view(&model, &adapter);
    Controller controller(&model, &adapter);
    controller.handler();
    /*adapter.get_input();
    model.do_something();
    adapter.get_input();*/

    

    return 0;
}