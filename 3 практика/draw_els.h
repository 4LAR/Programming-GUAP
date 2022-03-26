 
void triangle(int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j <= i; j++)
            cout << '#';
        cout << endl;
    }
}

//  #
// ###
//#####

void arrow(int height_arrow, int height_stick) {
    int i, j;

    // arrow
    int width_arrow = 1;
    for (i = 0; i < height_arrow; i++) {
        for (j = 1; j < height_arrow-i; j++) {
            cout << " ";
        }
        for (j = 0; j < width_arrow; j++) {
            cout << "#";
        }
        cout << endl;
        width_arrow += 2;
    }

    //stick
    for (i = 0; i < height_stick; i++) {
        for (j = 1; j < height_arrow; j++) {
            cout << " ";
        }
        cout << "#" << endl;
    }

}

void square(int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if ((i == 0 || i == height-1) || ( (0 < i < height-1) && (j == 0 || j == width-1) ))
                cout << "#";
            else{
                cout << " ";
            }
        }
        cout << endl;
    }
}
