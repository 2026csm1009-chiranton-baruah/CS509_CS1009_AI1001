#ifndef CONNECTED_H
#define CONNECTED_H

#include <vector>

using namespace std;

int connectedComponents(
    const vector<int>& offset,
    const vector<int>& edges,
    vector<int>& component
);

#endif
