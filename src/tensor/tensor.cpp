#include <tensor.h>
#include <vector>
#include <map>
#include <string>
using namespace std;



template <class T>
class Storage {
private:
    T *values;
public:
    void Storage(MemoryAllocator *memory_allocator, int size) {
        int ret = memory_allocator.allocate(values, size);
        if(ret != 0) {
            cout << "memory allocator could not allocate values of size " << size << "\n";
            exit(-1);
        }
    }
};

class TensorMeta{
private:
    vector<int>* shape;
public:
    void setShape(vector<int>& nshape) {
        for(int idx = 0 ; idx < nshape.size(); idx++) {
            (*shape)[idx] = nshape[idx];
        }
    }
}

class Tensor {
private: 
    TensorMeta meta;
public:
    void Tensor(TensorMeta &meta) {
        this->meta = meta;
    }
};

class FloatTensor: public Tensor {
private: 
    Storage<float> *storage;
public:
    void Tensor(Storage<float> *storage, TensorMeta &meta): Tensor(meta) {
        this->storage = storage;
    }
    
};

enum DeviceEnum {
    CPU, 
    GPU
};
enum DtypeEnum {
    FLOAT16 
    FLOAT32
    INT8
};


Tensor zeros(vector<int> &shape, DeviceEnum device, DtypeEnum dtype) {
    TensorMeta meta;
    meta.setShape(shape);
    if(dtype == FLOAT32) {
        // Storage<float> *storage = new Storage<float>()
    }
}


