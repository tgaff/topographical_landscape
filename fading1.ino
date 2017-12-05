// old flash code
// void setup() {
//  // put your setup code here, to run once:
// pinMode(11, OUTPUT);
//}
//void loop() {
//  digitalWrite(11, HIGH); 
//  delay(500);
//  digitalWrite(11, LOW);
//  delay(500);
//  
//}

/* Fader class
 * fades an LED at configurable speed
 */
class Fader
{
  public:
   int led;
   int brightness;
   int fadeAmount;

   /* Fader constructor
    *  fader x(11,0,5);
    *  pin = 11;           // the PWM pin the LED is attached to
    *  brightness = 0;    // how bright the LED is
    *  fadeSpeed = 5;    // how many points to fade the LED by (must be a factor of 255)
    */
    Fader(int pin, int initialBrightness, int fadeSpeed) {
      led = pin;
      brightness = initialBrightness;
      fadeAmount = fadeSpeed;
      pinMode(led, OUTPUT);
    }

    // call this function every 30ms or so to update the LED value
    virtual void update() { 
      analogWrite(led, brightness);
  
      // change the brightness for next time through the loop:
      brightness = brightness + fadeAmount;
  
      // reverse the direction of the fading at the ends of the fade:
      if (brightness <= 0 || brightness >= 255) {
        fadeAmount = -fadeAmount;
      }

    }
};

// declare our faders
Fader fader6(6, 0, 3); // pin 6, start at 0, increment by 3 
Fader fader11(11, 125, 5); // pin 11, start at 125, increment by 5


// the setup routine runs once when you press reset:
void setup() {
}

// the loop routine runs over and over again forever:
void loop() {
  fader6.update();
  fader11.update();

  // wait for 30 milliseconds before re-looping (otherwise too fast)
  delay(30); 
}
