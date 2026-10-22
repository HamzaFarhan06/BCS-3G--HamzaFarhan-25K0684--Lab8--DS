    #include <iostream>
    using namespace std;

    int merge(int arr[], int start, int mid, int end){
        int p =0 , q = 0, cmpcnt = 0;
        int n1 = mid - start + 1;
        int n2 = end - mid;
        int *a1 = new int[n1];
        int *a2 = new int[n2];
        for(int i = 0 ; i < n1 ; i++){
            a1[i] = arr[start+i];
        }
        for(int i = 0; i< n2; i++){
            a2[i] = arr[mid+1+i];
        }
        int cnt = 0;
        while(p < n1 && q < n2){
            if(a1[p] <= a2[q]){
                arr[start+cnt] = a1[p];
                p++;
            }else{
                arr[start+cnt] = a2[q];
                q++;
            }
            cmpcnt ++;
            cnt ++;

        }
        while(p < n1){
            arr[start + cnt] = a1[p];
            p++;
            cnt++;
        }
        while(q < n2){
            arr[start + cnt] = a2[q];
            q++;
            cnt++;
        }

        return cmpcnt;



    }



    int mergesort(int arr[], int start, int end){
        int mid = start + ( end -start)/2;
        int ans = 0;
        if (start < end){
            mergesort(arr, start, mid);
            mergesort(arr , mid + 1, end);
            ans += merge(arr, start , mid, end);

        }
        return ans;
    }


    int main(){
        int n;
        cout << "Enter the number of elements: " << endl;
        cin >> n;
        int* arr = new int[n];
        for(int i = 0 ; i < n ; i++){
            cout << "Enter the value of urgency: " << endl;
            cin >> arr[i];
        }
        for(int i = 0 ; i < n ; i++){
            cout << arr[i] << " " ;

        }
        cout << endl;
        int comp = mergesort(arr, 0, n-1);
        for(int i = 0 ; i < n ; i++){
            cout << arr[i] << " " ;

        }
    
        cout << endl;
        cout << "Total comparisions made : " << comp << endl;
    }