#ifndef BOARD_H_
#define BOARD_H_
class Board {
    private:
        int win_count = 0;
        static const int FIELD_SIZE = 3;//Размер поля
        enum END_GAME {WIN_O, WIN_X, DRAW, NEXT};//Победы О, Х или ничья
        enum SIGN {O, X, NONE};//Крестик или нолик
        END_GAME status;
        SIGN field[FIELD_SIZE][FIELD_SIZE];//Игровое поле
    public:
        Board();
        bool MakeMove(int x, int y, int sign);//Сделать ход !!!!bool or not bool?!!!!
        END_GAME Win();//Конец игры
        //SIGN GetSign(int index);//Получить значение крестика или нолика
        SIGN GetCell(int x, int y);//Получить значение ячейки
        int GetSize();//Получить размер поля
};
#endif
