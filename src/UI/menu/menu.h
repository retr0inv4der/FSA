
class NcursesManager{
    private:
        bool isInit =0  ;

    public:
        NcursesManager();
        bool isInitialized();
        int init();
        int shutdown();
};

class Menu{
    public:
    /*
     section 0 = TaskSection

     selected = 0 -> task section
     selected = 1 -> timer section
     */
    int section = 0 ;
    bool entered =false  ;
    int selected ;
    bool running = true;
    NcursesManager manager = NcursesManager();;

        Menu();
        void sh();
        void print_menu();
        void handle_key(int ch );
        int mainloop();
};
