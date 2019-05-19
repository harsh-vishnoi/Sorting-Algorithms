    #include<bits/stdc++.h>
    #include <graphics.h>
    #include <direct.h>
    #include<stdlib.h>
    #define RUN 32
    using namespace std;

    int n;
    int arr[1000];
    void printarray(int ,int );
    void printarray2(){
        cleardevice();
        for(int j = 0 ; j < n ; j++ )
           {setcolor(5);

            line(10+j*3,500,10+j*3,500-arr[j]);
           }
        delay (2000);
    }

    int getMax(int arr[], int n)
    {
        int mx = arr[0];
        for (int i = 1; i < n; i++)
            if (arr[i] > mx)
                mx = arr[i];
        return mx;
    }

    void countSort(int arr[], int n, int exp)
    {
        int output[n]; // output array
        int i, count[10] = {0};
        for (i = 0; i < n; i++)
            count[ (arr[i]/exp)%10 ]++;
        for (i = 1; i < 10; i++)
            count[i] += count[i - 1];

        for (i = n - 1; i >= 0; i--)
        {
            output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
            count[ (arr[i]/exp)%10 ]--;}
            srand(time(NULL));
          int alpha=rand();
          int beta=rand();
          printarray(alpha,beta);


          for (i = 0; i < n; i++)
            arr[i] = output[i];
    }

    void insertionSort(int arr[], int left, int right)
    {
        for (int i = left + 1; i <= right; i++)
        {
            int temp = arr[i];
            int j = i - 1;
            while (arr[j] > temp && j >= left)
            {
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = temp;
        }
    }

    void merge1(int arr[], int l, int m, int r)
    {
        int len1 = m - l + 1, len2 = r - m;
        int left[len1], right[len2];
        for (int i = 0; i < len1; i++)
            left[i] = arr[l + i];
        for (int i = 0; i < len2; i++)
            right[i] = arr[m + 1 + i];

        int i = 0;
        int j = 0;
        int k = l;
        while (i < len1 && j < len2)
        {
            if (left[i] <= right[j])
            {
                arr[k] = left[i];
                i++;
            }
            else
            {
                arr[k] = right[j];
                j++;
            }
            k++;
        }
        while (i < len1)
        {
            arr[k] = left[i];
            k++;
            i++;
        }

        // copy remaining element of right, if any
        while (j < len2)
        {
            arr[k] = right[j];
            k++;
            j++;
        }
    }

    void timSort(int arr[], int n)
    {

        for (int i = 0; i < n; i+=RUN)
            insertionSort(arr, i, min((i+31), (n-1)));
        for (int size = RUN; size < n; size = 2*size)
        {
            for (int left = 0; left < n; left += 2*size)
            {
                int mid = left + size - 1;
                int right = min((left + 2*size - 1), (n-1));
                merge1(arr, left, mid, right);
                int alpha=left;
                int beta=right;
                printarray(alpha,beta);
            }
        }
    }

    void radixsort(int arr[], int n)
    {
        int m = getMax(arr, n);

        for (int exp = 1; m/exp > 0; exp *= 10)
            countSort(arr, n, exp);
    }
        void merge(int arr[], int l, int m, int r)
    {
        int i, j, k;
        int n1 = m - l + 1;
        int n2 =  r - m;
        int L[n1], R[n2];
        for (i = 0; i < n1; i++)
            L[i] = arr[l + i];
        for (j = 0; j < n2; j++)
            R[j] = arr[m + 1+ j];
        i = 0; // Initial index of first subarray
        j = 0; // Initial index of second subarray
        k = l; // Initial index of merged subarray
        while (i < n1 && j < n2)
        {
            if (L[i] <= R[j])
            {
                arr[k] = L[i];
                i++;
            }
            else
            {
                arr[k] = R[j];
                j++;
            }
            k++;
        }
      while (i < n1)
        {
            arr[k] = L[i];
            i++;
            k++;
        }
        while (j < n2)
        {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    void mergeSort( int arr[],int l ,int r)
    {
        if (l < r)
        {
            int m = l+(r-l)/2;
      mergeSort(arr, l, m);
            mergeSort(arr, m+1, r);
            int alpha=m+1;
            int beta=r;
            srand(time(NULL));
            beta=rand()%500;
            printarray(alpha,beta);
            merge(arr, l, m, r);
        }
    }

    void selectionSort()
    {
        int i, j, min_idx;
       for (i = 0; i < n-1; i++)
        {   int alpha=-1,beta=-1;
            min_idx = i;
            for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
           swap(arr[min_idx], arr[i]);
           alpha=min_idx,beta=i;
           printarray(alpha,beta);
        }
    }

    void bubblesort()
    {
        for(int i=0;i<n-1;i++){
            int alpha=-1,beta=-1;
            for(int j=0;j<n-i-1;j++){
                if(arr[j]>arr[j+1]){
                    swap(arr[j+1],arr[j]);
                    alpha=j+1;
                    beta=j;

                }
            }
            printarray(alpha,beta);
        }
    }
    
    void heapify(int arr[], int n, int i)
    {
        int largest = i; // Initialize largest as root
        int l = 2*i + 1; // left = 2*i + 1
        int r = 2*i + 2; // right = 2*i + 2
        if (l < n && arr[l] > arr[largest])
            largest = l;
        if (r < n && arr[r] > arr[largest])
            largest = r;
        if (largest != i)
        {
            swap(arr[i], arr[largest]);
            //printarray(i,largest);
            heapify(arr, n, largest);
        }
    }

    void heapSort(int arr[], int n)
    {
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(arr, n, i);
        for (int i=n-1; i>=0; i--)
        {
            swap(arr[0], arr[i]);
            printarray(0,i);
            heapify(arr, i, 0);
        }
    }

    void printarray(int alpha,int beta){
        cleardevice();
       // setcolor(14);
        if(alpha==beta && beta==-1){
            return;
        }

        for(int j = 0 ; j < n ; j++ )
           {

            setcolor(1);

            if((j+n/20>alpha && j-n/20<alpha) || (j+n/20>beta && j-n/20<beta)){
                setcolor(14);
            }
            line(10+j*3,500,10+j*3,500-arr[j]);
            delay(0.5);
           }
    }
    
    int main()
    {
       int i, j = 0, gd = DETECT, gm;

       initgraph(&gd,&gm,"C:\\TC\\BGI");
        initwindow(2000,1000);
       settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
       outtextxy(25,240,"Press any key to view the moving car");

       getch();
        cleardevice();
        cin>>n;
        int b[n];
        for(int i=0;i<n;i++)cin>>arr[i],b[i]=arr[i];
        cout<<"pppp";
        bubblesort();
        printarray2();
        for(int i=0;i<n;i++)arr[i]=b[i];
        selectionSort();
        printarray2();
        for(int i=0;i<n;i++)arr[i]=b[i];
        mergeSort(arr,0,n);
        printarray2();
        for(int i=0;i<n;i++)arr[i]=b[i];
        heapSort(arr,n);
        printarray2();
        for(int i=0;i<n;i++)arr[i]=b[i];
        radixsort(arr,n);
        printarray2();
        for(int i=0;i<n;i++)arr[i]=b[i];
        timSort(arr,n);
        printarray2();
        getch();

       closegraph();
       return 0;
    }

