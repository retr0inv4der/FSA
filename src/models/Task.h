#ifndef TASK_H
#define TASK_H

#include <cstddef>

class Task {

    public:
        char name[20] ;
        char desc[100] ;
        bool status ;
        Task(const char* name , const char* desc , bool status);

};


class TaskQueue {
    private:
        Task** Queue;
        size_t size ;

    public :
        TaskQueue();
        size_t getSize();
        Task** getTasks();
        int addTask( const char* name ,  const char* des , bool status);
        int DelTask(size_t index);
        Task GetTask(size_t index);


};

#endif
