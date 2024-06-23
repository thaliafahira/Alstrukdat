bool IsEmpty (Queue Q){
    return Q.idxHead == IDX_UNDEF && Q.idxTail == IDX_UNDEF;
}

bool isFUll(Queue Q){
    return (Q.idx.Tail + 1) % CAPACITY == Q.idxHead;
}

int lenght (Queue Q){
    if (IsEmpty Q) {
        return 0;
    else {
        return (Q.idxTail - Q.idxHead + CAPACITY) % CAPACITY + 1;
    }

    }
}

void CreateQueue (Queue *Q){
    Q -> idxHead = IDX_UNDEF;
    Q -> idxTail = IDX_UNDEF;
}

void enqueue (Queue *Q, ElType val){
    if (!IsFull){
        if (IsEmpty){
            Q -> idxHead = 0;
        }
        Q -> idxTail = (Q -> idxTail + 1) % CAPACITY;
        Q -> buffer [Q -> idxTail] = val;
    }
}

void dequeue (Queue *Q, ElType val){
    if(!IsEmpty){
        *val = Q -> buffer[Q -> idxHead];
        if (Q -> idxHead == Q -> idxTail){
            Q -> idxHead = IDX_UNDEF;
            Q -> idxTail = IDX_UNDEF;
        }
        else{
            Q -> idxHead = (Q.idxHead + 1) % CAPACITY;
        }
    }
}