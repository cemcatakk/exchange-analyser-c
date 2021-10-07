#include <stdio.h>
#include <string.h>
struct ExItem{
  char name[10];
  double max;
  double min;
  double average;
};
struct ExRate{
  int ayNo;
  struct ExItem exItem[3];
};
struct Kur{
  char name[10];
  int dususYasananAy;
  int yukselisYasananAy;
  double maxDeger;
  int maxAyNo;
  double minDeger;
  int minAyNo;
  double ort;
};
int main(void) {
  struct ExRate exRates[10];
  int i,j=0;
  int ayNo=0,ayAdet=0;
  while(ayNo!=-1){
    printf("Ay No?\n");
    scanf("%d",&ayNo);
    if(ayNo!=-1){
      exRates[j].ayNo=ayNo;
      for(i=0;i<3;i++){
        printf("Item adi, max, min ve average degerleri?\n");
        scanf("%s %lf %lf %lf",exRates[j].exItem[i].name,&exRates[j].exItem[i].max,
        &exRates[j].exItem[i].min,&exRates[j].exItem[i].average);
      }
      j++;
      if(ayAdet<10)
        ayAdet++;
      if(j==10)
        j=0;
    }
  }
  struct Kur kurlar[3];
  strcpy(kurlar[0].name,"XAU");
  strcpy(kurlar[1].name,"EUR");
  strcpy(kurlar[2].name,"USD");
  for(i=0;i<3;i++){
    kurlar[i].minDeger=99999;
    kurlar[i].minAyNo=1;
    kurlar[i].maxDeger=0;
    kurlar[i].maxAyNo=1;
    kurlar[i].ort=0;
    kurlar[i].dususYasananAy=1;
    kurlar[i].yukselisYasananAy=1;
  }
  for(i=0;i<ayAdet;i++){
    if(exRates[i].ayNo>0){
      int kurid=0;
      for(j=0;j<3;j++){
        if(strcmp(exRates[i].exItem[j].name,"XAU")==0){
          kurid=0;
        }
        else if(strcmp(exRates[i].exItem[j].name,"EUR")==0){
          kurid=1;
        }
        else kurid=2;
        kurlar[kurid].ort+=exRates[i].exItem[j].average;
        if(i>0){
          if(exRates[i].exItem[j].average>exRates[i-1].exItem[j].average){
            kurlar[kurid].dususYasananAy++;
          }
          if(exRates[i].exItem[j].average<exRates[i-1].exItem[j].average){
            kurlar[kurid].yukselisYasananAy++;
          }
        }
        if(kurlar[kurid].maxDeger<exRates[i].exItem[j].max){
          kurlar[kurid].maxDeger = exRates[i].exItem[j].max;
          kurlar[kurid].maxAyNo = exRates[i].ayNo;
        }
        if(kurlar[kurid].minDeger>exRates[i].exItem[j].min){
          kurlar[kurid].minDeger = exRates[i].exItem[j].min;
          kurlar[kurid].minAyNo= exRates[i].ayNo;
        }
      }
    }
  }
  for(i=0;i<3;i++){
    kurlar[i].ort = kurlar[i].ort/ayAdet;
    printf("1-%s kurunda dusus yasanan ay sayisi: %d\n",kurlar[i].name,kurlar[i].dususYasananAy);
    printf("2-%s kurunda yukselis yasanan ay sayisi: %d\n",kurlar[i].name,kurlar[i].yukselisYasananAy);
    printf("3-%s kurunun maksimum degeri: %lf bu degerin gerceklestigi ay no: %d\n",kurlar[i].name,kurlar[i].maxDeger,kurlar[i].maxAyNo);
    printf("4-%s kurunun minimum degeri: %lf bu degerin gerceklestigi ay no: %d\n",kurlar[i].name,kurlar[i].minDeger,kurlar[i].minAyNo);
    printf("5-%s kurunun girilen aylardaki ortalama degeri: %lf\n",kurlar[i].name,kurlar[i].ort);
    printf("\n\n");
  }
  return 0;
}