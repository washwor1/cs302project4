//Andy Zeng and Walter Ashworth
//Github: https://github.com/washwor1/cs302project4
//the dijsktras algorithm to complete which path would be the best path
// dijsktras.cpp

// Main Execution
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
    int numInputs, intInput;
    char charInput;
    map<char,int> values;
    vector<char> board;
    pair<int,int> boardSize, start, finish;
    multimap<int,int> nodesToAdd;

    cin >> numInputs;
    //fills a map with the values of each character that will be in the grid
    for(int i =0; i<numInputs; i++) {
        cin >> charInput >> intInput;
        values.insert(make_pair(charInput,intInput));
    }

    cin >> boardSize.first >> boardSize.second;

    //creates the grid
    for(int i = 0; i < boardSize.first * boardSize.second; i++) {
        cin >> charInput;
        board.push_back(charInput);
    }

    cin >> start.first >> start.second >> finish.first >> finish.second;
    
    return 0;
}

