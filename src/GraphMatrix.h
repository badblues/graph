#pragma once

#include <vector>
#include <iostream>
using namespace std;

//adjacency matrix
template<class Vertex, class Edge>
class GraphMatrix {
    private:
        int edge_number;
        int vertex_number;
        bool directed;
        vector<vector<Edge*>> matrix;
        vector<Vertex*> vertices;
    public:
    
        GraphMatrix(bool directed) {
            this->directed = directed;
            edge_number = 0;
            vertex_number = 0;
            cout << "GraphMatrix()\n";
        }

        Vertex* InsertV() {
            Vertex* vertex = new Vertex(vertices.size(), vertices.size());
            vertices.push_back(vertex);
            vertex_number++;
            vector<Edge*> vector_;
            matrix.push_back(vector_);
            for (int i = 0; i < vertex_number; i++) {
                matrix[i].push_back(nullptr);  //push_backing in new column
                if (i < vertex_number - 1)
                    matrix[vertex_number - 1].push_back(nullptr); //push_backing in new row
            }
            cout << "MATRIX:\n";
            for (int i = 0; i < vertex_number; i++) {
                for (int j = 0; j < vertex_number; j++)
                    cout << matrix[i][j] << " ";
                cout << "\n";
            }
            return vertex;
        }

        Edge* InsertE(Vertex* V1, Vertex* V2) {
            int id1 = -1, id2 = -1;
            Edge* edge = new Edge(V1, V2);
            for (int i = 0; i < vertex_number && (id1 == -1 || id2 == -1); i++) {
                if (vertices[i] == V1)
                    id1 = i;
                if (vertices[i] == V2)
                    id2 = i;
            }
            matrix[id1][id2] = edge;
            cout << "MATRIX:\n";
            for (int i = 0; i < vertex_number; i++) {
                for (int j = 0; j < vertex_number; j++)
                    cout << matrix[i][j] << " ";
                cout << "\n";
            }
            return edge;
        }

        // bool DeleteV(Vertex V);
        // bool DeleteE(Vertex V1, Vertex V2); 
        // Edge* GetEdge(Vertex V1, Vertex V2);
        // void Clear();

};