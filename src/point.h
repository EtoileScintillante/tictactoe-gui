class Point {
public:
    int x;
    int y;
    Point() {x = 0; y = 0;}

    Point(int a, int b) {
        x = a;
        y = b;
    } 

    void print() {
        printf("(%i, %i)\n", x, y);
    }
};