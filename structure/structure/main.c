//
//  main.c
//  structure
//
//  Created by orsys on 16/12/2021.
//

#include <stdio.h>

struct S_meteo{
    float temp;
    unsigned long pression;
    unsigned int humidity;
};

struct S_gyro{
    float gx,gy,gz;
    float ix,iy,iz;
};
typedef struct S_gyro Gyro;

struct S_datas{
    struct S_meteo meteo;
    Gyro gyro;
};

void setTemperature(struct S_meteo *m)
{
    m->temp=25.4F;
    printf("%.2f;%6luul;%2d\n",m->temp,m->pression,m->humidity);
}

void setGyro(struct S_datas *d)
{
    d->gyro.gx = 2.3F;
    d->gyro.gy = 3.3F;
    d->gyro.gz = 4.3F;
    d->gyro.ix = 5.3F;
    d->gyro.iy = 5.3F;
    d->gyro.iz = 6.3F;
}

union U_S_datas
{
    struct S_datas s;
    uint8_t b[sizeof(struct S_datas)];
};

void viewUnionOfS_Data(struct S_datas structdata)
{
    union U_S_datas usd;
    usd.s=structdata;
    
    for(int i=0; i<sizeof(struct S_datas); i++)
    {
        printf("%d: ",usd.b[i]);
    }
}


int main(int argc, const char * argv[]) {
    struct S_datas datas;
    datas.meteo.temp=12.0F;
    datas.meteo.pression=10000ul;
    datas.meteo.humidity=37;
    setTemperature(&datas.meteo);
    setGyro(&datas);
    viewUnionOfS_Data(datas);
    
    printf("%.2f;%6luul;%2d\n",datas.meteo.temp,datas.meteo.pression,datas.meteo.humidity);
    
    
    return 0;
}


