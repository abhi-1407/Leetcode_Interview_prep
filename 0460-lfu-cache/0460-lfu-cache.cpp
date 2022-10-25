struct Node{
    int key,value,cnt;
    Node *next;
    Node *prev;
    Node(int key,int value)
    {
        this->key=key;
        this->value=value;
        cnt=1;
    }
};

struct List{
  int size;
  Node *head;
  Node *tail;
  List()
  {
      size=0;
      head=new Node(0,0);
      tail=new Node(0,0);
      head->next=tail;
      tail->prev=head;
  }

  void addNode(Node *newNode) {
        Node *temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
        size++;
    }
 void deleteNode(Node *delNode) {
        Node *delPrev = delNode->prev;
        Node *delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
        size--;
    }
};
class LFUCache {
public:
    unordered_map<int, Node*> addrOfKey;    // hashmap for storing the - address corresponding to a key / Node containing that key
    unordered_map<int, List*> freqListMap; 
    int maxSizeCache;
    int minFreq;
    int currsize;
    
    LFUCache(int capacity) {
         maxSizeCache=capacity;
         minFreq=0;
         currsize=0;
    }
        void updateFreqListMap(Node *node) {
        addrOfKey.erase(node->key);                     // delete the address of the key
        freqListMap[node->cnt]->deleteNode(node);       // delete the Node with "cnt" frequency from the corresponding List
        if (node->cnt == minFreq && freqListMap[node->cnt]->size == 0) {
            minFreq++;                                  // if the deleted node had the min-frequency, after deletion,
            // the Node with the next higher frequency will have the min-frequency
        }
        List *nextHigherFreqList = new List();
        if (freqListMap.find(node->cnt + 1) != freqListMap.end()) {
            nextHigherFreqList = freqListMap[node->cnt + 1]; // List containing Nodes which are accessed 1 time more than the deleted Node
            // (means the List having Nodes with use-frequency 1 more than use-frequency of the Nodes from the LFU list)
        }
        node->cnt += 1;                                      // increment the use-frequency of that Node by 1, bcz it is being accessed once more
        nextHigherFreqList->addNode(node);                   // add that Node at the front (MRU position) of the newly created List
        freqListMap[node->cnt] = nextHigherFreqList;         // Map the List against the new use-frequency
        addrOfKey[node->key] = node;                         // store the address of the newly added node against the key
    }
    
     int get(int key) {
        if (addrOfKey.find(key) == addrOfKey.end()) {       // if no such key exists in the record
            return -1;
        }
        Node *resNode = addrOfKey[key];                     // if the key exists, find the Node corresponding to that key
        int res = resNode->value;                             // get the value stored against that key
        updateFreqListMap(resNode);                         // make the changes associated to the Node containing the key
        return res;                                         // returns the value stored against that key
    }
    
       void put(int key, int value) {
        if (maxSizeCache == 0) {                           //  if the cache-size is zero, don't update the value against the key and return
            return;
        }
        if (addrOfKey.find(key) != addrOfKey.end()) {       // if the key is present in the address-map
            Node *existingNode = addrOfKey[key];            // find the Node that the key is residing in
            existingNode->value = value;                      // update the existing value of that Node with the new given value
            updateFreqListMap(existingNode);                // make the changes associated to the Node containing the key
        } else {                                            // if the key is NOT present in the address-map
            if (currsize == maxSizeCache) {                // if size of the cache reaches its maximum capacity, if cache is full
                List *list = freqListMap[minFreq];          // fetch the head of the List having LFU Nodes
                Node *prevNode = list->tail->prev;          // find the LRU Node from that List
                int keyToBeErased = prevNode->key;          // find the key corresponding to the LRU Node
                addrOfKey.erase(keyToBeErased);             // delete the address of that key
                freqListMap[minFreq]->deleteNode(prevNode); // delete the LRU node from the LRU location of that List
                currsize--;                                 // decrement the current size of cache, now cache is NOT full
            }

            // if the given key is NOT present in the address-map
            currsize++;                                     // increment the current size of the cache
            minFreq = 1;                                    // set the use - frequency of the Node containg that key to 1

            List *listFreq = new List();
            if (freqListMap.find(minFreq) != freqListMap.end()) {
                listFreq = freqListMap[minFreq];            // find the List with min-frequency (List having the LFU Nodes)
            }
            Node *newNode = new Node(key, value);           // create a new Node with the given key and value
            listFreq->addNode(newNode);                     // add the new Node at the front (MRU position) of the List having LFU Nodes
            addrOfKey[key] = newNode;                       // store the address of the MRU Node from the List having LFU Nodes
            freqListMap[minFreq] = listFreq;                // store the List having LFU Nodes against the minimum use-frequency
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */