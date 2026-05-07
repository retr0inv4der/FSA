#ifndef TP_H
#define TP_H
#include "../../models/Task.h"
#include "../NcManager/NcManager.h"
class TaskTab {
    public:
    NcursesManager manager = NcursesManager();//init the ncurses


    int print_TaskList(TaskQueue* queue );
    void print_TaskTab(TaskQueue* queue);
};
#endif
