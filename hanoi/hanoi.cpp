#include<iostream>
#include <cmath>
using namespace std;
void hanoi(int rollerCount,int sticksCount){
        int moveCount =pow(2,rollerCount) - 1;
        int arrRoller[sticksCount];

        for (int j = 1; j <= moveCount; j++) {
            int r = 0;

            while (true) {
                int temp = pow(2, r);
                int move = temp * 2;

                if (((j - temp) % move) == 0) {
                    if ((rollerCount + 1) % 2) {
                        arrRoller[r] = (arrRoller[r] + 2) % 3;
                    } else {
                        arrRoller[r] = (arrRoller[r] + 1) % 3;
                    }
                    break;
                }

                r++;
            }
        }
}
int main(){
   int rollerCount,sticksCount;
    cout<<"podaj ilosc krazkow:";
    cin>>rollerCount;
    cout<<"podaj ilosc patykow:";
    cin>>sticksCount;
    hanoi(rollerCount,sticksCount);
}
