
#include "../models/Task.h"
#include <iostream>
#include <cerrno>
#include <cstring>
#include <cstdio>
#include <cstdlib> 
#include <fcntl.h>

class storage : public TaskQueue  {
  private: 
    char* db  ;   

  public : 
    storage(){
        this-> db = (char*)malloc(100) ; 
        strcpy(this->db,"db/storage.db");  
    }
    

    int LoadFromDisk(){
        
    }


    

    int SaveToDisk(){ // returns the number of bytes written 
        FILE* file = fopen(this->db ,"w") ;       
        
        int n = fwrite(this->getTasks(),  sizeof(Task),this->getSize(),file );
        if(n==-1){
            std::cout<<errno   ; 
            exit(1 ) ; 
        }

    }


};
