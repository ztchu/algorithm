#include<iostream>
#include<string>
#include<vector>
#include<iterator>

using namespace std;

const int MAX_INT = 65536;

typedef struct 
{
	vector<vector<int> > mat;
	int vertex;
}Graph;

void Dijkstra(int start, Graph &g, vector<int> &dist, vector<int> &prev)
{
	dist.resize(g.vertex);
	prev.resize(g.vertex);
	vector<bool> visited(g.vertex, false);

	for (int i = 0; i < g.vertex; ++i)
	{
		dist[i] = g.mat[start][i];
		if (dist[i] == MAX_INT)
			prev[i] = -1;
		else
			prev[i] = start;
	}
	visited[start] = true;
	dist[start] = 0;

	for (int i = 1; i < g.vertex; ++i)
	{
		int minDist = MAX_INT;
		int loc = start;
		for (int j = 0; j < g.vertex; ++j)
		{
			if (!visited[j] && (dist[j] < minDist))
			{
				loc = j;
				minDist = dist[j];
			}
		}
		if (loc == start)
			break;
		visited[loc] = true;

		for (int j = 0; j < g.vertex; ++j)
		{
			if (!visited[j] && (g.mat[loc][j] < MAX_INT))
			{
				if (dist[loc] + g.mat[loc][j] < dist[j])
				{
					dist[j] = dist[loc] + g.mat[loc][j];
					prev[j] = loc;
				}
			}
		}
	}
}




void Print(Graph &g)
{
	cout << "the number of vertexs: " ;
	cout << g.vertex << endl;

	for (int i = 0; i < g.vertex; ++i)
	{
		for (int j = 0; j < g.vertex; ++j)
		{
			cout << g.mat[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void InitGraph(Graph &g)
{
	cout << "Please input the number of vertex:" << endl;
	cin >> g.vertex;

	g.mat.resize(g.vertex, vector<int> (g.vertex, MAX_INT));

	for (int i = 0; i < g.vertex; ++i)
	{
		g.mat[i][i] = 0;
	}

	cout << "Please input the number of edges:" << endl;
	int edge;
	cin >> edge;

	cout << "Please input the start end weight:" << endl;
	for (int i = 0; i < edge; ++i)
	{
		int start, end, weight;
		cin >> start >> end >> weight;
		g.mat[start][end] = g.mat[end][start] = weight;
	}
}

int main()
{
	Graph g;
	InitGraph(g);
	Print(g);

	int start = 0;
	vector<int> dist;
	vector<int> prev;

	Dijkstra(start, g, dist, prev);

	copy(dist.begin(), dist.end(), ostream_iterator<int>(cout, " "));
	
	//cout << "hello world" << endl;
}
