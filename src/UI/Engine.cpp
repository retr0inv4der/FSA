#include <iostream>
#include <ncurses.h>
#include "./menu/menu.h"
#include "./tasks/taskpage.h"
#include "../models/Task.h"
#include "NcManager/NcManager.h"

class window_handler{
    private:
    /*
     * window = -1 --> main menu
     * windows = 0 -->   Timer
     * window = 1 -->  Task menu
     *
     */
        int window = -1 ;

    public:
        void main_loop(){


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


        void start(){
            switch(this->window){
                case -1 :
                this->main_loop();

            }
        }


};




int main(){ 
    NcursesManager ncmanager = NcursesManager(); 
    // just for debugging
    window_handler winHanlder ;
    winHanlder.start();
    ncmanager.shutdown(); 
}
