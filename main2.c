#include <cstdio>

#define N 3
#define M 5

//INICIALIZACION COEFICIENTES
float* coef_initialize(){
    float* v_coef = (float*) malloc(N);
    for(int i=0; i<N; i++)
        v_coef[i] = 1/N;
        
    return v_coef;
}


int main()
{
    float* v_in = (float*) malloc(M+N-1);      //Señal de entrada
    float* v_coef;                              //Coeficientes
    float* v_out = (float*) malloc(M+N-1);     //Señal de salida
    
    //INICIALIZACION SIMPLE DE LOS COEFICIENTES
    v_coef = coef_initialize();
    
    //INICIALIZACION PROLOGO/EPILOGO
    for(int i=0; i<(N-1)/2; i++){
        v_in[i]     = 0;
        v_in[M+i]   = 0;
    }
    
    //INICIALIZACION VECTOR
    for(int i=N-1; i<M; i++)
        v_in[i] = ; //<---------------- FALTA -----------------
    
    //Ejecución del FIR
    for(int i=0; i<M+N-1; i++){
        v_out[i] = 0;
        for(int j=0; j<N ; j++)
            v_out[i] += v_coef[i] * v_in[i-j]; 
    }
    
    
            
    delete v_coef;
    delete v_in;
    delete v_out;
            
}