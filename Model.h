#ifndef BOARD_H_
#define BOARD_H_
class Board {
    private:
        static const int FIELD_SIZE = 3;//Размер поля
        int field[FIELD_SIZE][FIELD_SIZE];//Игровое поле
        enum END_GAME {WIN_O, WIN_X, DRAW};//Победы О, Х или ничья
        enum SIGN {O, X};//Крестик или нолик
    public:
        Board();
        bool MakeMove(int x, int y);//Сделать ход
        END_GAME Win();//Конец игры
        SIGN GetCell(int x, int y);//Получить значение ячейки
        int GetSize();//Получить размер поля
};
#endif
