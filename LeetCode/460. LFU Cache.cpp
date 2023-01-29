// https://www.youtube.com/watch?v=0PSB9y8ehbk&ab_channel=takeUforward

struct Node{
    int key, value, useCnt;
    Node * next = NULL;
    Node * prev = NULL;
    Node(int _key, int _value, int _useCnt){
        key = _key;
        value = _value;
        useCnt = _useCnt;
    }
};

struct List{
    Node * head;
    Node * tail;
    int size;
    List(){
        head = new Node(0,0,0);
        tail = new Node(0,0,0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    Node* addAfterHead(int _key, int _value, int _useCnt){
        Node * newNode = new Node(_key, _value, _useCnt);
        newNode->next = head->next;
        head->next->prev = newNode;
        newNode->prev = head;
        head->next = newNode;
        size++;
        return newNode;
    }

    void deleteNode(Node * node){ //has memory leak
        node->next->prev = node->prev;
        node->prev->next = node->next;
        size--;
    }
};

class LFUCache {
    unordered_map<int, Node*> keyNodeMap;
    unordered_map<int, List*> freqMap;
    int cap = 0, leastFreq = 1, currSize = 0;

public:
    LFUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(keyNodeMap.find(key) != keyNodeMap.end()){
           Node * node = keyNodeMap[key]; 
           int res = node->value;
           updateFreq(node);
           return res;
        }else return -1;
    }

    void updateFreq(Node * node){
        int useCnt = node->useCnt;
        if(freqMap.find(useCnt+1) == freqMap.end()) freqMap[useCnt+1] = new List();
        Node * newNode = freqMap[node->useCnt+1]->addAfterHead(node->key, node->value, node->useCnt+1);
        freqMap[useCnt]->deleteNode(node);
        if(useCnt == leastFreq && freqMap[useCnt]->size == 0) leastFreq = useCnt+1;
        keyNodeMap[node->key] = newNode;
    }
    
    void put(int key, int value) {
       if(cap == 0) return;
       if(keyNodeMap.find(key) != keyNodeMap.end()){
          Node * node = keyNodeMap[key];
          node->value = value;
          updateFreq(node);
       }else {
           if(currSize + 1 > cap){
              List* list = freqMap[leastFreq];
              keyNodeMap.erase(list->tail->prev->key);
              list->deleteNode(list->tail->prev);
              currSize--;
           }
           if(freqMap.find(1) == freqMap.end()) freqMap[1] = new List();
           Node * newNode = freqMap[1]->addAfterHead(key, value, 1);
           keyNodeMap[key] = newNode;
           leastFreq = 1;
           currSize++;
       }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */