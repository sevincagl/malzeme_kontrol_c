#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MaxMal 50
#define MaxRec 10

char materialnames[MaxMal][50];       //malzeme isimlerini saklar
int amountmaterial[MaxMal];            //malzeme miktarini saklar
char materialSTT[MaxMal][20];         //son tüketim tarihlerini(STT) saklar
int number_materials=0;

void menu();
void add_material();
void remove_material();
void material_list();

void menu2();
void last_date_check();
void recipe_suggestion();

char recipenames[10][20]={ "Chips", "Menemen" , "Crepe" , "Toast"};
char recipe_ingredient[MaxRec][10][20]={                  // her tarifin malzemelerini 
    {"potato","salt"},
   {"tomato","salt","egg"} ,
    { "milk","flour","sugar" },
    { "bread","cheese"}
     };
int recipe_number=4;
int recipe_ingredientcount[MaxRec]={2,3,3,2};            //her tarifin kac malzeme gerektigini tutar


int main(int argc, char *argv[]) {

    int choice=0;

    do{
	menu();
    printf("\nEnter your choose(1-4):");
    scanf("%d",&choice);
    switch(choice){
    	case 1:
		       add_material();
    	       break;
    	case 2:
    		   remove_material();
    		   break;
        case 3:
               material_list();
               break;
		case 4:
		       printf("exiting from menu 1\n");
    	       menu2();
    	       printf("\nEnter your choose(1-4):");
               scanf("%d",&choice);

               if(choice==1){
                    break;
               }
               else if(choice==2){
                    last_date_check();
                    break;
               }
               else if(choice==3){
                    recipe_suggestion();
                    break;
               }
               else if(choice==4){
                    printf("Exiting program\n");
                    return 0;
               }


	    default: printf("Invalid choice, please enter a number between 1 and 4\n");
	}
	}while(choice!=4);
     return 0;

}

void menu(){


    printf("\n");
	printf("*** MATERIAL MANAGEMENT SYSTEM ***\n");
	printf("1.Add Material \n");
	printf("2.Remove Material\n");
	printf("3.View Material List\n");
	printf("4.Exit\n");

}

void menu2(){

	printf("\n");
	printf("*** SMART REFRIGERATOR SYSTEM ***\n");
	printf("1.Material Management \n");
	printf("2.Expiration Date Check\n");
	printf("3.Recipe Suggestion\n");
	printf("4.Exit\n");
}


void add_material(){

    int i,amount;
    char material[50];
    char last_consumption_date[20];


	printf("\n");
	printf("Enter material name:");
	scanf("%s",material);
	printf("Enter the amount:");
	scanf("%d",&amount);
	printf("Enter the expiration date(yyyy/mm/dd):");
	scanf("%s",last_consumption_date);

    for(i=0;i<number_materials;i++){                            //malzeme kontrolu
	    if(strcmp(materialnames[i],material)==0){               //stringler arasi karakterleri karsilastiriliyor
	    	amountmaterial[i] += amount;                        //eger dizide varsa adetini artirir

	        printf("The material already exists,the quantity has been updated\n");
	        return;

		}
	}
	strcpy(materialnames[number_materials],material);               //malzeme adini diziye ekle
	amountmaterial[number_materials]=amount;                          //adeti diziye ekle
	strcpy(materialSTT[number_materials],last_consumption_date);    //son kullanim tarihini diziye ekle
	number_materials++;
	printf("Material successfully added\nTotal number of materials:%d\n",number_materials);

	//malzemeleri alfabetik siralama//
	char tempname[50];
	char tempSTT[20];
	int tempamount;
	int j;

	for(i=0;i<number_materials-1;i++){
		for(j=0;j<number_materials-i-1;j++){
			if(strcmp(materialnames[j],materialnames[j+1])>0){

			   strcpy(tempname,materialnames[j]);                 //strcpy stringleri kopyalar
			   strcpy(materialnames[j],materialnames[j+1]);     //malzeme isimlerini yerdegistir
			   strcpy(materialnames[j+1],tempname);

			   tempamount=amountmaterial[j];                    //malzeme adetlerini yerdegistir
			   amountmaterial[j]=amountmaterial[j+1];
			   amountmaterial[j+1]=tempamount;

			   strcpy(tempSTT,materialSTT[j]);                  //malzemenin son kullanim tarihlerini yerdegistir
			   strcpy(materialSTT[j],materialSTT[j+1]);
			   strcpy(materialSTT[j+1],tempSTT);

			}
		}
	}
}

void remove_material(){

	char material[50];
	int amount,i,j;
	if(number_materials==0){                                   //listeyi kontrol et
		printf("the material list is empty\n");
		return;
	}

	printf("Enter the name of the material to be removed:");
	scanf("%s",material);
	printf("enter the amount:");
	scanf("%d",&amount);

	for(i=0;i<number_materials;i++){
        if(strcmp(material,materialnames[i])==0){	                //stringlerde karakterleri karsilastiriliyor

	    	if(amountmaterial[i]>=amount){
	    		amountmaterial[i]-=amount;
	    		printf("material removed,remaining amount:%d\n",amountmaterial[i]);

	    	    if(amountmaterial[i]==0){                                     //miktar 0 düstüyse malzemeyi sil
	    	    	for(j=i;j<number_materials-1;j++){                        //eleman silme
	    	    			strcpy(materialnames[j],materialnames[j+1]);
                           	amountmaterial[j]=amountmaterial[j+1];
                         	strcpy(materialSTT[j],materialSTT[j+1]);
					}number_materials--;
					printf("Material completely removed\n");
				}

				}else                                 //malzeme adetinden büyük sayi girilirse
		         printf("Insufficient quantity of the material available\n");
		         return;
		}
	else                                              //cikarilacak malzeme dizide bulunmadiginda
	printf("Material not fount in the list\n");
	}
}
void material_list(){

    int i=0;
    if(number_materials==0){                          //listeyi kontrol et
        printf("the material list is empty\n");
        return;
    }
    printf("\n");
    printf("MATERIAL LIST\n");
    for(i=0;i<number_materials;i++){
        printf("%d.material=%s ,quantity=%d ,last comsumption date=%s \n",i+1,materialnames[i],amountmaterial[i],materialSTT[i]);

    }
	}


void last_date_check(){

    int i;
    char currentdate[20];
     printf("write current date(yyyy/mm/dd):");
     scanf("%s",currentdate);
     printf("\nOutdated materials:\n");

     for(i=0;i<number_materials;i++){

          if(strcmp(currentdate, materialSTT[i])>0){
            printf("-%s, last consumption date:%s\n",materialnames[i],materialSTT[i]);

          }
        }
}

void recipe_suggestion(){

    int i,j,k;
    int material_suggestion=0;                                    //tarif onerisi kontrolu yapýlmýs mi?
    int material_compatibility=0;                                 //uyumlu malzeme sayacý
    printf("Material Suggestion:\n");

    for(i=0;i<recipe_number;i++){                                 //her tarifi kontrol etmek
         material_compatibility=0;

        for(j=0;j<recipe_ingredientcount[i];j++){                 //her tarifin malzeme sayýsý
            for(k=0;k<number_materials;k++){
                if(strcmp(recipe_ingredient[i][j],materialnames[k])==0){
                   material_compatibility++;                      //eger malzeme bulunduysa sayacý artýr
                    break;
                }
        }
}
        if(material_compatibility==recipe_ingredientcount[i]){     //malzemeler uyumluysa tarifi oner
            printf("-%s: required materials: ",recipenames[i]);

            for(j=0;j<recipe_ingredientcount[i];j++){
                 printf("%s, ",recipe_ingredient[i][j]);
            }
            material_suggestion=1;                                 //tarifin onerildigi gosteriliyor
      }
}
       if(!material_suggestion){
        printf("No suitable recipe found\n");
       }
}


