#include "minesweeper.h"
Chessboard chessboard;
int a=-1,b=-1,boomNumber;
int main(){
    while(a==boom&&b==boom){
        cout<<"�������̵ĳ�x�Ϳ�y(0<x,y<=100) (��������-1��ȡ�������Կո�ָ�):";
        cin>>a>>b;
        if(a==boom&&b==boom)chessboard.help();
    }
    cout<<"����ը������:";
    cin>>boomNumber;
    chessboard.set(a,b,boomNumber);
    chessboard.createBoom();
    chessboard.createNumber();
    while(!chessboard.gameover())chessboard.input();
    chessboard.end();
    return 0;
}
