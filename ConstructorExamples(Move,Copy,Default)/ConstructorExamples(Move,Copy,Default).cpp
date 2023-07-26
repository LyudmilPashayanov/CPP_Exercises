#include <iostream>
#include <vector>

using namespace std;

class Move
{
private:
    int* data;

public:

    // default constuctor
    Move(int Data);

    // copy constructor
    Move(const Move& source); // uses L-Value reference (another existing object)
    
    // Move Constructor
    Move(Move&& move_source) noexcept;  // uses R-Value reference (when you want to create an object when passing a valeu for example- something temporary will be created)

    // Destructor
    ~Move();

    
};

Move::Move(int Data)
{
    data = new int;
    *data = Data;
    cout << "Constructor with data: " << *data << endl;
}

Move::Move(const Move& source) : Move{*source.data} // Done inside the function so it is more explisit
{
 //   data = new int;
 //   *data = *source.data;
    cout << "Copying constructor with data: " << *data << endl;
}

Move::Move(Move&& move_source) noexcept : data{ move_source.data } // Done inside the function so it is more explisit
{
    move_source.data = nullptr;
}

Move::~Move() {
    if(data != nullptr)
        cout << "Deconstructing the object with data: " << *data << endl;
    else
        cout << "Deconstructing the object with nullptr Data" << endl;
    delete data;
}

int main()
{
    vector<Move> vec;

    // Inserting Object of Move Class as an R-Value
    vec.push_back(Move{ 10 });
    vec.push_back(Move{ 20 });
    return 0;
}
