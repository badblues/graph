#pragma once

#include <vector>
#include <iostream>
#include <sstream>
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

        int V() {
            return vertex_number;
        }

        int E() {
            return edge_number;
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
            if (matrix[id1][id2] == nullptr) {
                edge_number++;
                cout << "isdirected = " << directed << "\n";
                if (!directed) {
                    matrix[id2][id1] = edge;
                }
                matrix[id1][id2] = edge;
                return edge;
            } else {
                return nullptr;
            }
        }

        Edge* GetEdge(Vertex* V1, Vertex* V2) {
            int id1 = -1, id2 = -1;
            for (int i = 0; i < vertex_number && (id1 == -1 || id2 == -1); i++) {
                if (vertices[i] == V1)
                    id1 = i;
                if (vertices[i] == V2)
                    id2 = i;
            }
            return matrix[id1][id2];
        }

        bool DeleteE(Vertex* V1, Vertex* V2) {
            int id1 = -1, id2 = -1;
            for (int i = 0; i < vertex_number && (id1 == -1 || id2 == -1); i++) {
                if (vertices[i] == V1)
                    id1 = i;
                if (vertices[i] == V2)
                    id2 = i;
            }
            if (matrix[id1][id2] != nullptr) {
                edge_number--;
                free(matrix[id1][id2]);
                matrix[id1][id2] = nullptr;
                if (!directed)
                    matrix[id2][id1] = nullptr;
                return true;
            }
            return false;
        } 

        bool DeleteV(Vertex* V) {
            int id = -1;
            for (int i = 0; i < vertex_number && id == -1; i++)
                if (vertices[i] == V)
                    id = i;
            if (id != -1) {
                for (int i = 0; i < vertex_number; i++) {
                    DeleteE(vertices[id], vertices[i]);
                    DeleteE(vertices[i], vertices[id]);
                    matrix[i].erase(matrix[i].begin() + id);
                }
                matrix.erase(matrix.begin() + id);
                vertex_number--;
                return true;
            }
            return false;
        }

        //my methods:

        // void Clear();

        string StructureToString() {
            stringstream *sstr = new stringstream;
            cout << "MATRIX:\n";
            for (int i = 0; i < vertex_number; i++) {
                for (int j = 0; j < vertex_number; j++)
                    *sstr << matrix[i][j] << " ";
                *sstr << "\n";
            }
            return sstr->str();
        }
};