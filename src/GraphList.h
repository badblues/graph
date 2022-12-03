#pragma once

#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

//adjacency list
template<class Vertex, class Edge>
class GraphList {
    private:
        int edge_number;
        int vertex_number;
        bool directed;
        vector<Vertex*> vertices;
        vector<vector<Edge*>> list;
    public:
    
        GraphList(bool directed) {
            this->directed = directed;
            edge_number = 0;
            vertex_number = 0;
            cout << "GraphList()\n";
        }

        int V() {
            return vertex_number;
        }

        int E() {
            return edge_number;
        }

        Vertex* InsertV() {
            Vertex* vertex = new Vertex();
            vertices.push_back(vertex);
            vertex_number++;
            vector<Edge*> vector_;
            list.push_back(vector_);
            return vertex;
        }

        Edge* InsertE(Vertex* V1, Vertex* V2) {
            int id1 = GetId(V1), id2 = GetId(V2);
            Edge* edge = new Edge(V1, V2);
            for (int i = 0; i < list[id1].size(); i++) {
                if (!directed && IsDesired(V1, V2, list[id1][i]))
                    return nullptr;
                if (directed && (list[id1][i]->V1() == V1 && list[id1][i]->V2() == V2))
                    return nullptr;
            }
            list[id1].push_back(edge);
            edge_number++;
            if (!directed && id1 != id2)
                list[id2].push_back(edge);
            return edge;
        }

        Edge* GetEdge(Vertex* V1, Vertex* V2) {
            int id1 = GetId(V1);
            for (int i = 0; i < list[id1].size(); i++)
                if (list[id1][i]->V2() == V2 && list[id1][i]->V1() == V1)
                    return list[id1][i];
            return nullptr;
        }

        bool DeleteE(Vertex* V1, Vertex* V2) {
            int id1 = GetId(V1), id2 = GetId(V2);
            if (id1 != -1 && id2 != -1) {
                if (!directed) {
                    for (int i = 0; i < list[id1].size(); i++)
                        if (IsDesired(V1, V2, list[id1][i])) {
                            list[id1].erase(list[id1].begin() + i);
                            break;
                        }
                    for (int i = 0; i < list[id2].size(); i++)
                        if (IsDesired(V1, V2, list[id2][i])) {
                            free(list[id2][i]);
                            list[id2].erase(list[id2].begin() + i);
                            edge_number--;
                            return true;
                        }
                } else {
                    for (int i = 0; i < list[id1].size(); i++)
                        if (list[id1][i]->V1() == V1 && list[id1][i]->V2() == V2) {
                            free(list[id1][i]);
                            list[id1].erase(list[id1].begin() + i);
                            edge_number--;
                            return true;
                        }
                }
            }
            return false;
        }

        bool DeleteV(Vertex* V) {
            int id = GetId(V);
            for (int i = 0; i < vertex_number; i++) {
                DeleteE(V, vertices[i]);
                if (directed)
                    DeleteE(vertices[i], V);
            }
            list.erase(list.begin() + id);
            free(vertices[id]);
            vertices.erase(vertices.begin() + id);
            vertex_number--;
            return false;
        }

        // void Clear();

        string ToString() {
            stringstream *sstr = new stringstream;
            for (int i = 0; i < vertex_number; i++) {
                *sstr << i << "[" << vertices[i]->GetName() << "," << vertices[i]->GetName() << "]: ";
                for (int j = 0; j < list[i].size(); j++) {
                    Edge* edge = list[i][j];
                    *sstr << "[" << GetId(edge->V1()) << "," << GetId(edge->V2()) << ",w(" << edge->GetW() << "),d(" << edge->GetData() << ")] ";
                }
                *sstr << "\n";
            }
            return sstr->str();
        }

    private:

        int GetId(Vertex* V) {
            int id = -1;
            for (int i = 0; i < vertex_number && id == -1; i++)
                if (vertices[i] == V)
                    id = i;
            return id;
        }

        bool IsDesired(Vertex* V1, Vertex* V2, Edge* E) {
            return (E->V1() == V1 && E->V2() == V2) || (E->V1() == V2 && E->V2() == V1);
        }
};