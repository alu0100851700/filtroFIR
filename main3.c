#include "stdio.h"

#define N 21    //COEFICIENTES
#define M 3332  //MUESTRAS

//INICIALIZACION COEFICIENTES
float* coef_initialize(){
    float* v_coef = (float *) malloc(N * sizeof(float));

    int i=0;
    FILE *f_in = fopen ("Coeficientes.csv", "r");
    while( fscanf (f_in, "%f", &v_coef[i]) != EOF && i<N) {
        i++;
    }
    
    fclose(f_in);
        
    return v_coef;
}

//INICIALIZACION VECTOR DE ENTRADA, PROLOGO y EPILOGO
float* signal_read(){
    float* v_in = (float *) malloc((M+N-1) * sizeof(float));
    float buffer;
    
    
    
    //INICIALIZACION PROLOGO/EPILOGO
    int i;
    for(i=0; i<(N-1)/2; i++){
        v_in[i]     = 0;
        v_in[M+i]   = 0;
    }
    
    //INICIALIZACION VECTOR y LECTURA DATOS
    i=(N-1)/2;
    FILE *f_in = fopen ("IBEX35.csv", "r");
    while( fscanf (f_in, "%f", &v_in[i]) != EOF) {
        i++;
    }
    fclose(f_in);
        
    return v_in;
}

//APLICACION FILTRO FIR
float* fir(float* v_coef, float* v_in){
    float* v_out = (float *) malloc((M+N-1) * sizeof(float));
    int i;
    int j;
    for(i=0; i<M+N-1; i++){
        v_out[i] = 0;
        for(j=0; j<N ; j++)
            v_out[i] += v_coef[j] * v_in[i-j]; 
    }
    
    return v_out;
}

void guardarDatos(float* v_out){
    FILE *f_out = fopen("salida.txt","w");
    int i;
    fprintf(f_out ,"Longitud del vector: %d y %d coeficientes\n", N, M);
    for(i=0; i<M+N-1; i++)
        fprintf(f_out, "%d\t%f\n", i+1, v_out[i]);
    
    fclose(f_out);
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
    v_out = fir(v_coef, v_in);
    
    guardarDatos(v_out); 
            
    free(v_coef);
    free(v_in);
    free(v_out);
            
}