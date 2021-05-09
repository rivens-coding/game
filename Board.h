#ifndef Board__H_
#define Board__H_







class Board{
public:
    int board[4][4]={};

    void init();

    bool checkUp();

    bool checkDown();

    bool checkRight();

    bool checkLeft();

    void Up();

    void Down();

    void Right();

    void Left();


};
#endif
