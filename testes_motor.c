#include <testes_motor.h>
//  1 - para trás - abre e 0 - para frente - fecha tampa
//  Motor 1: Rosca     Motor 2: Tampa

// Saídas: Motores de Passo
// Para rosca sem fim
#define i_BLU1             pin_a2//pin_a1
#define i_PNK1             pin_a1//pin_a2
#define i_YLW1             pin_b7//pin_a3
#define i_ORN1             pin_a3//pin_b7

// Para tampa
#define i_BLU2             pin_a5
#define i_PNK2             pin_e0
#define i_YLW2             pin_e1
#define i_ORN2             pin_e2

int posicao1 = 1, posicao2 = 1;

//Funções
void inicializar()                                                              // Inicializa o sistema (deixa todas as saídas em nível baixo)
{
   output_low(i_BLU1);
   output_low(i_PNK1);
   output_low(i_YLW1);
   output_low(i_ORN1);
   output_low(i_BLU2);
   output_low(i_PNK2);
   output_low(i_YLW2);
   output_low(i_ORN2);
}


/*                   INICIO DAS CONFIGURAÇÕES DO MOTOR DE PASSO                    */
//Os métodos Passo-i(); são as ativações das bobinas do motor de passo

void Passo1_Rosca(){
   output_high(i_BLU1);
   output_high(i_PNK1);
   output_low(i_YLW1);
   output_low(i_ORN1);
}

void Passo1_Tampa(){
   output_high(i_BLU2);
   output_high(i_PNK2);
   output_low(i_YLW2);
   output_low(i_ORN2);
}

void Passo2_Rosca(){
   output_low(i_BLU1);
   output_high(i_PNK1);
   output_high(i_YLW1);
   output_low(i_ORN1);
}

void Passo2_Tampa(){
   output_low(i_BLU2);
   output_high(i_PNK2);
   output_high(i_YLW2);
   output_low(i_ORN2);
}

void Passo3_Rosca(){
   output_low(i_BLU1);
   output_low(i_PNK1);
   output_high(i_YLW1);
   output_high(i_ORN1);
}

void Passo3_Tampa(){
   output_low(i_BLU2);
   output_low(i_PNK2);
   output_high(i_YLW2);
   output_high(i_ORN2);
}

void Passo4_Rosca(){
   output_high(i_BLU1);
   output_low(i_PNK1);
   output_low(i_YLW1);
   output_high(i_ORN1);
}

void Passo4_Tampa(){
   output_high(i_BLU2);
   output_low(i_PNK2);
   output_low(i_YLW2);
   output_high(i_ORN2);
}


void motorPasso (int enabl, int motor1ou2, int sentido)  //sentido 1 - trás || 0 - frente
{
   if(motor1ou2 == 1) //motor da rosca
   {
      if(enabl == 1)
      {
         switch (posicao1)
         {

               case 1:
                  if(sentido == 0)
                     Passo2_Rosca();
                  else
                     Passo4_Rosca();
                  break;
               case 2:
                  if(sentido == 0)
                     Passo3_Rosca();
                  else
                     Passo1_Rosca();
                  break;
               case 3:
                  if(sentido == 0)
                     Passo4_Rosca();
                  else
                     Passo2_Rosca();
                  break;
               case 4:
                  if(sentido == 0)
                     Passo1_Rosca();
                  else
                     Passo3_Rosca();
                  break;
               default:
                  break;

            }

            if(sentido == 0)
            {
               if(posicao1 == 4)                        //pequeno controle sobre a posição do motor de passo
                  posicao1 = 1;
               else
                  posicao1++;
            }

            else if(sentido == 1)
            {
               if(posicao1 == 1)                           //pequeno controle sobre a posição do motor de passo
                  posicao1 = 4;
               else
                  posicao1--;
            }
         }
      }



   else if(motor1ou2 == 2) //motor da tampa
   {
      if(enabl == 1)
      {
         switch (posicao2)
         {
            case 1:
               if(sentido == 0)
                  Passo2_Tampa();
               else
                  Passo4_Tampa();
               break;
            case 2:
               if(sentido == 0)
                  Passo3_Tampa();
               else
                  Passo1_Tampa();
               break;
            case 3:
               if(sentido == 0)
                  Passo4_Tampa();
               else
                  Passo2_Tampa();
               break;
            case 4:
               if(sentido == 0)
                  Passo1_Tampa();
               else
                  Passo3_Tampa();
               break;
            default:
               break;

          }

            if(sentido == 1)
            {
               if(posicao2 == 4)                        //pequeno controle sobre a posição do motor de passo
                  posicao2 = 1;
               else
                  posicao2++;
            }

            else if(sentido == 0)
            {
               if(posicao2 == 1)                           //pequeno controle sobre a posição do motor de passo
                  posicao2 = 4;
               else
                  posicao2--;
            }

         }
      }

}

void abreTampa(int16 tempo_em_ms)
{
    int16 i;
    for (i = 0; i < tempo_em_ms; i += 5){
        motorPasso (1, 2, 1); //a função de abrir o motor
        delay_ms(5);
    }
}

void fechaTampa(int16 tempo_em_ms)
{
    int16 i;
    for (i = 0; i < tempo_em_ms; i += 5){
        motorPasso (1, 2, 0); //a função de abrir o motor
        delay_ms(5);
    }
}

void abreRacao(int16 tempo_em_ms)
{
    int16 i;
    for (i = 0; i < tempo_em_ms; i += 5){
        motorPasso(1,1,1); //a função de abrir o motor
        delay_ms(5);
    }
}

void fechaRacao(int16 tempo_em_ms)
{
    int16 i;
    for (i = 0; i < tempo_em_ms; i += 5){
        motorPasso(1,1,0); //a função de abrir o motor
        delay_ms(5);
    }
}

void main()
{
    abreTampa(13000);
    
    delay_ms(20000);
    
    fechaTampa(13000);
}
