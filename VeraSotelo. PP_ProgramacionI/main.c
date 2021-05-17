#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 5

typedef struct{
int id;
char marca[20];
char procesador[20];
float precio;
}eNotebook;

float aplicarDescuento(float precio);
int contarCaracteres(char * cadena, char caracter);
int ordenarNotebooks(eNotebook notebooks[], int tam);

int main()
{
    //Punto 1
    float precio= 2500;
    printf("Precio inicial: $%.2f\n", precio);
    printf("Precio con descuento: $%.2f\n\n",aplicarDescuento(precio));

    //Punto 2
    char cadena[200]="Cadena de caracteres para probar la funcion";
    printf("Cantidad de veces que aparece el caracter en la cadena: %d\n", contarCaracteres(cadena,'a'));

    //Punto 3
    eNotebook notebooks[5]={
    {1,"Acer","Intel i5",50000},
    {2,"Dell","Intel i5",35000},
    {3,"HP","Intel i7",58000},
    {4,"Apple","Intel i5",60000},
    {5,"Toshiba","Intel i3",35000},
    };

    ordenarNotebooks(notebooks, TAM);

    for(int i=0;i<TAM;i++){
        printf("%s, $%.2f\n", notebooks[i].marca, notebooks[i].precio);
    }

    return 0;
}

/*1. Crear una función llamada aplicarDescuento que reciba como parámetro el precio de un producto
y devuelva el valor del producto con un descuento del 5%. Realizar la llamada desde el main. *
*/

float aplicarDescuento(float precio){
    return precio*0.95;
}

/*2. Crear una función que se llame contarCaracteres que reciba una cadena de caracteres como primer parámetro
y un carácter como segundo y devuelva la cantidad de veces que ese carácter aparece en la cadena */

int contarCaracteres(char * cadena, char caracter){
    int contCar=0;
    int tam;
    if(cadena!=NULL){
        tam=strlen(cadena)-1;
        for(int i=0;i<tam;i++){
            if(cadena[i]==caracter){
                contCar++;
            }
        }
    }
    return contCar;
}

/*3. Dada la estructura Notebook(id, procesador, marca, precio) generar una función que permita ordenar un array de dicha estructura por marca.
Ante igualdad de marca deberá ordenarse por precio. Hardcodear datos y mostrarlos desde el main.*/

int ordenarNotebooks(eNotebook notebooks[], int tam){
    int todoOk=0;
    eNotebook aux;
    if(notebooks!=NULL && tam>0){
        for(int i=0; i<tam-1;i++){
            for(int j=1; j<tam; j++){
                if((strcmp(notebooks[i].marca,notebooks[j].marca)>0)||
                   ((strcmp(notebooks[i].marca,notebooks[j].marca)==0)&&(notebooks[i].precio>notebooks[j].precio))){
                        aux=notebooks[i];
                        notebooks[i]=notebooks[j];
                        notebooks[j]=aux;
                }
            }
        }
        todoOk=1;
    }
    return todoOk;
}
