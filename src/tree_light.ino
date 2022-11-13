#define VARIAC_PIN   A2
#define SIPO_CLK     6
#define SIPO_LATCH   7
#define SIPO_DATA    8

uint32_t SIPO_dataset; //XXXX_XXXX__1100_0000__0000_0000__0000_0000


void setup()
{
    pinMode(SIPO_DATA, OUTPUT);
    pinMode(SIPO_CLK, OUTPUT);
    pinMode(SIPO_LATCH, OUTPUT);
    pinMode(VARIAC_PIN, INPUT);
    digitalWrite(SIPO_DATA, LOW);
    digitalWrite(SIPO_CLK, LOW);
    digitalWrite(SIPO_LATCH, HIGH);
}


void loop()
{
    int variable_value = analogRead(VARIAC_PIN);
    if(variable_value < 10)
    {
        SIPO_dataset = 0xFFFFFFFF;
    }
    else
    {
        variable_value = map(variable_value, 10, 1023, 10, 1000);
        SIPO_dataset = random(0xFF000000, 0xFFFFFFFF);
        delay(variable_value);
    }

    for(int i = 0; i < 24; i++)
    {
        digitalWrite(SIPO_DATA, !!(SIPO_dataset & ((uint32_t)1 << i)));

        digitalWrite(SIPO_CLK, HIGH);
        digitalWrite(SIPO_CLK, LOW);
    }
    digitalWrite(SIPO_LATCH, LOW);
    digitalWrite(SIPO_LATCH, HIGH);
}
