#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define N 8
#define endl '\n'
#define starting_node 1

static int visited[N+1] = {0};
vector<int> graph[N+1];

void dfs(int n) {
    cout<<n<<" ";
    visited[n] = 1;
    for (int x:graph[n]) {
        if (!visited[x]) {
            dfs(x);
        }
    }
}

int main(){
    graph[0] = {};
    graph[1] = {2,3};
    graph[2] = {1,5,6};
    graph[3] = {1,4,7};
    graph[4] = {3,8};
    graph[5] = {2};
    graph[6] = {2};
    graph[7] = {3,8};
    graph[8] = {4,7};

    dfs(1);

    cout<<endl;
    for (int i = 0;i<=N;i++) {
        cout<<i<<"->";
        for (int j:graph[i]) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
