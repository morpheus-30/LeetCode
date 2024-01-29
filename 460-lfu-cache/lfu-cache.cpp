class Node
{
public:
    pair<int, int> keyVal;
    Node *next;
    int cnt;
    Node *prev;
    

    Node(int key, int val)
    {
        keyVal = {key, val};
        next = NULL;
        prev = NULL;
        cnt = 1;
    }
};

class List
{
public:
    Node *head;
    Node *tail;
    int size;
    List()
    {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        size = 0;
        tail->prev = head;
    }
    void addFront(Node *node)
    {
        Node *temp = head->next;
        head->next = node;
        node->prev = head;
        node->next = temp;
        temp->prev = node;
        size++;
    }
    void removeNode(Node *node)
    {
        Node* delprev = node->prev;
        Node* delnext = node->next;
        delprev->next = delnext;
        delnext->prev = delprev;
        size--;
    }
};

class LFUCache
{
private:
    unordered_map<int, Node *> keyNode;
    unordered_map<int, List *> occuranceList;
    int minFreq;
    int maxSize;
    int currSize;

public:
    LFUCache(int capacity)
    {
        maxSize = capacity;
        currSize = 0;
        minFreq = 0;    
    }

    void updateFreqList(Node *node)
    {
        keyNode.erase(node->keyVal.first);
        occuranceList[node->cnt]->removeNode(node);
        if (node->cnt == minFreq && occuranceList[node->cnt]->size == 0)
        {
            minFreq++;
        }
        List *nextHigherFreqList = new List();
        if (occuranceList.find(node->cnt + 1) != occuranceList.end())
        {
            nextHigherFreqList = occuranceList[node->cnt + 1];
        }
        node->cnt+=1;
        nextHigherFreqList->addFront(node);
        occuranceList[node->cnt] = nextHigherFreqList;
        keyNode[node->keyVal.first] = node;
    }

    int get(int key)
    {
        if (keyNode.find(key) != keyNode.end())
        {
            Node *node = keyNode[key];
            int val = node->keyVal.second;
            updateFreqList(node);
            return val;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (maxSize == 0)
        {
            return;
        }
        if (keyNode.find(key) != keyNode.end())
        {
            Node *node = keyNode[key];
            node->keyVal = {key, value};
            updateFreqList(node);
        }
        else
        {
            if (currSize == maxSize)
            {
                List *mylist = occuranceList[minFreq];
                keyNode.erase(mylist->tail->prev->keyVal.first);
                occuranceList[minFreq]->removeNode(mylist->tail->prev);
                currSize--;
            }
            currSize++;
            minFreq = 1;
            List *listFreq = new List();
            if (occuranceList.find(minFreq) != occuranceList.end())
            {
                listFreq = occuranceList[minFreq];
            }
            Node* node = new Node(key,value);
            listFreq->addFront(node);
            keyNode[key] = node;
            occuranceList[minFreq] = listFreq;
        }
    }
};
