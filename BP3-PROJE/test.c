#include <stdlib.h>
#include <stdio.h>
#include "matrisoperations.h"
#include <time.h>
int G;
int F;
/*
* @file BP3PROJE
* @description matris1 ve matris2 uzerinde birbirine karsilik gelen
elemanlar birbirleri ile carpilip tum degerler toplanarak
olusturulacak yeni matrisin ilgili elemanının degeri hesaplanacaktır.
* @assignment PROJE_1
* @date 15/12/2021
* @author Bahadir Sina Terzioglu/bahadir.terzioglu@stu.fsm.edu.tr
*/
int main(int argc, char *argv[]){

    if (argc < 5 ){
        printf("EKSIK VERILER GIRILMISTIR. LUTFEN DOSYA ADI DAHIL SADECE 5 VERI GIRINIZ!!!");
    } else if (argc == 5){
     G = atoi(argv[1]);
        if(G<5){
         printf("MATRIS1 BOYUTU 5'DEN KUCUK GIRILEMEZ!!!");   
        } else if ((G >= 5) && ((G%2)== 1)){
         F = atoi(argv[2]);
            if(F==3 || F==5 ){
             int islemTipi = atoi(argv[3]);
                    if(islemTipi == 0 || islemTipi == 1){
                    srand(atoi(argv[4]));
                    int** matris1 = (int**)malloc(G * sizeof(int*));
                    for (int i = 0; i < G; i++)
                    {
                        matris1[i] = (int*)malloc(G * sizeof(int));
                    }
                    int** matris2 = (int**)malloc(F * sizeof(int*));
                    for (int j = 0; j < F; j++) 
                    {
                        matris2[j] = (int*)malloc(F * sizeof(int));
                    }
                printf("-------------MATRIS 1------------- \n");
                    for(int i=0;i<G;i++) 
                    {
                        for(int j=0;j<G;j++) 
                        {
                        matris1[i][j]=1 + rand()%10;
                        printf("%d\t",matris1[i][j]);
                        }
                        puts("\n");
                    }
                    printf("-----MATRIS 2----- \n");
                    for(int i=0;i<F;i++) 
                    {
                        for(int j=0;j<F;j++) 
                        {
                        matris2[i][j]=1 + rand()%10;
                        printf("%d\t",matris2[i][j]);
                        }
                        puts("\n");
                    }
                    operasyon1(matris1, matris2, islemTipi,G,F);
                    free(matris1);
                    free(matris2);
                    } else{
                    printf("ISLEM TIPI 0 VE 1 DISINDA GIRILEMEZ!!!"); 
                }  
            } else {
                 printf("MATRIS2 BOYUTU 3 VE 5 DISINDA GIRILEMEZ!!!");
            }
        } else{
            printf("MATRIS1 BOYUTU CIFT SAYILARDAN OLUSAMAZ!!!"); 
        }
    }else {
         printf("FAZLA VERI GIRILMISTIR. LUTFEN DOSYA ADI DAHIL SADECE 5 VERI GIRINIZ!!!");
    }

return 0;

}
