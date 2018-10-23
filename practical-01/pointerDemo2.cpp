#include<iostream>
#include<string>

using namespace std;

void changeValue(int x, int *y) {
    x += 10;
    *y += 10;
}

int main() {
    int x = 30;
    int y;
    y = x;
    changeValue(x, &y);
    cout << "Value of x: " << x << endl;
    cout << "Value of y: " << y << endl;

    /* The value of x remained at 30, and the value of y increased to 40. In C++, all variables are passed by values to function. So when x was passed to the function, a copy of its value(30) was passed into it. 
     * Wheras when the reference of y was passed into it, a copy of its address was made. Thus, any changes to the dereferenced value of y affected the variable y defined in main. 
     */
    // x and y in main are not the same x and y in changeValue
}
