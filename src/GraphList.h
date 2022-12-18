#pragma once

#include <sstream>
#include "GraphForm.h"
using namespace std;

//adjacency this->matrix
template<class Vertex, class Edge>
class GraphList : public GraphForm<Vertex, Edge> {
    public:
    
        GraphList(bool directed) : GraphForm<Vertex, Edge>(directed) {
            cout << "GraphList\n";
        }

        ~GraphList() {
            this->Clear();
        }

        Vertex* InsertV() override {
            Vertex* vertex = new Vertex();
            this->vertices.push_back(vertex);
            this->vertex_number++;
            vector<Edge*> vector_;
            this->matrix.push_back(vector_);
            return vertex;
        }

        Edge* InsertE(Vertex* V1, Vertex* V2) override {
            int id1 = this->GetId(V1), id2 = this->GetId(V2);
            Edge* edge = new Edge(V1, V2);
            for (int i = 0; i < this->matrix[id1].size(); i++) {
                if (!this->directed && IsDesired(V1, V2, this->matrix[id1][i]))
                    return nullptr;
                if (this->directed && (this->matrix[id1][i]->V1() == V1 && this->matrix[id1][i]->V2() == V2))
                    return nullptr;
            }
            this->matrix[id1].push_back(edge);
            this->edge_number++;
            if (!this->directed && id1 != id2)
                this->matrix[id2].push_back(edge);
            return edge;
        }

        Edge* GetEdge(Vertex* V1, Vertex* V2) override {
            int id1 = this->GetId(V1);
            for (int i = 0; i < this->matrix[id1].size(); i++)
                if (this->matrix[id1][i]->V2() == V2 && this->matrix[id1][i]->V1() == V1)
                    return this->matrix[id1][i];
            return nullptr;
        }

        bool DeleteE(Vertex* V1, Vertex* V2) override {
            int id1 = this->GetId(V1), id2 = this->GetId(V2);
            if (id1 != -1 && id2 != -1) {
                if (!this->directed) {
                    for (int i = 0; i < this->matrix[id1].size(); i++)
                        if (IsDesired(V1, V2, this->matrix[id1][i])) {
                            this->matrix[id1].erase(this->matrix[id1].begin() + i);
                            break;
                        }
                    for (int i = 0; i < this->matrix[id2].size(); i++)
                        if (IsDesired(V1, V2, this->matrix[id2][i])) {
                            free(this->matrix[id2][i]);
                            this->matrix[id2].erase(this->matrix[id2].begin() + i);
                            this->edge_number--;
                            return true;
                        }
                } else {
                    for (int i = 0; i < this->matrix[id1].size(); i++)
                        if (this->matrix[id1][i]->V1() == V1 && this->matrix[id1][i]->V2() == V2) {
                            free(this->matrix[id1][i]);
                            this->matrix[id1].erase(this->matrix[id1].begin() + i);
                            this->edge_number--;
                            return true;
                        }
                }
            }
            return false;
        }

        bool DeleteV(Vertex* V) override {
            int id = this->GetId(V);
            for (int i = 0; i < this->vertex_number; i++) {
                DeleteE(V, this->vertices[i]);
                if (this->directed)
                    DeleteE(this->vertices[i], V);
            }
            this->matrix.erase(this->matrix.begin() + id);
            free(this->vertices[id]);
            this->vertices.erase(this->vertices.begin() + id);
            this->vertex_number--;
            return false;
        }

        string ToString() override {
            stringstream *sstr = new stringstream;
            for (int i = 0; i < this->vertex_number; i++) {
                *sstr << i << "[" << this->vertices[i]->GetName() << "," << this->vertices[i]->GetName() << "]: ";
                for (int j = 0; j < this->matrix[i].size(); j++) {
                    Edge* edge = this->matrix[i][j];
                    *sstr << "[" << this->GetId(edge->V1()) << "," << this->GetId(edge->V2()) << ",w(" << edge->GetW() << "),d(" << edge->GetData() << ")] ";
                }
                *sstr << "\n";
            }
            return sstr->str();
        }

    private:

        bool IsDesired(Vertex* V1, Vertex* V2, Edge* E) {
            return (E->V1() == V1 && E->V2() == V2) || (E->V1() == V2 && E->V2() == V1);
        }
};