#include <iostream>
#include <bits/stdc++.h> 
#include <vector> 
using namespace std; 
class busqueda_BoS{
	public:
		int key;
		vector<int> array;
		
		
		int is_in_BS() {
			int N;
			int posicion;
			N=int(array.size());
			for(int i = 0; i <= N-1; i = i++){
				if (array[i]==key){
					posicion=i;
					return posicion;
				}
			}
		}
		
		
		float is_in_BB(){
			int N;
			N=int(array.size());
			int posicion;
			int bajo=0;
			int alto=N;
			float promedio;
			int resultado;
			for(int i = 0; i <= N-1; i = i++){
				if(bajo==alto ){
					i=N+1;
					resultado=bajo;
					return resultado;
					
				}
				promedio=ceil((bajo+alto)/2);
				if (array[promedio]<=key ){
					bajo=promedio;
				
				}
				
				if (key<=array[promedio] ){
					alto=promedio;
				}
					
			}
			
			
		
			
		} 
};
int main(){
	int resultado;
	int n=1001;
	vector<int> array;
	array.assign(n,100);
	for(int i = 0; i <= n-1; i = i++){
		array[i]=i+1;
	}
	busqueda_BoS BS;
	BS.array=array;
	for(int i = 0; i <= n-1; i = i++){
		BS.key=i+1;
		resultado=BS.is_in_BB();
		//resultado= ceil(3); 
		std::cout << resultado;
		std::cout << "----";
		std::cout << BS.key;
		std::cout << "\n";
	}
	//BS.key=23;
	//resultado=BS.is_in_BB();
	//resultado= ceil(3); 
	//std::cout << resultado;
	return 0;
}
