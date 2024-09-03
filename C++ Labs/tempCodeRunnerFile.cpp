/* Aadrij Upadya
May 24th, 2024
Shortest Path Algorithm, Lab 7 Parts 1 and 2
Finds shortest path between two vertices on a graph
*/

#include <iostream>
#include <set>
#include <string>
#include <math.h>
#include <vector>
#include <queue>

using namespace std;

// creating a struct that can hold vetrtices and adjacent matrix as a 2d array
struct graph
{
    int num_verts;
    int adj_matx[20][20];
};

// creating a struct that can hold the information for each vertex (shortest path to it, predecessors, if its visited)
struct vertex
{
    int shortest_path;
    int predecessors;
    bool visited;
};

/**
 * @brief Initializes an adjacency matrix for given graph
 * @param g new graph that has an empty adjacency matrix
 * @return graph with a newly initialized adjacency matrix (with 0s)
 */
void init_adj_matx(graph &g)
{
    // nested for loop that iterates n x n, where n is number of vertices graph has
    for (int row = 0; row < g.num_verts; row++)
    {
        for (int col = 0; col < g.num_verts; col++)
        {
            // initially everything is set to zero because no edges are provided
            g.adj_matx[row][col] = 0;
        }
    }
}

/**
 * @brief Adds edge to given graph
 * @param g graph that we want to add edges to
 * @param vertex1 integer that represents one of the vertices incident on the edge we are adding
 * @param vertex2 integer that represents one of the vertices incident on the edge we are adding
 * @return graph with a change in adj_matx that reflects edge being added
 */
void add_edge(graph &g, int vertex1, int vertex2)
{
    // make sure to set both (i,j) and (j,i) as 1, as an edge is reversable
    g.adj_matx[vertex1][vertex2] = 1;
    g.adj_matx[vertex2][vertex1] = 1;
}

/**
 * @brief Stores information of graph on page 382 #10
 * @param g graph variable that we want to store information in
 * @param num_verts number of vertices for the provided graph
 * @return graph with edges provided
 */
void create_graph_382(graph &g, int num_verts)
{
    g.num_verts = num_verts;
    init_adj_matx(g);
    // adding all the necessary edges
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 3);
    add_edge(g, 2, 5);
    add_edge(g, 1, 2);
    add_edge(g, 1, 4);
    add_edge(g, 2, 4);
    add_edge(g, 3, 4);
    add_edge(g, 4, 5);
}

/**
 * @brief Stores information of graph on page 404 #5
 * @param g graph variable that we want to store information in
 * @param num_verts number of vertices for the provided graph
 * @return graph with edges provided
 */
void create_graph_404(graph &g, int num_verts)
{
    g.num_verts = num_verts;
    init_adj_matx(g);
    // adding all the necessary edges
    add_edge(g, 0, 1);
    add_edge(g, 1, 2);
    add_edge(g, 2, 3);
    add_edge(g, 3, 4);
    add_edge(g, 0, 5);
    add_edge(g, 5, 6);
    add_edge(g, 6, 7);
    add_edge(g, 4, 7);
    add_edge(g, 1, 6);
    add_edge(g, 3, 6);
    add_edge(g, 6, 8);
    add_edge(g, 8, 9);
    add_edge(g, 6, 9);
}

/**
 * @brief Stores information of graph on page 403 #1
 * @param g graph variable that we want to store information in
 * @param num_verts number of vertices for the provided graph
 * @return graph with edges provided
 */
void create_graph_403(graph &g, int num_verts)
{
    g.num_verts = num_verts;
    init_adj_matx(g);
    // adding all the necessary edges
    add_edge(g, 0, 1);
    add_edge(g, 0, 3);
    add_edge(g, 0, 4);
    add_edge(g, 0, 8);
    add_edge(g, 1, 2);
    add_edge(g, 1, 4);
    add_edge(g, 1, 6);
    add_edge(g, 2, 6);
    add_edge(g, 2, 7);
    add_edge(g, 3, 8);
    add_edge(g, 4, 8);
    add_edge(g, 4, 5);
    add_edge(g, 5, 6);
    add_edge(g, 5, 8);
    add_edge(g, 5, 9);
    add_edge(g, 6, 7);
    add_edge(g, 7, 9);
    add_edge(g, 8, 9);
}

/**
 * @brief Prints contents of adjacency matrix
 * @param g graph that we want to view adjacency matrix of
 */
void print_adj_matx(graph &g)
{
    // nested for loop to iterate through every element
    for (int row = 0; row < g.num_verts; row++)
    {
        for (int col = 0; col < g.num_verts; col++)
        {
            cout << g.adj_matx[row][col] << " ";
        }
        cout << endl;
    }
}

/**
 * @brief Prints contents of edge list given incident matrix
 * @param g graph that we want to view adjacency matrix of
 */
void print_edge_list(vector<vector<int>> inc_matx)
{
    // iterating through 2d vector where each vector represents column of incident matrix
    for (int row = 0; row < inc_matx.size(); row++)
    {
        cout << "Edge " << row + 1 << " from points: ";
        for (int col = 0; col < inc_matx[0].size(); col++)
        {
            // if one of the nested vectors is 1, that means an edge originates or ends at that vertex
            if (inc_matx[row][col] == 1)
            {
                cout << col << " ";
                // column number contains the vertex at given index
            }
        }
        cout << endl;
    }
}

/**
 * @brief Prints incident matrix of a given graph
 * @param g graph that we want to view incident matrix of
 */
void create_and_print_inc_matx(graph &g)
{
    // storing incident matrix as a vector because it is dependent on number of edges, which we don't store as a variable
    vector<vector<int>> inc_matx;
    // iterate through adjacency matrix, which we will use to form incident matrix
    for (int row = 0; row < g.num_verts; row++)
    {
        for (int col = 0; col < g.num_verts; col++)
        {
            // if a certain vertex is adjacent at a point (value is 1), and the incident matrix hasn't already covered that point
            if (g.adj_matx[row][col] == 1 && inc_matx[col][row] != 1)
            {
                // create a vector that represents edge between given vertices
                vector<int> edge;
                bool duplicate = false;
                // row and column both represent vertex points, so add 1 to edge if we hit those points
                for (int i = 0; i < g.num_verts; i++)
                {
                    if ((i == row) || (i == col))
                    {
                        edge.push_back(1);
                    }
                    else
                    {
                        edge.push_back(0);
                    }
                }
                // checking for duplicate edges by checking edges already in incident matrix
                for (int j = 0; j < inc_matx.size(); j++)
                {
                    if (edge == inc_matx[j])
                    {
                        duplicate = true;
                    }
                }
                // if not a duplicate, we add to our incident matrix
                if (!duplicate)
                {
                    inc_matx.push_back(edge);
                }
            }
        }
    }

    // printing contents of incident matrix by column and row because we stored each vector as a row (so we need to transpose the matrix)
    for (int row = 0; row < inc_matx[0].size(); row++)
    {
        for (int col = 0; col < inc_matx.size(); col++)
        {
            cout << inc_matx[col][row] << " ";
        }
        cout << endl;
    }

    // printing edges that are formed as well
    cout << endl;
    cout << "Edge list" << endl;
    print_edge_list(inc_matx);
    cout << endl;
}

/**
 * @brief Finds shortest path between any two vertices of a graph
 * @param gr reference to graph that contain the vertices
 * @param start_vert integer that refers to the starting of the path
 * @param end_vert integer that refers to the end of the path
 */
void find_shortest_path(graph &gr, int start_vert, int end_vert)
{
    // creating a queue of unprocessed vertices to keep track of path
    queue<int> unproc_vertices;
    bool done = false;
    // initializing array of vertices to keep track of graph informatinon
    vertex vertices[20];
    // initializing each vertex with default settings, as unvisited
    for (int i = 0; i < gr.num_verts; i++)
    {
        vertex v;
        v.visited = false;
        vertices[i] = v;
    }
    // start vertex has default settings as well, push it to queue
    vertices[start_vert].predecessors = -1;
    vertices[start_vert].shortest_path = 0;
    vertices[start_vert].visited = true;
    unproc_vertices.push(start_vert);
    // loop while we aren't at end vertex and there are still unprocessed vertices
    while (!done && !unproc_vertices.empty())
    {
        // front vertex will be the vertex we compare to
        int front_comparison = unproc_vertices.front();
        unproc_vertices.pop();
        // remember to pop after processing
        for (int nn = 0; nn < gr.num_verts; nn++)
        {
            // checking each next neighbors of the front vertex to see if there is a connection between that neighbor and front vertex
            if ((gr.adj_matx[front_comparison][nn] == 1) && vertices[nn].visited == false)
            {
                // checking to see if we have hit end vertex, if so, we kill the loop
                if (nn == end_vert)
                {
                    done = !done;
                }
                // adding said neighbor to the path
                vertices[nn].visited = true;
                vertices[nn].shortest_path = vertices[front_comparison].shortest_path + 1;
                vertices[nn].predecessors = front_comparison;
                // this neighbor becomes our next vertex to process
                unproc_vertices.push(nn);
            }
        }
    }

    // following code aims to reverse the path while reading
    cout << endl;
    int from = end_vert;
    int to = vertices[end_vert].shortest_path;
    vertices[to].shortest_path = end_vert;
    // continually reversing using predecessor and shortest path to that vertex
    while (from != -1)
    {
        to -= 1;
        vertices[to].shortest_path = vertices[from].predecessors;
        from = vertices[from].predecessors;
    }
    // display shortest path at end, in terms of number of edges crossed
    cout << "Number of edges crossed: " << vertices[end_vert].shortest_path << endl;
    // loop to display vertices in order that are covered in our path
    cout << "Vertices traversed: ";
    for (int i = 0; i <= vertices[end_vert].shortest_path; i++)
    {
        cout << vertices[i].shortest_path << " ";
    }
    cout << endl;
}

int main()
{
    // printing information for each of the different graph datasets

    cout << "Graph 382 #10's information" << endl;
    graph g382;
    cout << endl;
    create_graph_382(g382, 6);
    cout << "adjacency matrix" << endl;
    print_adj_matx(g382);
    cout << endl;
    cout << "incidence matrix" << endl;
    create_and_print_inc_matx(g382);
    find_shortest_path(g382, 0, 5);
    cout << endl;

    cout << "Graph 404 #5's information" << endl;
    graph g404;
    cout << endl;
    create_graph_404(g404, 10);
    cout << "adjacency matrix" << endl;
    print_adj_matx(g404);
    cout << endl;
    cout << "incidence matrix" << endl;
    create_and_print_inc_matx(g404);
    find_shortest_path(g404, 1, 8);
    cout << endl;

    cout << "Graph 403 #1's information" << endl;
    graph g403;
    cout << endl;
    create_graph_403(g403, 10);
    cout << "adjacency matrix" << endl;
    print_adj_matx(g403);
    cout << endl;
    cout << "incidence matrix" << endl;
    create_and_print_inc_matx(g403);
    find_shortest_path(g403, 0, 6);
    cout << endl;
}
