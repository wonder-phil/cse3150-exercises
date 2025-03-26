
#ifndef _TOP_H
#define _TOP_H


class Top {
    public:
        int publicInt;

    protected:
        int protectedInt;

    private:
        int privateInt;

    public:
        int getProtectedInt() {
            return protectedInt;
        }
};

#endif