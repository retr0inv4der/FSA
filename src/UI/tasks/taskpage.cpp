#include "taskpage.h"
#include "../../models/Task.h"
#include <ncurses.h>



int TaskTab::print_TaskList(TaskQueue* queue ){
    clear();
    //get the task queue
    printw("---Task List---\n") ;
    refresh() ;
    for(int i = 0 ; i < queue->getSize() ; i ++) {
        if(i == this->selected){
          printw("   >%s<   \n" , queue->GetTask(i).name) ;
        }else{
          printw("    %s\n" , queue->GetTask(i).name); 
        }

    }
    refresh();
    return 999;
}
int TaskTab::print_TaskDes() { 
    // 17 + 
    move(0 , 17) ; 
    printw("--- Description ---\n");
    move(1,17) ; 
    printw(this->GetTask(this->selected).desc);
    return 0 ; 
}

int TaskTab::print_status(){
    move(0 , 34) ;
    printw("--- status ---\n");
    move(1,34) ;
    return 0 ; 
}

int TaskTab::handle_key(int ch) {
    switch (ch) {
        case 'q' : 
            return -1 ; // return back to the menu 
            break;
        case KEY_UP : 
            if(this->selected > 0) this->selected -=1; 
            break ; 
        case KEY_DOWN : 
            if(this->selected < this->getSize()-1) this->selected+=1 ; 
    } 
    return 0 ;  

} 


int TaskTab::main_loop(TaskQueue* queue){
    int ch ; 
    while(this->running){
        this->print_TaskList( queue); 
        this->print_TaskDes();
        this->print_status() ;
        ch = getch(); 
        if(this->handle_key(ch) == -1){
            return -1 ;
        } 
  }
  
   return -10 ; 
} 
