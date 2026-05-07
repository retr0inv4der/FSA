

#include "NcManager.h"
#include <ncurses.h>
 NcursesManager::NcursesManager(){
            if(!this->isInitialized()){
                initscr();
                this->isInit = true;
            }
        }
        bool NcursesManager::isInitialized(){return this->isInit ;}

        int NcursesManager::init(){
             if(!isInit){
                 initscr();
                 this->isInit = true;
                 return 0;
             }
             return -1 ;
        }

        int NcursesManager::shutdown(){
            if(isInit){
                endwin();
                this->isInit = false ;
                return 0 ;
            }
            return -1 ;
        }
