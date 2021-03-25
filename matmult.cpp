#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <pthread.h>
#include <vector>

using namespace std;

int u;
int v;
int w;
vector<vector<int> > mat1;
vector<vector<int> > mat2;
vector<vector<int> > matmult;

void *compute(void *args) {
    return NULL;
}

int main(int argc, char *argv[]) {
    //getting command line arguments
    istringstream(argv[1]) >> u;
    istringstream(argv[2]) >> v;
    istringstream(argv[3]) >> w;
    string inputFile1 = argv[4];
    string inputFile2 = argv[5];
    string outputFile = argv[6];
    int threadCount;
    istringstream(argv[7]) >> threadCount;

    //checking if inputs are negative
    if (u < 0 || v < 0 || w < 0 || threadCount < 1) {
        cout << "Please enter a valid parameter.\n";
        exit(0);
    }

    //setting up file reading to read matrices into arrays
    ifstream file1(inputFile1.c_str());
    ifstream file2(inputFile2.c_str());

    int num;

    //resizing matrices
    mat1.resize(u);
    for (int i = 0; i < u; i++) {
        mat1[i].resize(v);
    }

    mat2.resize(v);
    for (int i = 0; i < v; i++) {
        mat2[i].resize(w);
    }

    matmult.resize(u);
    for (int i = 0; i < u; i++) {
        matmult.resize(w);
    }

    //filling first matrix
    for (int i = 0; i < u; i++) {
        for (int j = 0; j < v; j++) {
            if (file1 >> num) {
                mat1[i][j] = num;
            }
        }
    }
    file1.close();

    //filling second matrix
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < w; j++) {
            if (file2 >> num) {
                mat2[i][j] = num;
            }
        }
    }
    file2.close();

    //creating the array of threads
    pthread_t t[threadCount];

    for (int i = 0; i < threadCount; i++) {
        pthread_create(&t[i], NULL, compute, NULL);
    }

    for (int i = 0; i < threadCount; i++) {
        pthread_join(t[i], NULL);
    }
}