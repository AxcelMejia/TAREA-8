#include <stdio.h>
#include <stdlib.h>

#define MAX_VEHICULOS 10

typedef struct {
    char marca[50];
    char modelo[50];
    float galonesConsumidos;
    float precioxGalon;
    float costoTotal;
} Vehiculo;

void NV (Vehiculo vehiculos[], int *NVehiculos)
{
    printf("Ingrese el numero de vehiculos (max %d): ", MAX_VEHICULOS);
    scanf("%d", NVehiculos);

    FILE *file = fopen("vehIculos.txt", "a");
    if (file == NULL)
        {
        printf("Error al abrir el archivo.\n");
        return;
    }

    for (int i = 0; i < *NVehiculos; i++)
        {
        printf("Vehículo %d:\n", i + 1);
        printf("Marca: ");
        scanf("%s", vehiculos[i].marca);
        printf("Modelo: ");
        scanf("%s", vehiculos[i].modelo);
        printf("Galones consumidos: ");
        scanf("%f", &vehiculos[i].galonesConsumidos);
        printf("Costo por galón: ");
        scanf("%f", &vehiculos[i].precioxGalon);

        vehiculos[i].costoTotal = vehiculos[i].galonesConsumidos * vehiculos[i].precioxGalon;

        fprintf(file, "%s %s %.2f %.2f %.2f\n", vehiculos[i].marca, vehiculos[i].modelo, vehiculos[i].galonesConsumidos, vehiculos[i].precioxGalon, vehiculos[i].costoTotal);
    }

    fclose(file);
}

void COSTO (Vehiculo vehiculos[], int NVehiculos)
{
    printf("\nResumen de costos:\n");
    for (int i = 0; i < NVehiculos; i++) {
        printf("Marca: %s | Modelo: %s | Galones consumidos: %.2f | Costo total: %.2f\n",
               vehiculos[i].marca, vehiculos[i].modelo, vehiculos[i].galonesConsumidos, vehiculos[i].costoTotal);
    }
}

int main()
{
    Vehiculo vehiculos[MAX_VEHICULOS];
    int NVehiculos;

    NV(vehiculos, &NVehiculos);
    COSTO(vehiculos, NVehiculos);

    return 0;
}


