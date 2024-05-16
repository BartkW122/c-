#include <iostream>
#include <vector>
#include <ctime>
using namespace std;
<<<<<<< HEAD
=======
void hanoi(int rollerCount,int sticksCount){
        int moveCount =pow(2,rollerCount) - 1;
        int arrRoller[sticksCount];
>>>>>>> 665f6c02b81c33e4fab107ccc7cedda6be149cdd

extern __inline__ unsigned long long int atime()

{
	unsigned long long int cnt;

	__asm__ volatile (".byte 0x0f, 0x31" : "=A" (cnt));

 	return cnt;
}

int powH(int r) {
    int t = 2;
    if (r == 0) {
        return 1;
    }
    for (int i = 1; i < r; i++) {
        t = t * 2;
    }
    return t;
}

void hanoi(int rollerCount) {
    int moveCount = powH(rollerCount) - 1;
    vector<int> arrRoller(rollerCount, 0);

    for (int j = 1; j <= moveCount; j++) {
        int r = 0;

        while (true) {
            int temp = powH(r);
            int move = temp * 2;

            if ((j - temp) % move == 0) {
                if ((r + 1) % 2 == 1) {
                    arrRoller[r] = (arrRoller[r] + 2) % 3;
                } else {
                    arrRoller[r] = (arrRoller[r] + 1) % 3;
                }

                cout << "Ruch krazka " << r + 1 << " na patyk " << arrRoller[r] + 1 << endl;
                break;
            }

            r++;
            if (r >= rollerCount) {
                break;
            }
        }
    }

    cout << "\nIlosc ruchow to: " << moveCount << endl;
}

int main() {
    srand(clock());

    int rollerCount, sticksCount;
    cout << "Podaj ilosc krazkow: ";
    cin >> rollerCount;
    cout << "Podaj ilosc patykow: ";
    cin >> sticksCount;

    if (sticksCount < 3) {
        cout << "Liczba patykow musi byc co najmniej 3." << endl;
        return 1;
    }

    unsigned long long int end = 0;
	unsigned long long int start = 0;
	srand((unsigned)time(NULL));
	start = atime();

    hanoi(rollerCount);

    end += (atime() - start)/1000;

	cout<<"czas sortowania: "<<end<<" milisekund"<<endl;

    return 0;
}
