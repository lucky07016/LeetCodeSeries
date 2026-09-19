class LRUCache {
public:
    class Node {
    public:
        int key, value;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            prev = nullptr;
            next = nullptr;
        }
    };

    int capacity;
    unordered_map<int, Node*> mp;

    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        this->capacity = capacity;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    void removeNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void addToFront(Node* node) {
        Node* temp = head->next;

        head->next = node;
        node->prev = head;

        node->next = temp;
        temp->prev = node;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        Node* node = mp[key];

        removeNode(node);
        addToFront(node);

        return node->value;
    }

    void put(int key, int value) {

        // Key already exists
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];

            node->value = value;

            removeNode(node);
            addToFront(node);

            return;
        }

        // Cache is full
        if (mp.size() == capacity) {
            Node* lru = tail->prev;

            mp.erase(lru->key);
            removeNode(lru);
            delete lru;
        }

        Node* newNode = new Node(key, value);

        addToFront(newNode);
        mp[key] = newNode;
    }
};