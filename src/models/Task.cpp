#include <cstddef>
#include <cstdlib>
#include <string.h>
#include "Task.h"


Task::Task(const char* name , const char* desc , bool status){
    strcpy(this->name, name) ;
    strcpy(this->desc, desc) ;
    this->status = status ;
}

TaskQueue::TaskQueue(){
    this->size = 0 ;
    this->Queue = NULL;
}

size_t TaskQueue::getSize(){
    return this->size ;
}

Task** TaskQueue::getTasks(){
    return this->Queue;
}

int TaskQueue::addTask( const char* name ,  const char* des , bool status){
    // allocate memory for the taskQueue
    this->size+=1;
    size_t size= this->size * sizeof(Task*) ;
    this->Queue =(Task**) realloc(this->Queue, size );

    // this->Queue[this->size-1]
    // assign
    Task* task =  new Task(name , des, status) ; //it allocates it on heap
    this->Queue[this->size-1] = task ;
    return 0 ;
}

int TaskQueue::DelTask(size_t index){
    delete this->Queue[index] ;
    for(int i = 0 ; i<this->size ; i++){
        if(i>index)this->Queue[i-1] = this->Queue[i];
    }
    this->size -=1;
    this->Queue = (Task**) realloc(this->Queue , this->size * sizeof(Task*)) ;
    return 0;
}

Task TaskQueue::GetTask(size_t index){
    return *(this->Queue[index]);
}
