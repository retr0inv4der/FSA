#ifndef MENU_H
#define MENU_H
#include "../NcManager/NcManager.h"
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

        Menu();
        void sh();
        void print_menu();
        void handle_key(int ch );
        int mainloop();
};
#endif
