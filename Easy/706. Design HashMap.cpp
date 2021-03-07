class MyHashMap {
    vector<int> hashmap;
public:
    MyHashMap() : hashmap(1000001, -1) {} //All keys and values are in the range of [0, 1000000]
    
    void put(int key, int value) {hashmap[key] = value;}
    
    int get(int key) {return hashmap[key];}
    
    void remove(int key) {hashmap[key] = -1;}
};