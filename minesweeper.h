#pragma GCC optimize(3,"Ofast","inline")
#include<iostream>
#include<cstdio>
using namespace std;
const int boom=-1;
const int N=101;
class Chessboard{
public:
    int length=0,width=0;
    int num=0;
    void help(){
        system("cls");
        printf("-----------使用帮助-----------\n");
        printf("1.本游戏的所有坐标以及长和宽皆为先纵后横,其中皆以空格间隔,示例输入：5 5 1\n");
        printf("2.本游戏的操作有两个:1是打开，2是放旗\n");
        system("pause");
        system("cls");
    }
    void set(int a1,int b1,int boomNumber){
        length=a1;
        width=b1;
        num=boomNumber;
    }
    void createBoom(){
        srand((unsigned int)time(nullptr));
        int x1,y1;
        for(int i=1;i<=num;i++){
            x1=rand()%length+1;
            y1=rand()%width+1;
            if(a[x1][y1]!=boom)a[x1][y1]=boom;
            else i--;
        }
    }
    void createNumber(){
        for(int i=1;i<=length;i++){
            for(int j=1;j<=width;j++){
                if(a[i][j]==boom){
                    if(i>1&&j>1&&a[i-1][j-1]!=boom)a[i-1][j-1]++;
                    if(i>1&&a[i-1][j]!=boom)a[i-1][j]++;
                    if(i>1&&j<width&&a[i-1][j+1]!=boom)a[i-1][j+1]++;
                    if(j>1&&a[i][j-1]!=boom)a[i][j-1]++;
                    if(j<width&&a[i][j+1]!=boom)a[i][j+1]++;
                    if(i<length&&j>1&&a[i+1][j-1]!=boom)a[i+1][j-1]++;
                    if(i<length&&a[i+1][j]!=boom)a[i+1][j]++;
                    if(i<length&&j<width&&a[i+1][j+1]!=boom)a[i+1][j+1]++;
                }
            }
        }
    }
    void print(bool dev) const{
        system("cls");
        for(int i=0;i<=width;i++)printf("%2d ",i);
        printf("\n");
        for(int i=1;i<=length;i++){
            printf("%2d ",i);
            for(int j=1;j<=width;j++){
                if(a[i][j]==boom&&dev)printf(" * ");
                else if(dev||b[i][j]==1){
                    if(a[i][j])printf("%2d ",a[i][j]);
                    else printf("   ");
                }
                else if(b[i][j]==2)printf(" ^ ");
                else printf(" - ");
            }
            printf("\n");
        }
    }
    void input(){
        print(false);
        cout<<"输入坐标和操作：";
        cin>>x>>y>>operation;
        if(operation==1){
            if(a[x][y]==boom)fail=true;
            else if(!b[x][y])b[x][y]=1;
            if(!a[x][y])change(x,y);
        }
        else{
            if(!b[x][y]&&a[x][y])b[x][y]=2;
            else if(b[x][y]==2)b[x][y]=0;
        }
    }
    bool gameover(){
        if(fail)return true;
        int sum=0;
        for(int i=1;i<=length;i++){
            for(int j=1;j<=width;j++){
                if(a[i][j]!=boom && b[i][j]==1)sum++;
            }
        }
        return sum==length*width-num;
    }
    void end() const{
        print(true);
        if(fail)printf("你输了,再接再厉!\n");
        else printf("恭喜,你赢了!\n");
        system("pause");
    }
private:
    bool fail=false;
    int a[N][N]{},b[N][N]{};
    int x=0,y=0,operation=0;
    void change(int i,int j){
        if(i>1&&j>1&&a[i-1][j-1]!=boom&&!b[i-1][j-1]){
            b[i-1][j-1]=1;
            if(!a[i-1][j-1])change(i-1,j-1);
        }
        if(i>1&&a[i-1][j]!=boom&&!b[i-1][j]){
            b[i-1][j]=1;
            if(!a[i-1][j])change(i-1,j);
        }
        if(i>1&&j<width&&a[i-1][j+1]!=boom&&!b[i-1][j+1]){
            b[i-1][j+1]=1;
            if(!a[i-1][j+1])change(i-1,j+1);
        }
        if(j>1&&a[i][j-1]!=boom&&!b[i][j-1]){
            b[i][j-1]=1;
            if(!a[i][j-1])change(i,j-1);
        }
        if(j<width&&a[i][j+1]!=boom&&!b[i][j+1]){
            b[i][j+1]=1;
            if(!a[i][j+1])change(i,j+1);
        }
        if(i<length&&j>1&&a[i+1][j-1]!=boom&&!b[i+1][j-1]){
            b[i+1][j-1]=1;
            if(!a[i+1][j-1])change(i+1,j-1);
        }
        if(i<length&&a[i+1][j]!=boom&&!b[i+1][j]){
            b[i+1][j]=1;
            if(!a[i+1][j])change(i+1,j);
        }
        if(i<length&&j<width&&a[i+1][j+1]!=boom&&!b[i+1][j+1]){
            b[i+1][j+1]=1;
            if(!a[i+1][j+1])change(i+1,j+1);
        }
    }
};