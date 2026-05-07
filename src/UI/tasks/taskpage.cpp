#include "taskpage.h"
#include "../../models/Task.h"
#include <ncurses.h>


    int TaskTab::print_TaskList(TaskQueue* queue ){
        //get the task queue
        printw("---Task List---\n") ;
        refresh() ;
        for(int i = 0 ; i < queue->getSize() ; i ++) {
            printw("%s\n" , queue->GetTask(i).name) ;
        }
        refresh();
        getch();
        return 999;
    }
