#include <stdio.h>

int main() {
	
//cadatro de cartas da cidade
	//variaveis da cidade 
	char Uf = 'A';
	int CodCarta = 1;
	char nomeCidade[20];
	int Populacao;
	float areaKM;
	float pib;
	int NumPointTurism;
    float MediaDensidade,MediaPIB;
	//chamando cidade A01
	printf("\n               Informe Primeira cidade! \n\n");
	printf("Informe o Estado: ");
	scanf("%s", &Uf);
	printf("Informe o Codigo da Carta: ");
	scanf("%d", &CodCarta);
	printf("Informe o Nome da Cidade: ");
	scanf("%s", &nomeCidade);
	printf("Informe a Populacao: ");
	scanf("%d", &Populacao);
	printf("Informe a Area da Cidade: ");
	scanf("%f", &areaKM);
	printf("Informe o PIB: ");
	scanf("%f", &pib);
	printf("Informe a quantidade de pontos turisticos: ");
	scanf("%d", &NumPointTurism);

	//exibe primeiro cadastro
	printf("\n \n              Cadastro da Primeira cidade realizado! \n\n\n");

	printf("Carta: %d \n", CodCarta);
	printf("Estado: %c \n", Uf);
	printf("Codigo: %c0%d \n", Uf,CodCarta);
	printf("Nome da Cidade: %s \n", nomeCidade);
	printf("Populacao: %d \n", Populacao);
	printf("Area: %.2f KM \n", areaKM);
	printf("PIB: %.2f Bilhoes de reais\n", pib);
	printf("Numero de Pontos Turisticos: %d \n", NumPointTurism);
    
	MediaDensidade = (float)(Populacao / areaKM);
    MediaPIB = (float)(pib / Populacao);
    
    printf("Densidade Populacional: %.2f hab/km² \n",MediaDensidade);
    printf("PIB per capita: %.2f reais\n",MediaPIB);

	//chamando cidade A02
	printf("\n\n\n\n\n              Informe Segunda cidade! \n\n\n");
	printf("Informe o Estado: ");
	scanf("%s", &Uf);
	printf("Informe o Codigo da Carta: ");
	scanf("%d", &CodCarta);
	printf("Informe o Nome da Cidade: ");
	scanf("%s", &nomeCidade);
	printf("Informe a Populacao: ");
	scanf("%d", &Populacao);
	printf("Informe a Area da Cidade: ");
	scanf("%f", &areaKM);
	printf("Informe o PIB: ");
	scanf("%f", &pib);
	printf("Informe a quantidade de pontos turisticos: ");
	scanf("%d", &NumPointTurism);

	//exibe primeiro cadastro
	printf("\n \n              Cadastro da Segunda cidade realizado! \n\n\n");

	printf("Carta: %d \n", CodCarta);
	printf("Estado: %c \n", Uf);
	printf("Codigo: %c0%d \n", Uf, CodCarta);
	printf("Nome da Cidade: %s \n", nomeCidade);
	printf("Populacao: %d \n", Populacao);
	printf("Area: %.2f KM \n", areaKM);
	printf("PIB: %.2f Bilhoes de reais\n", pib);
	printf("Numero de Pontos Turisticos: %d \n", NumPointTurism);
    
	MediaDensidade = (float)(Populacao / areaKM);
    MediaPIB = (float)(pib / Populacao);
    
    printf("Densidade Populacional: %.2f hab/km² \n",MediaDensidade);
    printf("PIB per capita: %.2f reais\n",MediaPIB);


	return 0;
}
