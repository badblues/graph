template<typename E, typename N>
class Edge {
    public:

        Edge(Node<N> v1_, Node<N> v2_) {
            v1 = v1_;
            v2 = v2_;
        }

        Edge(Node<N> v1_, Node<N> v2_, int w_) {
            v1 = v1_;
            v2 = v2_;
            w = w_;
        }

        Edge(Node<N> v1_, Node<N> v2_, int w_, E data_) {
            v1 = v1_;
            v2 = v2_;
            w = w_;
            data = data_;
        }

        Node<N> V1() {
            return v1;
        }

        Node<N> V2() {
            return v2;
        }

        int GetW() {
            return w;
        }

        void SetW(int w_) {
            w = w_;
        }

        E GetData() {
            return data;
        }

        void SetData(E data_) {
            data = data_;
        }
        
    private:
        Node<N> v1;
        Node<N> v2;
        int w;
        E data;
}