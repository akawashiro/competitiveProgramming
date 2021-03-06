struct Edge{
        int to,cost;
};
bool operator < (const Edge &e,const Edge &f){	return e.cost>f.cost;	};	//INVERSE!!
typedef vector<vector<Edge>> Graph;

void addEdge(Graph &g,int from,int to,int cost){
    g[from].push_back((Edge){to,cost});
}

int dijkstra(const Graph &G, vector<int> &dist, int s,int g)
{
    dist = vector<int>(G.size(),INT_MAX/2);
    priority_queue<Edge> que;
    que.push(Edge{s,0});
    while(!que.empty()){
        Edge e=que.top();
        que.pop();
        if(e.cost<=dist[e.to]){
            dist[e.to]=e.cost;
            for(int i=0;i<(int)G[e.to].size();i++){
                if(e.cost+G[e.to][i].cost < dist[G[e.to][i].to]){
                    dist[G[e.to][i].to] = e.cost+G[e.to][i].cost;
                    que.push(Edge{G[e.to][i].to,e.cost+G[e.to][i].cost});
                }
            }
        }
    }
    return dist[g];
}

