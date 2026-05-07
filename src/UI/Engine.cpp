#include <iostream>
#include <ncurses.h>
#include "../models/Task.h"



class NcursesManager{
    private:
        bool isInit  = 0 ;

    public:
        NcursesManager(){
            initscr();
            this->isInit = true;
        }
        bool isInitialized(){return this->isInit ;}

        int init(){
             if(!isInit){
                 initscr();
                 this->isInit = true;
                 return 0;
             }
             return -1 ;
        }

        int shutdown(){
            if(isInit){
                endwin();
                this->isInit = false ;
                return 0 ;
            }
            return -1 ;
        }
};

class Menu{
    public:
    /*
     section 0 = TaskSection

     selected = 0 -> task section
     selected = 1 -> timer section
     */
        int section = 0 ;
        bool entered =false  ;
        int selected ;
        bool running = true;
        NcursesManager manager = NcursesManager();

        Menu(){
            if(!manager.isInitialized()){
                std::cout << "constructor is called \n\n" ;
                manager.init();

            }
            keypad(stdscr, TRUE);
            noecho() ;
        }
        void sh(){
            if(manager.isInitialized()){
                manager.shutdown();
            }
            std::cout<< "destructor is called \n"  ;
        }
        void print_menu(){
            // TODO : implement your own blinking animation.

            move(0,0);
            printw("-------FSA-------\n");
            if(this->section == 0 ){
                attron(A_BLINK | A_BOLD) ;
                printw("     >Tasks<\n");
                attroff(A_BLINK | A_BOLD);
                printw("      Timer \n");
            }
            else if (this->section == 1 ) {
                printw("      Tasks\n");
                attron(A_BLINK  | A_BOLD) ;
                printw("     >Timer<\n");
                attroff(A_BLINK| A_BOLD) ;
            }
            refresh();
        }

        void handle_key(int ch ){
            switch (ch) {
                case 'q':
                    this->running = false;
                    break;

                case  KEY_UP :
                    if(this->section != 0){
                        this->section = 0;
                    }
                    break ;

                case KEY_DOWN :
                    if(this->section != 1) {
                        this->section = 1 ;
                    }
                    break;

                case '\n' :
                    this->entered = true ;
                    this->selected = this->section ;
                    break ;
            }


        }


        int mainloop(){
            int ch ;
            this->print_menu();

            while(this->running){
                ch = getch();
                this->handle_key(ch);
                if(this->entered){
                    //return the page number to the window manager
                    break;
                }

                this->print_menu();
            }

            if(entered){
                this->entered = false;
                return this->selected;
            }
            return 999;
        }
};
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
            menu.sh() ;
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
