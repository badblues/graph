#pragma once


template<typename Name, typename Data>
class Vertex{
    public:

        Vertex() {}
        Vertex(Name name_, Data data_) {
            name = name_;
            data = data_;
        }

        Name GetName() {
            return name;
        }

        Data GetData() {
            return data;
        }

        void SetName(Name name_) {
            name = name_;
        }

        void SetData(Data data_) {
            data = data_;
        } 
        
    private:
        Name name;
        Data data;
        int index;
};