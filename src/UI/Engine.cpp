#include <iostream>
#include <ncurses.h>
#include "../models/Task.h"

// #define KEY_UP 10
// #define KEY_DOWN 11
// #define KEY_LEFT 12
// #define KEY_RIGHT 13
// #define KEY_ENTER 14




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
     */
        int section = 0 ;
        NcursesManager manager = NcursesManager();

        Menu(){
            if(!manager.isInitialized()){
                std::cout << "constructor is called \n\n" ;
                manager.init();

            }
            keypad(stdscr, TRUE);
            noecho() ;
        }
        ~Menu(){
            if(manager.isInitialized()){
                manager.shutdown();
            }
            std::cout<< "destructor is called \n"  ;
        }
        void print_menu(){
            move(0,0);
            printw("-------FSA-------\n");
            if(this->section == 0 ){
                attron(A_BLINK) ;
                printw("     >Tasks<\n");
                attroff(A_BLINK);
                printw("     >Timer<\n");
            }
            else if (this->section == 1 ) {
                printw("     >Tasks<\n");
                attron(A_BLINK) ;
                printw("     >Timer<\n");
                attroff(A_BLINK) ;
            }
            refresh();
        }

        void handle_key(int ch ){
            switch (ch) {
                case  KEY_UP :
                    if(section != 0){
                        this->section = 0;
                    }
                    break ;
                case KEY_DOWN :
                    if(section != 1) {
                        this->section = 1 ;
                    }
                    break;
            }

        }


        void mainloop(){
            int ch ;
            this->print_menu();

            while((ch = getch()) != 'q'){
                this->handle_key(ch);
                this->print_menu();


            }
        }
};


int main(){ // just for debugging
    Menu menu = Menu() ;
    menu.mainloop();

}
