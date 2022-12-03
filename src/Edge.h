#pragma once

#include "Vertex.h"


template<class Vertex, typename W, typename Data>
class Edge {
    public:

        Edge(Vertex* v1_, Vertex* v2_) {
            v1 = v1_;
            v2 = v2_;
        }

        Edge(Vertex* v1_, Vertex* v2_, W w_) {
            v1 = v1_;
            v2 = v2_;
            w = w_;
        }

        Edge(Vertex* v1_, Vertex* v2_, W w_, Data data_) {
            v1 = v1_;
            v2 = v2_;
            w = w_;
            data = data_;
        }

        Vertex* V1() {
            return v1;
        }

        Vertex* V2() {
            return v2;
        }

        W GetW() {
            return w;
        }

        void SetW(W w_) {
            w = w_;
        }

        Data GetData() {
            return data;
        }

        void SetData(Data data_) {
            data = data_;
        }
        
    private:
        Vertex* v1;
        Vertex* v2;
        W w;
        Data data;
};