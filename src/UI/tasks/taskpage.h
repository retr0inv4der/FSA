#ifndef TP_H
#define TP_H
#include "../../models/Task.h"
#include "../NcManager/NcManager.h"


class TaskTab  : public TaskQueue{
    public:
        int selected = 0 ;
        static inline bool running = true ;
        NcursesManager manager = NcursesManager();//init the ncurses
        int handle_key(int ch) ;
        int main_loop() ;
        int print_TaskList();
        int print_TaskDes() ;
        int print_status() ;
        void add_task_dialog();
        void reset_states();
};

#endif
