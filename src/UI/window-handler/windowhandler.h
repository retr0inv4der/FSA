class window_handler{
    private:
    /*
     * window = -1 --> main menu
     * windows = 0 -->   Timer
     * window = 1 -->  Task menu
     *
     */
        int window = -1 ;

    public:
        void main_loop();
        void start();
};
