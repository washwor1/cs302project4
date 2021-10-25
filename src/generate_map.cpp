//Andy Zeng and Walter Ashworth
//Github: https://github.com/washwor1/cs302project4
//This program generate a nxn file that would be the input for the path finding lab

#include <time.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int main(){
    string name;
    int map_size, random_number;
    char letter[6] = {'f','g','G','h','m','r'};
    cout << "File Name: ";
    cin >> name;
    ofstream outfile;
    outfile.open(name);

    outfile << "6" << endl;
    outfile << "f 3" << endl;
    outfile << "g 1" << endl;
    outfile << "G 2" << endl;
    outfile << "h 4" << endl;
    outfile << "m 7" << endl;
    outfile << "r 5" << endl;

    cout << "Size of the map: ";
    cin >> map_size;

    outfile << map_size << " " << map_size << endl;

    for (int i = 0; i < map_size; i++)
    {
        for (int j = 0; j < map_size - 1; j++)
        {
            random_number = rand() % 6;
            outfile << letter[random_number] << " ";
        }
        random_number = rand() % 6;
        outfile << letter[random_number] << endl;
    }
    
    outfile << "0 0" << endl;
    random_number = rand() % map_size;
    outfile << random_number << " ";
    random_number = rand() % map_size;
    outfile << random_number << endl;

    outfile.close();


    return 0;
}