#include <stdio.h>
#include <stdlib.h>
typedef struct{
	int val;
	int idx;
}Node;

Node* tree;
int* arr;

int swap_count = 0;

Node maxNode(Node a, Node b){
	if(a.val > b.val) return a;
	else return b;

}

Node build(int node, int start, int end){
	if(start == end){
		tree[node].val = arr[start];
		tree[node].idx = start;
		return tree[node];
	}
	
	int mid = (start+end) /2;
	
	Node left = build(node*2, start, mid);
	Node right = build(node*2+1, mid+1,end);
	
	tree[node] = maxNode(left,right);
	return tree[node];
}

Node query(int node, int start, int end, int l, int r){
	Node invalid = {-1, -1};

	if(r < start || end < l) return invalid;

	if(l <= start && end <= r) return tree[node];

	int mid = (start + end) /2;

	Node left = query(node*2, start, mid, l, r);
	Node right = query(node*2+1, mid+1, end, l, r);
		
	if(left.idx == -1) return right;
	if(right.idx == -1) return left;

	return maxNode(left,right);
}

void update(int node, int start, int end, int idx){
	if(start == end){
		tree[node].val = arr[idx];
		return;
	}

	int mid = (start + end) /2;

	if(idx <= mid) update(node*2,start,mid,idx);
	else update(node*2+1,mid+1,end,idx);

	tree[node] = maxNode(tree[node*2],tree[node*2+1]);
}

void selection_sort(int N, int K){
	for(int i=N-1;i>0;i--){
		Node max = query(1,0,N-1,0,i);
		if(max.idx != i){
			swap_count++;
			
			arr[max.idx] = arr[i];
			arr[i] = max.val;
            
            if(swap_count == K){
                for(int j=0;j<N;j++) printf("%d ",arr[j]);
                return;
            }
            
			update(1,0,N-1,i);
			update(1,0,N-1,max.idx);
		}
	}
}

int main(){
        int N,K;
        scanf("%d %d",&N,&K);
        tree = (Node*)malloc(sizeof(Node)*(N*4));
        arr = (int*)malloc(sizeof(int)*N);
        for(int i=0;i<N;i++){
                scanf("%d",&arr[i]);
        }
	build(1,0,N-1);
	selection_sort(N,K);
	if(swap_count < K) printf("-1");
	return 0;
}

