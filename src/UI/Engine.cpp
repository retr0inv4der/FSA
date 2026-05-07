#include <iostream>
#include <ncurses.h>
#include "../models/Task.h"
#include "./menu/menu.h"


class window_handler{
    private:
    /*
     * windows = 0 --> main menu
     * window = 1 -->  timer menu
     *
     */
        int window = 0 ;

    public:
        void menu_main_loop(){
            Menu menu = Menu();

            int window ;
            window = menu.mainloop();
            menu.sh() ; // i gotta study destructors tho ..
            std::cout << "[DEBUG] SIGNAL TO WIN:" << window  << std::endl;
        }


        void start(){
            switch(this->window){
                case 0 :
                this->menu_main_loop();

            }
        }


};




int main(){ // just for debugging
    window_handler winHanlder ;
    winHanlder.start();
}
