void prima (int** g,int n) // алгоритм Прима
{
	vector<bool> used (n);
	vector<int> min_e (n, INF), sel_e (n, -1);
	min_e[0] = 0;
	for (int i=0; i<n; ++i) 
	{
		int v = -1;
		for (int j=0; j<n; ++j)
			if (!used[j] && (v == -1 || min_e[j] < min_e[v]))
				v = j;
		used[v] = true;
		if (sel_e[v] != -1)
			cout << v << " " << sel_e[v] << endl;
		for (int to=0; to<n; ++to)
			if (g[v][to] < min_e[to]) 
			{
				min_e[to] = g[v][to];
				sel_e[to] = v;
			}
	}
}