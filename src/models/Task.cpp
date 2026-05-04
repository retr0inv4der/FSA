#include <cstddef>
#include <cstdlib>
#include <string.h>


class Task {

    public:
        char name[20] ;
        char desc[100] ;
        bool status ;
        Task(const char* name , const char* desc , bool status){
            strcpy(this->name, name) ;
            strcpy(this->desc, desc) ;
            this->status = status ;
        }


};


class TaskQueue {
    private:
      Task** Queue;
      size_t size ;

    public :
        TaskQueue(){
            this->size = 0 ;
            this->Queue = NULL;
        }
        size_t getSize(){
            return this->size ;
        }
        Task** getTasks(){
            return this->Queue;
        }

        int addTask( const char* name ,  const char* des , bool status){
            //allocate memory for the taskQueue
            this->size+=1;
            size_t size= this->size * sizeof(Task*) ;
            this->Queue =(Task**) realloc(this->Queue, size );
            // this->Queue[this->size-1]
            // assign
            Task* task =  new Task(name , des, status) ; //it allocates it on heap
            this->Queue[this->size-1] = task ;
            return 0 ;

        }

        int DelTask(size_t index){
            delete this->Queue[index] ;
            for(int i = 0 ; i<this->size ; i++){
                if(i>index)this->Queue[i-1] = this->Queue[i];
            }
            this->size -=1;
            this->Queue = (Task**) realloc(this->Queue , this->size * sizeof(Task*)) ;
            return 0;
        }

        Task GetTask(size_t index){
            return *(this->Queue[index]);
        }


};
