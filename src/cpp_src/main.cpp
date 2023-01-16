#include <iostream>
#include "t265.hpp"

using namespace std;

int main(int argc, char * argv[])
{
    T265 camera = T265();

    while (true) {
        std::vector<double> pose = camera.get_translation();
        cout << "pose: "<<pose[0] << " "<< pose[1] << " "<< pose[2] << endl;
    }

    return EXIT_SUCCESS;
}