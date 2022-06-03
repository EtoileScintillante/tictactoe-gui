class Point {
public:
    Point() {x = 0; y = 0;}
    int x;
    int y;
    Point(int a, int b) {
        x = a;
        y = b;
    } 
    void print() {
        printf("(%i, %i)\n", x, y);
    }
};