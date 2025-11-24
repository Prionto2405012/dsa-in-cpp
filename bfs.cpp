#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define N 9
#define endl '\n'
#define starting_node 6

int main(){
    vector<int> graph[N+1];
    graph[0] = {};
    graph[1] = {2,6};
    graph[2] = {3,1,4};
    graph[3] = {2};
    graph[4] = {2,5};
    graph[5] = {4,8};
    graph[6] = {1,9,7};
    graph[7] = {6,8};
    graph[8] = {5,7};
    graph[9] = {6};

    int visited[N+1] = {0};
    queue<int> q;
    q.push(starting_node);
    visited[starting_node] = 1;
    while (!q.empty()) {
        int curr = q.front();
        cout<<curr<<" ";
        q.pop();
        for (int x:graph[curr]) {
            if (!visited[x]) {
                visited[x] = 1;
                q.push(x);
            }
        }
    }
    cout<<endl;


    cout<<endl;
    for (int i = 0;i<=N;i++) {
        cout<<i<<"->";
        for (int j:graph[i]) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
