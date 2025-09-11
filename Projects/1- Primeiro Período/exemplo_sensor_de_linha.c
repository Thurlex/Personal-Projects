#define D0_PIN 13
#define ANA_LINHA_PIN A0


void setup() {
  pinMode(D0_PIN, INPUT);
  pinMode(ANA_LINHA_PIN, INPUT);

  Serial.begin(9600);
  while (!Serial);
}

// Imprime uma string com uma variável inteira, formatada como no printf
// RETORNO: zero se operação for bem sucedida, menor que zero se houver erro nos formatos da string
int serial_print_int(
  const char * const fmt, // string com a mensagem e um único formato %d
  const int valor // valor referente ao formato %d de fmt
) {
  #define TAMANHO_DA_STRING 50
  char myString[TAMANHO_DA_STRING];

  int err = snprintf(myString, TAMANHO_DA_STRING, fmt, valor);
  if (err < 0)
    return err;

  Serial.println(myString);

  return 0;
}

bool estado_deteccao_linha = LOW;
void loop() {
  bool achou_linha = digitalRead(D0_PIN);

  int analog_val = analogRead(ANA_LINHA_PIN);
  serial_print_int("analog = %d", analog_val);

  if (achou_linha != estado_deteccao_linha) {
    serial_print_int("Retorno linha = %d", (int)achou_linha);
    if (achou_linha)
      Serial.println("Linha detectada");
    else
      Serial.println("Linha deixou de ser detectada");
  }

  estado_deteccao_linha = achou_linha;

}
