#include <ncurses.h>
#include <iostream>
#include "menu.h"





        Menu::Menu(){
            if(!manager.isInitialized()){
                std::cout << "constructor is called \n\n" ;
                manager.init();

            } // TODO : I THINK WE DONT NEED THIS
            keypad(stdscr, TRUE);
            noecho() ;
        }
        void Menu::sh(){
            if(manager.isInitialized()){
                manager.shutdown();
            }
            std::cout<< "destructor is called \n"  ;
        }


        void Menu::print_menu(){
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

        void Menu::handle_key(int ch ){
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


        int Menu::mainloop(){
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
