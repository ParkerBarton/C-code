//
//  main.c
//  COP4600_P2
//
//  Created by Parker Barton on 2/28/20.
//  Copyright © 2020 Parker Barton. All rights reserved.
//

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include<time.h>

struct address{
    unsigned addr;
    char rw;
    int dirty;
};


/*copied code*/
struct Queue
{
    int front, rear, size;
    unsigned capacity;
    //int* array;
    struct address *array;
};
struct Queue* createQueue(unsigned capacity)
{
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;  // This is important, see the enqueue
    queue->array = (struct address*) malloc(queue->capacity * sizeof(struct address));
    return queue;
}
int isFull(struct Queue* queue)
{  return (queue->size == queue->capacity);  }
int isEmpty(struct Queue* queue)
{  return (queue->size == 0); }
void enqueue(struct Queue* queue, struct address item)
{
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1)%queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
    //printf("%d enqueued to queue\n", item);
}
  
// Function to remove an item from queue.
// It changes front and size
struct address dequeue(struct Queue* queue)
{
//    if (isEmpty(queue))
//        return NULL;
    struct address item = queue->array[queue->front];
    queue->front = (queue->front + 1)%queue->capacity;
    queue->size = queue->size - 1;
    return item;
}
struct Queue* removeFromQueue(struct Queue* queue, struct address item, int nframes) {
    struct Queue* temp = createQueue(nframes);
    while(!isEmpty(queue)){
        if(queue->array[queue->front].addr != item.addr)
            enqueue(temp, dequeue(queue));
        else
            dequeue(queue);
    }
    while(!isEmpty(temp))
        enqueue(queue, dequeue(temp));
    return queue;
}
int isInQueue(struct Queue* queue, struct address item, int nframes) {
    for(int i=0;i<nframes;i++){
        if(queue->array[i].addr == item.addr){
            return 1;
        }
    }
    return 0;
}
/*copied code*/



int isin(struct address pt[], unsigned addr, int nframes){
    for(int i=0;i<nframes;i++){
        if(pt[i].addr == addr){
            return 1;
        }
    }
    return 0;
}

void debugPrint(int access, char hm, int evict) {
    if(evict == -1){
        printf("%d\t%c\t\n", access, hm);
    }
    else
        printf("%d\t%c\t%d\n", access, hm, evict);
}


void RDM(struct address pt[], struct address addrs[], int dq, int nframes, int npages){
    srand(time(0));
    int Wcount = 0, Rcount = 0, j = 0;
    for(int i = 0;i < nframes + j; i++){
        if(!isin(pt, addrs[i].addr, nframes)) {
            if(addrs[i].rw == 'R')
                Rcount++;
            pt[i-j] = addrs[i];
            if(dq == 1)
                debugPrint(addrs[i].addr, 'M', -1);
        }
        else {
            j++;
            if(dq == 1)
                debugPrint(addrs[i].addr, 'H', -1);
        }
    }
    for(int i = nframes + j;i < npages;i++){
        int evict = ((rand() % nframes));
        if(!isin(pt, addrs[i].addr, nframes)){
            if(pt[evict].rw == 'W')
                Wcount++;
            if(addrs[i].rw == 'R')
                Rcount++;
            if(dq == 1)
                debugPrint(addrs[i].addr, 'M', pt[evict].addr);
            pt[evict] = addrs[i];
            
        }
        else if(dq == 1)
            debugPrint(addrs[i].addr, 'H', -1);
    }
    printf("Read: %d, Write: %d\n", Rcount, Wcount);
}
void LRU(struct address pt[], struct address addrs[], int dq, int nframes, int npages){
    struct Queue* pageTable = createQueue(nframes);
    int Wcount = 0, Rcount = 0, i = 0;
    while(!isFull(pageTable)){
        if(!isInQueue(pageTable, addrs[i], nframes)) {
            if(addrs[i].rw == 'R')
                Rcount++;
            enqueue(pageTable, addrs[i]);
            if(dq == 1)
                debugPrint(addrs[i].addr, 'M', -1);
        } else {
            removeFromQueue(pageTable, addrs[i], nframes);
            enqueue(pageTable, addrs[i]);
            if (dq == 1)
                debugPrint(addrs[i].addr, 'H', -1);
        }
        i++;
    }
    for(; i < npages; i++) {
        if(!isInQueue(pageTable, addrs[i], nframes)) {
            if(dq == 1)
                debugPrint(addrs[i].addr, 'M', pageTable->array[pageTable->front].addr);
            if(dequeue(pageTable).rw == 'W')
                Wcount++;
            if(addrs[i].rw == 'R')
                Rcount++;
            enqueue(pageTable, addrs[i]);
            
        }
        else {
            removeFromQueue(pageTable, addrs[i], nframes);
            enqueue(pageTable, addrs[i]);
            if (dq == 1)
                debugPrint(addrs[i].addr, 'H', -1);
        }
    }
    printf("Read: %d, Write: %d\n", Rcount, Wcount);
    
}
void FIFO(struct address pt[], struct address addrs[], int dq, int nframes, int npages){
    struct Queue* pageTable = createQueue(nframes);
    int Wcount = 0, Rcount = 0, i = 0;
    while(!isFull(pageTable)){
        if(!isInQueue(pageTable, addrs[i], nframes)) {
            if(addrs[i].rw == 'R')
                Rcount++;
            enqueue(pageTable, addrs[i]);
            if(dq == 1)
                debugPrint(addrs[i].addr, 'M', -1);
        } else if (dq == 1)
            debugPrint(addrs[i].addr, 'H', -1);
        i++;
    }
    for(; i < npages; i++) {
        if(!isInQueue(pageTable, addrs[i], nframes)) {
            if(dq == 1)
                debugPrint(addrs[i].addr, 'M', pageTable->array[pageTable->front].addr);
            if(dequeue(pageTable).rw == 'W')
                Wcount++;
            if(addrs[i].rw == 'R')
                Rcount++;
            enqueue(pageTable, addrs[i]);
            
        }
        else if (dq == 1)
            debugPrint(addrs[i].addr, 'H', -1);
    }
    printf("Read: %d, Write: %d\n", Rcount, Wcount);
    
    
    
}

int ptIsFull(struct Queue* p1, struct Queue* p2, struct Queue* c, struct Queue* d, int nframes) {
    //printf("%d",p1->size + p2->size + c->size + d->size);
    if(p1->size + p2->size + c->size + d->size >= nframes)
        return 1;
    return 0;
}

void VMS(int Paddrs[], struct address pt[], struct address addrs[], int dq, int nframes, int npages){
    int RSS = nframes/2;
    struct Queue* p1 = createQueue(RSS);
    struct Queue* p2 = createQueue(RSS);
    struct Queue* clean = createQueue(RSS);
    struct Queue* dirty = createQueue(RSS);
    
    struct address evict;
    
    int Wcount = 0, Rcount = 0;
    for(int i = 0; i < npages; i++) {
        evict.addr=-1;
        char hm = 'M';
        
        if(isInQueue(clean, addrs[i], RSS) || isInQueue(dirty, addrs[i], RSS)) {
            hm = 'H';
        }
        
        if(isInQueue(clean, addrs[i], RSS))
            removeFromQueue(clean, addrs[i], RSS);
        else if(isInQueue(dirty, addrs[i], RSS))
            removeFromQueue(dirty, addrs[i], RSS);

        if(Paddrs[i] == 3) {
            if(!isInQueue(p1, addrs[i], RSS)) {
                if(ptIsFull(p1, p2, clean, dirty, nframes)) {
                    if(!isEmpty(clean))
                        evict = dequeue(clean);
                    else if(!isEmpty(dirty)){
                        evict = dequeue(dirty);
                        Wcount++;
                    }
                }
                if(isFull(p1)) {
                    if(p1->array[p1->front].rw == 'R') {
                        if(isFull(clean))
                            evict = dequeue(clean);
                        enqueue(clean, dequeue(p1));
                    }
                    else {
                        if(isFull(dirty)) {
                            evict = dequeue(dirty);
                            Wcount++;
                        }
                        enqueue(dirty, dequeue(p1));
                    }
                }
                enqueue(p1, addrs[i]);
            } else {
                hm = 'H';
                
            }
        }
        else {
            if(!isInQueue(p2, addrs[i], RSS)) {
                if(ptIsFull(p1, p2, clean, dirty, nframes)) {
                    if(!isEmpty(clean))
                        evict = dequeue(clean);
                    else if(!isEmpty(dirty)){
                        evict = dequeue(dirty);
                        Wcount++;
                    }
                }
                if(isFull(p2)) {
                    if(p2->array[p2->front].rw == 'R') {
                        if(isFull(clean))
                            evict = dequeue(clean);
                        enqueue(clean, dequeue(p2));
                    }
                    else {
                        if(isFull(dirty)) {
                            evict = dequeue(dirty);
                            Wcount++;
                        }
                        enqueue(dirty, dequeue(p2));
                    }
                }
                enqueue(p2, addrs[i]);
            }
            else
                hm = 'H';
        }
        if(addrs[i].rw == 'R' && hm == 'M')
            Rcount++;
        if(dq == 1) {
            debugPrint(addrs[i].addr, hm, evict.addr);
        }
    }
    printf("Read: %d, Write: %d\n", Rcount, Wcount);
    
}
 
void memsim(char tracefile[], int nframes, int alg, int dq){
    FILE *in_file  = fopen(tracefile, "r");
    struct address pageTable[nframes];
    unsigned addr;
    char rw;
    int R = 0, W = 0, i=0;
    int Paddrs[1000000];
    struct address *addrs = malloc(1500000 * sizeof(struct address));
    while(EOF != fscanf(in_file,"%x %c",&addr,&rw)){
        Paddrs[i] = (addr>>28) & 0xF;
        addrs[i].addr = addr>>12;
        addrs[i].rw = rw;
        i++;
        if(rw == 'R'){R++;}
        else{W++;}
    }
    fclose(in_file);
    switch (alg) {
        case 1:
            RDM(pageTable, addrs, dq, nframes, (R+W));
            break;
        case 2:
            LRU(pageTable, addrs, dq, nframes, (R+W));
            break;
        case 3:
            FIFO(pageTable, addrs, dq, nframes, (R+W));
            break;
        case 4:
            VMS(Paddrs, pageTable, addrs, dq, nframes, (R+W));
            break;
        default:
            break;
    }
}

int main(void) 
{
    char file[100];
    int frames, algChoice, runType;
    
    printf("Memory Simulator!\n");
    printf("Enter the name of trace file: ");
    scanf("%s",file);
    printf("Enter number of frames: ");
    scanf("%d",&frames);
    printf("Algorithm Choice:\n1. RDM\n2. LRU\n3. FIFO\n4. VMS\nEnter choice: ");
    scanf("%d",&algChoice);
    printf("Run Type:\n1. Debug\n2. Quiet\nEnter choice: ");
    scanf("%d",&runType);
    
    memsim(file, frames, algChoice, runType);
    return 0;
}
