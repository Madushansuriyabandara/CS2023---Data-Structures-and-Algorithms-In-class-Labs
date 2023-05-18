#include <iostream>
#include <list>
using namespace std;

struct Node {
    int label;
    list<int> neighbours;
};

struct Graph {
    int n = 8;
    Node* nodes = new Node[n];

    void initializeNodes(){
        for(int i = 0; i < n; i++){
            nodes[i].label = i + 1;
        }
    }

    void addedge(int u, int v){
        nodes[u - 1].neighbours.push_back(v);
        nodes[v - 1].neighbours.push_back(u);
    }

    void print(){
        for(int i = 0; i < n; i++){
            cout << nodes[i].label << " -> [";
            for(auto it = nodes[i].neighbours.begin(); it != nodes[i].neighbours.end(); ++it){
                cout << *it;
                if(next(it) != nodes[i].neighbours.end()){
                    cout << ", ";
                }
            }
            cout << "]" << endl;
        }
    }
};

int main() {
    Graph* g = new Graph;
    g->initializeNodes();
    // Add edges for the graph here.
    g->addedge(1, 2);
    g->addedge(1, 3);
    g->addedge(1, 4);
    g->addedge(1, 5);
    g->addedge(2, 3);
    g->addedge(2, 6);
    g->addedge(3, 1);
    g->addedge(3, 2);
    g->addedge(4, 1);
    g->addedge(4, 6);
    g->addedge(4, 7);
    g->addedge(4, 8);
    g->addedge(5, 1);
    g->addedge(5, 6);
    g->addedge(5, 7);
    g->addedge(5, 8);

    // Print the graph adjacency list
    g->print();

    delete g;
    return 0;
}

