#include <iostream>
#include <ncurses.h>
#include "./menu/menu.h"
#include "./tasks/taskpage.h"
#include "../models/Task.h"

class window_handler{
    private:
    /*
     * windows = 0 --> main menu / Timer
     * window = 1 -->  Task menu
     *
     */
        int window = 0 ;

    public:
        void main_loop(){
            //TEST
            TaskQueue tasks = TaskQueue() ;
            tasks.addTask("task1" , "sex in yard", false) ;
            tasks.addTask("task2" , "sex in yard", false) ;


            bool running = true;
            Menu menu  = Menu() ;
            TaskTab task_tab ;
            while(running){
                switch (this->window) {
                    case 0 :

                        this->window = menu.mainloop();
                        menu.sh();
                        break;

                    case 1 :
                    this->window =task_tab.print_TaskList(&tasks) ;
                        break;
                    case 999:
                        running = false;
                        break;
                }
            }
        }


        void start(){
            switch(this->window){
                case 0 :
                this->main_loop();

            }
        }


};




int main(){ // just for debugging
    window_handler winHanlder ;
    winHanlder.start();
}
