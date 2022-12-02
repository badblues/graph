#pragma once


template<typename N, typename ND>
class Vertex{
    public:

        Vertex() {}
        Vertex(N name_, ND data_) {
            name = name_;
            data = data_;
        }

        N GetName() {
            return name;
        }

        ND GetData() {
            return data;
        }

        void SetName(N name_) {
            name = name_;
        }

        void SetData(ND data_) {
            data = data_;
        } 
        
    private:
        N name;
        ND data;
        int index;
};