#include <iostream> 
#include <vector> 

using namespace std; 

typedef vector<vector<int>> matrix; 

matrix add(matrix A, matrix B) { 
    matrix res(A.size(), vector<int>(A[0].size())); 
    for (int i = 0; i < A.size(); i++){
        for (int j = 0; j < A[0].size(); j++) {
            res[i][j] = A[i][j] + B[i][j]; 
        }
    }
    return res; 
}

matrix multiply(matrix &A, matrix &B) { 
    int n = A.size(); 
    matrix res(n, vector<int>(n));

    if (n == 1){
        res[0][0] = A[0][0] * B[0][0]; 
        return res; 
    }

    vector<matrix> subM(8, matrix(n/2, vector<int>(n/2))); 

    for (int i = 0; i < n/2; i++){
        for (int j = 0; j < n/2; j++){
            subM[0][i][j] = A[i][j]; 
            subM[1][i][j] = A[i][j + n/2]; 
            subM[2][i][j] = A[i + n/2][j]; 
            subM[3][i][j] = A[i + n/2][j + n/2]; 
            subM[4][i][j] = B[i][j]; 
            subM[5][i][j] = B[i][j + n/2]; 
            subM[6][i][j] = B[i + n/2][j]; 
            subM[7][i][j] = B[i + n/2][j + n/2]; 
        }
    }
    for (int i = 0; i < n/2; i++){
        for (int j = 0; j < n/2; j++){
            subM[4][i][j] = B[i][j]; 
        }
    }

    // todo: continue here
}
int main(){
    int n1 = 0, m1 = 0, n2 = 0, m2 = 0; 
    cout<<"Enter the number of rows and columns of the first matrix: ";
    cout<<"rows for arr1: ";
    cin >> n1;
    cout<<"columns for arr1: ";
    cin >> m1;
    cout<<"Enter the number of rows and columns of the second matrix: ";
    cout<<"rows for arr2: ";
    cin >> n2;
    cout<<"columns for arr2: ";
    cin >> m2;
    matrix arr1(n1, vector<int>(m1)); 
    matrix arr2(n2, vector<int>(m2)); 

    if(m1 != n2){
        cout<<"The matrices cannot be multiplied";
        return 0;
    }

    cout << "Enter the elements of the first matrix: "; 

    for(int i = 0; i < n1; i++){
        for(int j = 0; j < m1; j++){
            cin>>arr1[i][j];
        }
    }

    cout << "Enter the elements of the second matrix: "; 

    for(int i = 0; i < n2; i++){
        for(int j = 0; j < m2; j++){
            cin>>arr2[i][j];
        }
    }
    
    matrix result(n1, vector<int>(m2)); 


}