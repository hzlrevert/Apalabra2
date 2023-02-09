#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include<time.h>



int val_men( void);
void rglmt(void);
void score(void);
void des(void);
void creard(void);
void JN(void);

void e_s(int pt);
int aleat(void);




int main()
{
int opc;


printf("\n\t\t BIENVENIDO A DICCIONADOS\n");
 men:
 printf("\n\n\n\tMENU:\n\t1-Instrucciones\n\t2-Juego nuevo \n\t3-Puntuaciones \n\t4-Desarrollador (requiere contrase\xA4");printf("a)\n\t5-Salida");
 printf("\n\n\tSeleccione una opcion:  ");

opc=val_men();

switch(opc)
{
	case 1:
		{
		rglmt();     /*APERTURA REGLAMENTO*/
        
		goto men;
		
		break;
	}
	case 2:
		/*JUEGO NUEVO;*/
		JN();
		goto men;
		break;
		
	case 3:
		/*SCORE*/
		score();
		goto men;
		break;
		
	case 4:
		/*;DESARROLL*/
		des();
		goto men;
		break;			
		
	case 5:
		/*;EXIT*/
		break;	
	
}

 

	return 0;
	
}





																/*------FUNCIONES-------*/
																
																
/*------------------------------------JN---------------------------------------*/
void JN(void)
{
	
int i=0,res=0;
	char palabra[50], def[300];
	//arr--
	
	  char p_a[100][50], d_a[100][300];
	  char p_i[1][50];
	//--

	FILE *D=fopen("diccionario.dat", "r");
	

	
	if(D==NULL)
	{
	
		printf("El archivo no se pudo abrir");
	}
	else
	{
	fscanf(D ,"%s", palabra);
			fgets (def, 300, D);
	}
/*/
//------------
/*/
	while(!feof(D))
	{
		
		
		
		/* almacenar en arr p_a*/
		{
		
		strcpy(p_a[i],palabra);
	}
		/*-------*/
		
		/*almacenar d_a*/
		{
		strcpy(d_a[i],def);
		}
		/*------*/
			i++;
		/*------*/
		
		fscanf(D ,"%s", palabra);
			fgets (def, 300, D);
		
	}
/*cerrar diccionario*/
fclose(D);


int j,err=0,pt=0;
printf("\n\n\n\tAdivinar la palabra:\n");
while(err<3)
{
//definir j
j=aleat();//llamado a aleatorio
//
printf("\n\n\n\t%d\n",pt+err);
printf("La definicion es: %s\n",d_a[j]);
printf("\n\n\n\tIngrese la palabra:\t");
scanf("%s",&p_i[0]);
printf("\n\t%s",p_i[0]);

res=strncmp(p_a[j],p_i[0],49);
if(res==0)
{	pt++;
	printf("\tEs correcto, llevas %d \n",pt);
	if(pt==100)
	{
		printf("GANASTE!! RESOLVISTE TODAS LAS PALABRAS");
		goto FIN;
	}
}
	else
	{
		printf("\n\tEs incorrecto");
		err++;
		printf(" Llevas %d respuestas incorrectas",err);
		if(err==3)
		{
			

			printf("\n\t\tPERDISTE\n");
			FIN:
			e_s(pt);
		}
	}
}
	
	
}

/*-------------ESCRIBIR SCORE--------------------------------*/

void e_s(int pt)
{
		
	char nmb[30];
	

	FILE *D=fopen("score.dat", "at");
	

	
	if(D==NULL)
	{
		printf("El archivo no pudo abrirse");
	}
	
		else
	{
		
		printf("introduzca su nombre\n");
		printf(">");
		scanf("%s",nmb);
	
	/*escribir en .dat*/
	
	while(!feof(stdin)){
		
		fprintf(D,"\n %d %s ",pt, nmb);
		printf("presione ctrl+Z para contiuar\n");
		scanf("%s",nmb);//ctrl+z finaliza el ingreso
		
	
	}
	/*chau while*/
	
	
	fclose(D);
	
	}
}
	


/*-------------VALIDACION DEL MENU--------------------------------*/

int val_men()
{
	 int ctrl=0,opc;
	 
 while(ctrl==0)
 {
 
 scanf("%d",&opc);
 if(opc>0&&opc<6)
 {
 		ctrl=1;/*  INGRESAR UN CHAR*/
 }
 else
 {
 printf("\n\tOPCION INCORRECTA");
 printf("\n\tSeleccione una opcion:  ");
 
 }
}
return (opc);
}


/*-------------------LECTOR DEL REGLAMENTO--------------------------*/

void rglmt()
{
	
		
	char reglas;
	FILE *D=fopen("reglamento.dat", "r");
	

	
	if(D==NULL)
	{
		printf("El archivo no pudo abrirse");
	}
do {
putchar (reglas=getc(D));
}
while (reglas !=EOF);


/*cerrar diccionario*/
fclose(D);

/*//---------*/


}
	
/*-------------------LECTOR DEL SCORE--------------------------*/

void score()
{
	
		
	char score;
	FILE *D=fopen("score.dat", "r");
	

	
	if(D==NULL)
	{
		printf("El archivo no pudo abrirse");
	}
do {
putchar (score=getc(D));


}
while (score!=EOF);
printf("\n\n");

/*cerrar score*/
fclose(D);

/*//---------*/

	
}
/*-------------------DESARROLADOR--------------------------*/
void des()
{

	char clave;
	
	
	printf("\n\n\t**MODO EDICION**\n\n");
	
clave=getch();
printf("*");

if(clave=='z')
	{
	creard();	
	}
	else 
	exit(-1);
}

/*-------------------CREARD--------------------------*/
void creard()
{
	
	char palabra[30], def[300];
	
		
	/*renombrar diccionario.DAT en diccionario.bkp*/
	
	 rename("diccionario.DAT","diccionario.bkp");
	
		
/*/--------------------*/
	
	FILE *D;
	if((D=fopen("diccionario.dat","w"))==NULL)
	{
		printf("El archivo no pudo abrirse");
	}
	else
	{
		
		printf("introduzca la palabra y la definicion \n");
		printf(">");
		scanf("%s %s",palabra,def);
	
	/*escribir en .dat*/
	while(!feof(stdin)){
		
		fprintf(D,"%s %s \n",palabra, def);
		printf(">");
		scanf("%s %s",palabra,def);
	}
	/*chau while*/
	
	
	fclose(D);
	printf("\n\n\t\tSE CREO UN DICCIONARIO NUEVO\n\t\tPARA RECUPERAR EL VIEJO SE DEBE BORRAR DICCIONARIO.DAT \n\t\tY CAMBIAR LA EXTENCION DE DICCIONARIO.BKP A .DAT\n\n");
	
	
	}
}

/*---------------------------------------------------------ALEATORIO-------------------------------------------------*/

int aleat(void)
{
	int gen[100]={100},j=0,i=0,ctrl=0,valor=0;
	
while(ctrl==0)
{
srand( time( NULL ) );
valor = 0 + (rand() % 100);
gen[i]=valor;
for(j=0;j<100;j++)
{
	if(gen[j]!=valor)
	{
		ctrl=1;
		i++;
	}
	else
	{ctrl=0;
	}
}

}
return (valor);
		
}
