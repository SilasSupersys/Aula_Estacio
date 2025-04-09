#include <stdio.h>

int main() {

	//cadatro de cartas da cidade
		//variaveis da cidade 
	char Uf1 = 'A', Uf2 = 'B';
	int CodCarta1 = 1, CodCarta2 = 1;
	char nomeCidade1[20] = "", nomeCidade2[20] = "";
	int Populacao1, Populacao2;
	float areaKM1, areaKM2;
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
	printf("Estado: %c \n", Uf1);
	printf("Codigo: %c0%d \n", Uf1, CodCarta1);
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

	printf(" **** Super Poder Cidade 1 *****: %.2f", PoderCidade1);

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
	printf("Estado: %c \n", Uf2);
	printf("Codigo: %c0%d \n", Uf2, CodCarta2);
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

	printf(" **** Super Poder Cidade 2 *****: %.2f", PoderCidade2);

	printf("\n\nComparacao de Cartas:\n");
	printf("Populacao: ");
	if (PoderCidade1 > PoderCidade2)printf("Cidade 1 venceu (%d)", (PoderCidade1 > PoderCidade2));
    else printf("Cidade 2 venceu (%d)", (PoderCidade1 > PoderCidade2));
    printf("\nArea: ");
	if (areaKM1 > areaKM2)	printf("Cidade 1 venceu (%d)", (areaKM1 > areaKM2));
    else	printf("Cidade 2 venceu (%d)", (areaKM1 > areaKM2));
    printf("\nPIB: ");
	if (pib1 > pib2)	printf("Cidade 1 venceu (%d)", (pib1 > pib2));
    else	printf("Cidade 2 venceu (%d)", (pib1 > pib2));
    printf("\nPontos Turísticos: ");
	if (NumPointTurism1 > NumPointTurism2)	printf("Cidade 1 venceu (%d)", (NumPointTurism1 > NumPointTurism2));
    else	printf("Cidade 2 venceu (%d)", (NumPointTurism1 > NumPointTurism2));
    printf("\nDensidade Populacional: ");
	if (MediaDensidade1 < MediaDensidade2)	printf("Cidade 1 venceu (%d)", (MediaDensidade1 < MediaDensidade2));
    else	printf("Cidade 2 venceu (%d)", (MediaDensidade1 < MediaDensidade2));
    printf("\nPIB per Capita: ");
	if (MediaPIB1> MediaPIB2)	printf("Cidade 1 venceu (%d)", (MediaPIB1 > MediaPIB2));
    else	printf("Cidade 2 venceu (%d)", (MediaPIB1 > MediaPIB2));
	printf("\nSuper Poder: ");
	if (PoderCidade1> PoderCidade2)	printf("Cidade 1 venceu (%d)", (PoderCidade1 > PoderCidade2));
    else	printf("Cidade 2 venceu (%d)", (PoderCidade1 > PoderCidade2));

	
	return 0;
}
