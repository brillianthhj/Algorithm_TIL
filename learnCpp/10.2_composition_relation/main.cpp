#include "10.2_composition_relation/Position2D.h"
#include "Monster.h"

using namespace std;

int main()
{
    // Composition: 전체(Monster), 부품(Position2D)
    // mon1, mon2 각각의 location 들은 객체가 사라지면 같이 사라지고
    // 상위 클래스가 시키기만 하고 세부 내용은 Position2D에서 진행하도록.
    Monster mon1("Sanson", Position2D(0, 0));
    Monster mon2("Ddomi", Position2D(0, 0));

    cout << mon1 << endl;

    //while (1)   // game loop
    {
        // event
        mon1.moveTo(Position2D(1, 1));
        cout << mon1 << endl;
    }

    return 0;
}