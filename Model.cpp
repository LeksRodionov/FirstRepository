#include <stdio.h>
#include "Model.h"
Board::Board() {
    for (int i = 0; i < FIELD_SIZE; i++) {
        for (int j = 0; j < FIELD_SIZE; j++) {
            field[i][j] = NONE;
        }
    }
}
int Board::GetSize() {
    return FIELD_SIZE;
}
bool Board::MakeMove(int x, int y, int sign) {
    int count_horiz = 1, count_vert = 1;
    int count_left_top = 0, count_right_top = 0;
    //Проверка победы по горизонтали
    for (int i = 0; i < FIELD_SIZE; i++) {
        if (field[x][i] == sign) count_horiz++;
    }
    if (count_horiz >= FIELD_SIZE) {
        switch(sign) {
            case 0: status = WIN_O;
                break;
            case 1: status = WIN_X;
                break;
        }
    }
    //Проверка победы повертикали
    for (int i = 0; i < FIELD_SIZE; i++) {
        if (field[i][y] == sign) count_vert++;
    }
    if (count_vert >= FIELD_SIZE) {
        switch(sign) {
            case 0: status = WIN_O;
                break;
            case 1: status = WIN_X;
                break;
        }
    }
    //Проверка победы по диагонали сверху слева
    for (int i = x; i < FIELD_SIZE; i++) {
        if (field[i][i] == sign) count_left_top++;
    }
    for (int i = x; i > 0; i--) {
        if (field[i][i] == sign) count_left_top++;
    }
    if (count_left_top >= FIELD_SIZE) {
        switch(sign) {
            case 0: status = WIN_O;
                break;
            case 1: status = WIN_X;
                break;
        }
    }
    //Проверка победы по диагонали сверху справа
    for (int i = x; i > 0; i--) {
        for (int j = y; j < FIELD_SIZE; j++) {
            if (field[i][j] == sign) count_right_top++;
        }
    }
    for (int i = x; i < FIELD_SIZE; i++) {
        for (int j = y; j > 0; j--) {
            if (field[i][j] == sign) count_right_top++;
        }
    }
    if (count_right_top >= FIELD_SIZE) {
        switch(sign) {
            case 0: status = WIN_O;
                break;
            case 1: status = WIN_X;
                break;
        }
    }
    //Проверка на корректность данных
    if ((field[x][y] == NONE)&&(x >= 0)&&(x < FIELD_SIZE)&&(y >= 0)&&(y < FIELD_SIZE)) {
        switch(sign) {
            case 0: field[x][y] = O;
                break;
            case 1: field[x][y] = X;
                break;
            default: field[x][y] = NONE;
                break;
            }
        return true;
    }
    else {
        return false;
    }
}
Board::END_GAME Board::Win() {
    int draw = 0;
    for (int i = 0; i < FIELD_SIZE; i++) {
        for (int j = 0; j < FIELD_SIZE; j++) {
            if (field[i][j] == NONE) draw++;
        }
    }
    if (draw == 0) {
        return DRAW;
    }
    else if (status == WIN_O) {
        return WIN_O;
    }
    else if (status == WIN_X) {
        return WIN_X;
    }
    else {
        return NEXT;
    }
}
Board::SIGN Board::GetCell(int x, int y) {
    return field[x][y];
}
