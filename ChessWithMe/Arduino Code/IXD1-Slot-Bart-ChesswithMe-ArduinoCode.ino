// Bart Slot - Chess with me - Project Interaction design 1 - started by Bart Slot 19 October 2018, edited on July 29 2019
//1. line 23  
// 2 chessboardtiles with NEOPIXELS | the Chessboard tiles are on Analog pins. If there is a value, there's a chesspiece on the tile.

//2. line 87
// 1 Chesspiece that contains an known resistor acting as an ID for the specific piece. (for example: ohm 200 resistor is a Queen)

//3. line 123
//Players can choose their color (for now by using the console.Read function)

// Chessboard code 

//Neopixel SETUP
  #include <Adafruit_NeoPixel.h>
  #ifdef __AVR__
    #include <avr/power.h>
  #endif
  // Pin LED out
  #define PIN 6 // D pin LED Data 
  #define NUM_LEDS 6 // Total LEDS
  Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);

  //1. 2 chessboardtiles with NEOPIXELS 
  int analogPin1 = 0; // A pin measurement
  int analogPin2 = 1; // A pin measurement

  
  int colorPlayer1 = 0;
  int colorPlayer2 = 1;
  int val = 0;


  int raw1 = 0;
  int raw2 = 0;
  int Vin = 5;

  float Vout = 0;
  float r0 = 1000;
  float r1 = 0;
  float r2 = 0;
 
  float buffer= 0;

  int a1 = 1;
  int b1 = 2;

  char from = A1;
  char to = B1;

  bool PieceOn = false;
  int b = 0;
  byte neopix_gamma[] = { // Code for Neopixels
      0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1,
      1,  1,  1,  1,  1,  1,  1,  1,  1,  2,  2,  2,  2,  2,  2,  2,
      2,  3,  3,  3,  3,  3,  3,  3,  4,  4,  4,  4,  4,  5,  5,  5,
      5,  6,  6,  6,  6,  7,  7,  7,  7,  8,  8,  8,  9,  9,  9, 10,
     10, 10, 11, 11, 11, 12, 12, 13, 13, 13, 14, 14, 15, 15, 16, 16,
     17, 17, 18, 18, 19, 19, 20, 20, 21, 21, 22, 22, 23, 24, 24, 25,
     25, 26, 27, 27, 28, 29, 29, 30, 31, 32, 32, 33, 34, 35, 35, 36,
     37, 38, 39, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 50,
     51, 52, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 66, 67, 68,
     69, 70, 72, 73, 74, 75, 77, 78, 79, 81, 82, 83, 85, 86, 87, 89,
     90, 92, 93, 95, 96, 98, 99,101,102,104,105,107,109,110,112,114,
    115,117,119,120,122,124,126,127,129,131,133,135,137,138,140,142,
    144,146,148,150,152,154,156,158,160,162,164,167,169,171,173,175,
    177,180,182,184,186,189,191,193,196,198,200,203,205,208,210,213,
    215,218,220,223,225,228,231,233,236,239,241,244,247,249,252,255 };

void setup() {
    // Code for Neopixels
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  // End of trinket special code
  
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'

  char rx_byte_from = 0;
  char rx_byte_to = 0;
  Serial.begin(115200);
  
  //First time, players pick color.
  setPlayerColor();
  
}

void loop() {

  //2. 1 Chesspiece that contains an known resistor acting as an ID for the specific piece. (for example: ohm 200 resistor is a Queen)
  raw1= analogRead(analogPin1); //Chesstile
  raw2= analogRead(analogPin2); //Chesstile 2
  
  if(raw1) //Check if there is a piece on the chessboard tile (check the resistor values)
  {
    buffer= raw1 * Vin;
    Vout= (buffer)/1024.0;
    buffer= (Vin/Vout) -1;
    r2= r1 * buffer;
    Serial.print("r2: ");
    if ((r2 >= 0.1) && (r2 <= r2)) { // If the resistor in a certain range: we know what the piece is.
      Serial.println(r2); Serial.print("Queen P1");
      delay(1000);
    }
    
    chess(colorPlayer1); //Get color value 
  }
  
  if(raw2) 
  {
    buffer= raw2 * Vin;
    Vout= (buffer)/1024.0;
    buffer= (Vin/Vout) -1;
    r3= r1 * buffer;
    Serial.print("r3: ");
    Serial.println(r3);
    delay(1000);
  }
  if(r3 < 1) {
    chess(5);
  }
}



//3. Players can choose their color (for now by using the console.Read function)

void checkPlayerColor() { 
  Serial.println("Pick your Color: 1 = RED | 2 = BLUE | 3 = GREEN | 4 = YELLOW");
  colorPlayer1 = Serial.read();
  if(colorPlayer1 == 1) {
    SetPlayerColor(255,10,10); //Make the playercolor Red
  } else if (colorPlayer1 == 2){
    SetPlayerColor(10,10,255); //Make the playercolor blue
  } else if (colorPlayer1 == 3){
    SetPlayerColor(10,255,10); //Make the playercolor Green
  } else {
    SetPlayerColor(255,255,10); //Make the playercolor Yellow
  }
  Serial.println("Pick Color player 2: 1 = RED | 2 = BLUE | 3 = GREEN | 4 = YELLOW");
  colorPlayer2 = Serial.read();
  if(colorPlayer1 == colorPlayer2){
    delay(1000);
    Serial.println("Player 1 already picked " + colorPlayer1);
    Serial.println("Pick Color player 2" );
    colorPlayer2 = Serial.read();
  }
  if(colorPlayer2 == 1) {
    SetPlayerColor(255,10,10); //Make the playercolor Red
  } else if (colorPlayer2 == 2){
    SetPlayerColor(10,10,255); //Make the playercolor blue
  } else if (colorPlayer2 == 3){
    SetPlayerColor(10,255,10); //Make the playercolor Green
  } else (colorPlayer2 = 4){
    SetPlayerColor(255,255,10); //Make the playercolor Yellow
  }
  
  OK(1,1); //Fade 1 time green (for player 1)
}
void OK (uint32_t n, uint32_t wait) {

  for(int j = 0; j < 256 ; j++){  //Pulse brighter Green
      strip.setPixelColor(n, strip.Color(0,255,0, neopix_gamma[j] ) );
      delay(wait);
      strip.show();
  for(int j = 255; j >= 0 ; j--){ //Pulse less bright Green
      strip.setPixelColor(n, strip.Color(0,255,0, neopix_gamma[j] ) );
  }
      delay(wait);
      strip.show();
  }
}
void SetPlayerColor(uint32_t r,uint32_t g, uint32_t b) { //Change pixels to color RGB values
  strip.setPixelColor(r, g, b, 255);
  strip.show();
}

void chess(uint32_t n) {
  strip.setPixelColor(n, 30, 50, 255);
  strip.show();
}

void isTakenOff(uint8_t n, uint8_t wait) {
  for(int j = 0; j < 256 ; j++){  //Pulse brighter
      strip.setPixelColor(n, strip.Color(0,0,0, neopix_gamma[j] ) );
      delay(wait);
      strip.show();
  }
  for(int j = 255; j >= 0 ; j--){ //Pulse less bright
      strip.setPixelColor(n, strip.Color(0,0,0, neopix_gamma[j] ) );
      }
      delay(wait);
      strip.show();
}

