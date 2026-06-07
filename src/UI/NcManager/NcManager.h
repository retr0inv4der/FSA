#ifndef NCM_H
#define NCM_H

class NcursesManager {
    private:
        static inline bool isInit = 0 ;

    public:
        NcursesManager();
        bool isInitialized();
        int init();
        int shutdown();
};

#endif
