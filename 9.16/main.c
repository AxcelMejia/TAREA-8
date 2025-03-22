#include <stdio.h>
#include <stdlib.h>
void sumypro(FILE *);
void main(void)
{
    FILE *ap;
    if ((ap=fopen("arc2.txt", "r")) != NULL)
    {
        sumypro(ap);
        /* Se llama a la función sumypro. Se pasa el archivo ap como parámetro. */
        fclose(ap);
    }
    else
        printf("No se puede abrir el archivo");
}
void sumypro(FILE *ap1)
/* Esta función lee cadenas de caracteres de un archivo, detecta aquellas
➥que comienzan con números, y obtiene la suma y el promedio de dichos
➥números. */
{
    char cad[30];
    int i = 0;
    float sum = 0.0, r;
    while (!feof (ap1))
    {
        fgets(cad,30,ap1); /* Se lee la cadena del archivo. */
        r = atof(cad);
        if (r)
        {
            i++;
            sum += r;
        }
    }
    printf("\nSuma: %.2f", sum);
    if (i)
        printf("\nPromedio: %.2f", sum/i);
}
