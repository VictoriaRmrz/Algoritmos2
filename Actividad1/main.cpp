// Victoria Ramírez Castro A01640824
//Andrea Valeria Pintor Valencia  A01067424


#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <algorithm>

using namespace std;
int contador = 0;

void displayData(vector<int> unsortedData){
    int vectorSize = unsortedData.size();
    cout << "[";
    for(int i = 0; i < vectorSize; i++){
        cout << unsortedData[i] << " ";
    }
    cout << "]" << endl;
}

vector<int> bubbleSort(vector<int> data){   // Complejidad O(n^2)
    int vectorSize = data.size();
	bool swapped = false;
    contador = 0;
    
	for(int i = 0; i < vectorSize - 1; i++){
		for(int j = 0; j < vectorSize - i - 1; j++){
			if(data[j] > data[j + 1]){ 
				swap(data[j], data[j + 1]);
				swapped = true;
                contador ++;
			}
		}
		if(swapped == false) break; 
	}
    return data;
}

void merge(vector<int> &data, int low, int mid, int high){
    int leftVecSize = mid - low + 1;
    int rigthVecSize = high - mid;
    int leftHalf[leftVecSize], 
        rigthHalf[rigthVecSize];
    for(int i = 0; i < leftVecSize; i++){
        leftHalf[i] = data[low + i];
    }
    for(int j = 0; j < rigthVecSize; j++){
        rigthHalf[j] = data[mid + 1 + j];
    }
    int i = 0;
    int j = 0;
    int k = low;
    while(i < leftVecSize && j < rigthVecSize){
        if(leftHalf[i] < rigthHalf[j]){
            data[k] = leftHalf[i];
            i++;
        }
        else{
            data[k] = rigthHalf[j];
            j++;
        }
        k++;
    }
    while(i < leftVecSize){
        data[k] = leftHalf[i];
        k++;
        i++;
    }
    while(j < rigthVecSize){
        data[k] = rigthHalf[j];
        k++;
        j++;
    }
}

void mergeSort(vector<int> &data, int low, int high){   // Complejidad O(n.log(n))
    vector<int> sortedData;
    if(low < high){ 
        int mid = (low + high) / 2;
        mergeSort(data, low, mid);
        mergeSort(data, mid + 1, high);
    
        contador ++;
        return merge(data, low, mid, high);
    }
}

int quick(vector<int> &data, int low, int high){
    int pivot = data[high];
    int i = low - 1;
    
    for(int j = low; j <= high - 1; j++){
        if(data[j] < pivot){
            i++;
            swap(data[i], data[j]);
            
        }
    }
    swap(data[i + 1], data[high]);
    return i + 1;
}

void quickSort(vector<int> &data, int low, int high){   // Complejidad O(n.log(n))
    
    if(low < high){
        int pivot = quick(data, low, high);
        quickSort(data, low, pivot - 1);
        quickSort(data, pivot + 1, high);
        
    }
    contador ++;
}


vector<vector <int>> createVectors(int cantidad){
    vector<vector <int>> vectors;
    vector<int> randomVector;
    vector<int> ascendenteVector;
    vector<int> descendenteVector;
    for(int i = 0; i < cantidad; i++){
        int valor = 1 + rand() % 10000;
        randomVector.push_back(valor);
        ascendenteVector.push_back(valor);
        descendenteVector.push_back(valor);
        valor++;
    
    }
    vectors.push_back(randomVector);
    vectors.push_back(ascendenteVector);
    vectors.push_back(descendenteVector);

    return vectors;
}

void analizarConBubbleSort(int size, vector<int> vector_ascendente, vector<int> vector_descendente, vector<int> vector_desordenado){
    cout << "---------------------------" << endl;
    cout << "Bubble sort" << endl;
    cout << "---------------------------" << endl;
    cout << "Vector de "<< size << endl;
    cout << "---------------------------" << endl;
    cout << "\nVector ascendente" << endl;
    bubbleSort(vector_ascendente);
    cout << "Numero de comparaciones: " << contador << endl;
    cout << "\nVector descendente" << endl;
    bubbleSort(vector_descendente);
    cout << "Numero de comparaciones: " << contador << endl;
    cout << "\nVector desordenado" << endl;
    bubbleSort(vector_desordenado);
    cout << "Numero de comparaciones: " << contador << endl;
}

void analizarConQuickSort(int size, vector<int> vector_ascendente, vector<int> vector_descendente, vector<int> vector_desordenado){

    cout << "---------------------------" << endl;
    cout << "Quick sort" << endl;
    cout << "---------------------------" << endl;
    cout << "Vector de "<< size << endl;
    cout << "---------------------------" << endl;
    cout << "\nVector ascendente" << endl;
    quickSort(vector_ascendente, 0, vector_ascendente.size() - 1);
    cout << "Numero de comparaciones: " << contador << endl;
    cout << "\nVector descendente" << endl;
    quickSort(vector_descendente, 0, vector_descendente.size() - 1);
    cout << "Numero de comparaciones: " << contador << endl;
    cout << "\nVector desordenado" << endl;
    quickSort(vector_desordenado, 0, vector_desordenado.size() - 1);
    cout << "Numero de comparaciones: " << contador << endl;
}

void analizarConMergeSort(int size, vector<int> vector_ascendente, vector<int> vector_descendente, vector<int> vector_desordenado){

    cout << "---------------------------" << endl;
    cout << "Merge sort" << endl;
    cout << "---------------------------" << endl;
    cout << "Vector de "<< size << endl;
    cout << "---------------------------" << endl;
    cout << "\nVector ascendente" << endl;
    mergeSort(vector_ascendente, 0, vector_ascendente.size() - 1);
    cout << "Numero de comparaciones: " << contador << endl;
    cout << "\nVector descendente" << endl;
    mergeSort(vector_descendente, 0, vector_descendente.size() - 1);
    cout << "Numero de comparaciones: " << contador << endl;
    cout << "\nVector desordenado" << endl;
    mergeSort(vector_desordenado, 0, vector_desordenado.size() - 1);
    cout << "Numero de comparaciones: " << contador << endl;
}

int main(){
    srand(time(NULL));
    vector<int> sizeVectors = {10,100, 1000, 10000};

    for(int i = 0; i < sizeVectors.size(); i++){
        int size = sizeVectors[i];
        vector<vector <int>> vectors = createVectors(size);

        //acomoda cada vector de la lista de vectores de manera ascendente
        vector<int> vector_ascendente = vectors[0];
        vector<int> vector_descendente = vectors[1];
        vector<int> vector_desordenado = vectors[2];

        sort(vector_ascendente.begin(), vector_ascendente.end());
        sort(vector_descendente.begin(), vector_descendente.end());
        reverse(vector_descendente.begin(), vector_descendente.end());
       
        
        analizarConBubbleSort(size, vector_ascendente, vector_descendente, vector_desordenado);
        analizarConQuickSort(size, vector_ascendente, vector_descendente, vector_desordenado);
        analizarConMergeSort(size, vector_ascendente, vector_descendente, vector_desordenado);

    }
    return 0;
}