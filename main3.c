#include <cstdio>

#define N 3
#define M 5

//INICIALIZACION COEFICIENTES
float* coef_initialize(){
    float* v_coef = (float *) malloc(N);
    for(int i=0; i<N; i++)
        v_coef[i] = 1/N;
        
    return v_coef;
}

//INICIALIZACION VECTOR DE ENTRADA, PROLOGO y EPILOGO
float* signal_read(){
    float* v_in = (float *) malloc(M+N-1);
    //INICIALIZACION PROLOGO/EPILOGO
    for(int i=0; i<(N-1)/2; i++){
        v_in[i]     = 0;
        v_in[M+i]   = 0;
    }
    
    //INICIALIZACION VECTOR
    for(int i=N-1; i<M; i++)
        v_in[i] = ;
        
    return v_in;
}

//APLICACION FILTRO FIR
float* fir(){
    float* v_out = (float *) malloc(M+N-1);
    
    for(int i=0; i<M+N-1; i++){
        v_out[i] = 0;
        for(int j=0; j<N ; j++)
            v_out[i] += v_coef[i] * v_in[i-j]; 
    }
    
    return v_out;
}

int main()
{
    float* v_in;    //Señal de entrada
    float* v_coef;  //Coeficientes
    float* v_out;   //Señal de salida
    
    //Inicializacion simple de coeficientes
    v_coef = coef_initialize();
    
    //Lectura de la señal
    v_in = signal_read();
    
    //Ejecución del FIR
    v_out = fir();
    
    
            
    delete v_coef;
    delete v_in;
    delete v_out;
            
}