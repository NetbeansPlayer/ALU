int EstadoA=0;
int EstadoB=0;
//ENTRADAS DE CONTROL
int EstadoZ=0;
int EstadoY=0;
int EstadoX=0;
int EstadoW=0;
void setup() {
  // put your setup code here, to run once:
  pinMode (2,INPUT);
  pinMode (3,INPUT);
  pinMode (4,INPUT);//CONTROL 1 Z
  pinMode (5,INPUT);//CONTROL 2 Y
  pinMode (6,INPUT);//CONTROL 3 X
  pinMode (7,INPUT);//CONTROL 4 W
  pinMode (9,OUTPUT);//OPERACIONES / NOT A
  pinMode (10,OUTPUT);//ACARREO / NOT B
  pinMode (11,OUTPUT);//SIGNO
  pinMode (12,OUTPUT);//INFINITO
  pinMode (13,OUTPUT);//INDEFINIDO
}

void loop() {
  // put your main code here, to run repeatedly:
  //Leer las variables físicas
  EstadoA=digitalRead (2);
  EstadoB=digitalRead (3);
  //ESTADOS DE CONTROL
  EstadoZ=digitalRead (4);
  EstadoY=digitalRead (5);
  EstadoX=digitalRead (6);
  EstadoW=digitalRead (7);
  
  //inicia ALU
    //XOR ^ (Suma)
    if((!EstadoZ&&!EstadoY&&!EstadoX&&EstadoW)&&(EstadoA^EstadoB)){digitalWrite(9,HIGH);}
    //AND && (Acarreos)
    if((!EstadoZ&&!EstadoY&&!EstadoX&&EstadoW)&&(EstadoA&&EstadoB)){digitalWrite(10,HIGH);}

    //XOR ^ (Resta)
    if((!EstadoZ&&!EstadoY&&EstadoX&&!EstadoW)&&(EstadoA^EstadoB)){digitalWrite(9,HIGH);}
    //AND+NOT(A) ! && (Signo)
    if((!EstadoZ&&!EstadoY&&EstadoX&&!EstadoW)&&(!EstadoA&&EstadoB)){digitalWrite(11,HIGH);}
  
    //AND && (Multiplicación)
    if((!EstadoZ&&!EstadoY&&EstadoX&&EstadoW)&&(EstadoA&&EstadoB)){digitalWrite(9,HIGH);}

    //AND && (División)
    if((!EstadoZ&&EstadoY&&!EstadoX&&!EstadoW)&&(EstadoA&&EstadoB)){digitalWrite(9,HIGH);digitalWrite(12,LOW);digitalWrite(13,LOW);}
    else if ((!EstadoZ&&EstadoY&&!EstadoX&&!EstadoW)&&(!EstadoA&&EstadoB)){digitalWrite(9,LOW);digitalWrite(12,LOW);digitalWrite(13,LOW);}
    //AND+NOT && ! (Infinito)
    if((!EstadoZ&&EstadoY&&!EstadoX&&!EstadoW)&&(EstadoA&&!EstadoB)){digitalWrite(9,LOW);digitalWrite(12,HIGH);digitalWrite(13,LOW);}
    //AND+NOT ! && ! (Indefinido)
    if((!EstadoZ&&EstadoY&&!EstadoX&&!EstadoW)&&(!EstadoA&&!EstadoB)){digitalWrite(9,LOW);digitalWrite(12,LOW);digitalWrite(13,HIGH);}
  
    //AND &&
    if((!EstadoZ&&EstadoY&&!EstadoX&&EstadoW)&&(EstadoA&&EstadoB)){digitalWrite(9,HIGH);}
  
    //OR ||
    if((!EstadoZ&&EstadoY&&EstadoX&&!EstadoW)&&(EstadoA||EstadoB)){digitalWrite(9,HIGH);}
  
    //NOT A !
    if((!EstadoZ&&EstadoY&&EstadoX&&EstadoW)&&!EstadoA){digitalWrite(9,HIGH);}
    else if (EstadoA){digitalWrite(9,LOW);}
    //NOT B !
    if((!EstadoZ&&EstadoY&&EstadoX&&EstadoW)&&!EstadoB){digitalWrite(10,HIGH);}
    else if (EstadoB){digitalWrite(10,LOW);}
  
    //XOR ^
    if((EstadoZ&&!EstadoY&&!EstadoX&&!EstadoW)&&(EstadoA^EstadoB)){digitalWrite(9,HIGH);}
  
    //NOR !||!
    if((EstadoZ&&!EstadoY&&!EstadoX&&EstadoW)&&(!EstadoA&&!EstadoB)){digitalWrite(9,HIGH);}
    else if ((EstadoZ&&!EstadoY&&!EstadoX&&EstadoW)&&(EstadoA&&EstadoB)){digitalWrite(9,LOW);}
  
    //XNOR !^!
    if((EstadoZ&&!EstadoY&&EstadoX&&!EstadoW)&&(!EstadoA&&!EstadoB)){digitalWrite(9,HIGH);}
    else if ((EstadoZ&&!EstadoY&&EstadoX&&!EstadoW)&&(EstadoA&&EstadoB)){digitalWrite(9,HIGH);}
  
    //NAND &&
    if((EstadoZ&&!EstadoY&&EstadoX&&EstadoW)&&(!EstadoA||!EstadoB)){digitalWrite(9,HIGH);}
    else if ((EstadoZ&&!EstadoY&&EstadoX&&EstadoW)&&(EstadoA||EstadoB)){digitalWrite(9,LOW);}
  

  //Si no hay OPERACIÓN esta apagado (NOP)
  digitalWrite(9,LOW);digitalWrite(10,LOW);digitalWrite(11,LOW);digitalWrite(12,LOW);digitalWrite(13,LOW);
}
