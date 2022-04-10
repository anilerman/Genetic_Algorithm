#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#define NUMBER_OF_POPULATION 20
#define COORDINATE_RANGE_END 100
#define NUMBER_OF_CITIES 8
#define MUTATION_RATE 0.1


int duzenle (int rastgeleRota[],int u)
{
	for (int t = 0; t<NUMBER_OF_CITIES ; t++)
	{
		if (rastgeleRota[t]==u)
		{
			return 0;
		}
	}
	return 1;

}

int main ()
{
   int a,b,z,y,t,k,l,m;
   int degistir;
   int rota [NUMBER_OF_POPULATION][NUMBER_OF_CITIES];
   int sehir[NUMBER_OF_CITIES][2];

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------- 
    // ÞEHÝRE KOORDÝNAT ATMASI

	srand(time(NULL));

	for(a=0 ; a<NUMBER_OF_CITIES ; a++)
		
		for (b=0 ; b<2 ; b++)
		{
			sehir[a][b]= rand()%COORDINATE_RANGE_END;

		}



	printf("\t\t       %s%13s\n", " x", "y");

	for (z=0 ; z<NUMBER_OF_CITIES ; z++)
	
		{
			printf ("%d. sehir ---------->  ",z+1);
          if (z<1)
          {
          	printf (" ");
		  }
		  printf("%d", sehir[z][0]);
		  
		  	if (sehir [z][0]<10)
			{
				printf (" ");
			}
		   printf("           %d\n ",sehir[z][1]);
		  
		}
		
		printf ("\n");

				printf ("**********************************************************");																				
																						printf ("\n\n");

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------																												
																																		
		//ROTA OLUÞTURMA

	    int o,q;
	    int rastgeleRota[NUMBER_OF_POPULATION][NUMBER_OF_CITIES];  //rastgele rota oluþturmak için dizi tanýmý 
	    srand(time(NULL));
	    int u;
		for (int o=0 ; o<NUMBER_OF_POPULATION ; o++)
		{
			if (o<9)
			{
				printf(" ");
			}

			printf ("%d --------------->\t",o+1);
		 	for (q=0 ; q<NUMBER_OF_CITIES; q++ )
		 	{
		 		

				 
		 		u=1+rand()%NUMBER_OF_CITIES;
		 		while (duzenle(rastgeleRota[o],u)==0)
		 		{
		 		u=1+rand()%NUMBER_OF_CITIES;
		 	    }
		 	    

				
			rastgeleRota[o][q]=u;
			printf("%d   ",rastgeleRota[o][q]);
					
			}
				printf("\n");
			}
			
			

		
				//********************* HER ÞEHÝRÝN BÝRBÝRNE OLAN UZAKLIÐI ******************************
				
				
				
				/*bazý sehirlerin birbirne olan uzaklýðýný kontrol etmek için yardýmcý kod:
		
			printf ("1. sehir ve 1. sehir arasý mesafe : %f \n",sqrt(pow(sehir[0][0]-sehir[0][0],2)+pow(sehir[0][1]-sehir[0][1],2)));				
			printf ("1. sehir ve 2. sehir arasý mesafe : %f \n",sqrt(pow(sehir[0][0]-sehir[1][0],2)+pow(sehir[0][1]-sehir[1][1],2)));
			printf ("1. sehir ve 3. sehir arasý mesafe : %f \n",sqrt(pow(sehir[0][0]-sehir[2][0],2)+pow(sehir[0][1]-sehir[2][1],2)));
			printf ("1. sehir ve 4. sehir arasý mesafe : %f \n",sqrt(pow(sehir[0][0]-sehir[3][0],2)+pow(sehir[0][1]-sehir[3][1],2)));
			printf ("1. sehir ve 5. sehir arasý mesafe : %f \n",sqrt(pow(sehir[0][0]-sehir[4][0],2)+pow(sehir[0][1]-sehir[4][1],2)));
			printf ("1. sehir ve 6. sehir arasý mesafe : %f \n\n",sqrt(pow(sehir[0][0]-sehir[5][0],2)+pow(sehir[0][1]-sehir[5][1],2)));
			
			printf ("2. sehir ve 1. sehir arasý mesafe : %f \n",sqrt(pow(sehir[1][0]-sehir[0][0],2)+pow(sehir[1][1]-sehir[0][1],2)));			
			printf ("2. sehir ve 2. sehir arasý mesafe : %f \n",sqrt(pow(sehir[1][0]-sehir[1][0],2)+pow(sehir[1][1]-sehir[1][1],2)));
			printf ("2. sehir ve 3. sehir arasý mesafe : %f \n",sqrt(pow(sehir[1][0]-sehir[2][0],2)+pow(sehir[1][1]-sehir[2][1],2)));
			printf ("2. sehir ve 4. sehir arasý mesafe : %f \n",sqrt(pow(sehir[1][0]-sehir[3][0],2)+pow(sehir[1][1]-sehir[3][1],2)));
			printf ("2. sehir ve 5. sehir arasý mesafe : %f \n",sqrt(pow(sehir[1][0]-sehir[4][0],2)+pow(sehir[1][1]-sehir[4][1],2)));
			printf ("2. sehir ve 6. sehir arasý mesafe : %f \n\n",sqrt(pow(sehir[1][0]-sehir[5][0],2)+pow(sehir[1][1]-sehir[5][1],2)));
			
			printf ("3. sehir ve 1. sehir arasý mesafe : %f \n",sqrt(pow(sehir[2][0]-sehir[0][0],2)+pow(sehir[2][1]-sehir[0][1],2)));			
			printf ("3. sehir ve 2. sehir arasý mesafe : %f \n",sqrt(pow(sehir[2][0]-sehir[1][0],2)+pow(sehir[2][1]-sehir[1][1],2)));
			printf ("3. sehir ve 3. sehir arasý mesafe : %f \n",sqrt(pow(sehir[2][0]-sehir[2][0],2)+pow(sehir[2][1]-sehir[2][1],2)));
			printf ("3. sehir ve 4. sehir arasý mesafe : %f \n",sqrt(pow(sehir[2][0]-sehir[3][0],2)+pow(sehir[2][1]-sehir[3][1],2)));
			printf ("3. sehir ve 5. sehir arasý mesafe : %f \n",sqrt(pow(sehir[2][0]-sehir[4][0],2)+pow(sehir[2][1]-sehir[4][1],2)));
			printf ("3. sehir ve 6. sehir arasý mesafe : %f \n\n",sqrt(pow(sehir[2][0]-sehir[5][0],2)+pow(sehir[2][1]-sehir[5][1],2)));
			
			*/

			
			printf ("\n**********************************************************\n\n");
			
		for (o=0 ; o<NUMBER_OF_CITIES ; o++)  //her sehrin birbirine olan mesafesini göstermek için for döngüsü (ilk döngü sütun için)
		{
			for (q=0 ; q<NUMBER_OF_CITIES ; q++) //ikinci döngü de satýr için
			{
				printf ("%d. sehir ve %d. sehir arasý mesafe : %f \n",o+1,q+1,sqrt(pow(sehir[o][0]-sehir[q][0],2)+pow(sehir[o][1]-sehir[q][1],2)));
			}
			
			printf ("\n\n");
		}
		
		
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------	


		// ÞEHÝR MESAFELERÝNÝ DÝZÝYE KAYDETMEK
		
		int p,f;
		float g;
		float rotaHafiza[NUMBER_OF_CITIES][NUMBER_OF_CITIES]; //sehir mesafelerini kaydetmek için oluþturualn dizi
		
		for (p=0; p<NUMBER_OF_CITIES; p++)
		{
			for(f=0; f<NUMBER_OF_CITIES; f++)
			{
								
				rotaHafiza[p][f]=sqrt(pow(sehir[p][0]-sehir[f][0],2)+pow(sehir[p][1]-sehir[f][1],2)); //sehir mesafelerinin hesaplanýp diziye kaydedilmesi


			}
		}
		
				printf ("**********************************************************\n\n");
				/* rota hesaplama kontrolu için yardýmcý referanslar
				printf ("%d\n",rastgeleRota[0][0]);
				printf ("%d\n",rastgeleRota[0][1]);				
				printf ("%d\n",rastgeleRota[0][2]);	
				printf ("%d\n",rastgeleRota[0][3]);
				
				printf("%f\n",rotaHafiza[rastgeleRota[0][0]-1][rastgeleRota[0][1]-1]);
								printf("%f\n",rotaHafiza[rastgeleRota[0][1]-1][rastgeleRota[0][2]-1]);
								printf("ILK IKI ROTA : %f\n",rotaHafiza[rastgeleRota[0][0]-1][rastgeleRota[0][1]-1] + rotaHafiza[rastgeleRota[0][1]-1][rastgeleRota[0][2]-1]);
								
				*/				
								
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------				
								
				
				// RASTGELE ROTAYÝ KULLANARAK TOPLAM ROTAYI BULMA
	
				
				float populasyonHafiza [NUMBER_OF_POPULATION] ;
				float r = 0.000000;
				for (p=0; p<NUMBER_OF_POPULATION ; p++)
				{
					r=0.000000;
					for (f=1; f<NUMBER_OF_CITIES; f++)
					{
						r =r + (rotaHafiza[rastgeleRota[p][f-1]-1][rastgeleRota[p][f]-1]);
						populasyonHafiza [p]=r;
						
						/*rota toplam kontrolu yapmak için kod :

						printf("%f\n\n",r);
						
						*/

						
					}
						if (p<9)
						{
							printf ("%d.  | rota ----------> %f |\n", p+1, populasyonHafiza[p]);
						}
						else
						{
							printf ("%d. | rota ----------> %f |\n", p+1, populasyonHafiza[p]);
						}
				}
				
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------

				
		// ROTALARI KÜÇÜKtEN BÜYÜÐE SIRALAMAK ÝÇÝN BUBBLE SORT ALGORÝTMASI
				
				float smaller,smallest;
				
				float change,gecici;
				
				for (p=0 ; p<NUMBER_OF_POPULATION; p++)
				{
					for (f=0; f<NUMBER_OF_POPULATION  ; f++  )
					{
						if (populasyonHafiza [f]< populasyonHafiza [f+1])
						{
							change = populasyonHafiza [f]; //mesafeleri sýralamak için deðiþtirme
							populasyonHafiza [f] = populasyonHafiza [f+1];
							populasyonHafiza [f+1] = change;
							
							for (int i =0 ; i<NUMBER_OF_CITIES ; i++)
							{
								gecici = rastgeleRota [f][i];  //rastgele rotaþlarý sýralmak için tekrardan düzenleme 
								rastgeleRota [f][i] = rastgeleRota [f+1][i];
								rastgeleRota [f+1][i] = gecici;
							}
						}
					}
				}
				
		printf ("\n**********************************************************\n\n");
		
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------
	
		//BUBBLE SORTUN SONUCUNUN BASTIRILMASI
		
		printf ("rota mesafelerinin siralanmis hali:\n\n");
		for (p=0 ; p<NUMBER_OF_POPULATION; p++)
		{
		if (p<9)     // 1-9 RAKAMLARINDA TABLONUN BÝR BOÞLUK BIRAKILARAK DAHA DÜZGÜN GÖZÜKMESÝ ÝÇÝN 
		{
		printf ("%d.  | rota ----------> %f |\n", p+1, populasyonHafiza[p]);
		}
		else
		{
		printf ("%d. | rota ----------> %f |\n", p+1, populasyonHafiza[p]);
		}
		}
		printf ("\n**********************************************************\n\n");
		
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------


		//SIRALANMIS ROTA MESAFELERÝNE GÖRE TEKRARDAN RASTGELE ROTALARI DÜZENLEME 
		
		
		printf ("rastgele rotanin tekrar siralanmis hali:\n\n");
		
		for (p=0;p<NUMBER_OF_POPULATION; p++) //mesafelere göre sýralanmýþ rotalarý tekrardan yazmak için for döngüsü
		{
			printf ("%d. | rota ---------->   | ",p+1);
			for (f=0 ; f<NUMBER_OF_CITIES ; f++)
			{
				printf ("%3d",rastgeleRota [p][f]);
			}
			
			printf ("\n");

		}
				printf ("\n**********************************************************\n");
				
				int rot = 2;
				ROT:
				if(populasyonHafiza[NUMBER_OF_POPULATION-rot]==populasyonHafiza[NUMBER_OF_POPULATION-1]) // eger en kýsa iki rota eþitse ikinci en kýsa rotayý bulmak icin if statement.
				
				{
					rot = rot + 1;
					
					goto ROT;
					
				}

		printf ("\nen kisa rota %d. rota ====> ",NUMBER_OF_POPULATION);  //en kýsa rotayý ne olduðunu görmek için
		for (int i=0;i<NUMBER_OF_CITIES;i++)
		{
		printf ("%d  ",rastgeleRota[NUMBER_OF_POPULATION-1][i]);
	}
	
		printf ("mesafe = %f", populasyonHafiza[NUMBER_OF_POPULATION-1]);
			printf ("\nkisa  rota   %d. rota ====> ",NUMBER_OF_POPULATION-1);  //kýsa rotayý görmek için
		for (int i=0;i<NUMBER_OF_CITIES;i++)
		{
		printf ("%d  ",rastgeleRota[NUMBER_OF_POPULATION-rot][i]);
		}
		printf ("mesafe = %f", populasyonHafiza[NUMBER_OF_POPULATION-rot]);
	

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------

	// ********************************** CROSSÝNG-OVER *************************************
	
	int enKisaRotaSayisi = 0;
	int enKisaRotaHafiza = 0;
	float minRota1 = populasyonHafiza [NUMBER_OF_POPULATION-1]; 
	float minRota2 = populasyonHafiza [NUMBER_OF_POPULATION-rot]; 
	
	crossDongu:
	int randNumber;
	srand(time(NULL));
	randNumber=1+rand()%(NUMBER_OF_CITIES-1);
	for (int i=randNumber;i<NUMBER_OF_CITIES;i++)
	{
		int cross=rastgeleRota[NUMBER_OF_POPULATION-1][i];
		rastgeleRota[NUMBER_OF_POPULATION-1][i]=rastgeleRota[NUMBER_OF_POPULATION-rot][i];
		rastgeleRota[NUMBER_OF_POPULATION-rot][i]=cross;
	}
	
		r=0.000000;
		for (f=1; f<NUMBER_OF_CITIES; f++)
		{
		r =r + (rotaHafiza[rastgeleRota[NUMBER_OF_POPULATION-1][f-1]-1][rastgeleRota[NUMBER_OF_POPULATION-1][f]-1]);
		populasyonHafiza [NUMBER_OF_POPULATION-1]=r;
				/*rota toplam kontrolu yapmak için kod :

						printf("%f\n\n",r);
						
						*/
						
	}
	
	printf("\n\ncross sonrasi");

			printf ("\n\nen kisa rota %d. rota ====> ",NUMBER_OF_POPULATION);  //en kýsa rotayý ne olduðunu görmek için
		for (int i=0;i<NUMBER_OF_CITIES;i++)
		{
		printf ("%d  ",rastgeleRota[NUMBER_OF_POPULATION-1][i]);
	}


			printf ("\nkisa  rota   %d. rota ====> ",NUMBER_OF_POPULATION-1);  //kýsa rotayý görmek için
		for (int i=0;i<NUMBER_OF_CITIES;i++)
		{
		printf ("%d  ",rastgeleRota[NUMBER_OF_POPULATION-rot][i]);
		}
		
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------

// ***************************** CROSSÝNG OVER SONRASI HATA DUZELTME ***************************************************
		
for(int i=0;i<NUMBER_OF_CITIES;i++){  // kisa rotanýn hatalarýný düzeltme
			for(int j=0;j<NUMBER_OF_CITIES;j++){
				if(i==j){
				}
				else{
					if(rastgeleRota[NUMBER_OF_POPULATION-rot][i]==rastgeleRota[NUMBER_OF_POPULATION-rot][j]){
						kontrol1:rastgeleRota[NUMBER_OF_POPULATION-rot][j]=1+rand()%NUMBER_OF_CITIES;
							for(int p=0; p<NUMBER_OF_CITIES ; p++ ){
									if(j==p){
									}
									else{
										if(rastgeleRota[NUMBER_OF_POPULATION-rot][j]==rastgeleRota[NUMBER_OF_POPULATION-rot][p]){
										goto kontrol1;
										}
									
								}
						
					}
				}
			}
		}
	} 
	
	for(int i=0;i<NUMBER_OF_CITIES;i++){ // en kýsa rotanýn hatalarýný düzeltme
			for(int j=0;j<NUMBER_OF_CITIES;j++){
				if(i==j){
				}
				else{
					if(rastgeleRota[NUMBER_OF_POPULATION-1][i]==rastgeleRota[NUMBER_OF_POPULATION-1][j]){
						kontrol2:rastgeleRota[NUMBER_OF_POPULATION-1][j]=1+rand()%NUMBER_OF_CITIES;
							for(int p=0; p<NUMBER_OF_CITIES ; p++ ){
									if(j==p){
									}
									else{
										if(rastgeleRota[NUMBER_OF_POPULATION-1][j]==rastgeleRota[NUMBER_OF_POPULATION-1][p]){
										goto kontrol2;
										}
									
								}
						
					}
				}
			}
		}
	} 
	
 
	
			
			
			
			printf ("\n\nduzeltme sonrasi");


//---------------------------------------------------------------------------------------------------------------------------------------------------------------------

// *********************************** CROSSÝNG OVER SONRASI TEKRAR ROTA HESAPLAMA ***********************************************

		
					 g=0.000000;
		for (f=1; f<NUMBER_OF_CITIES; f++)
		{
		g=g + (rotaHafiza[rastgeleRota[NUMBER_OF_POPULATION-rot][f-1]-1][rastgeleRota[NUMBER_OF_POPULATION-1][f]-1]);
		populasyonHafiza [NUMBER_OF_POPULATION-rot]=t;
				/*rota toplam kontrolu yapmak için kod :

						printf("%f\n\n",r);
						
						*/
						
	}
	
		printf ("\n\nen kisa rota %d. rota ====> ",NUMBER_OF_POPULATION);  //en kýsa rotayý ne olduðunu görmek için
		for (int i=0;i<NUMBER_OF_CITIES;i++)
		{
		printf ("%d  ",rastgeleRota[NUMBER_OF_POPULATION-1][i]);
	}
	

			printf ("\nkisa  rota   %d. rota ====> ",NUMBER_OF_POPULATION-1);  //kýsa rotayý görmek için
		for (int i=0;i<NUMBER_OF_CITIES;i++)
		{
		printf ("%d  ",rastgeleRota[NUMBER_OF_POPULATION-rot][i]);
		}
		
		

	//---------------------------------------------------------------------------------------------------------------------------------------------------------------------
	
	//******************************************************** MUTASTON *******************************************************************************
	
	int mutasyonBasla1 = 2;
	int mutasyonBasla2 = 4;
	int mutasyonDeger;
	int mutasyonDegerDuzeltme = 1/MUTATION_RATE;

	
	mutasyonDeger = 1+rand()%mutasyonDegerDuzeltme;
	
	if (mutasyonDeger==mutasyonBasla1)
	{
		printf("\n\nMutasyon uygulaniyor...");
		int mutasyonHafiza=rastgeleRota[NUMBER_OF_POPULATION-rot][1];
		rastgeleRota[NUMBER_OF_POPULATION-rot][1]=rastgeleRota[NUMBER_OF_POPULATION-rot][2];
		rastgeleRota[NUMBER_OF_POPULATION-rot][2]=mutasyonHafiza;
		mutasyonHafiza=rastgeleRota[NUMBER_OF_POPULATION-1][1];
		rastgeleRota[NUMBER_OF_POPULATION-1][1]=rastgeleRota[NUMBER_OF_POPULATION-1][2];
		rastgeleRota[NUMBER_OF_POPULATION-1][2]=mutasyonHafiza;
		
	if (mutasyonDeger==mutasyonBasla2)
	{
		printf("\n\nMutasyon uygulaniyor...");
		int mutasyonHafiza=rastgeleRota[NUMBER_OF_POPULATION-rot][0];
		rastgeleRota[NUMBER_OF_POPULATION-rot][0]=rastgeleRota[NUMBER_OF_POPULATION-rot][NUMBER_OF_CITIES];
		rastgeleRota[NUMBER_OF_POPULATION-rot][NUMBER_OF_CITIES]=mutasyonHafiza;
		mutasyonHafiza=rastgeleRota[NUMBER_OF_POPULATION-1][0];
		rastgeleRota[NUMBER_OF_POPULATION-1][0]=rastgeleRota[NUMBER_OF_POPULATION-1][NUMBER_OF_CITIES];
		rastgeleRota[NUMBER_OF_POPULATION-1][NUMBER_OF_CITIES]=mutasyonHafiza;
		
		}
	
	}
	
			
					 g=0.000000;
		for (f=1; f<NUMBER_OF_CITIES; f++)
		{
		g=g + (rotaHafiza[rastgeleRota[NUMBER_OF_POPULATION-rot][f-1]-1][rastgeleRota[NUMBER_OF_POPULATION-rot][f]-1]);
		populasyonHafiza [NUMBER_OF_POPULATION-rot]=t;
				/*rota toplam kontrolu yapmak için kod :

						printf("%f\n\n",r);
						
						*/
		}
	
		printf ("\n\nen kisa rota %d. rota ====> ",NUMBER_OF_POPULATION);  //en kýsa rotayý ne olduðunu görmek için
		for (int i=0;i<NUMBER_OF_CITIES;i++)
		{
		printf ("%d  ",rastgeleRota[NUMBER_OF_POPULATION-1][i]);
	}
	

			printf ("\nkisa  rota   %d. rota ====> ",NUMBER_OF_POPULATION-1);  //kýsa rotayý görmek için
		for (int i=0;i<NUMBER_OF_CITIES;i++)
		{
		printf ("%d  ",rastgeleRota[NUMBER_OF_POPULATION-rot][i]);
		}
		
		
		
		
if (populasyonHafiza [NUMBER_OF_POPULATION-1] <= minRota1)
{
	minRota1 = populasyonHafiza [NUMBER_OF_POPULATION-1];
	minRota2 = populasyonHafiza [NUMBER_OF_POPULATION-rot];
}




		
enKisaRotaSayisi++;

		


		
	if (enKisaRotaSayisi == 200)
		{
			goto bitis;
		}
	

		goto crossDongu;

     bitis:
     	
     	
	printf ("\n\n algoritma bitti.... ");
	printf("\n\n1. en kisa rota  =================> = %f ---------------> ",minRota1);
			for (int i=0;i<NUMBER_OF_CITIES;i++)
		{
		printf ("%d  ",rastgeleRota[NUMBER_OF_POPULATION-1][i]);
	}
	

	


	
	
	
	
	
	
	
	
}

