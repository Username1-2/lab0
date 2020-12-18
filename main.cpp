#include "Header.h"

int main(int argc, char* argv[])
{
    if (argc > 3)
    {
        cout << "To many arguments" << endl;
        return 1;
    }
    if (argc < 3)
    {
        cout << "To few arguments" << endl;
        return 1;
    }

    Reader read(argv[1]);
    Writer write(argv[2]);
    write.WI(read);

    return 0;
}
