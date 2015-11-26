#include <stdio.h>
#include "View.h"

BoardView::BoardView(Board *b) {
    board = b;
}
void BoardView::Output() {//Вывод игрового поля
    for (int i = 0; i < board->GetSize(); i++) {
        printf("\n|");
        for (int j = 0; j < board->GetSize(); j++) {
            switch(board->GetCell(i, j)) {
                case 0: printf(" O |");
                break;
                case 1: printf(" X |");
                break;
                default: printf("   |");
                break;
            }
        }
    }
}
void BoardView::LoopGame() {
    bool repeat_move;//Отвечает за правильность введения координат
    int x1, y1;//Координаты хода
    while(board->Win() == 3) {//Пока игра продолжается
        printf("Введите координаты крестика(x, y): ");
        scanf("%d %d", &x1, &y1);
        repeat_move = board->MakeMove(x1, y1, 1);
        while (!repeat_move) {//Проверка на правильность введеных данных
            printf("\nДанные не корректны, попробуйте еще раз: ");
            scanf("%d %d", &x1, &y1);
            repeat_move = board->MakeMove(x1, y1, 1);
        }
        Output();
        if (board->Win() == 3) {//Ход второго игрока
            printf("\nВведите координаты нолика(x, y): ");
            scanf("%d %d", &x1, &y1);
            board->MakeMove(x1, y1, 0);
            while (!repeat_move) {
                printf("\nДанные не корректны, попробуйте еще раз: ");
                scanf("%d %d", &x1, &y1);
                repeat_move = board->MakeMove(x1, y1, 1);
        }
            Output();
            printf("\n");
        }
    }
    switch(board->Win()) {
        case 0: printf("\nНолики победили\n");
            break;
        case 1: printf("\nКрестики победили\n");
            break;
        case 2: printf("\nНичья\n");
            break;
    }
}
