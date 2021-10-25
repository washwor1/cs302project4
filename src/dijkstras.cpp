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

    //sets the first node to be the start and runs the first round of dijkstras to do specialty for first node (since its backedge remains null). This is also essentially how my main dijkstras will work with the addition of
    //backedge.
    //my comments on here are the same as the ones that I would use for the main loop
    nodesToAdd.insert(make_pair(0, (boardSize.second*start.second+start.first)));
    
    //finds the smallest distance in the multimap and saves a pointer to it
    multimap<int,int>::iterator it = nodesToAdd.begin();

    //sets required values (in this case visited and distance, but in the main loop it will mark the backedge.)
    visited.at(it->second) = true;
    distance.at(it->second) = 0;

    //checks each adjascent square to see if it exists and makes sure it has not yet been visited. If it passes these conditions, it gets added to the multimap.
    if (it->second%boardSize.second>0 && visited.at(it->second-1) != true) {
        nodesToAdd.insert(make_pair(it->first+values.find(board.at(it->second-1))->second, (it->second-1)));
    }
    if (it->second%boardSize.second<boardSize.second-1 && visited.at(it->second+1) != true) {
        nodesToAdd.insert(make_pair(it->first+values.find(board.at(it->second+1))->second, (it->second+1)));
    }
    if (it->second/boardSize.second>0 && visited.at(it->second-boardSize.second) != true) {
        nodesToAdd.insert(make_pair(it->first+values.find(board.at(it->second-boardSize.second))->second, (it->second-boardSize.second)));
    }
    if (it->second/boardSize.second<boardSize.first && visited.at(it->second+boardSize.second) != true) {
        nodesToAdd.insert(make_pair(it->first+values.find(board.at(it->second+boardSize.second))->second, (it->second+boardSize.second)));
    }

    //erases the visited node from the multimap
    nodesToAdd.erase(it);
    
    for (multimap<int,int>::iterator i = nodesToAdd.begin(); i != nodesToAdd.end(); ++i) {
        cout << i->first << ' ' << i-> second << '\n';
    }

    //begin main dijkstras 
    //iteratively scans through each node using the outline from above.
    // for(int i = 0; i<boardSize.first*boardSize.second-1; i++) {
    //     visited.at(nodesToAdd.begin()->second) = true;
    //     back
    // }

    
    return 0;
}

