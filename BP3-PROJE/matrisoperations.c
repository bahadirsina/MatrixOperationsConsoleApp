#include <stdlib.h>
#include <stdio.h>
#include "matrisoperations.h"

/*
* @file BP3PROJE
* @description matris1 ve matris2 uzerinde birbirine karsilik gelen
elemanlar birbirleri ile carpilip tum degerler toplanarak
olusturulacak yeni matrisin ilgili elemanının degeri hesaplanacaktır.
* @assignment PROJE_1
* @date 15/12/2021
* @author Bahadir Sina Terzioglu/bahadir.terzioglu@stu.fsm.edu.tr
*/

int** operasyon1(int** matris1, int** matris2, int islemTipi, int G, int F){
int MB; // Olusacak matrisin boyutu
int **NM; // Olusacak yeni matris
int D;
int S; // Toplam 
int NB; //Yeni boyut  
switch (islemTipi){ //islem tipi mainde 0 olarak girildiğinde D = 0 olur. 
case 0:
    D = 0;
    break;
case 1://islem tipi mainde 1 olarak girildiğinde yandaki denkleme gore D sonucu bulunur. 
    D = (F-1)/2;
    break;
default:
    break;
printf("Uygun islem tipi girilmedi!! "); // mainde bu iki deger disinda girildiginde yandaki yazı cikmaktadir.
exit(EXIT_SUCCESS);
}
if (D == 0){ // islem tipi 0 oldugu zaman yeni matrisin boyu denkleme gore hesaplanir.  
    MB = ((G-F + 2*D) /1) + 1;
    NM = (int**)malloc(MB * sizeof(int*)); //Ardindan dinamik bellek kullanımı yaptigimiz için yeni matrise heap de alan ayrilir.
    for (int i = 0; i < MB; i++) {
        NM[i] = (int*)malloc(MB * sizeof(int));
    }
 for( int i = 0; i < MB; i++) // Mainde olursturulan 1. ve 2. matrisler çarpılıp toplanarak yeni matrise sonuclari yazilir.
 {
        for( int j = 0; j < MB; j++)
        {
            S = 0; 
            for( int k = 0; k < F; k++)
            {
                for( int l = 0; l< F; l++)
                {
                    S += (matris1[k+i][l+j])*(matris2[k][l]);  
                }
            }
            NM[i][j] = S;

        }
    }
    printf("-----YENI MATRIS----- \n");  // Olusan  matris yazdirilir.
        for(int i=0;i<MB;i++) 
        {
            for(int j=0;j<MB;j++) 
            {
            printf("%d\t",NM[i][j]);
            }
        puts("\n"); 
        }

}
if(islemTipi == 1)  // islem tipi 1 oldugu zaman D degerine gore yeni matrisin boyutu hesaplanir.
{
MB = ((G-F + 2*D) /1) + 1;

    NM = (int**)malloc(MB * sizeof(int*)); // Heap alanında yeni matris icin yer ayrilir. 
    for (int i = 0; i < MB; i++) 
    {
        NM[i] = (int*)malloc(MB * sizeof(int));
    }
NB = G + 2;    
matris1 = (int**)realloc(matris1,NB * sizeof(int**)); // Senaryo 2 icin matris1'in boyutunda da değişiklik yapilacagi icin realloc sayesinde matris1'in bellek alanı genisletilir.
    for (int i = 0; i < G; i++)
    {
        matris1[i] = (int*)realloc(matris1[i], NB * sizeof(int));
    }
    for (int i = G; i < NB; i++) 
    {
    matris1[i] = (int*) malloc(NB * sizeof(int));  
    }

    for (int i=0; i<NB; i++) // Bu kisimda yeni olusturulan matris1'in once saga 1 kez kaydirma islemi gerceklestirilir.
    {
    int temp = matris1[i][NB-1];
        for (int j = NB-1; j > 0; j--)
        {
             matris1[i][j] = matris1[i][j-1];
        }
             matris1[i][0] = temp;
    }
    for (int i=0; i<NB; i++) // Bu kisimda ise saga 1 kez kaydirilan matris1, asagi 1 kez kaydirilir. 
    {                        // Bu sekilde ortalanmis olur. 
    int temp = matris1[NB-1][i];
        for (int j = NB-1; j > 0; j--)
        {
             matris1[j][i] = matris1[j-1][i];
        }
             matris1[0][i] = temp;
    }
    for (int i = 0; i < NB; (i+=NB-1)) // Burada da kaydirilan yani ortaya alinan matris1'in cevresini 0 yaptik.
    {
        for (int j = 0; j < NB; j++)
        {
            matris1[i][j] = 0;
        }
    }
    for (int i = 0; i < NB; (i+=NB-1))
    {
        for (int j = 0; j < NB; j++)
        {
            matris1[j][i] = 0;
        }
    }
    
printf("-------------------YENI MATRIS 1------------------- \n"); // Yeni matris1 ekrana yazdirildi. 
    for(int i=0;i<NB;i++)
     {
        for(int j=0;j<NB;j++) 
        {
            printf("%d\t",matris1[i][j]);
        }
    puts("\n"); 
    }
for( int i = 0; i < MB; i++)  // Yeni matris1'e göre matris2 ile carpilip toplanan yeni degerler yeni olusturulan matrise atandı. 
{
    for( int j = 0; j < MB; j++)
    {
        S = 0; 
        for( int k = 0; k < F; k++)
        {
            for(int l = 0; l< F; l++)
            {
                S += (matris1[k+i][l+j])*(matris2[k][l]) ;
             }
        }
            NM[i][j] = S;
    }
}
printf("-------------YENI MATRIS------------- \n"); // Yeni matrisin degeri ekrana yazdirildi. 
    for(int i=0;i<MB;i++) 
    {
        for(int j=0;j<MB;j++) 
        {
        printf("%d\t",NM[i][j]);
        }
    puts("\n");
    }

    }
    free(matris1);  // Bellek alanları geri iade edildi. 
    free(matris2);
    free(NM);
}