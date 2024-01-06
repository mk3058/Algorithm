#include <iostream>
#include <string>

using namespace std;

int pixels[65][65] = {};
int N;

bool checkArea(int xs, int xe, int ys, int ye) {

    for (int i = xs; i <= xe; i++) {
        for (int j = ys; j <= ye; j++) {
            if (pixels[xs][ys] != pixels[i][j])
                return false;
        }
    }
    return true;
}

string compress(int xs, int xe, int ys, int ye) {
    string compressed;

    if (checkArea(xs, xe, ys, ye)) {
        compressed += to_string(pixels[xs][ys]);
    } else {
        compressed += "(";
        int midX = xs + (xe - xs) / 2;
        int midY = ys + (ye - ys) / 2;

        if (checkArea(xs, midX, ys, midY)) {
            compressed += to_string(pixels[xs][ys]);
        } else {
            compressed += compress(xs, midX, ys, midY);
        }

        if (checkArea(midX + 1, xe, ys, midY)) {
            compressed += to_string(pixels[midX + 1][ys]);
        } else {
            compressed += compress(midX + 1, xe, ys, midY);
        }

        if (checkArea(xs, midX, midY + 1, ye)) {
            compressed += to_string(pixels[xs][midY + 1]);
        } else {
            compressed += compress(xs, midX, midY + 1, ye);
        }

        if (checkArea(midX + 1, xe, midY + 1, ye)) {
            compressed += to_string(pixels[midX + 1][midY + 1]);
        } else {
            compressed += compress(midX + 1, xe, midY + 1, ye);
        }
        compressed += ")";
    }

    return compressed;
}

int main() {

    cin >> N;
    for (int i = 1; i <= N; i++) {
        string input;

        cin >> input;
        for (int j = 1; j <= N; j++) {
            pixels[j][i] = input[j - 1] - '0';
        }
    }

    cout << compress(1, N, 1, N);
}