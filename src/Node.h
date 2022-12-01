
template<typename N>
class Node{
    public:

        Node() {}
        Node(string name_, N data_) {
            name = name_;
            data = data_;
        }

        string GetName() {
            return name;
        }

        N GetData() {
            return data;
        }

        void SetName(string name_) {
            name = name_;
        }

        void SetData(N data_) {
            data = data_;
        } 
        
    private:
        string name;
        N data;
        int index;
}