class AdjMatrixGraph
{
public:
	AdjMatrixGraph( );
	AdjMatrixGraph(int totalVertices);

	void createAdjMatrixGraph(const vector<vector<string>>& graphData);

	void printVertices() const;
	void printAllSuccessors() const;

	// The Big 5

	//copy contructor
	AdjMatrixGraph(const AdjMatrixGraph& otherMatrix);

	//move constructor
	AdjMatrixGraph(AdjMatrixGraph&& otherMatrix);

	//assignment operator
	AdjMatrixGraph& operator=(const AdjMatrixGraph&);

	//move assignement operator
	AdjMatrixGraph& operator=(AdjMatrixGraph&& otherMatrix);

	//destructor
	~AdjMatrixGraph();

	// detroyGraph
	void destroyGraph();

private:

	string *vertices;		//will point to an array storing labels for vertices
    int **matrix;			//will point to the adjacency matrix
    int maxVertices;		//max number of vertices the graph can hold (capacity)
    int numOfVertices;		//total number of vertices

};
