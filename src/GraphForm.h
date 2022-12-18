#pragma once
#include <vector>
#include <iostream>

using namespace std;

template<class Vertex, class Edge>
class GraphForm {
    public:

        GraphForm(bool directed) {
            this->directed = directed;
            edge_number = 0;
            vertex_number = 0;
            cout << "GraphForm()\n";
        }

        int V() {
            return vertex_number;
        }

        int E() {
            return edge_number;
        }

        virtual Vertex* InsertV() = 0;

        virtual Edge* InsertE(Vertex* V1, Vertex* V2) = 0;

        virtual Edge* GetEdge(Vertex* V1, Vertex* V2) = 0;

        virtual bool DeleteE(Vertex* V1, Vertex* V2) = 0;

        virtual bool DeleteV(Vertex* V) = 0;

        virtual string ToString() = 0;

    protected:

        int edge_number;
        int vertex_number;
        bool directed;
        vector<Vertex*> vertices;

        int GetId(Vertex* V) {
            int id = -1;
            for (int i = 0; i < vertex_number && id == -1; i++)
                if (vertices[i] == V)
                    id = i;
            return id;
        }

};