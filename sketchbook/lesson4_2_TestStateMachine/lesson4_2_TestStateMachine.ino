// Definimos os pinos que vamos usar
const int buttonPin = 2;
const int pedGreenPin = 3;
const int pedRedPin = 4;
const int carRedPin = 5;
const int carYellowPin = 6;
const int carGreenPin = 7;

// Esse vetor ajuda na hora de inicializar e testar os pinos
const int ledPins[] = {pedGreenPin, pedRedPin, carRedPin, carYellowPin, carGreenPin};

// Essa variável vai contar quantas vezes apertamos o botão
int timesButtonPressed = 0;

// Essa variável guarda o estado atual
int state = 0;

void setup()
{
  // Pino do botão definido como INPUT_PULLUP
  // Assim, usamos o resistor de pull-up interno e poupamos um resistor!
  pinMode(buttonPin, INPUT_PULLUP);
  
  // Pinos dos LEDs definidos como OUTPUT
  // Usamos o vetor ledPins e o for para não termos que nos repetir
  for(int i = 0; i < 5; i++)
    pinMode(ledPins[i], OUTPUT);
    
  // Vamos usar a porta Serial para ver se estamos trocando de estado
  Serial.begin(9600);
}

void loop()
{ 
  // Se botão for pressionado, incrementar a contagem
  // Lembrem-se: No modo INPUT_PULLUP, botão pressionado fica LOW!
  if(digitalRead(buttonPin) == LOW)
    timesButtonPressed++;
  
  // A % B faz a divisão de A por B e retorna o resto
  // Isso permite que state varie de forma circular: 0, 1, 2, 3, 4, 0, 1, 2, ...
  state = timesButtonPressed % 5;
  
  // Esse switch/case permite que o comportamento mude, de acordo com o estado atual
  switch(state)
  {
    case 0:
      state_0();
      break;
    case 1:
      state_1();
      break;
    case 2:
      state_2();
      break;
    case 3:
      state_3();
      break;
    case 4:
      state_4();
      break;
    default:
      state_unknown();
      break;
  }
  
  // Esse delay ameniza o efeito do bounce do botão
  delay(100);
}

// Funções que dizem o que acontece em cada estado
void state_0()
{
  Serial.println("State 0");
}

void state_1()
{
  Serial.println("State 1");
}

void state_2()
{
  Serial.println("State 2");
}

void state_3()
{
  Serial.println("State 3");
}

void state_4()
{
  Serial.println("State 4");
}

void state_unknown()
{
  Serial.println("Unknown state!");
}
