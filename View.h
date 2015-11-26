#ifndef VIEW_H_
#define VIEW_H_
#include "Model.h"
class BoardView {
    private:
        void Output();//Вывод игрового поля
        Board * board;
    public:
        void LoopGame();//Игровой цикл с точкой выхода
        BoardView(Board * board);
};
#endif
