#include <stdio.h>

int main() {

	//cadatro de cartas da cidade
		//variaveis da cidade 
	char Uf1[2], Uf2[2];
	int CodCarta1, CodCarta2;
	char nomeCidade1[20] , nomeCidade2[20];
	int Populacao1,Populacao2,opcao;
	float areaKM1,areaKM2;
	float pib1, pib2;
	int NumPointTurism1, NumPointTurism2;
	float MediaDensidade1, MediaPIB1;
	float MediaDensidade2, MediaPIB2;
	float PoderCidade1, PoderCidade2;
    
	//chamando cidade A01
	printf("\n               Informe Primeira cidade! \n\n");
	printf("Informe o Estado: ");
	scanf("%s", &Uf1);
	printf("Informe o Codigo da Carta: ");
	scanf("%d", &CodCarta1);
	printf("Informe o Nome da Cidade: ");
	scanf("%s", &nomeCidade1);
	printf("Informe a Populacao: ");
	scanf("%d", &Populacao1);
	printf("Informe a Area da Cidade: ");
	scanf("%f", &areaKM1);
	printf("Informe o PIB: ");
	scanf("%f", &pib1);
	printf("Informe a quantidade de pontos turisticos: ");
	scanf("%d", &NumPointTurism1);

	//exibe primeiro cadastro
	printf("\n \n              Cadastro da Primeira cidade realizado! \n\n\n");
	
	printf("Carta: %d \n", CodCarta1);
	printf("Estado: %s \n", Uf1);
	printf("Codigo: %s0%d \n", Uf1, CodCarta1);
	printf("Nome da Cidade: %s \n", nomeCidade1);
	printf("Populacao: %d \n", Populacao1);
	printf("Area: %.2f KM \n", areaKM1);
	printf("PIB: %.2f Bilhoes de reais\n", pib1);
	printf("Numero de Pontos Turisticos: %d \n", NumPointTurism1);

	MediaDensidade1 = (float)(Populacao1 / areaKM1);
	MediaPIB1 = (float)(pib1 / Populacao1);

	printf("Densidade Populacional: %.2f hab/km² \n", MediaDensidade1);
	printf("PIB per capita: %.2f reais\n\n\n\n", MediaPIB1);

	//soma poderes da cidade 1 e exibe
	PoderCidade1 = (float)(Populacao1 + areaKM1 + pib1 + NumPointTurism1 + MediaDensidade1 + MediaPIB1);

	printf(" **** Super Poder Cidade 1 *****: %d", PoderCidade1);

	//chamando cidade A02
	printf("\n\n\n\n\n              Informe Segunda cidade! \n\n\n");
	printf("Informe o Estado: ");
	scanf("%s", &Uf2);
	printf("Informe o Codigo da Carta: ");
	scanf("%d", &CodCarta2);
	printf("Informe o Nome da Cidade: ");
	scanf("%s", &nomeCidade2);
	printf("Informe a Populacao: ");
	scanf("%d", &Populacao2);
	printf("Informe a Area da Cidade: ");
	scanf("%f", &areaKM2);
	printf("Informe o PIB: ");
	scanf("%f", &pib2);
	printf("Informe a quantidade de pontos turisticos: ");
	scanf("%d", &NumPointTurism2);

	//exibe primeiro cadastro
	printf("\n \n              Cadastro da Segunda cidade realizado! \n\n\n");

	printf("Carta: %d \n", CodCarta2);
	printf("Estado: %s \n", Uf2);
	printf("Codigo: %s0%d \n", Uf2, CodCarta2);
	printf("Nome da Cidade: %s \n", nomeCidade2);
	printf("Populacao: %d \n", Populacao2);
	printf("Area: %.2f KM \n", areaKM2);
	printf("PIB: %.2f Bilhoes de reais\n", pib2);
	printf("Numero de Pontos Turisticos: %d \n", NumPointTurism2);

	MediaDensidade2 = (float)(Populacao2 / areaKM2);
	MediaPIB2 = (float)(pib2 / Populacao2);

	printf("Densidade Populacional: %.2f hab/km² \n", MediaDensidade2);
	printf("PIB per capita: %.2f reais\n", MediaPIB2);

	//soma poderes da cidade 2 e exibe
	PoderCidade2 = (float)(Populacao2 + areaKM2 + pib2 + NumPointTurism2 + MediaDensidade2 + MediaPIB2);

	printf(" **** Super Poder Cidade 2 *****: %d", PoderCidade2);

	printf("\n\nComparacao de Cartas:\n");
	printf("Populacao: ");
	if (Populacao1 > Populacao2){
	   printf("Cidade 1 venceu (%d)", (Populacao1 > Populacao2));}
    else {
		printf("Cidade 2 venceu (%d)", (Populacao1 > Populacao2));
	}
    printf("\nArea: ");
	if (areaKM1 > areaKM2){
			printf("Cidade 1 venceu (%d)", (areaKM1 > areaKM2));}
    else {
		printf("Cidade 2 venceu (%d)", (areaKM1 > areaKM2));
	}
    printf("\nPIB: ");
	if (pib1 > pib2){
			printf("Cidade 1 venceu (%d)", (pib1 > pib2));}
    else{	
		printf("Cidade 2 venceu (%d)", (pib1 > pib2));
	}
    printf("\nPontos Turísticos: ");
	if (NumPointTurism1 > NumPointTurism2){
			printf("Cidade 1 venceu (%d)", (NumPointTurism1 > NumPointTurism2));}
    else{	
		printf("Cidade 2 venceu (%d)", (NumPointTurism1 > NumPointTurism2));
	}
    printf("\nDensidade Populacional: ");
	if (MediaDensidade1 < MediaDensidade2){
			printf("Cidade 1 venceu (%d)", (MediaDensidade1 < MediaDensidade2));}
    else{
			printf("Cidade 2 venceu (%d)", (MediaDensidade1 < MediaDensidade2));
	}
    printf("\nPIB per Capita: ");
	if (MediaPIB1> MediaPIB2){	
		printf("Cidade 1 venceu (%d)", (MediaPIB1 > MediaPIB2));}
    else{	
		printf("Cidade 2 venceu (%d)", (MediaPIB1 > MediaPIB2));
	}
	printf("\nSuper Poder: ");
	if (PoderCidade1> PoderCidade2){	
		printf("Cidade 1 venceu (%d)", (PoderCidade1 > PoderCidade2));}
    else{	
		printf("Cidade 2 venceu (%d)", (PoderCidade1 > PoderCidade2));
	}
    
	printf("\n\n ====== MENU DE RESULTADO ======\n");
	printf("0-[Populacao]           |  1-[Area KM]         |  2-[PIB]         |  3-[Pontos Turisticos] \n");
	printf("4-[Dens. Populacional]  |  5-[PIB per capita]  |  6-[Poder]\n");
	scanf("%d",&opcao);
	
	switch(opcao){
	case 0:
	    printf("\nPopulacao\n");
		printf("Carta %d - %s (%s):%d \n",CodCarta1,nomeCidade1,Uf1,Populacao1);
		printf("Carta %d - %s (%s):%d \n",CodCarta2,nomeCidade2,Uf2,Populacao2);
		if(Populacao1 > Populacao2){
            printf("Resultado: Carta %d (%s) venceu!\n",CodCarta1,nomeCidade1);
		}else if(Populacao1 = Populacao2){
			printf("Empate");
		}else{
            printf("Resultado: Carta %d (%s) venceu!\n",CodCarta2,nomeCidade2);   
		}			
	break;	
	case 1:
	    printf("\nArea\n");
		printf("Carta %d - %s (%s):%.2f \n",CodCarta1,nomeCidade1,Uf1,areaKM1);
		printf("Carta %d - %s (%s):%.2f \n",CodCarta2,nomeCidade2,Uf2,areaKM2);
		if(areaKM1 > areaKM2){
            printf("Resultado: Carta %d (%s) venceu!\n",CodCarta1,nomeCidade1);
		}else if(areaKM1 = areaKM2){
			printf("Empate");
		}else{
			printf("Resultado: Carta %d (%s) venceu!\n",CodCarta2,nomeCidade2);
		}	
	break;	
	case 2:
	    printf("\nPIB\n");
		printf("Carta %d - %s (%s):%.2f \n",CodCarta1,nomeCidade1,Uf1,pib1);
		printf("Carta %d - %s (%s):%.2f \n",CodCarta2,nomeCidade2,Uf2,pib2);
		if(pib1 > pib2){
            printf("Resultado: Carta %d (%s) venceu!\n",CodCarta1,nomeCidade1);
		}else if(pib1 = pib2){
			printf("Empate");
		}else{
			printf("Resultado: Carta %d (%s) venceu!\n",CodCarta2,nomeCidade2);
		}
	break;	
	case 3:
	    rintf("\nPontos Turisticos\n");	
		printf("Carta %d - %s (%s):%d \n",CodCarta1,nomeCidade1,Uf1,NumPointTurism1);
		printf("Carta %d - %s (%s):%d \n",CodCarta2,nomeCidade2,Uf2,NumPointTurism2);
		if(NumPointTurism1 > NumPointTurism2){
            printf("Resultado: Carta %d (%s) venceu!\n",CodCarta1,nomeCidade1);
		}else if(NumPointTurism1 = NumPointTurism2){
			printf("Empate");
		}else{
			printf("Resultado: Carta %d (%s) venceu!\n",CodCarta2,nomeCidade2);
		}
	break;	
	case 4:
	    printf("Dens. Populacional\n");
		printf("Carta %d - %s (%s):%.2f \n",CodCarta1,nomeCidade1,Uf1,MediaDensidade1);
		printf("Carta %d - %s (%s):%.2f \n",CodCarta2,nomeCidade2,Uf2,MediaDensidade2);
		if(MediaDensidade1 > MediaDensidade2){
            printf("Resultado: Carta %d (%s) venceu!\n",CodCarta1,nomeCidade1);
		}else if(MediaDensidade1 = MediaDensidade2){
			printf("Empate");
		}else{
			printf("Resultado: Carta %d (%s) venceu!\n",CodCarta2,nomeCidade2);
		}
	break;	
	case 5:
	    printf("PIB per capita\n");
		printf("Carta %d - %s (%s):%.2f \n",CodCarta1,nomeCidade1,Uf1,MediaPIB1);
		printf("Carta %d - %s (%s):%.2f \n",CodCarta2,nomeCidade2,Uf2,MediaPIB2);
		if(MediaPIB1 > MediaPIB2){
            printf("Resultado: Carta %d (%s) venceu!\n",CodCarta1,nomeCidade1);
		}else if(MediaPIB1 = MediaPIB2){
			printf("Empate");
		}else{
			printf("Resultado: Carta %d (%s) venceu!\n",CodCarta2,nomeCidade2);
		}
	break;	
	case 6:
	    printf("\nPoder\n");
		printf("Carta %d - %s (%s):%.2f \n",CodCarta1,nomeCidade1,Uf1,PoderCidade1);
		printf("Carta %d - %s (%s):%.2f \n",CodCarta2,nomeCidade2,Uf2,PoderCidade2);
		if(PoderCidade1 > PoderCidade2){
            printf("Resultado: Carta %d (%s) venceu!\n",CodCarta1,nomeCidade1);
		}else if(PoderCidade1 = PoderCidade2){
			printf("Empate");
		}else{
			printf("Resultado: Carta %d (%s) venceu!\n",CodCarta2,nomeCidade2);
		}
	break;	
	}	
	
	return 0;
}
