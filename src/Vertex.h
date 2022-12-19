#pragma once

template <typename Name, typename Data> class Vertex {
public:
  Vertex() {}

  Vertex(int index_) { index = index_; }

  int GetIndex() { return index; }

  Name GetName() { return name; }

  Data GetData() { return data; }

  void SetName(Name name_) { name = name_; }

  void SetData(Data data_) { data = data_; }

  void SetIndex(int index_) { index = index_; }

private:
  Name name = Name(0);
  Data data = Data(0);
  int index = 0;
};