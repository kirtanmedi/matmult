#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]){
    //getting command line arguments
    int u;
    istringstream(argv[1]) >> u;
    int v;
    istringstream(argv[2]) >> v;
    int w;
    istringstream(argv[3]) >> w;
    string inputFile1 = argv[4];
    string inputFile2 = argv[5];
    string outputFile = argv[6];
    int threadCount;
    istringstream(argv[7]) >> threadCount;

    //initializing the matrices
    int matrix1[u][v];
    int matrix2[v][w];

    //setting up file reading to read matrices into arrays
    ifstream file1(inputFile1.c_str());
    ifstream file2(inputFile2.c_str());

    int num;

    //filling first matrix
    for (int i = 0; i < u; i++) {
        for (int j = 0; j < v; j++) {
            if (file1 >> num) {
                matrix1[i][j] = num;
            }
        }
    }
    file1.close();

    //filling second matrix
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < w; j++) {
            if (file2 >> num) {
                matrix2[i][j] = num;
            }
        }
    }
    file2.close();
}