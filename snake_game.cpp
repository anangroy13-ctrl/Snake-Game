#include<iostream>
#include<conio.h>    // this includes functions like kbhit and getch
#include<windows.h>    // this include sleep function
using namespace std;
bool GameOver;
int width = 20, height = 20, x, y, fruitX, fruitY, Score=0 ;
int tail, tailx[100], taily[100];

#define LEFT 1
#define RIGHT 2
#define UP 3
#define DOWN 4

int dir; 

void Setup() {
    GameOver = false;
    x = width/2;
    y= height/2;
    fruitX= width/3;
    fruitY= height/3;
}
void Draw() {
    system("cls");  // So that - doesn't keep on repeating till GameOver is true
    for(int i=0; i < width; i++) {
        cout << "-";
    }

        cout << endl;

        for(int j=0; j < height; j++) {
           for(int i=0; i < width; i++) {

            if(i==0) {
                cout << "|";
            }

            else if(i == width-1) {
                cout << "|" << endl;
            }


            else {

                if(i==x && j==y) {
                    cout << "0 ";
                }

                else if(i==fruitX && j==fruitY) {
                    cout << "*";
                }

                else {
                    bool print = false;
                    for(int k=0; k<tail; k++) {
                        if(i == tailx[k] && j == taily[k]) {
                            cout << "o";
                            print = true;
                        }
                    }
                    if(!print) {
                        cout<< " ";
                    }
                }
            }
           } 
        }

    for(int i=0; i<width; i++) {
        cout << "-";
    }
      cout << endl;
      cout << "SCORE = " << Score;

}
void Input() {
    if(kbhit()) {      // This identifies if a key is pressed
        char ch = getch();    // Gets the character pressed in keyboard and stores in ch
        if(ch == 'a') {
            dir = LEFT;
        }
        else if(ch == 'd') {
            dir = RIGHT;
        }
        else if(ch == 'w') {
            dir = UP;
        }
        else if(ch == 's') {
            dir = DOWN;
        }
        else if(ch == 'x') {
            GameOver = true;
        }
    }
}
void Logic() {
    int tempx = tailx[0];
    int tempy = taily[0];
    int temp2x, temp2y;
    tailx[0] = x;
    taily[0] = y;

    for(int i=1; i<tail; i++) {
        temp2x = tailx[i];
        temp2y = taily[i];
        tailx[i] = tempx;
        taily[i] = tempy;
        tempx = temp2x;
        tempy = temp2y;

    }
    if(dir == LEFT) {
        x--;
    }

    else if(dir == RIGHT) {
       x++;
    }

    else if(dir == UP) {
        y--;
    }

    else if(dir ==  DOWN) {
        y++;
    }

    for(int i=0; i<tail; i++) {
        if(x==tailx[i] && y==taily[i]) {
            GameOver=true;
        }
    }

    if(x== fruitX && y== fruitY) {
        Score+=10;
        fruitX = rand()% width;   // so that however big number it generates but we get a number between 0 to width-1
        fruitY = rand()% height;
        tail++;
    }

        // if(x<0 || x>width || y<0 || y>height) {
        //     GameOver = true;                                    // This ensures game gets over when hit by wall 
        // }

        if(x>=width) {
            x=0;
        }
        else if(x<0) {
            x=width-1;
        }
        if(y>=height) {
            y=0;
        }
        else if(y<0) {
            y=height-1;
        }
    
}

int main() {
    Setup();

     while(!GameOver) {
        Draw();
        Input();
        Logic();
        Sleep(100);   // Waits for 100 ms before stating the loop again
    }


}