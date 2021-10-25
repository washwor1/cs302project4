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
    vector<bool> visited;
    vector<int> backedge, distance;
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
        visited.push_back(false);
        backedge.push_back(NULL);
        distance.push_back(-1);
    }

    cin >> start.first >> start.second >> finish.first >> finish.second;

    //sets the first node to be the start and runs the first round of dijkstras to do specialty for first node.
    nodesToAdd.insert(make_pair(0, (boardSize.second*start.second+start.first)));
    multimap<int,int>::iterator it = nodesToAdd.begin();
    visited.at(it->second) = true;
    distance.at(it->second) = 0;
    if (it->second%boardSize.second>0) {
        
    }
    


    //begin main dijkstras 
    //iteratively scans through each node; updating distances, backedges, the multimap, and visited status.
    for(int i = 0; i<boardSize.first*boardSize.second-1; i++) {
        visited.at(nodesToAdd.begin()->second) = true;
        back
    }

    
    return 0;
}

