class AdjListGraph
{
public:
	AdjListGraph( );
	AdjListGraph(int totalVertices);

	void createAdjListGraph(const vector<vector<string>>& graphData);

	void printVertices() const;
	void printAllSuccessors() const;
	
	// The Big 5

	//copy contructor
	AdjListGraph(const AdjListGraph& otherGraph);

	//move constructor
	AdjListGraph(AdjListGraph&& otherGraph);

	//assignment operator
	AdjListGraph& operator =(const AdjListGraph& otherGraph);

	//move assignment operator
	AdjListGraph& operator =(AdjListGraph&& otherGraph);

	//destructor
	~AdjListGraph();

	// Function destroyGraph
	void destroyGraph();

	

protected:

	string *vertices;		//will point to an array storing labels for vertices
	AnyList **list;			//will point to an array of objects of type AnyList (successors)
    int maxVertices;		//max number of vertices the graph can hold (capacity)
    int numOfVertices;		//total number of vertices
};

#endif
