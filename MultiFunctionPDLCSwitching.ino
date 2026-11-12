#define NUM_RELAYS 10

const int relayPins[NUM_RELAYS] = { 34, 35,36, 37, 39, 41, 43, 45,47,49};

const int relayPins2[NUM_RELAYS] = { 34, 35,36, 37, 39, 41, 43, 45,47,49};

bool canRunSectionOne = true;
bool canRunSectionTwo = false;
bool canRunSectionThree = false;
bool canRunSectionFour = false;
bool canRunSectionFive = false;

unsigned long previousMillis = millis();
unsigned long interval = 2000;       // Desired interval to blink (milliseconds)

void setup() {

  Serial.begin(9600); 
  
  // Initialize the pins
  for (int i = 0; i < NUM_RELAYS; i++)
  { 
    pinMode(relayPins[i], OUTPUT);
    digitalWrite(relayPins[i], LOW);  // Ensure relays are off initially
  }
}
void loop() 
{
    manualControl();
}
void manualControl()
{
  unsigned long currentMillis = millis();

         if (currentMillis - previousMillis >= interval) 
         {
                  previousMillis = currentMillis; // Save the last time you blinked the LED

                  if(canRunSectionOne == true)
                  {
                      for (int i = 0; i < NUM_RELAYS; i++) 
                      {
                           digitalWrite(relayPins[i], HIGH);  // Activate relay
                          digitalWrite(relayPins[i+1], HIGH);  // Activate relay
                           digitalWrite(relayPins[i+2], HIGH);  // Activate relay
                           delay(600);
                            digitalWrite(relayPins[i], LOW);
                         digitalWrite(relayPins[i+1], LOW);
                         digitalWrite(relayPins[i+2], LOW);
                        Serial.println(relayPins[i]);
                              if(relayPins[i] == 49)
                               {
                                    Serial.println("TRUE");
                                     delay(1000);
                                    canRunSectionOne = false;
                                    canRunSectionTwo = true;
                                    break;
                               }
                       }
                  }

                  if(canRunSectionTwo == true)
                  {
                     for (int i = NUM_RELAYS ; i >0; i--) 
                      {
                           digitalWrite(relayPins[i], HIGH);  // Activate relay
                          digitalWrite(relayPins[i-1], HIGH);  // Activate relay
                           digitalWrite(relayPins[i-2], HIGH);  // Activate relay
                           delay(600);
                            digitalWrite(relayPins[i], LOW);
                         digitalWrite(relayPins[i-1], LOW);
                         digitalWrite(relayPins[i-2], LOW);
                        Serial.println(relayPins[i]);
                              if(relayPins[i] == 34)
                               {
                                    Serial.println("TRUE");
                                     delay(1000);
                                     canRunSectionThree = true ;
                                    canRunSectionTwo = false;
                                    break;
                               }
                       }
                  }

                  if(canRunSectionThree == true)
                  {
                     for (int i = 0; i < NUM_RELAYS; i++) 
                      {
                           digitalWrite(relayPins[i], HIGH);  // Activate relay
                          digitalWrite(relayPins[i+1], HIGH);  // Activate relay
                           digitalWrite(relayPins[i+2], HIGH);  // Activate relay
                           digitalWrite(relayPins[i+3], HIGH);  // Activate relay
                           delay(300);
                            digitalWrite(relayPins[i], LOW);
                         digitalWrite(relayPins[i+1], LOW);
                         digitalWrite(relayPins[i+2], LOW);
                         digitalWrite(relayPins[i+3], LOW);
                        Serial.println(relayPins[i]);
                              if(relayPins[i] == 49)
                               {
                                    Serial.println("TRUE");
                                     delay(1000);
                                     canRunSectionThree = false;
                                    canRunSectionFour= true;
                                    break;
                               }
                       }
                  }

                   if(canRunSectionFour == true)
                  {
                     for (int i = 0; i < NUM_RELAYS; i++) 
                      {
                           digitalWrite(relayPins[i], HIGH);  // Activate relay
                          digitalWrite(relayPins[i+2], HIGH);  // Activate relay
                           digitalWrite(relayPins[i+4], HIGH);  // Activate relay
                           digitalWrite(relayPins[i+6], HIGH);  // Activate relay
                            digitalWrite(relayPins[i+8], HIGH);  // Activate relay
                           delay(1200);
                            digitalWrite(relayPins[i], LOW);
                         digitalWrite(relayPins[i+2], LOW);
                         digitalWrite(relayPins[i+4], LOW);
                         digitalWrite(relayPins[i+6], LOW);
                          digitalWrite(relayPins[i+8], LOW);  // Activate relay
                        Serial.println(relayPins[i]);
                              if(relayPins[i] == 49)
                               {
                                    Serial.println("TRUE");
                                     delay(1000);
                                     canRunSectionFive = true;
                                    canRunSectionFour= false;
                                    break;
                               }
                       }
                  }
                  if(canRunSectionFive == true)
                  {
                     for (int i = 0; i < 1; i++) 
                      {
                           digitalWrite(relayPins[i], HIGH);  // Activate relay
                           digitalWrite(relayPins[i+1], HIGH);  // Activate relay
                           digitalWrite(relayPins[i+2], HIGH);  // Activate relay
                           digitalWrite(relayPins[i+3], HIGH);  // Activate relay
                           digitalWrite(relayPins[i+4], HIGH);  // Activate relay
                          digitalWrite(relayPins[i+5], HIGH);  // Activate relay
                           digitalWrite(relayPins[i+6], HIGH);  // Activate relay
                           digitalWrite(relayPins[i+7], HIGH);  // Activate relay
                            digitalWrite(relayPins[i+8], HIGH);  // Activate relay
                             digitalWrite(relayPins[i+9], HIGH);  // Activate relay
                           delay(5000);
                           digitalWrite(relayPins[i], LOW);  // Activate relay
                           digitalWrite(relayPins[i+1], LOW);  // Activate relay
                           digitalWrite(relayPins[i+2], LOW);  // Activate relay
                           digitalWrite(relayPins[i+3], LOW);  // Activate relay
                           digitalWrite(relayPins[i+4], LOW);  // Activate relay
                          digitalWrite(relayPins[i+5], LOW);  // Activate relay
                           digitalWrite(relayPins[i+6], LOW);  // Activate relay
                           digitalWrite(relayPins[i+7], LOW);  // Activate relay
                            digitalWrite(relayPins[i+8], LOW);  // Activate relay
                             digitalWrite(relayPins[i+9], LOW);  // Activate relay
                        Serial.println(relayPins[i]);
                              if(relayPins[i] == 34)
                               {
                                    Serial.println("TRUE");
                                     delay(1500);
                                     canRunSectionOne = true;
                                    canRunSectionFive= false;
                                    break;
                               }
                       }
                  }

     
          }
bailout:
  // Program execution continues here
  Serial.println("Exited both loops!");
    
}

