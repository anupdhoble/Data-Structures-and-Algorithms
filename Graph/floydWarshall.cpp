#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // void shortest_distance(vector<vector<int>>&matrix){
	//     // Code here
	//     int n = matrix.size();
	    
	//     for(int i=0; i<n; i++) {
	//         for(int j=0; j<n; j++) {
	//             if(matrix[i][j] == -1)
	//                 matrix[i][j] = 1e9;
	//             if(i == j)
	//                 matrix[i][j] = 0;
	//         }
	//     }
	    
	//     for(int via=0; via<n;via++) {
	//         for(int i=0; i<n; i++) {
	//             for(int j=0; j<n; j++) {
	//                 matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]);
	//             }
	//         }
	//     }
	    
	   
	//    //repalce 1e9 to -1 
	//    for(int i=0; i<n; i++) {
	//        for(int j=0; j<n; j++) {
	//            if(matrix[i][j] == 1e9)
	//                 matrix[i][j] = -1;
	//        }
	//    }
	// }

    	void shortest_distance(vector<vector<int>>&matrix){
	    
	    int n=matrix.size();
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            for(int k=0;k<n;k++){
	                if((matrix[j][i]!=-1 && matrix[i][k]!=-1) && (matrix[j][i]+matrix[i][k]<matrix[j][k]||matrix[j][k]==-1)){
	                    matrix[j][k]=matrix[j][i]+matrix[i][k];
	                }
	            }
	        }
	    }
	}
    //My method from clg classes
};

int main() {
    Solution solution;

    // Example matrix
    vector<vector<int>> matrix = {
        {0, -1, 3, -1},
        {2, 0, -1, -1},
        {-1, 7, 0, 1},
        {6, -1, -1, 0}
    };

    // Print the original matrix
    cout << "Original matrix:\n";
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << (val == -1 ? "INF" : to_string(val)) << "\t";
        }
        cout << endl;
    }

    // Apply the modified Floyd-Warshall algorithm
    solution.shortest_distance(matrix);

    // Print the resulting matrix
    cout << "\nShortest distances matrix:\n";
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << (val == -1 ? "INF" : to_string(val)) << "\t";
        }
        cout << endl;
    }

    return 0;
}
