#include "SingleGame.h"
//test comment
int main(void) {
    srand(time(NULL));
    SingleGame g{ 10 };
    g.start();
    system("pause");
    return 0;
}