#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


int menu1(){
    int diff;
    printf("---------------------------Kart Hatirlama Oyununa Hos Geldiniz-------------------------------\n");
    printf("--------------ACIKLAMA-------------\n");
    printf("Bu oyun bilgisayara karsi oynanir. Oncelikle oynanilacak oyunun zorlugu secilir. \nOyunda 3 tip zorluk olmak uzere bunlar: Kolay (1), Orta(2), ve Zor(3) olarak siniflandirilir.\n");
    printf("Oyuncu rasgele sectigi iki karti acarak oyuna baslar. Eger kartlar eslesirse, iki kart acma hakki daha bulunmaktadir.\n Eslesmezse, sira bilgisayara gecer ve ayni islemi yapar. \n");
    printf("Bilgisayarin yeni actigi bir kart, hafizasinda varsa, onu da acar ve bir sonraki kart acma hakki ile oyuna devam eder.\n");
    printf("Kolay zorlukta 4x4 olmak uzere 16 kart, Orta zorlukta 36, Zor zorlukta ise 64 kart bulunmaktadir.\n");
    printf("Tablodaki her cift bulundugunda oyuncu veya bilgisayardan hangisi daha fazla cift bulmussa o oyunu kazanir.\n");
    printf("-----------------------------------------------------------------------------------------------------------\n\n");
    printf("Baslamak icin lutfen zorluk seviyesini giriniz.\n1(Kolay), 2(Orta), 3(Zor)\n");
    scanf("%d", &diff);
    printf("\n\n");
    system("cls");
    return diff;

}

int randSelect(int n, int ind, int randomArr[]){
    int j, random, flag, a;
    flag = 0;
    random = (rand() % (n*n)/2) + 1;
    for(j = 0; j<n*n; j++){
        if(randomArr[j] == random){
            flag++;
        }
    }
    if(flag >= 2){
        randSelect(n, ind, randomArr);
    }else{
        randomArr[ind] = random;
        return ind, random;
    }
}

void cpuRand(int randSelected1[], int n, int randSelected2[], int *ind3, int* X, int* Y){
    *X = rand() % (n);
    *Y = rand() % (n);
    int flag;
    flag = 0;
    int x, y;

    for(int i = 0; i<n*n; i++){
        if(*X == randSelected1[i] && *Y == randSelected2[i]){
            flag++;
        }
        if(flag != 0){
            cpuRand(randSelected1, n, randSelected2, ind3, X, Y);
        }else{
            printf("Ind is: %d\n", *ind3);
            randSelected1[*ind3] = *X;
            randSelected2[*ind3] = *Y;
            *ind3++;
        }
    }
}

/* ----------------------------------------------------------------------------------------------------------------- */

int main(){

    int n, flag = 0, randNum, dif, turn=0;
    dif = menu1();
    srand(time(NULL)); //declaring srand for the random number selection
    if(dif==1){
        n = 4; 
    }else if(dif==2){
        n = 6;
    }else if(dif==3){
        n = 8;
    }

    int plain[n][n], randomArr[n*n], randSelected1[n*n], randSelected2[n*n];
    char plainStr[n][n];
    int i, o, random, ind = 0, j, ind1 = 0;
    time_t t;
    srand((unsigned) time(&t));

    for(j = 0; j<n*n; j++){
        randomArr[j] = -1;
    }
    for(j = 0; j<n; j++){
        for(i = 0; i<n; i++){
            plainStr[j][i] = '*';
        }
    }

    for(o = 0; o<n; o++){
        for(i = 0; i<n; i++){
                ind, random = randSelect(n, ind, randomArr);
                ind++;
                plain[o][i] = random;
            }
        }

    int userX1, userY1, userSelectedCard1, userPoint = 0, cpuPoint = 0, charvalue, userSelectedCard2, userX2, userY2, cpuX1, cpuY1, cpuSelectedCard1, cpuSelectedCard2, cpuX2, cpuY2;

    for(int j = 0; j<n*n; j++){
        randSelected1[j] = 0;
    }
    for(int j = 0; j<n*n; j++){
        randSelected2[j] = 0;
    }

    while(1){
        if(turn % 2 == 0){
            printf("\t\t\tOyun Sirasi: Oyuncu\n\n");
            for(o=0; o<n; o++){
                printf("\t\t\t");
                for(i=0; i<n; i++){
                    printf("%c    ", plainStr[o][i]);
                }
                printf("\n\n\n");
            }
            printf("Lutfen Secmek istediginiz 1. kartin kacinci satirda oldugunu giriniz: ");
            scanf("%d", &userX1);
            printf("Lutfen Secmek istediginiz 1. kartin kacinci sutunda oldugunu giriniz: ");
            scanf("%d", &userY1);
            system("cls");
            userSelectedCard1 = plain[userX1][userY1];
            printf("Sectiginiz Kart: %d\n", plain[userX1][userY1]);
            charvalue = userSelectedCard1 + '0';
            plainStr[userX1][userY1] = charvalue;
            for(o=0; o<n; o++){
                printf("\t\t\t");
                for(i=0; i<n; i++){
                    printf("%c    ", plainStr[o][i]);
                }
                printf("\n\n\n");
            }
            printf("Lutfen Secmek istediginiz 2. kartin kacinci satirda oldugunu giriniz: ");
            scanf("%d", &userX2);
            printf("Lutfen Secmek istediginiz 2. kartin kacinci sutunda oldugunu giriniz: ");
            scanf("%d", &userY2);
            system("cls");
            userSelectedCard2 = plain[userX2][userY2];
            printf("Sectiginiz Kart: %d\n", plain[userX2][userY2]);
            charvalue = userSelectedCard2 + '0';
            plainStr[userX2][userY2] = charvalue;
            for(o=0; o<n; o++){
                printf("\t\t\t");
                for(i=0; i<n; i++){
                    printf("%c    ", plainStr[o][i]);
                }
                printf("\n\n\n");
            }
            sleep(2);
            if(userSelectedCard2 == userSelectedCard1){
                userPoint++;
                system("cls");
                printf("!!Tebrikler bir adet es kart buldunuz!!\n");
                sleep(3);
                plainStr[userX1][userY1] = '-';
                plainStr[userX2][userY2] = '-';
                randSelected1[ind1] = userX1;
                randSelected2[ind1] = userY1;
                ind1++;
                randSelected1[ind1] = userX2;
                randSelected2[ind1] = userY2;
                ind1++;
            }else{
                printf("Es kart bulamadiniz, sira bilgisayara gecti\n");
                turn++;
                sleep(3);
                system("cls");
                plainStr[userX1][userY1] = '*';
                plainStr[userX2][userY2] = '*';
            }
        }else{
            printf("\t\t\tOyun Sirasi: Bilgisayar\n\n");
            for(o=0; o<n; o++){
                printf("\t\t\t");
                for(i=0; i<n; i++){
                    printf("%c    ", plainStr[o][i]);
                }
            }
            sleep(2);

            cpuRand(randSelected1, n, randSelected2, &ind1, &cpuX1, &cpuY1);
            //printf("\ncpuX1: %d --- cpuY1: %d\n", cpuX1, cpuY1);
            cpuSelectedCard1 = plain[cpuX1][cpuY1];
            //printf("%d", cpuSelectedCard1);
            randSelected1[ind1] = cpuX1;
            randSelected2[ind1] = cpuY1;
            ind1++;

            cpuRand(randSelected1, n, randSelected2, &ind1, &cpuX2, &cpuY2);
            cpuSelectedCard2 = plain[cpuX2][cpuY2];
            randSelected1[ind1] = cpuX2;
            randSelected2[ind1] = cpuY2;
            ind1++;

            printf("Bilgisayarin Sectigi Kartlar: %d - %d\n", cpuSelectedCard1, cpuSelectedCard2);
            charvalue = cpuSelectedCard1 + '0';
            plainStr[cpuX1][cpuY1] = charvalue;
            charvalue = cpuSelectedCard2 + '0';
            plainStr[cpuX2][cpuY2] = charvalue;

            for(o=0; o<n; o++){
                printf("\t\t\t");
                for(i=0; i<n; i++){
                    printf("%c    ", plainStr[o][i]);
                }
                printf("\n\n\n");
            }

            sleep(3);

            printf("\n\n\n");
            
            system("cls");
        }   
    }
    return 0;
}