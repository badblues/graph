#pragma once

#include <sstream>
#include "GraphForm.h"
using namespace std;

//adjacency matrix
template<class Vertex, class Edge>
class GraphMatrix : public GraphForm<Vertex, Edge> {
    private:
        vector<vector<Edge*>> matrix;
    public:
    
        GraphMatrix(bool directed) : GraphForm<Vertex, Edge>(directed) {
            cout << "GraphMatrix()\n";
        }

        Vertex* InsertV() override {
            Vertex* vertex = new Vertex();
            this->vertices.push_back(vertex);
            this->vertex_number++;
            vector<Edge*> vector_;
            matrix.push_back(vector_);
            for (int i = 0; i < this->vertex_number; i++) {
                matrix[i].push_back(nullptr);  //push_backing in new column
                if (i < this->vertex_number - 1)
                    matrix[this->vertex_number - 1].push_back(nullptr); //push_backing in new row
            }
            return vertex;
        }

        Edge* InsertE(Vertex* V1, Vertex* V2) override {
            int id1 = this->GetId(V1), id2 = this->GetId(V2);
            Edge* edge = new Edge(V1, V2);
            if (id1 != -1 && id2 != -1 && matrix[id1][id2] == nullptr) {
                this->edge_number++;
                if (!this->directed) {
                    matrix[id2][id1] = edge;
                }
                matrix[id1][id2] = edge;
                return edge;
            } else {
                return nullptr;
            }
        }

        Edge* GetEdge(Vertex* V1, Vertex* V2) override {
            int id1 = this->GetId(V1), id2 = this->GetId(V2);
            return matrix[id1][id2];
        }

        bool DeleteE(Vertex* V1, Vertex* V2) override {
            int id1 = this->GetId(V1), id2 = this->GetId(V2);
            if (id1 != -1 && id2 != -1 && matrix[id1][id2] != nullptr) {
                this->edge_number--;
                free(matrix[id1][id2]);
                matrix[id1][id2] = nullptr;
                if (!this->directed)
                    matrix[id2][id1] = nullptr;
                return true;
            }
            return false;
        } 

        bool DeleteV(Vertex* V) override {
            int id = this->GetId(V);
            if (id != -1) {
                for (int i = 0; i < this->vertex_number; i++) {
                    DeleteE(this->vertices[id], this->vertices[i]);
                    DeleteE(this->vertices[i], this->vertices[id]);
                    matrix[i].erase(matrix[i].begin() + id);
                }
                matrix.erase(matrix.begin() + id);
                free(this->vertices[id]);
                this->vertices.erase(this->vertices.begin() + id);
                this->vertex_number--;
                return true;
            }
            return false;
        }

        // void Clear();

        string ToString() override {
            stringstream *sstr = new stringstream;
            for (int i = 0; i < this->vertex_number; i++) {
                *sstr << " " << i << "[" << this->vertices[i]->GetName() << "," << this->vertices[i]->GetData() << "]"; 
            }
            *sstr << "\n";
            for (int i = 0; i < this->vertex_number; i++) {
                *sstr << i << " ";
                for (int j = 0; j < this->vertex_number; j++) {
                    Edge* edge = matrix[i][j];
                    if (edge) {
                        *sstr << "[" << edge->GetW() << ", " << edge->GetData() << "] ";
                    } else {
                        *sstr << "null  ";
                    }
                }
                *sstr << "\n";
            }
            return sstr->str();
        }

    private:

};