#include <iostream>
#include <vector>

void print_vec(const std::vector<int>& num) {
    for (int v : num) std::cout << v << " ";
    std::cout << "\n";
}

void quicksort(std::vector<int>& num,int l,int r){
    if(l>=r)return ;
    int pivot = num[l];
    int i=l+1,j=r;
    while(i<j){
        while(i<j&&num[j]>=pivot)j--;
        while(i<j&&num[i]<=pivot)i++;
        
        if(i<j)std::swap(num[i],num[j]);
    }
    std::swap(num[l],num[i]);
    quicksort(num,l,i-1);
    quicksort(num,i+1,r);
}
void merge(std::vector<int> &num,int l,int mid,int r){
    int i=l,j = mid+1,k=0;
    std::vector<int> tmp(r-l+1);
    while(i<=mid&&j<=r){
        if(num[i]<=num[j])tmp[k++]=num[i++];
        else tmp[k++]=num[j++];
    }
    while(i<=mid)tmp[k++]=num[i++];
    while(j<=r)tmp[k++]=num[j++];
    for(int i=0;i<k;i++)num[i+l]=tmp[i];
}
void mergesort(std::vector<int> &num,int l,int r){
    if(l>=r)return ;
    int mid = l + (r-l)/2;
    mergesort(num,l,mid);
    mergesort(num,mid+1,r);
    merge(num,l,mid,r);
}
void heapify(std::vector<int> &num,int root ,int n){
    int child = root*2+1;
    while(child<n){
        if(child+1<n&&num[child+1]>num[child])child++;
        if(num[root]<num[child]){
            std::swap(num[root],num[child]);
            root = child,child = root*2+1;
        }else break;
    }
}
void heapsort(std::vector<int> &num){
    const int n = num.size();
    for(int i=n/2-1;i>=0;i--)heapify(num,i,n);
    for(int i=n-1;i>0;i--){
        std::swap(num[0],num[i]);
        heapify(num,0,i);
    }
}

int main() {
    std::vector<int> data = {5, 1, 4, 2, 8, 3};

    std::vector<int> a = data;
    quicksort(a, 0, static_cast<int>(a.size()) - 1);
    std::cout << "quick sort: ";
    print_vec(a);

    std::vector<int> b = data;
    mergesort(b, 0, static_cast<int>(b.size()) - 1);
    std::cout << "merge sort: ";
    print_vec(b);

    std::vector<int> c = data;
    heapsort(c);
    std::cout << "heap sort: ";
    print_vec(c);

    return 0;
}