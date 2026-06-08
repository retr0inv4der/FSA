#include "taskpage.h"
#include "../../models/Task.h"
#include <cstdio>
#include <cstdlib>
#include <ncurses.h>


int TaskTab::print_TaskList(){
    clear();
    //get the task queue
    printw("---Task List---\n") ;
    refresh() ;
    for(int i = 0 ; i < this->getSize() ; i ++) {
        if(i == this->selected){
            printw("   >%s<   \n" , this->GetTask(i).name) ;
        }else{
            printw("    %s\n" , this->GetTask(i).name);
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
    printw("%s", this->GetTask(this->selected).desc);
    return 0 ;
}

int TaskTab::print_status(){
    move(0 , 40) ;
    printw("--- status ---\n");
    move(1,40) ;
    return 0 ;
}

int TaskTab::handle_key(int ch) {
    switch (ch) {
        case 'q' :
            this->running = false;
            return -1 ; // return back to the menu
            break;
        case KEY_UP :
            if(this->selected > 0) this->selected -=1;
            return 999;
            break ;
        case KEY_DOWN :
            if(this->selected < this->getSize()-1) this->selected+=1 ;
            return 999;
            break;
        case 'a' :
       		TaskTab::add_task_dialog();
        	break;

    }
    return 0 ;
}

int TaskTab::main_loop(){
    int ch ;
    this->reset_states();
    while(this->running){
        this->print_TaskList();
        this->print_TaskDes();
        this->print_status() ;
        ch = getch();
        if(this->handle_key(ch) == -1){
            return -1 ;
        }
    }

    return -10 ;
}

void TaskTab::add_task_dialog(){
	clear();
	move(0,0);
	echo();
	refresh();
	printw("name of the task:");
	char* moz = (char*)malloc(20) ;
	getnstr(moz , 20) ;
	TaskTab::addTask(moz, "test", false ) ;
	noecho();
}

void TaskTab::reset_states(){
	this->running = true ;
}
