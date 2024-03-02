#include "minesweeper.h"
Chessboard chessboard;
int a=-1,b=-1,boomNumber;
int main(){
    while(a==boom&&b==boom){
        cout<<"输入棋盘的长x和宽y(0<x,y<=100) (输入两个-1获取帮助，以空格分隔):";
        cin>>a>>b;
        if(a==boom&&b==boom)chessboard.help();
    }
    cout<<"输入炸弹数量:";
    cin>>boomNumber;
    chessboard.set(a,b,boomNumber);
    chessboard.createBoom();
    chessboard.createNumber();
    while(!chessboard.gameover())chessboard.input();
    chessboard.end();
    return 0;
}
