#include<iostream>

using namespace std;

/*class hero {

    private :
    int health;

    public:
    char level;

    int getHealth() {

        return health;
    }

    char getLevel() {

        return level;
    }

    void setHealth(int h) {

        health = h;
    }

    void setLevel(char ch) {

        level = ch;
    }
};

int main() {

    hero ramesh;
    cout<<" ramesh health is "<<ramesh.getHealth() <<endl;

    ramesh.setHealth(70);
    ramesh.level = 'A';

    cout<<" health is "<<ramesh.getHealth()<<endl;
    cout<<" level is "<< ramesh.level << endl; 
}

*/

class rectangle {

    int x,y;
    public:
    rectangle(int a, int b) {

        x = a;
        y = b;
    }

    int area() {

        return(x*y);
    }
};

int main() {

    rectangle rectangle(3,4);
    cout<<"area is "<<rectangle.area();
    return 0;
}
