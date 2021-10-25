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
    multimap<int,pair<int,int>> nodesToAdd;

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
        backedge.push_back(-1);
        distance.push_back(-1);
    }

    cin >> start.first >> start.second >> finish.first >> finish.second;

    //sets the first node to be the start and runs the first round of dijkstras to do specialty for first node (since its backedge remains null). This is also essentially how my main dijkstras will work with the addition of
    //backedge.
    //my comments on here are the same as the ones that I would use for the main loop
    nodesToAdd.insert(make_pair(0, make_pair(boardSize.second*start.first+start.second, 0)));
    
    //finds the smallest distance in the multimap and saves a pointer to it
    multimap<int,pair<int,int>>::iterator it = nodesToAdd.begin();

    //sets required values (in this case visited and distance, but in the main loop it will mark the backedge.)
    visited.at(it->second.first) = true;
    distance.at(it->second.first) = 0;

    //checks each adjascent square to see if it exists and makes sure it has not yet been visited. If it passes these conditions, it gets added to the multimap.
    if (it->second.first%boardSize.second>0 && visited.at(it->second.first-1) != true) {
        nodesToAdd.insert(make_pair(it->first+values.find(board.at(it->second.first-1))->second, make_pair((it->second.first-1), it->second.first)));
    }
    if (it->second.first%boardSize.second<boardSize.second-1 && visited.at(it->second.first+1) != true) {
        nodesToAdd.insert(make_pair(it->first+values.find(board.at(it->second.first+1))->second, make_pair((it->second.first+1), it->second.first)));
    }
    if (it->second.first/boardSize.second>0 && visited.at(it->second.first-boardSize.second) != true) {
        nodesToAdd.insert(make_pair(it->first+values.find(board.at(it->second.first-boardSize.second))->second, make_pair(it->second.first-boardSize.second, it->second.first)));
    }
    if (it->second.first/boardSize.second<boardSize.first && visited.at(it->second.first+boardSize.second) != true) {
        nodesToAdd.insert(make_pair(it->first+values.find(board.at(it->second.first+boardSize.second))->second, make_pair(it->second.first+boardSize.second, it->second.first)));
    }

    //erases the visited node from the multimap
    nodesToAdd.erase(it);
    cout << '\n';
    //begin main dijkstras 
    //iteratively scans through each node using the outline from above.
    while(visited.at(boardSize.second*finish.first+finish.second)==false) {
        it = nodesToAdd.begin();
        if(visited.at(it->second.first)!=true) {
            cout << it->second.first/boardSize.second << ' ' << it->second.first%boardSize.second << ' ' << backedge.at(it->second.first)/boardSize.second << ' ' << backedge.at(it->second.first)%boardSize.second << '\n';
            visited.at(it->second.first) = true;
            distance.at(it->second.first) = it->first;
            backedge.at(it->second.first) = it->second.second;
            if (it->second.first%boardSize.second>0 && visited.at(it->second.first-1) != true) {
                nodesToAdd.insert(make_pair(it->first+values.find(board.at(it->second.first-1))->second, make_pair((it->second.first-1), it->second.first)));
            }
            if (it->second.first%boardSize.second<boardSize.second-1 && visited.at(it->second.first+1) != true) {
                nodesToAdd.insert(make_pair(it->first+values.find(board.at(it->second.first+1))->second, make_pair((it->second.first+1), it->second.first)));
            }
            if (it->second.first/boardSize.second>0 && visited.at(it->second.first-boardSize.second) != true) {
                nodesToAdd.insert(make_pair(it->first+values.find(board.at(it->second.first-boardSize.second))->second, make_pair(it->second.first-boardSize.second, it->second.first)));
            }
            if (it->second.first/boardSize.second<boardSize.first-1 && visited.at(it->second.first+boardSize.second) != true) {
                nodesToAdd.insert(make_pair(it->first+values.find(board.at(it->second.first+boardSize.second))->second, make_pair(it->second.first+boardSize.second, it->second.first)));
            }
        }
        nodesToAdd.erase(it);
    }

    vector<int> moves;
    int j = boardSize.second*finish.first+finish.second;
    cout << distance.at(j) << '\n';
    while(j != -1) {
        moves.push_back(j);
        j = backedge.at(j);
    }
    int size = moves.size();
    for (int i = size-1; i>=0; i--) {
        cout << moves.at(i)/boardSize.second << ' ' << moves.at(i)%boardSize.second <<  '\n';
    }

    
    return 0;
}

