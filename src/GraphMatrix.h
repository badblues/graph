#pragma once

#include <sstream>
#include "GraphForm.h"
using namespace std;

//adjacency this->matrix
template<class Vertex, class Edge>
class GraphMatrix : public GraphForm<Vertex, Edge> {
    public:
    
        GraphMatrix(bool directed) : GraphForm<Vertex, Edge>(directed) {
            cout << "GraphMatrix\n";
        }

        ~GraphMatrix() {
            this->Clear();
        }

        Vertex* InsertV() override {
            Vertex* vertex = new Vertex(this->vertex_number);
            this->vertex_number++;
            vector<Edge*> vector_;
            this->matrix.push_back(vector_);
            for (int i = 0; i < this->vertex_number; i++) {
                this->matrix[i].push_back(nullptr);  //push_backing in new column
                if (i < this->vertex_number - 1)
                    this->matrix[this->vertex_number - 1].push_back(nullptr); //push_backing in new row
            }
            return vertex;
        }

        Edge* InsertE(Vertex* V1, Vertex* V2) override {
            int id1 = V1->GetIndex(), id2 = V2->GetIndex();
            Edge* edge = new Edge(V1, V2);
            if (this->matrix[id1][id2] == nullptr) {
                this->edge_number++;
                if (!this->directed) {
                    this->matrix[id2][id1] = edge;
                }
                this->matrix[id1][id2] = edge;
                return edge;
            } else {
                return nullptr;
            }
        }

        Vertex* InsertV(Vertex* V) override {
            this->vertex_number++;
            vector<Edge*> vector_;
            this->matrix.push_back(vector_);
            for (int i = 0; i < this->vertex_number; i++) {
                this->matrix[i].push_back(nullptr);  //push_backing in new column
                if (i < this->vertex_number - 1)
                    this->matrix[this->vertex_number - 1].push_back(nullptr); //push_backing in new row
            }
            return V;
        }

        Edge* InsertE(Edge* edge) override {
            int id1 = (edge->V1())->GetIndex(), id2 = (edge->V2())->GetIndex();
            if (id1 != -1 && id2 != -1 && this->matrix[id1][id2] == nullptr) {
                this->edge_number++;
                if (!this->directed) {
                    this->matrix[id2][id1] = edge;
                }
                this->matrix[id1][id2] = edge;
                return edge;
            } else {
                return nullptr;
            }
        }

        Edge* GetEdge(Vertex* V1, Vertex* V2) override {
            int id1 = V1->GetIndex(), id2 = V2->GetIndex();
            return this->matrix[id1][id2];
        }

        bool DeleteE(Vertex* V1, Vertex* V2) override {
            int id1 = V1->GetIndex(), id2 = V2->GetIndex();
            if (id1 != -1 && id2 != -1 && this->matrix[id1][id2] != nullptr) {
                this->edge_number--;
                this->matrix[id1][id2] = nullptr;
                if (!this->directed)
                    this->matrix[id2][id1] = nullptr;
                return true;
            }
            return false;
        } 

        bool DeleteV(Vertex* V) override {
            int id = V->GetIndex();
            for (int i = 0; i < this->matrix[id].size(); i++) {
                Edge* edge = this->matrix[id][i];
                if (edge != nullptr) {
                    Vertex* V2 = (edge->V1() == V) ? edge->V2() : edge->V1();
                    DeleteE(V, V2);
                }
                this->matrix[i].erase(this->matrix[i].begin() + id);
            }
            this->matrix.erase(this->matrix.begin() + id);
            this->vertex_number--;
            return true;
        }

        string ToString(vector<Vertex*> vertices) override {
            stringstream *sstr = new stringstream;
            for (int i = 0; i < this->vertex_number; i++) {
                *sstr << " " << i << "[" << vertices[i]->GetName() << "," << vertices[i]->GetData() << "]"; 
            }
            *sstr << "\n";
            for (int i = 0; i < this->vertex_number; i++) {
                *sstr << i << " ";
                for (int j = 0; j < this->vertex_number; j++) {
                    Edge* edge = this->matrix[i][j];
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

};