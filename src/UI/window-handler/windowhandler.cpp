#include "windowhandler.h"
#include "../menu/menu.h"
#include "../tasks/taskpage.h"


void window_handler::main_loop(){
    bool running = true;
    Menu menu  = Menu() ;
    TaskTab task_tab  ;
    task_tab.addTask("task1" , "sex in yard", false) ;
    task_tab.addTask("task2" , "MOVE YO FUCKING ASS", false) ;
    while(running){
        switch (this->window) {
            case -1 :
                this->window = menu.mainloop();
                menu.sh(); // shutdown
                break;
            case 0 :
                this->window =task_tab.main_loop(&task_tab);
                break;
            case 999:
                running = false;
                break;
        }
    }
}

void window_handler::start(){
    switch(this->window){
        case -1 :
        this->main_loop();
    }
}
