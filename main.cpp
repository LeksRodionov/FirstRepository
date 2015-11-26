#include <stdio.h>
#include "Model.h"
#include "View.h"

int main()
{
    Board b;
    BoardView v(&b);
    v.LoopGame();
    return 0;
}
