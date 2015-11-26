#include <stdio.h>
#include "View.h"

BoardView::BoardView(Board *b) {
    board = b;
}
void BoardView::Output() {
    for (int i = 0; i < board->GetSize(); i++) {
        for (int j = 0; j < board->GetSize(); j++) {
            printf("\n");
            //b->getCell(i, j);
        }
    }
}
void BoardView::LoopGame() {
    while(1) {
        scanf("");
        //b->makeMove();
        Output();
        if (1) {
            scanf("");
            //b->makeMove();
            Output();
        }
    }
    printf("Result");
}
